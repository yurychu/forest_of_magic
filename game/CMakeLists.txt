project(game_project)

add_executable(
        game
		game.cpp
)

set_property(TARGET game APPEND PROPERTY CXX_STANDARD 14)

target_link_libraries(
        game

        PRIVATE
        fom_engine
)
