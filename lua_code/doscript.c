//
// Created by yurychu on 08.09.2021.
//

#include <stdio.h>

#include <lauxlib.h>  // Auxiliary functions for building Lua libraries
#include <lua.h>  // Lua - A Scripting Language
#include <lualib.h>  // Lua standard libraries

#ifdef FOM_LUA_SCRIPTS_DIR_NAME
#define FOM_SCRIPT_DIR FOM_LUA_SCRIPTS_DIR_NAME
#elif
#define FOM_SCRIPT_DIR ""
#endif

int main(int argc, char* argv[])
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, FOM_SCRIPT_DIR"script.lua");

    return 0;
}
