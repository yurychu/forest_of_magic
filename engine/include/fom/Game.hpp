#ifndef FOM_GAME_HPP
#define FOM_GAME_HPP

#include <memory>
#include <iostream>
#include <string>

#include<SDL.h>
#include<SDL_image.h>


namespace fom {

	void cout_message(const std::string & msg);

	class Game
	{
	private:
		bool itsRunning;

		SDL_Window * itsWindow;
		SDL_Renderer * itsRenderer;

		int itsCurrentFrame;

	public:
		Game();
		~Game();

		static std::shared_ptr<fom::Game> create();

		bool init(
			const std::string & title,
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


#endif  // !FOM_GAME_HPP



