cmake_minimum_required(VERSION 3.17)

project(fom_project C)
set(CMAKE_C_STANDARD 11)

add_library(
        fom
        STATIC
        include/fom/fom.h
        src/fom/fom.c
)

target_include_directories(
        fom
        PUBLIC
        include
)
