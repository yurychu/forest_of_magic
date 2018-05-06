#include "GameOjbect.hpp"


void fom::GameObject::load(int x, int y, int width, int height, const std::string & texture_id)
{
	itsX = x;
	itsY = y;
	itsWidth = width;
	itsHeight = height;
	itsTextureId = texture_id;
	itsCurrentRow = 1;
	itsCurrentFrame = 1;
}

void fom::GameObject::draw(fom::Renderer & renderer)
{
	fom::TextureManager::instance().draw_frame(itsTextureId, itsX, itsY,
		itsWidth, itsHeight, itsCurrentRow, itsCurrentFrame, renderer);
}

void fom::GameObject::update()
{
	itsX -= 1;
}
