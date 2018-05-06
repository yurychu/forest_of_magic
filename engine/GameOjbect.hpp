#ifndef FOM_GAME_OBJECT_HPP
#define FOM_GAME_OBJECT_HPP

#include <iostream>

#include <SDL.h>


namespace fom {

	class GameObject
	{
	protected:
		std::string itsTextureId;

		int itsCurrentFrame;
		int itsCurrentRow;

		int itsX;
		int itsY;

		int itsWidth;
		int itsHeight;

	public:
		GameObject() = default;
		virtual ~GameObject() = default;

		virtual void load(int x, int y, int width, int height, const std::string & texture_id);
		virtual void draw(SDL_Renderer * renderer);
		virtual void update();
		virtual void clean() { std::cout << "clean game object" << std::endl; }

	};

}



#endif  // !FOM_GAME_OBJECT_HPP