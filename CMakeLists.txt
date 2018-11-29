cmake_minimum_required(VERSION 3.5)
project(forest_of_magic)

add_compile_options(-Wall -Wno-unused-function)


IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DSOME_DEFINITION)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)


add_subdirectory(engine)
add_subdirectory(game)
add_subdirectory(editor)
