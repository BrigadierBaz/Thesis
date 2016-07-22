#include "LuaInterpreter.h"

LuaInterpreter::LuaInterpreter()
{
}

void LuaInterpreter::getAgentVelocityLua(size_t agentNum)
{
    //kaguya::State m_luaTest;
    lua_State *L = luaL_newstate();

    // Make standard libraries available in the Lua object
    luaL_openlibs(L);

    // Load the program; this supports both source code and bytecode files.
    luaL_loadfile(L, "table.lua");

    double x = m_sim->getAgentVelocity(agentNum).x();
    double y = m_sim->getAgentVelocity(agentNum).y();
    double z = m_sim->getAgentVelocity(agentNum).z();

//    std::vector<double> vect = { x,y,z };
//    m_luaTest["vect"] = vect;
//    m_luaTest("print(type(vect))");// table
//    m_luaTest("for i,v in ipairs(vect) do print(v) end");

      /* push functions and arguments */
      lua_getglobal(L, "setVector");  /* function to be called */
      lua_pushnumber(L, x);   /* push 1st argument */
      lua_pushnumber(L, y);   /* push 2nd argument */
      lua_pushnumber(L, z);

      /* do the call (2 arguments, 1 result) */
//      if (lua_pcall(m_luaTest, 3, 1, 0) != 0)
//        error(m_luaTest, "error running function `f': %s",
//                 lua_tostring(m_luaTest, -1));

      /* retrieve result */
//      if (!lua_isnumber(m_luaTest, -1))
//        error(m_luaTest, "function `f' must return a number");
      double vx  = lua_tonumber(L, -3);
      double vy  = lua_tonumber(L, -2);
      double vz  = lua_tonumber(L, -1);

//      lua_pop(m_luaTest, 1);  /* pop returned value */
//      lua_pop(m_luaTest, 2);
//      lua_pop(m_luaTest, 3);

      lua_settop(L, 0);

}

