#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include "NGLScene.h"
#include "Flock.h"

#include "FileLoad.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file UserInterface.h
/// @brief this independant class manages the GUI. Signals from the GUI are used to adjust paramters and manipulate the simulation. This class is derived from an earlier work "FlockingSystemFinal" by the same author. Available from: https://github.com/NCCA/asecgitech201516-BrigadierBaz.
/// @author Luke Bazalgette
/// @version 1.0
/// @date 7/8/16
//----------------------------------------------------------------------------------------------------------------------


namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
  Q_OBJECT

public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for the Window drawing class
  /// @param [in] parent the parent window to the class
  //----------------------------------------------------------------------------------------------------------------------
  explicit UserInterface(QWidget *parent = 0);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor must close down window and release resources
  //----------------------------------------------------------------------------------------------------------------------
  ~UserInterface();

  Ui::UserInterface *m_ui;
    FileLoad *m_load;


  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the openGL widget
  //----------------------------------------------------------------------------------------------------------------------
  NGLScene *m_gl;

private slots:
  void on_pushButton_clicked();
  void on_agentRadius_valueChanged(double _r);
  void on_numNeighbors_valueChanged(int _n);
  void on_neighborDistance_valueChanged(double _d);
  void on_restartSim_clicked();
  void on_runScript_clicked();
};

#endif // USERINTERFACE_H
