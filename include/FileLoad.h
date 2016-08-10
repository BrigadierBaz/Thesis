#ifndef FILELOAD_H
#define FILELOAD_H

#include <QDialog>
#include <memory>
#include "Flock.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file FileLoad.h
/// @brief This independant class managed an external dialog box in the GUI. Through this dialogue, users can view and edit the Lua script from inside the program.
/// @author Luke Bazalgette
/// @version 1.0
/// @date 8/8/16
//----------------------------------------------------------------------------------------------------------------------


namespace Ui {
class FileLoad;
}

class FileLoad : public QDialog
{
  Q_OBJECT

public:
  explicit FileLoad(QWidget *parent = 0);
  ~FileLoad();

  std::string m_simFilePath;

private slots:
  void on_loadScript_clicked();
  void on_getFilePath_clicked();

  void on_saveRun_clicked();

private:
  Ui::FileLoad *m_ui;
};

#endif // FILELOAD_H
