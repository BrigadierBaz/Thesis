#include "FileLoad.h"
#include "ui_FileLoad.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

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

// Get the file being pointed to in the text entry field and load into TextEdit
void FileLoad::on_loadScript_clicked()
{ 
  QString filePath = m_ui->filePath->toPlainText();

  QFile simFile (filePath);

  // If read fails flag up a warning
  if(!simFile.open(QIODevice::ReadOnly))
  {
    QMessageBox::information(0,"Error",simFile.errorString());
  }

  // Get the contents of the file
  QTextStream in(&simFile);

  m_ui->luaViewer->setText(in.readAll());

  m_simFilePath = filePath.toUtf8().constData();

  simFile.flush();
  simFile.close();

}


// retrieve the path of a script file for use in the sim
void FileLoad::on_getFilePath_clicked()
{
    // Does not work correctly in this format
    QString fileName = QFileDialog::getSaveFileName(nullptr,
       tr("Open Lua"), "/home/", tr("Lua Source File (*.lua)"));

}


// write the cntents of the text box back into the file
void FileLoad::on_saveRun_clicked()
{
  QString filePath = m_ui->filePath->toPlainText();

  QFile simFile (filePath);

  // If write fails, flag up a warning
  if(!simFile.open(QIODevice::WriteOnly))
  {
    QMessageBox::information(0,"Error",simFile.errorString());
  }

  // Text is transferred via TextStream
  QTextStream out(&simFile);
  out << m_ui->luaViewer->toPlainText();
  simFile.flush();
  simFile.close();
}
