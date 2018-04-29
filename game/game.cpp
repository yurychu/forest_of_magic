#include <iostream>
#include <string>

#include<SDL.h>

#include "windows_functions.h"


void cout_message(const std::string & msg)
{
	std::cout << msg << std::endl;
}

int main(int argc, char * argv [])
{
	make_console();

	SDL_Window * window = nullptr;
	SDL_Renderer * renderer = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		window = SDL_CreateWindow(
			"Setting SDL",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN
		);

		if (window){
			cout_message("Window created");
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer){
				cout_message("Renderer created");
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
				SDL_Delay(50000);
				SDL_Quit();
			}
			else {
				cout_message("Error create renderer");
				return EXIT_FAILURE;
			}
		}
		else {
			cout_message("Error create window");
			return EXIT_FAILURE;
		}
	}
	else {
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}
