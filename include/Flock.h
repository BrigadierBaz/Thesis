#ifndef FLOCK_H
#define FLOCK_H

//extern "C" {
//# include "lua.h"
//# include "lauxlib.h"
//# include "lualib.h"
//}

#include <memory>
#include "RVO.h"

#include "kaguya.hpp"
#include "LuaInterpreter.h"

class Flock
{
public:
  Flock();

//  void loadScript(lua_State* L, const std::string& scriptFilename);

  bool m_stray = false;
  bool m_danger = false;

//  bool m_alignment = false;
//  bool m_expand = false;
//  bool m_cohesion = true;
//  bool m_cohesionAlt = false;
//  bool m_eddy = false;
//  bool m_separation = false;
//  bool m_targetCenter = false;
//  bool m_repel = false;
//  bool m_baitBall = false;
//  bool m_tube = false;
//  bool m_feather = false;
//  bool m_geometric = false;
//  bool m_trefoil = false;
//  bool m_stretch = false;

//      bool m_alignment = true;
//      bool m_expand = true;
//      bool m_cohesion = true;
//      bool m_cohesionAlt = false;
//      bool m_eddy = true;
//      bool m_separation = true;
//      bool m_targetCenter = true;
//      bool m_repel = true;
//      bool m_baitBall = true;
//      bool m_tube = true;
//      bool m_feather = true;
//      bool m_geometric = true;
//      bool m_trefoil = true;
//      bool m_stretch = true;

      float m_alignmentInfluence = 0.7f;
      float m_cohesionInfluence;
      float m_eddyInfluence = 0.4f;
      float m_repelInfluence = 1.0f;

      float m_baitBallInfluence = 2.0f;

      float m_trefoilInfluence = 1.0f;
      float m_geometricInfluence = 1.0f;
      float m_stretchInfluence = 1.0f;
      float m_featherInfluence = 1.0f;
      float m_tubeInfluence = 1.0f;


  /// the sim
  std::unique_ptr<RVO::RVOSimulator> m_sim;
  std::unique_ptr<LuaInterpreter> m_lua;
  std::vector <RVO::Vector3> m_goals;
  //std::shared_ptr<LuaScript> interactFunc;
  void setupSim();
  void setPreferredVelocities();
  bool reachedGoal();
  //RVO::Vector3 getVelocities(size_t agentNum);
  //int l_getVelocities(lua_State* L);
//  void loadScript(lua_State* L, const std::string& scriptFilename);

  bool m_animate=true;

  //New Variables

  float m_minNegative;
  float m_minPositive;
  float m_maxPositive;
  float m_maxNegative;

  int   m_numberOfBlocks;
  float m_blocksOffset;

  std::vector <RVO::Vector3> m_obstacles;

//    RVO::Vector3 m_vCenterOfSchool;
//    RVO::Vector3 m_vGoalPosition;

  enum class TerrainState {BASIC};

  TerrainState m_terrainState = TerrainState::BASIC;


  RVO::Vector3 m_centerOfSchool = RVO::Vector3(0.0f,0.0f,0.0f);
  RVO::Vector3 m_goalPosition = RVO::Vector3(0.0f,0.0f,0.0f);

};

#endif // FLOCK_H
