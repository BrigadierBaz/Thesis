#ifndef FLOCK_H
#define FLOCK_H

#include "luawrapper.hpp"

#include <memory>
#include "RVO.h"
#include "LuaInterpreter.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file Flock.h
/// @brief This class dictates the default status of the sim and which scripts to load.
/// @author Luke Bazalgette
/// @version 1.0
/// @date 8/8/16
//----------------------------------------------------------------------------------------------------------------------


class Flock
{
public:
  Flock();

  /// the sim
  static std::unique_ptr <LuaInterpreter> m_lua;
  std::vector <RVO::Vector3> m_goals;
  void setupSim();
  void setPreferredVelocities();

  // String to store filepath retrieved from file dialog
  std::string m_luaSimScript = "";

  void processCommandLine(int argc, char **argv);
  bool m_animate=true;

  // Agent defaults
  double m_neighborDist = 15.0f;
  int m_numOfNeighbors = 15;
  double m_agentRadius = 2.0f;

};

#endif // FLOCK_H
