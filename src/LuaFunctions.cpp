#include <iostream>
#include <string>

#include "lua.hpp"

#include "luawrapper.hpp"
#include "luawrapperutil.hpp"

#include "LuaCustomTypes.hpp"
#include "Flock.h"


// Define functions to be used in lua in this class.
// Ensure to follow the same format.


/* Retrieve Agent information */
int LuaInterpreter_getAgentVelocity(lua_State *L)
{
    int agentNum = luaL_checkinteger(L,2);

    RVO::Vector3 result = Flock::m_lua->getAgentVelocity(agentNum);
    lua_newtable(L);
    luaU_push(L, result);

    return 1;
}

int LuaInterpreter_getAgentPosition(lua_State *L)
{
    int agentNum = luaL_checkinteger(L,2);

    RVO::Vector3 result = Flock::m_lua->getAgentPosition(agentNum);
    lua_newtable(L);
    luaU_push(L, result);

    return 1;
}


/* Get data on agent Neighbor */
int LuaInterpreter_getAgentNeighborNum(lua_State *L)
{
  // Get values from the lua stack. You must retrieve them in the order you pushed them.
  int agentNum = luaL_checkinteger(L,2);
  int neighborCount = luaL_checkinteger(L,3);

  lua_pushnumber(L, Flock::m_lua->getAgentNeighborNum(agentNum,neighborCount));
  return 1;
}

int LuaInterpreter_getAgentNeighborCount(lua_State *L)
{
  int agentNum = luaL_checkinteger(L,2);

  lua_pushnumber(L, Flock::m_lua->getAgentNeighborCount(agentNum));
  return 1;
}




/* Constraints and useful values */
int LuaInterpreter_getCenterOfSwarm(lua_State *L)
{
  RVO::Vector3 result = Flock::m_lua->getCenterOfSwarm();

  lua_newtable(L);
  luaU_push(L, result);

  return 1;
}

int LuaInterpreter_getNumAgents(lua_State *L)
{
  // Minus 1 as index starts from 0.
  lua_pushnumber(L, Flock::m_lua->m_sim->getNumAgents() - 1);
  return 1;
}




/* Set velocities of given agents */

int LuaInterpreter_setSingleAgentVelocity(lua_State *L)
{
  int agentNum = luaL_checkinteger(L,2);
  // Vector3 check defined in luawrapperutil
  RVO::Vector3 target = luaU_check<RVO::Vector3>(L,3);

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




/* Get/Set the overall speed of a given agent */

int LuaInterpreter_getAgentMaxSpeed(lua_State *L)
{
  int agentNum = luaL_checknumber(L,2);

  lua_pushnumber(L, Flock::m_lua->getAgentMaxSpeed(agentNum));
  return 1;
}

int LuaInterpreter_setAgentMaxSpeed(lua_State *L)
{
  int agentNum = luaL_checkinteger(L,2);
  float newSpeed = luaL_checknumber(L,3);

  Flock::m_lua->setAgentMaxSpeed(agentNum,newSpeed);
  return 0;
}





/* Preset formations */

int LuaInterpreter_getCohesion(lua_State *L)
{
  int agentNum = luaL_checknumber(L,2);

  lua_newtable(L);
  luaU_push(L, Flock::m_lua->getCohesion(agentNum));
  return 1;
}

int LuaInterpreter_getAlignment(lua_State *L)
{
  int agentNum = luaL_checknumber(L,2);

  lua_newtable(L);
  luaU_push(L, Flock::m_lua->getAlignment(agentNum));
  return 1;
}



/* Retrieve predator data */
int LuaInterpreter_getPredators(lua_State *L)
{
  lua_pushinteger(L, Flock::m_lua->m_predators.size());
  return 1;
}

int LuaInterpreter_setPredators(lua_State *L)
{
  RVO::Vector3 predator = luaU_check<RVO::Vector3>(L,2);

  Flock::m_lua->setPredators(predator);
  return 0;
}





/* Vector Operations */
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

int LuaInterpreter_getAbsoluteValue(lua_State *L)
{
  RVO::Vector3 input  = luaU_check<RVO::Vector3>(L,2);
  lua_pushnumber(L, Flock::m_lua->getAbsoluteValue(input));
  return 1;
}

int LuaInterpreter_getPowerOf(lua_State *L)
{
  float input = luaL_checknumber(L,2);
  float power = luaL_checknumber(L,3);

  lua_pushnumber(L, Flock::m_lua->getPowerOf(input, power));
  return 1;
}





/* Others */
static int LuaInterpreter_printMe(lua_State* L)
{
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




// Lua functions are defined in here
// write "interpreter:" and the string to the left with brackets and any arguments.
static luaL_reg LuaInterpreter_metatable[] =
{ 
  // Instructions in this format are simple get set functions
  { "getAgent", luaU_get<LuaInterpreter, int, &LuaInterpreter::m_agent> },
  { "setAgent", luaU_set<LuaInterpreter, int, &LuaInterpreter::m_agent> },

  { "getPredatorAngle", luaU_get<LuaInterpreter, float, &LuaInterpreter::m_predatorAngle> },
  { "setPredatorAngle", luaU_set<LuaInterpreter, float, &LuaInterpreter::m_predatorAngle> },

  { "getGoal", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_goal> },
  { "setGoal", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_goal> },
  { "goal", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_goal> },

  { "getCenter", luaU_get<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_center> },
  { "setCenter", luaU_set<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_center> },
  { "center", luaU_getset<LuaInterpreter, RVO::Vector3, &LuaInterpreter::m_center> },


  // Functions can be found above, require complicated procedures

  { "getAgentNeighborNum", LuaInterpreter_getAgentNeighborNum },
  { "getAgentNeighborCount", LuaInterpreter_getAgentNeighborCount },

  { "getCohesion", LuaInterpreter_getCohesion },
  { "getAlignment", LuaInterpreter_getAlignment },

  { "setPredators", LuaInterpreter_setPredators },
  { "getPredators", LuaInterpreter_getPredators },

  // Custom functions
  { "getAgentVelocity", LuaInterpreter_getAgentVelocity },
  { "getAgentPosition", LuaInterpreter_getAgentPosition },
  { "getCenterOfSwarm",  LuaInterpreter_getCenterOfSwarm },

  { "getNumAgents", LuaInterpreter_getNumAgents },
  { "getAbsoluteValue",  LuaInterpreter_getAbsoluteValue },
  { "getPowerOf", LuaInterpreter_getPowerOf },

  { "setSingleAgentVelocity", LuaInterpreter_setSingleAgentVelocity },
  { "setNeighborAgentVelocity", LuaInterpreter_setNeighborAgentVelocity },
  { "setAllAgentVelocities", LuaInterpreter_setAllAgentVelocities },

  { "addVectors", LuaInterpreter_addVectors },
  { "subVectors", LuaInterpreter_subVectors },
  { "multiplyVectors", LuaInterpreter_multiplyVectors },
  { "divideVectors", LuaInterpreter_divideVectors },
  { "compareVectors", LuaInterpreter_compareVectors },

  { "printMe", LuaInterpreter_printMe },

  { "setAgentMaxSpeed", LuaInterpreter_setAgentMaxSpeed },
  { "getAgentMaxSpeed", LuaInterpreter_getAgentMaxSpeed },


  {NULL, NULL}
};

int luaopen_LuaInterpreter(lua_State* L)
{
    // Register the metatable in Lua
    luaW_register<LuaInterpreter>(L, "LuaInterpreter", NULL, LuaInterpreter_metatable);
    return 1;
}
