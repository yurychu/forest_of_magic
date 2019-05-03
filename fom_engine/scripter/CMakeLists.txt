project(scripter_lib_project)

add_library(
		scripter_lib
        STATIC
		include/scripter/scripter.hpp
		src/scripter.cpp
)

set_property(TARGET scripter_lib APPEND PROPERTY CXX_STANDARD 14)

# may be need set env variable LUA_DIR to installed library
find_package(
		Lua 5.3 EXACT
		REQUIRED
)

target_include_directories(
		scripter_lib

        PUBLIC
        include

		PRIVATE
		include/scripter
        ${LUA_INCLUDE_DIR}
)

target_link_libraries(
		scripter_lib

		PRIVATE
		${LUA_LIBRARIES}


)