#include <iostream>
#include <string>

extern "C"
{
#include "lua.h"
#include "luaconf.h"
#include "lualib.h"
}

#include "luawrapper.hpp"
#include "luawrapperutil.hpp"

#include "LuaCustomTypes.hpp"
#include "Flock.h"

int LuaInterpreter_retrieveAgentVelocity(lua_State *L)
{
    int agentNum = luaL_checkinteger(L,2);

    RVO::Vector3 result = Flock::m_lua->retrieveAgentVelocity(agentNum);
    lua_newtable(L);
    luaU_push(L, result);

    return 1;
}

int LuaInterpreter_retrieveAgentPosition(lua_State *L)
{
    int agentNum = luaL_checkinteger(L,2);

    RVO::Vector3 result = Flock::m_lua->retrieveAgentPosition(agentNum);
    lua_newtable(L);
    luaU_push(L, result);

    return 1;
}

int LuaInterpreter_retrieveGoalPosition(lua_State *L)
{
    RVO::Vector3 result = Flock::m_lua->retrieveGoalPosition();

    lua_newtable(L);
    luaU_push(L, result);

    return 1;
}

int LuaInterpreter_retrieveCenterOfSwarm(lua_State *L)
{

  //int firstAgent = luaL_checkinteger(L,2);
  //int lastAgent = luaL_checkinteger(L,3);

//  RVO::Vector3 result = Flock::m_lua->retrieveCenterOfSwarm(firstAgent, lastAgent);
  RVO::Vector3 result = Flock::m_lua->retrieveCenterOfSwarm();

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_retrieveGoalVector(lua_State *L)
{

  int agentNum = luaL_checkinteger(L,2);

  RVO::Vector3 result = Flock::m_lua->retrieveGoalVector(agentNum);

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_retrieveCenterVector(lua_State *L)
{

  int agentNum = luaL_checkinteger(L,2);

  RVO::Vector3 result = Flock::m_lua->retrieveCenterVector(agentNum);

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_retrieveNumAgents(lua_State *L)
{
  // Minus 1 as index starts from 0.
  lua_pushnumber(L, Flock::m_lua->m_sim->getNumAgents() - 1);
  return 1;
}

int LuaInterpreter_retrieveAbsoluteValue(lua_State *L)
{
  RVO::Vector3 input  = luaU_check<RVO::Vector3>(L,2);
  lua_pushnumber(L, Flock::m_lua->retrieveAbsoluteValue(input));
  return 1;
}

int LuaInterpreter_retrievePowerOf(lua_State *L)
{
  float input = luaL_checknumber(L,2);
  float power = luaL_checknumber(L,3);

  lua_pushnumber(L, Flock::m_lua->retrievePowerOf(input, power));
  return 1;
}


int LuaInterpreter_setSingleAgentVelocity(lua_State *L)
{
  int agentNum = luaL_checkinteger(L,2);
  RVO::Vector3 target = luaU_check<RVO::Vector3>(L,3);
  //RVO::Vector3 inputVelocity = luaU_check<RVO::Vector3>(L,4);
  //RVO::Vector3 agentPosition = luaU_check<RVO::Vector3>(L,5);

  //RVO::Vector3 target (0.0f,0.0f,0.0f);
  //RVO::Vector3 inputVelocity (0.1f,0.1f,0.1f);

  Flock::m_lua->setSingleAgentVelocity(agentNum,target);
  return 0;
}

int LuaInterpreter_setNeighborAgentVelocity(lua_State *L)
{
  int agentNum = luaL_checkinteger(L,2);
  RVO::Vector3 target = luaU_check<RVO::Vector3>(L,3);

  Flock::m_lua->setNeighborAgentVelocity(agentNum,target);
  return 0;
}

int LuaInterpreter_setAllAgentVelocities(lua_State *L)
{
  RVO::Vector3 target = luaU_check<RVO::Vector3>(L,2);
  RVO::Vector3 inputVelocity = luaU_check<RVO::Vector3>(L,3);

  Flock::m_lua->setAllAgentVelocities(target,inputVelocity);
  return 0;
}

int LuaInterpreter_addVectors(lua_State *L)
{
  RVO::Vector3 firstVector = luaU_check<RVO::Vector3>(L,2);
  RVO::Vector3 secondVector = luaU_check<RVO::Vector3>(L,3);

  RVO::Vector3 result = Flock::m_lua->addVectors(firstVector,secondVector);

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_subVectors(lua_State *L)
{
  RVO::Vector3 firstVector = luaU_check<RVO::Vector3>(L,2);
  RVO::Vector3 secondVector = luaU_check<RVO::Vector3>(L,3);

  RVO::Vector3 result = Flock::m_lua->subVectors(firstVector,secondVector);

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_multiplyVectors(lua_State *L)
{
  RVO::Vector3 firstVector = luaU_check<RVO::Vector3>(L,2);
  float value = luaL_checknumber(L,3);

  RVO::Vector3 result = Flock::m_lua->multiplyVectors(firstVector,value);

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_divideVectors(lua_State *L)
{
  RVO::Vector3 firstVector = luaU_check<RVO::Vector3>(L,2);
  float secondVector = luaL_checknumber(L,3);

  RVO::Vector3 result = Flock::m_lua->divideVectors(firstVector,secondVector);

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_compareVectors(lua_State *L)
{
  RVO::Vector3 firstVector = luaU_check<RVO::Vector3>(L,2);
  RVO::Vector3 secondVector = luaU_check<RVO::Vector3>(L,3);

  Flock::m_lua->compareVectors(firstVector,secondVector);
  return 0;
}


int LuaInterpreter_getAgent(lua_State *L)
{
  lua_pushnumber(L, Flock::m_lua->getAgent());
  return 1;
}

int LuaInterpreter_setAgent(lua_State *L)
{
  int number = luaL_checkinteger(L,2);
  Flock::m_lua->setAgent(number);
  return 0;
}

int LuaInterpreter_setAgentMaxSpeed(lua_State *L)
{
  int agentNum = luaL_checkinteger(L,2);
  float newSpeed = luaL_checknumber(L,3);

  Flock::m_lua->setAgentMaxSpeed(agentNum,newSpeed);
  return 0;
}

int LuaInterpreter_retrieveAgentMaxSpeed(lua_State *L)
{
  int agentNum = luaL_checknumber(L,2);

  lua_pushnumber(L, Flock::m_lua->retrieveAgentMaxSpeed(agentNum));
  return 1;
}

int LuaInterpreter_retrieveCohesion(lua_State *L)
{
  int agentNum = luaL_checknumber(L,2);

  lua_newtable(L);
  luaU_push(L, Flock::m_lua->retrieveCohesion(agentNum));
  return 1;
}

int LuaInterpreter_getAlignment(lua_State *L)
{
  int agentNum = luaL_checknumber(L,2);

  lua_newtable(L);
  luaU_push(L, Flock::m_lua->getAlignment(agentNum));
  return 1;
}

int LuaInterpreter_setPredators(lua_State *L)
{
  // Minus 1 to correct index
  int predatorNum = (luaL_checknumber(L,2));
  RVO::Vector3 predator = luaU_check<RVO::Vector3>(L,3);

  Flock::m_lua->setPredators(predatorNum, predator);
  return 0;
}

int LuaInterpreter_getPredators(lua_State *L)
{
  lua_pushinteger(L, Flock::m_lua->m_predators.size());
  return 1;
}

//static int LuaInterpreter_ReturnVelocity(lua_State* L)
//{
//    LuaInterpreter* interpreter = luaW_check<LuaInterpreter>(L, 1);
//    Flock::m_lua->m_velocity = interpreter->m_velocity;
//    return 0;
//}

static int LuaInterpreter_printMe(lua_State* L)
{
    std::cout
        << "velocity={x=" << Flock::m_lua->m_velocity.x()
        << ",y=" << Flock::m_lua->m_velocity.y()
        << ",z=" << Flock::m_lua->m_velocity.z()
         << "}"  << std::endl;
    std::cout
        << "position={x=" << Flock::m_lua->m_position.x()
        << ",y=" << Flock::m_lua->m_position.y()
        << ",z=" << Flock::m_lua->m_position.z()
         << "}"  << std::endl;
    std::cout
        << "goal={x=" << Flock::m_lua->m_goal.x()
        << ",y=" << Flock::m_lua->m_goal.y()
        << ",z=" << Flock::m_lua->m_goal.z()
         << "}"  << std::endl;
    std::cout
        << "center={x=" << Flock::m_lua->m_center.x()
        << ",y=" << Flock::m_lua->m_center.y()
        << ",z=" << Flock::m_lua->m_center.z()
         << "}"  << std::endl;
    std::cout
        << "total agents={x=" << Flock::m_lua->m_sim->getNumAgents()
         << "}"  << std::endl;
    return 0;
}

static luaL_reg LuaInterpreter_metatable[] =
{

  { "getVelocity", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_velocity> },
  { "setVelocity", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_velocity> },
  { "velocity", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_velocity> },

  { "getPosition", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_position> },
  { "setPosition", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_position> },
  { "position", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_position> },

  { "getGoal", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_goal> },
  { "setGoal", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_goal> },
  { "coal", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_goal> },

  { "getCenter", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_center> },
  { "setCenter", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_center> },
  { "center", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_center> },

//  { "getPredatorPosition", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_predator> },
//  { "setPredatorPosition", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_predator> },
//  { "predatorPosition", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_predator> },

  { "retrieveCohesion", LuaInterpreter_retrieveCohesion },
  { "getCohesion", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_cohesion> },
  { "setCohesion", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_cohesion> },
  { "cohesion", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_cohesion> },

  { "getAlignment", LuaInterpreter_getAlignment },

  { "getPredatorAngle", luaU_get<LuaInterpreter, float, &LuaInterpreter::m_predatorAngle> },
  { "setPredatorAngle", luaU_set<LuaInterpreter, float, &LuaInterpreter::m_predatorAngle> },

  { "setPredators", LuaInterpreter_setPredators },
  { "getPredators", LuaInterpreter_getPredators },

  // Custom functions
  { "retrieveAgentVelocity", LuaInterpreter_retrieveAgentVelocity },
  { "retrieveAgentPosition", LuaInterpreter_retrieveAgentPosition },
  { "retrieveGoalPosition",  LuaInterpreter_retrieveGoalPosition },
  { "retrieveCenterOfSwarm",  LuaInterpreter_retrieveCenterOfSwarm },

  { "retrieveNumAgents", LuaInterpreter_retrieveNumAgents },
  { "retrieveGoalVector",  LuaInterpreter_retrieveGoalVector },
  { "retrieveCenterVector",  LuaInterpreter_retrieveCenterVector },
  { "retrieveAbsoluteValue",  LuaInterpreter_retrieveAbsoluteValue },
  { "retrievePowerOf", LuaInterpreter_retrievePowerOf },

  { "setSingleAgentVelocity", LuaInterpreter_setSingleAgentVelocity },
  { "setNeighborAgentVelocity", LuaInterpreter_setNeighborAgentVelocity },
  { "setAllAgentVelocities", LuaInterpreter_setAllAgentVelocities },

  { "addVectors", LuaInterpreter_addVectors },
  { "subVectors", LuaInterpreter_subVectors },
  { "multiplyVectors", LuaInterpreter_multiplyVectors },
  { "divideVectors", LuaInterpreter_divideVectors },
  { "compareVectors", LuaInterpreter_compareVectors },

  { "printMe", LuaInterpreter_printMe },

  { "getAgent", LuaInterpreter_getAgent },
  { "setAgent", LuaInterpreter_setAgent },

  { "setAgentMaxSpeed", LuaInterpreter_setAgentMaxSpeed },
  { "retrieveAgentMaxSpeed", LuaInterpreter_retrieveAgentMaxSpeed },
  //{ "setAgent", luaU_set<LuaInterpreter, int, &LuaInterpreter::m_agent> },
  //{ "Agent", luaU_getset<LuaInterpreter, int, &LuaInterpreter::m_agent> },


  {NULL, NULL}
};

int luaopen_LuaInterpreter(lua_State* L)
{
    luaW_register<LuaInterpreter>(L, "LuaInterpreter", NULL, LuaInterpreter_metatable);//, Flock::m_lua->L);
    return 1;
}
