//----------------------------------------------------------------------------------------------------------------------
/// @file lua.hpp
/// @brief Lua header files for C++. <<extern "C">> is not supplied automatically because Lua also compiles as C++
/// @author Luke Bazalgette
/// Modified from :- http://download.redis.io/redis-stable/deps/lua/etc/lua.hpp
/// @version 1.0
/// @date 8/8/16
//----------------------------------------------------------------------------------------------------------------------

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
