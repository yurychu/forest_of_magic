#include "Player.hpp"


void fom::Player::load(int x, int y, int width, int height, const std::string & texture_id)
{
	fom::GameObject::load(x, y, width, height, texture_id);
}

void fom::Player::draw(SDL_Renderer * renderer)
{
	fom::GameObject::draw(renderer);
}

void fom::Player::update()
{
	itsX += 1;
}

void fom::Player::clean()
{
	fom::GameObject::clean();
}
