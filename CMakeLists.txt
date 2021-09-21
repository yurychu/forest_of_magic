cmake_minimum_required(VERSION 3.17)

project(forest_of_magic_proj C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(Lua_ROOT CACHE PATH "Specify lua installed location")
find_package(Lua 5.3 REQUIRED)
# Lua build: local MinGW environment


set(FOM_LUA_SCRIPTS_DIR_NAME bin_scripts)
add_library(
        lua_code_scripts
        INTERFACE
        ${FOM_LUA_SCRIPTS_DIR_NAME}
)
add_custom_command(
        OUTPUT
        ${FOM_LUA_SCRIPTS_DIR_NAME}
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/lua_code/scripts
        ${CMAKE_CURRENT_BINARY_DIR}/${FOM_LUA_SCRIPTS_DIR_NAME}
        COMMENT "Copy scripts to ${FOM_LUA_SCRIPTS_DIR_NAME}"
        DEPENDS  # add core lua script files here!
        lua_code/scripts/script.lua
        lua_code/scripts/mymodule.lua
)

# executable
add_executable(
        loadmodule
        lua_code/loadmodule.c
)
target_include_directories(
        loadmodule
        PUBLIC
        ${LUA_INCLUDE_DIR}
)
target_link_libraries(
        loadmodule
        PUBLIC
        ${LUA_LIBRARIES}
        PUBLIC
        lua_code_scripts
)
target_compile_definitions(
        loadmodule
        PRIVATE
        FOM_LUA_SCRIPTS_DIR_NAME="${FOM_LUA_SCRIPTS_DIR_NAME}/"
)

#include(FOMGetLua)
#fom_get_lua()

#add_subdirectory(fom)
#add_subdirectory(game)
