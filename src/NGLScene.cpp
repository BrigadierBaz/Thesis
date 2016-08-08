#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <ngl/Random.h>
#include <ngl/ShaderLib.h>
#include <iostream>
#include <cmath>
//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for x/y translation with mouse movement
//----------------------------------------------------------------------------------------------------------------------
constexpr float INCREMENT=1.0f;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for the wheel zoom
//----------------------------------------------------------------------------------------------------------------------
constexpr float ZOOM=8.0f;

NGLScene::NGLScene( QWidget *_parent ) : QOpenGLWidget( _parent )
{
  // set this widget to have the initial keyboard focus
  setFocus();
  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
  this->resize(_parent->size());

  m_flock.reset(new Flock);

  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
}


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}

void NGLScene::resizeGL(QResizeEvent *_event)
{
  m_width=_event->size().width()*devicePixelRatio();
  m_height=_event->size().height()*devicePixelRatio();
}

void NGLScene::resizeGL(int _w , int _h)
{
  m_width=_w*devicePixelRatio();
  m_height=_h*devicePixelRatio();
}

void NGLScene::timerEvent(QTimerEvent *)
{
  if(m_flock->m_animate)
  {
    //By calling the script here, this prevents multiple calls and increases performance
    m_flock->setPreferredVelocities();
    m_flock->m_lua->m_sim->doStep();

  }
  update();
}


void NGLScene::initializeGL()
{
  // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
  // be done once we have a valid GL context but before we call any GL commands. If we dont do
  // this everything will crash
  ngl::NGLInit::instance();
  glViewport(0,0,m_width,m_height);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["nglDiffuseShader"]->use();
  shader->setShaderParam4f("Colour",1,1,0,1);
  shader->setShaderParam3f("lightPos",1,1,1);
  shader->setShaderParam4f("lightDiffuse",1,1,1,1);
  // Now we will create a basic Camera from the graphics library
  // This is a static camera so it only needs to be set once
  // First create Values for the camera position
  ngl::Vec3 from(0,0,60);
  ngl::Vec3 to(0,0,0);
  ngl::Vec3 up(0,1,0);
  // now load to our new camera
  m_cam.set(from,to,up);
  // set the shape using FOV 45 Aspect Ratio based on Width and Height
  // The final two are near and far clipping planes of 0.5 and 10
  m_cam.setShape(50.0f,720.0f/576.0f,0.05f,350.0f);
  ngl::VAOPrimitives::instance()->createSphere("sphere",1.5,40);
  m_flock->setupSim();
  buildVAO();
  startTimer(0);


}


void NGLScene::loadMatricesToShader()
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();

  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;

  MV=  m_bodyTransform*m_globalTransformMatrix*m_cam.getViewMatrix();
  MVP= MV*m_cam.getVPMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setRegisteredUniform("MVP",MVP);
  shader->setRegisteredUniform("normalMatrix",normalMatrix);
}

