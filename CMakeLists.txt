cmake_minimum_required(VERSION 3.5)
project(forest_of_magic)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wno-unused-function)

set(CMAKE_BUILD_TYPE Debug)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DSOME_DEFINITION)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)


add_subdirectory(engine)
add_subdirectory(game)

