#ifndef FOM_GAME_HPP
#define FOM_GAME_HPP

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include<SDL2/SDL.h>
//#include<SDL2/SDL_image.h>

#include "GameObject.hpp"
#include "Player.hpp"


namespace fom {

	void cout_message(const std::string & msg);


	enum class GameStateType
	{
		PROMO = 1,
		START_MENU = 2,
		GAMEPLAY = 3,
		PAUSE = 4
	};

	class GameState
	{
	private:
		std::vector <fom::GameObject> itsObjects;

	public:
		GameState() = default;
		~GameState() = default;

	};


	class Game
	{
	private:
		bool itsRunning;

		SDL_Window * itsWindow;
		SDL_Renderer * itsRenderer;

		fom::GameStateType itsCurrentState;
		std::map <
			fom::GameStateType,
			std::shared_ptr <fom::GameState>
		> itsGameStates;

	public:
		Game();
		~Game();

		static std::shared_ptr<fom::Game>
		create();

		bool init(
			const std::string & title,
			int width, int height,
			bool fullscreen
		);

		void render();
		void update();
		void handle_events();
		void clean();

		bool running() const
		{
			return itsRunning;
		}

	};

}


#endif  // !FOM_GAME_HPP



