
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

target_link_libraries(
        game
        PUBLIC
        fom_engine
)
