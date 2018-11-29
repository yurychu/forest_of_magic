
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

set_property(TARGET game APPEND PROPERTY CXX_STANDARD 14)

target_link_libraries(
        game
        PUBLIC
        fom_engine
)
