#ifndef FOM_PLAYER_HPP
#define FOM_PLAYER_HPP

#include <iostream>

#include "GameOjbect.hpp"

namespace fom {

	class Player : public fom::GameObject
	{
	protected:
		int itsX;
		int itsY;

	public:
		Player() = default;
		virtual ~Player() = default;

		void load(int x, int y, int width, int height, const std::string & texture_id);
		void draw(SDL_Renderer * renderer);
		void update();
		void clean();

	};

}



#endif  // !FOM_PLAYER_HPP