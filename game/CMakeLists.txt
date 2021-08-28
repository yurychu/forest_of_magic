project(game_project)

add_executable(
        game
		game.cpp
)

target_link_libraries(
        game
        PRIVATE
        fom
)
