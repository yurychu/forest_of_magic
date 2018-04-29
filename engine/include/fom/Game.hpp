#ifndef FOM_GAME_HPP
#define FOM_GAME_HPP

#include <memory>
#include <iostream>
#include <string>

#include<SDL.h>

namespace fom {

	void cout_message(const std::string & msg);

	class Game
	{
	private:
		bool itsRunning;

		SDL_Window * itsWindow;
		SDL_Renderer * itsRenderer;
	public:
		Game();
		~Game();

		static std::shared_ptr<fom::Game> create();

		bool init(
			const std::string & title,
			int xpos, int ypos,
			int width, int height,
			bool fullscreen
		);

		void render();
		void update();
		void handle_events();
		void clean();

		bool running()
		{
			return itsRunning;
		}

	};

}


#endif // !FOM_GAME_HPP


