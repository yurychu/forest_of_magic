cmake_minimum_required(VERSION 3.17)

# Prevent in-source build
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR “In-source build detected!”)
endif()


project(forest_of_magic_proj LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Find packages:
# Lua
set(Lua_ROOT CACHE PATH "Specify lua installed location")
find_package(Lua 5.3 REQUIRED)
# Lua build: local MinGW (gcc) environment

# GLFW
set(glfw3_ROOT CACHE PATH "Specify glfw3 installed location")
find_package(glfw3 3.3 REQUIRED)
# glfw3 build: MinGW (gcc) environment

# Lua scripts list "custom target"
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
        DEPENDS  # add lua scripts here!
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

# use glfw
add_executable(
        graphics_exe
        graphics/graphics.c
)
target_link_libraries(
        graphics_exe
        PRIVATE
        glfw
)

#include(FOMGetLua)
#fom_get_lua()

#add_subdirectory(fom)
#add_subdirectory(game)