void NGLScene::paintGL()
{

  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,m_width,m_height);
  // grab an instance of the shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["nglDiffuseShader"]->use();

    shader->setUniform("Colour",0.0f,1.0f,0.0f,1.0f);

    ngl::Transformation t;
    t.setPosition(m_flock->m_lua->m_goal.x(),
                  m_flock->m_lua->m_goal.y(),
                  m_flock->m_lua->m_goal.z());
    t.setScale(2.0,1.0,2.0);
    m_bodyTransform=t.getMatrix();
    loadMatricesToShader();
    ngl::VAOPrimitives::instance()->draw("cube");

    for (size_t i = 0; i < Flock::m_lua->m_predators.size(); ++i)
    {
      shader->setUniform("Colour",1.0f,0.0f,1.0f,1.0f);

      RVO::Vector3 p = m_flock->m_lua->m_predators[i];

      t.setPosition(p.x(),p.y(),p.z());
      t.setScale(8.0,8.0,8.0);
      m_bodyTransform=t.getMatrix();
      loadMatricesToShader();
      ngl::VAOPrimitives::instance()->draw("troll");
    }

    m_flock->m_lua->m_predators.clear();

  for(size_t j=0; j < 4; j++)
  {
//    RVO::Vector3 obstaclePosition = m_obstacles.at(j);

//    ngl::Transformation t;
//    t.setPosition(obstaclePosition.x(),obstaclePosition.y(),obstaclePosition.z());
//    t.setScale(60.0,60.0,60.0);
//    m_bodyTransform=t.getMatrix();
//    loadMatricesToShader();
//    ngl::VAOPrimitives::instance()->draw("sphere");
  }

  // Rotation based on the mouse position for our global transform
  ngl::Mat4 rotX;
  ngl::Mat4 rotY;
  // create the rotation matrices
  rotX.rotateX(m_spinXFace);
  rotY.rotateY(m_spinYFace);
  // multiply the rotations
  m_globalTransformMatrix=rotY*rotX;
  // add the translations
  m_globalTransformMatrix.m_m[3][0] = m_modelPos.m_x;
  m_globalTransformMatrix.m_m[3][1] = m_modelPos.m_y;
  m_globalTransformMatrix.m_m[3][2] = m_modelPos.m_z;
  // now draw
  m_vao->bind();

  shader->setUniform("Colour",1.0f,0.0f,0.0f,1.0f);

  for (size_t i = 0; i < m_flock->m_lua->m_sim->getNumAgents(); ++i)
  {
    ngl::Transformation t;
    RVO::Vector3 p=m_flock->m_lua->m_sim->getAgentPosition(i);
    RVO::Vector3 v=m_flock->m_lua->m_sim->getAgentVelocity(i);
    RVO::Vector3 next=p+v;

    RVO::Vector3 f=next-p;
    ngl::Real x=f.x();
    ngl::Real y=f.y();
    ngl::Real z=f.z();

    //using spherical geometry we calculate the rotation based on the New Point
    auto yrot=ngl::degrees(atan2f(x,z))+180.0f; // Now convert from radians to deg

    // Now for the zrot
    auto r=sqrt(x*x+y*y+z*z);
    auto xrot=ngl::degrees(asinf(y/r));

    t.setPosition(p.x(),p.y(),p.z());
    t.setScale(1.5f,1.5f,1.5f);
    t.setRotation(xrot,yrot,0.0f);

    m_bodyTransform=t.getMatrix();
    loadMatricesToShader();
    m_vao->draw();
  }
  m_vao->unbind();

}

void NGLScene::buildVAO()
{
  ngl::Vec3 verts[]=
  {
    ngl::Vec3(0,1,1),
    ngl::Vec3(0,0,-1),
    ngl::Vec3(-0.5,0,1),
    ngl::Vec3(0,1,1),
    ngl::Vec3(0,0,-1),
    ngl::Vec3(0.5,0,1),
    ngl::Vec3(0,1,1),
    ngl::Vec3(0,0,1.5),
    ngl::Vec3(-0.5,0,1),
    ngl::Vec3(0,1,1),
    ngl::Vec3(0,0,1.5),
    ngl::Vec3(0.5,0,1)

  };

  std::vector <ngl::Vec3> normals;
  ngl::Vec3 n=ngl::calcNormal(verts[2],verts[1],verts[0]);
  normals.push_back(n);
  normals.push_back(n);
  normals.push_back(n);
  n=ngl::calcNormal(verts[3],verts[4],verts[5]);
  normals.push_back(n);
  normals.push_back(n);
  normals.push_back(n);

  n=ngl::calcNormal(verts[6],verts[7],verts[8]);
  normals.push_back(n);
  normals.push_back(n);
  normals.push_back(n);

  n=ngl::calcNormal(verts[11],verts[10],verts[9]);
  normals.push_back(n);
  normals.push_back(n);
  normals.push_back(n);

  std::cout<<"sizeof(verts) "<<sizeof(verts)<<" sizeof(ngl::Vec3) "<<sizeof(ngl::Vec3)<<"\n";
  // create a vao as a series of GL_TRIANGLES
  m_vao.reset( ngl::VertexArrayObject::createVOA(GL_TRIANGLES));
  m_vao->bind();

  // in this case we are going to set our data as the vertices above

  m_vao->setData(sizeof(verts),verts[0].m_x);
  // now we set the attribute pointer to be 0 (as this matches vertIn in our shader)

  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);

  m_vao->setData(sizeof(verts),normals[0].m_x);
  // now we set the attribute pointer to be 2 (as this matches normal in our shader)

  m_vao->setVertexAttributePointer(2,3,GL_FLOAT,0,0);

  m_vao->setNumIndices(sizeof(verts)/sizeof(ngl::Vec3));

 // now unbind
  m_vao->unbind();


}


