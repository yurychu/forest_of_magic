cmake_minimum_required(VERSION 3.5)
project(forest_of_magic)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wno-unused-function)

set(CMAKE_BUILD_TYPE Debug)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DSOME_DEFINITION)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

set(INSTALLED_LIBS_DIR
        /home/yurychu/Developing/installed_libs
        )

set(ENGINE_DIR engine)
set(SOURCE_ENGINE
        engine/Game.cpp
        engine/Game.hpp
        engine/GameObject.cpp
        engine/GameObject.hpp
        engine/Player.cpp
        engine/Player.hpp
        engine/TextureManager.cpp
        engine/TextureManager.hpp

        )

set(GAME_APP_NAME game_app)
set(GAME_DIR game)
set(SOURCE_FILES
        ${GAME_DIR}/app.cpp

        ${SOURCE_ENGINE}

        ${INCLUDE_FILES}
        )

# SDL SETTINGS
set(SDL_HOME
        ${INSTALLED_LIBS_DIR}/SDL208
        )

# COMMON SETTINGS
include_directories(
        ${SDL_HOME}/include

        ${ENGINE_DIR}
)

link_directories(
        ${SDL_HOME}/lib
)

add_executable(
        ${GAME_APP_NAME}
        ${SOURCE_FILES}
)

set(SDL_LIB_NAMES
        SDL2
        SDL2_image
        )

target_link_libraries(
        ${GAME_APP_NAME}

        pthread

        ${SDL_LIB_NAMES}
)
