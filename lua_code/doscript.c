//
// Created by yurychu on 08.09.2021.
//


#include <lauxlib.h>  // Auxiliary functions for building Lua libraries
#include <lua.h>  // Lua - A Scripting Language
#include <lualib.h>  // Lua standard libraries


int main(int argc, char* argv[])
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "bin_scripts/script.lua");

    return 0;
}
