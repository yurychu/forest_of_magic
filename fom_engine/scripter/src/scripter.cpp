#include <scripter.hpp>

#include <iostream>

#include <lua.hpp>


std::string
fom::get_scripter_version()
{
    std::string result { SCRIPTER_VERSION };
    result += ", backend: ";
    result += "lua ";
    result +=  LUA_VERSION_MAJOR;
    result += ".";
    result +=  LUA_VERSION_MINOR;

    return result;
}

void
fom::run_script(const std::string & script_name)
{
    if (script_name.empty()){
        std::cout << "script_name empty" << std::endl;
    }

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, script_name.c_str());
}