//----------------------------------------------------------------------------------------------------------------------
void NGLScene::mouseMoveEvent (QMouseEvent * _event)
{
  // note the method buttons() is the button state when event was called
  // this is different from button() which is used to check which button was
  // pressed when the mousePress/Release event is generated
  if(m_rotate && _event->buttons() == Qt::LeftButton)
  {
    int diffx=_event->x()-m_origX;
    int diffy=_event->y()-m_origY;
    m_spinXFace += (float) 0.5f * diffy;
    m_spinYFace += (float) 0.5f * diffx;
    m_origX = _event->x();
    m_origY = _event->y();

  }
        // right mouse translate code
  else if(m_translate && _event->buttons() == Qt::RightButton)
  {
    int diffX = (int)(_event->x() - m_origXPos);
    int diffY = (int)(_event->y() - m_origYPos);
    m_origXPos=_event->x();
    m_origYPos=_event->y();
    m_modelPos.m_x += INCREMENT * diffX;
    m_modelPos.m_y -= INCREMENT * diffY;

   }

  else if(m_moveGoal && _event->buttons() == Qt::MiddleButton)
  {
    int diffX = (int)(_event->x() - m_origXPos);
    int diffY = (int)(_event->y() - m_origYPos);
    m_origXPos=_event->x();
    m_origYPos=_event->y();
    m_flock->m_lua->m_goal.operator += (RVO::Vector3((INCREMENT * diffX)*1,0.0,(INCREMENT * diffY)*1));

   }
}


//----------------------------------------------------------------------------------------------------------------------
void NGLScene::mousePressEvent ( QMouseEvent * _event)
{
  // this method is called when the mouse button is pressed in this case we
  // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
  if(_event->button() == Qt::LeftButton)
  {
    m_origX = _event->x();
    m_origY = _event->y();
    m_rotate =true;
  }
  // right mouse translate mode
  else if(_event->button() == Qt::RightButton)
  {
    m_origXPos = _event->x();
    m_origYPos = _event->y();
    m_translate=true;
  }
  // middle mouse moves goal position
  else if(_event->button() == Qt::MiddleButton)
  {

    m_origXPos=_event->x();
    m_origYPos=_event->y();
    m_moveGoal=true;
  }

}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::mouseReleaseEvent ( QMouseEvent * _event )
{
  // this event is called when the mouse button is released
  // we then set Rotate to false
  if (_event->button() == Qt::LeftButton)
  {
    m_rotate=false;
  }
        // right mouse translate mode
  if (_event->button() == Qt::RightButton)
  {
    m_translate=false;
  }
}

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::wheelEvent(QWheelEvent *_event)
{

  // check the diff of the wheel position (0 means no change)
  if(_event->delta() > 0)
  {
    m_modelPos.m_z+=ZOOM;
  }
  else if(_event->delta() <0 )
  {
    m_modelPos.m_z-=ZOOM;
  }
  update();
}
//----------------------------------------------------------------------------------------------------------------------

void NGLScene::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
  // escape key to quite
  case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  case Qt::Key_R : m_flock->setupSim(); break;
  case Qt::Key_Space : m_flock->m_animate^=true; break;

//  case Qt::Key_1     : m_flock->m_repel       = !m_flock->m_repel;break;
//  case Qt::Key_2     : m_flock->m_expand      = !m_flock->m_expand;break;
//  case Qt::Key_3     : m_flock->m_cohesion    = !m_flock->m_cohesion;break;
//  case Qt::Key_4     : m_flock->m_eddy        = !m_flock->m_eddy;break;
//  case Qt::Key_5     : m_flock->m_separation  = !m_flock->m_separation;break;
//  case Qt::Key_6     : m_flock->m_baitBall    = !m_flock->m_baitBall;break;
//  case Qt::Key_7     : m_flock->m_trefoil     = !m_flock->m_trefoil;break;
//  case Qt::Key_8     : m_flock->m_geometric   = !m_flock->m_geometric;break;
//  case Qt::Key_9     : m_flock->m_targetCenter= !m_flock->m_targetCenter;break;

  default : break;



  }
  // finally update the GLWindow and re-draw

    update();
}
