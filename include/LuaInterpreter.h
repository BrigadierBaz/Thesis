#ifndef LUA_INTERPRETER_H
#define LUA_INTERPRETER_H

#include <memory>
#include "RVO.h"
//#include "Flock.h"

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

class LuaInterpreter
{
  public:

      LuaInterpreter();

      void getAgentVelocityLua(size_t agentNum);

      //kaguya::State m_luaTest;
      //lua_State *m_luaTest = luaL_newstate();

      std::unique_ptr<RVO::RVOSimulator> m_sim;
};


#endif // LUA_INTERPRETER_H

