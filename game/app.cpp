#include <iostream>
#include <string>

#include <Game.hpp>


int main(int argc, char * argv [])
{
	// code here
	auto game = fom::Game::create();

	game->init("Window Name", 640, 480, false);

	while (game->running()){
		game->handle_events();
		game->update();
		game->render();
	}

	game->clean();

    return EXIT_SUCCESS;
}
