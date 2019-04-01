cmake_minimum_required(VERSION 3.5)
message("inf: CMAKE_VERSION = ${CMAKE_VERSION}")

project(forest_of_magic)

# add_compile_options(-Wall -Wno-unused-function)

add_subdirectory(engine)
add_subdirectory(game)
# add_subdirectory(editor)
