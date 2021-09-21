//
// Created by yurychu on 08.09.2021.
//


#include <lauxlib.h>  // Auxiliary functions for building Lua libraries
#include <lua.h>  // Lua - A Scripting Language
#include <lualib.h>  // Lua standard libraries

#ifdef FOM_LUA_SCRIPTS_DIR_NAME
#define FOM_SCRIPT_DIR FOM_LUA_SCRIPTS_DIR_NAME
#elif
#define FOM_SCRIPT_DIR ""
#endif
// todo(y.chu): move to header

int main(int argc, char* argv[])
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, FOM_SCRIPT_DIR"mymodule.lua");
    lua_setglobal(L, "mymodule");  // set returned from dofile value as global variable mymodule
    lua_settop(L, 0);  // change stack to contain 0 values, in this case = emptying the stack

    return 0;
}
