#include <iostream>

#include "../../include/fom/Game.hpp"


void
fom::cout_message(const std::string & msg)
{
	std::cout << msg << std::endl;
}


fom::Game::Game()
	:
	itsRunning(false),
	itsWindow(nullptr),
	itsRenderer(nullptr)
{
}

fom::Game::~Game()
{
}

std::shared_ptr<fom::Game>
fom::Game::create()
{
	return std::make_shared<fom::Game>();
}

bool
fom::Game::init(const std::string & title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	bool result = false;
	int flags = 0;

	if (fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		itsWindow = SDL_CreateWindow(
			title.c_str(),
			xpos, ypos,
			width, height,			flags		);
		if (itsWindow){
			itsRenderer = SDL_CreateRenderer(itsWindow, -1, 0);

			if (itsRenderer){
				SDL_SetRenderDrawColor(itsRenderer, 0, 255, 0, 255);
				result = true;
			}
			else {
				fom::cout_message("renderer init fail");
			}
		}
		else {
			fom::cout_message("window init fail");
		}
	}
	else {
		fom::cout_message("SDL init fail");
	}

	itsRunning = result;

	return result;
}

void
fom::Game::render()
{
	SDL_RenderClear(itsRenderer);
	SDL_RenderPresent(itsRenderer);
}

void
fom::Game::update()
{
}

void
fom::Game::handle_events()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)){

		switch (event.type) {
			case SDL_QUIT : {
				itsRunning = false;
			} break;
			
			default : {

			} break;
			
		}
	}
}

void
fom::Game::clean()
{
	SDL_DestroyRenderer(itsRenderer);
	SDL_DestroyWindow(itsWindow);
	SDL_Quit();
}
