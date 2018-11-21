
include_directories(
        ${PROJECT_SOURCE_DIR}
)


set (INC_GAME
        Game.hpp

)

set (SRC_GAME
        app.cpp
        )


add_executable(
        game
        ${INC_GAME}
        ${SRC_GAME}
)


target_link_libraries(
        game
        LINK_PUBLIC
        fom_engine
)