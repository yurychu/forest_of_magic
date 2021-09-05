cmake_minimum_required(VERSION 3.17)

project(fom_project C)
set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

add_library(
        fom
        STATIC
        include/fom/fom.h
        src/fom/fom.c
)

target_include_directories(
        fom
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
