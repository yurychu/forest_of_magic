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
	itsRenderer(nullptr),
	itsTexture(nullptr)
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
fom::Game::init(const std::string & title, int width, int height, bool fullscreen)
{
	auto result = false;
	auto window_flags = SDL_WINDOW_SHOWN;

	if (fullscreen){
		window_flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		itsWindow = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height,
			window_flags
		);

		if (itsWindow){
			const auto renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
			const int driver = -1;
			itsRenderer = SDL_CreateRenderer(itsWindow, driver, renderer_flags);

			if (itsRenderer){
				SDL_SetRenderDrawColor(itsRenderer, 0, 255, 255, 255);
				result = true;
			}
			else {
				const std::string err_msg = SDL_GetError();
				fom::cout_message("renderer init fail: " + err_msg);	
			}
		}
		else {
			const std::string err_msg = SDL_GetError();
			fom::cout_message("window init fail: " + err_msg);
		}
	}
	else {
		const std::string err_msg = SDL_GetError();
		fom::cout_message("SDL init fail: " + err_msg);
	}

	itsRunning = result;

	// load textures
	auto temp_surface = SDL_LoadBMP("assets/files/walking_man.bmp");
	if (temp_surface) {
		itsTexture = SDL_CreateTextureFromSurface(itsRenderer, temp_surface);
		SDL_FreeSurface(temp_surface);

		if (SDL_QueryTexture(itsTexture, 0, 0, &itsSourceRectangle.w, &itsSourceRectangle.h) == 0) {
			
			
			itsSourceRectangle.w = std::floor(itsSourceRectangle.w / 8);

			itsDestinationRectangle.x = itsSourceRectangle.x = 0;
			itsDestinationRectangle.y = itsSourceRectangle.y = 0;
			itsDestinationRectangle.w = itsSourceRectangle.w;
			itsDestinationRectangle.h = itsSourceRectangle.h;
		}

	}
	else {
		const std::string err_msg = SDL_GetError();
		fom::cout_message("SDL fail load BMP: " + err_msg);
	}



	return result;
}

void
fom::Game::render()
{
	SDL_RenderClear(itsRenderer);
	SDL_RenderCopy(itsRenderer, itsTexture, &itsSourceRectangle, &itsDestinationRectangle);
	SDL_RenderPresent(itsRenderer);
}

void
fom::Game::update()
{
	itsSourceRectangle.x = itsSourceRectangle.w * int(((SDL_GetTicks() / 150) % 8));
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
