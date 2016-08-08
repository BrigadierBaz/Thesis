#include "FileLoad.h"
#include "ui_FileLoad.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

FileLoad::FileLoad(QWidget *parent) :
  QDialog(parent),
  m_ui(new Ui::FileLoad)
{
  m_ui->setupUi(this);
}

FileLoad::~FileLoad()
{
  delete m_ui;
}

void FileLoad::on_loadScript_clicked()
{
//  QFileDialog dialog(this);
//  QString fileName = dialog.getOpenFileName(this, tr("Open File"),"./",tr("*"));

  QString fileName = QFileDialog::getOpenFileName(NULL,
     tr("Open Lua"), "/home/", tr("Lua Source File (*.lua)"));

//  QFile simFile ("loadtest.lua");
//  if(!simFile.open(QIODevice::ReadOnly))
//  {
//    QMessageBox::information(0,"Info",simFile.errorString());
//  }

//  QTextStream in(&simFile);

//  m_ui->luaViewer->setText(in.readAll());
}
