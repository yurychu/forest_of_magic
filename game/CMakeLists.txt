
include_directories(
        ${PROJECT_SOURCE_DIR}
)


set (INC_GAME
        Game.hpp

)

set (SRC_GAME
        game.cpp
        )


add_executable(
        game
        ${INC_GAME}
        ${SRC_GAME}
)


link_directories(
        /home/yurych4/developing/installs/lib

)

target_link_libraries(
        game
        PUBLIC
        fom_engine

        SDL2

)
