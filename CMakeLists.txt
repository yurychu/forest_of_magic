cmake_minimum_required(VERSION 3.5)
project(forest_of_magic)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall)


set (ENGINE_DIR engine)
set (GAME_DIR game)

set (INCLUDE_FILES
        ${ENGINE_DIR}/include/Project.hpp
        ${ENGINE_DIR}/include/Window.hpp
        ${ENGINE_DIR}/include/Renderer.hpp
        ${ENGINE_DIR}/include/Engine.hpp
        ${ENGINE_DIR}/include/Exceptions.hpp
        ${ENGINE_DIR}/include/GameManager.hpp
        )

set(SOURCE_FILES
        ${GAME_DIR}/game.cpp

        ${ENGINE_DIR}/src/Window.cpp
        ${ENGINE_DIR}/src/Renderer.cpp
        ${ENGINE_DIR}/src/Engine.cpp
        ${ENGINE_DIR}/src/Exceptions.cpp
        ${ENGINE_DIR}/src/GameManager.cpp

        ${INCLUDE_FILES}
        )

include_directories(
        ${ENGINE_DIR}/include
)

add_executable(
        ${CMAKE_PROJECT_NAME}
        ${SOURCE_FILES}
)

target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        pthread
        SDL2
        SDL2_image
        SDL2_ttf
        SDL2_mixer
)