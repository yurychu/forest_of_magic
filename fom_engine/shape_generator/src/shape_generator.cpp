#include <shape_generator.hpp>

#include <iostream>

#include <lua.hpp>


std::string
fom::get_shape_generator_version()
{
	auto lua_st = luaL_newstate();
	auto l_vs = lua_version(lua_st);
	std::cout << "Lua vers: " << l_vs << std::endl;

	return { SHAPE_GENERATOR_VERSION };
}
