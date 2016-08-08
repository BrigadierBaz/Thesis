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

  m_gl=new  NGLScene(this);

  m_ui->s_mainWindowGridLayout->addWidget(m_gl,0,0,9,1);

  //m_ui->luaViewer->setText("Lua code is displayed here. Load a file to begin editing.");

//   QFile styleFile("lua.qss");
//   styleFile.open(QFile::ReadOnly);
//   QString styleSheet = QLatin1String(styleFile.readAll());

}

UserInterface::~UserInterface()
{
  delete m_ui;
}

void UserInterface::on_pushButton_clicked()
{
  FileLoad *load = new FileLoad(this);
  load->show();
//  QFileDialog dialog(this);
//  dialog.setFileMode(QFileDialog::DirectoryOnly);
//  dialog.setViewMode(QFileDialog::List);
//  dialog.setOption(QFileDialog::ShowDirsOnly, true);
//  //dialog.testOption(QFileDialog::DontUseNativeDialog);
//  //QString fileName = QFileDialog::getExistingDirectory(this,tr("Open Lua File"),QDir::currentPath(),QFileDialog::DontUseNativeDialog);
////  QString fileName = dialog.getOpenFileName(this, tr("Open File"),"./",tr("*"));
//  QString dir = dialog.getExistingDirectory(this, tr("Open Directory"),
//                                                 "./",
//                                                 QFileDialog::ShowDirsOnly
//                                                 | QFileDialog::DontResolveSymlinks);
  //QMessageBox::information(0,"Info",simFile.errorString());

  //QFile simFile (fileName);
//  if(!simFile.open(QIODevice::ReadOnly))
//  {
//    QMessageBox::information(0,"Info",simFile.errorString());
//  }

//  QTextStream in(&simFile);

//  m_ui->luaViewer->setText(in.readAll());
}

void UserInterface::on_agentRadius_valueChanged(double _r)
{
  for (size_t i=0; i <m_gl->m_flock->m_lua->m_sim->getNumAgents(); i++)
  {
    m_gl->m_flock->m_lua->m_sim->setAgentRadius(i,_r);
  }
}

void UserInterface::on_numNeighbors_valueChanged(int _n)
{
  for (size_t i=0; i <m_gl->m_flock->m_lua->m_sim->getNumAgents(); i++)
  {
    m_gl->m_flock->m_lua->m_sim->setAgentMaxNeighbors(i,_n);
  }
}

void UserInterface::on_neighborDistance_valueChanged(double _d)
{
  for (size_t i=0; i < m_gl->m_flock->m_lua->m_sim->getNumAgents(); i++)
  {
    m_gl->m_flock->m_lua->m_sim->setAgentNeighborDist(i,_d);
  }
}

void UserInterface::on_restartSim_clicked()
{
    m_gl->m_flock->setupSim();
}
