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


// These two functions let me convert the RVO::Vector3 structure into a Lua
// table holding the x, y and z values
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

//// It is possible to get multiple Vectors from an array
//template<>
//struct luaU_Impl<std::vector<RVO::Vector3>>
//{
//    static std::vector<RVO::Vector3> luaU_check(lua_State* L, int index)
//    {
//        return RVO::Vector3(
//            luaU_getfield<float>(L, index, "x"),
//            luaU_getfield<float>(L, index, "y"),
//            luaU_getfield<float>(L, index, "z"));
//    }

//    static std::vector<RVO::Vector3> luaU_to(lua_State* L, int index )
//    {
//        return RVO::Vector3(
//            luaU_getfield<float>(L, index, "x"),
//            luaU_getfield<float>(L, index, "y"),
//            luaU_getfield<float>(L, index, "z"));
//    }

//    static void luaU_push (lua_State* L, const std::vector<RVO::Vector3>& val)
//    {
//        lua_newtable(L);
//        luaU_setfield<float>(L, -1, "z", val.z());
//        luaU_setfield<float>(L, -1, "y", val.y());
//        luaU_setfield<float>(L, -1, "x", val.x());
//    }
//};

// size_t is not recognised by default to needs to be defined
//template<>
//struct luaU_Impl<size_t>
//{
//    static size_t luaU_check(lua_State* L, int index)
//    {
//        return size_t(luaL_checkinteger(L, index));
//    }

//    static size_t luaU_to(lua_State* L, int index )
//    {
//        return size_t(lua_tointeger(L, index));
//    }

//    static void luaU_push (lua_State* L, const size_t& val)
//    {
//        lua_pushinteger(L, val);
//    }
//};


#endif // LUACUSTOMTYPES

