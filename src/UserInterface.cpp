#include "UserInterface.h"
#include "ui_UserInterface.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>

#include "FileLoad.h"

UserInterface::UserInterface(QWidget *parent) :QMainWindow(parent),m_ui(new Ui::UserInterface)
{
  m_ui->setupUi(this);

  // Create the NGLScene and simulation
  m_gl=new  NGLScene(this);
  m_load = new FileLoad(this);

  // Set the NGL Window to appear in left hand side
  m_ui->s_mainWindowGridLayout->addWidget(m_gl,0,0,9,1);
}

UserInterface::~UserInterface()
{
  // Destructor
  delete m_ui;
}

void UserInterface::on_pushButton_clicked()
{
  // Show the Lua dialog con click
  m_load->show();
}

void UserInterface::on_agentRadius_valueChanged(double _r)
{
  // Set the agent radius value for all agents and set the default value
  for (size_t i=0; i <m_gl->m_flock->m_lua->m_sim->getNumAgents(); i++)
  {
    m_gl->m_flock->m_lua->m_sim->setAgentRadius(i,_r);
  }

   m_gl->m_flock->m_agentRadius = _r;
}

void UserInterface::on_numNeighbors_valueChanged(int _n)
{
  // Set the max number of neighbors for all agents and set the default value
  for (size_t i=0; i <m_gl->m_flock->m_lua->m_sim->getNumAgents(); i++)
  {
    m_gl->m_flock->m_lua->m_sim->setAgentMaxNeighbors(i,_n);
  }

  m_gl->m_flock->m_numOfNeighbors = _n;
}

void UserInterface::on_neighborDistance_valueChanged(double _d)
{
  // Set the max neighbor distance for all agents and set the default value
  for (size_t i=0; i < m_gl->m_flock->m_lua->m_sim->getNumAgents(); i++)
  {
    m_gl->m_flock->m_lua->m_sim->setAgentNeighborDist(i,_d);
  }

  m_gl->m_flock->m_neighborDist = _d;
}

void UserInterface::on_restartSim_clicked()
{
    // Restart the simulation
    m_gl->m_flock->setupSim();
}

void UserInterface::on_runScript_clicked()
{
    //Get the file path of the external script and return it to the setup
    // The sim is then restarted to reflect the changes
    m_gl->m_flock->m_luaSimScript = m_load->m_simFilePath;
    m_gl->m_flock->setupSim();
}
