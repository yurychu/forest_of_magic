#include <iostream>
#include <string>

#include "windows_functions.h"

#include "../engine/include/fom/Game.hpp"


int main(int argc, char * argv [])
{
	// helpers functional
	make_console();
	
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
