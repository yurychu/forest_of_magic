#include <scripter.hpp>

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
