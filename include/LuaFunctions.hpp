#ifndef LUAFUNCTIONS
#define LUAFUNCTIONS


//----------------------------------------------------------------------------------------------------------------------
/// @file LuaFunctions.h
/// @brief This header file opens a Lua state for the interpreter.
/// @author Luke Bazalgette
/// Modified from :-
/// Alex Ames (April 5 2013). LuaWrapperExample/example2/ [online].
/// [Accessed 2016]. Available from: <https://bitbucket.org/alexames/luawrapperexample/src/f6958844b60f91ed90d039eabe807522a1b13ba8/example2/LuaExample.hpp?at=default&fileviewer=file-view-default>.
/// @class LuaFunctions
/// @date 07/04/13
/// @brief this class acts as a bridge between Lua and the Cpp environment.
/// Lua friendly functions point directly to non-static functions.
/// Lua functions are assigned descriptive strings inside the Metatable.
//----------------------------------------------------------------------------------------------------------------------


struct lua_State;

int luaopen_LuaInterpreter(lua_State*);

#endif // LUAFUNCTIONS

