#ifndef LUACUSTOMTYPES
#define LUACUSTOMTYPES

#include <string>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

#include "lua.h"
#include "luawrapper.hpp"
#include "luawrapperutil.hpp"

#include "RVO.h"

//----------------------------------------------------------------------------------------------------------------------
/// @file LuaCustomTypes.h
/// @brief this class inherits from the Qt OpenGLWindow and allows us to use NGL to draw OpenGL
/// @author Luke Bazalgette
/// Modified from :-
/// Alex Ames (April 5 2013). LuaWrapperExample/example2/ [online].
/// [Accessed 2016]. Available from: <https://bitbucket.org/alexames/luawrapperexample/src/f6958844b60f91ed90d039eabe807522a1b13ba8/example2/LuaCustomTypes.hpp?at=default&fileviewer=file-view-default>.
//----------------------------------------------------------------------------------------------------------------------

// LuaWrapper knows about primitive types like ints and floats, but it doesn't
// know about things like std::strings or other more complicated types.
// Sometimes, rather than register the type with LuaWrapper, it's easier to
// be able to convert it to and from Lua's primitive types, like strings or
// tables.
//
// To do this, you must write luaU_check, luaU_to and luaU_push functions for
// your type. You don't always need all three, it depends on if you're pushing
// objects to Lua, getting objects from Lua, or both.

// This example uses std::string, but if you have other custom string types it
// should be easy to write versions of those functions too

template<>
struct luaU_Impl<std::string>
{
    static std::string luaU_check(lua_State* L, int index)
    {
        return std::string(luaL_checkstring(L, index));
    }

    static std::string luaU_to(lua_State* L, int index )
    {
        return std::string(lua_tostring(L, index));
    }

    static void luaU_push (lua_State* L, const std::string& val)
    {
        lua_pushstring(L, val.c_str());
    }
};

// RVO Vector3 type is not supported by default,
// to simplify code I have created a series of get/set templates
template<>
struct luaU_Impl<RVO::Vector3>
{
    static RVO::Vector3 luaU_check(lua_State* L, int index)
    {
        return RVO::Vector3(
            luaU_getfield<float>(L, index, "x"),
            luaU_getfield<float>(L, index, "y"),
            luaU_getfield<float>(L, index, "z"));
    }

    static RVO::Vector3 luaU_to(lua_State* L, int index )
    {
        return RVO::Vector3(
            luaU_getfield<float>(L, index, "x"),
            luaU_getfield<float>(L, index, "y"),
            luaU_getfield<float>(L, index, "z"));
    }

    static void luaU_push (lua_State* L, const RVO::Vector3& val)
    {
        lua_newtable(L);
        luaU_setfield<float>(L, -1, "z", val.z());
        luaU_setfield<float>(L, -1, "y", val.y());
        luaU_setfield<float>(L, -1, "x", val.x());
    }
};


#endif // LUACUSTOMTYPES

