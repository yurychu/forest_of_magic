project(ext_libs_project)

# cmake_policy(SET CMP0074 NEW)  # package_ROOT env variable to find

# lua add lib target
include(lua/definitions.cmake)
if (NOT ${lua_FOUND})
    message(FATAL_ERROR "You need set lua library in lua directory with custom cmake")
else()
    set(TO_ADD_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lua/${lua_LIBRARY}")
    message(STATUS "TO_ADD_LIB DEB: ${TO_ADD_LIB}")
    message(STATUS "Lua found!")
    message(STATUS "Lua library: ${lua_LIBRARY}")
    message(STATUS "Lua include directory: ${lua_INCLUDE_DIRECTORY}")
    add_library(
            ext_lua_lib
            STATIC
            IMPORTED
    )

    set_target_properties(
            ext_lua_lib
            PROPERTIES
            IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lua/${lua_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/lua/{lua_INCLUDE_DIRECTORY}"
    )

endif()

add_library(my_super_lib
        STATIC
        my_lib/my_lib.cpp
        )

target_include_directories(my_super_lib
        PUBLIC
        my_lib
        )

set_target_properties(
        my_super_lib
        PROPERTIES
        HI_THERE "ABC.hi"
)
