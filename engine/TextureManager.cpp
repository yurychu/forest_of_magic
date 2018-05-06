#include <iostream>

#include "TextureManager.hpp"


fom::TextureManager::TextureManager()
{
}


fom::TextureManager::~TextureManager()
{
}

bool
fom::TextureManager::load(const std::string & file_name, const std::string & id,
	SDL_Renderer * renderer)
{
	auto result = false;
	auto temp_surface = IMG_Load(file_name.c_str());
	if (temp_surface) {
		auto texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
		SDL_FreeSurface(temp_surface);
		if (texture) {
			itsTextureMap[id] = texture;
			result = true;
		}
		else {
			const std::string err_msg = SDL_GetError();
			fom::cout_message("SDL fail convert to texture: " + file_name + " msg: " + err_msg);
		}
	}
	else {
		const std::string err_msg = SDL_GetError();
		fom::cout_message("SDL fail load image: " + file_name + " msg: " + err_msg);
	}

	return result;
}

void
fom::TextureManager::draw(const std::string & id, int x, int y, int width, int height,
	SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect src_rect;
	SDL_Rect dest_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = dest_rect.w = width;
	src_rect.h = dest_rect.h = height;

	dest_rect.x = x;
	dest_rect.y = y;

	SDL_RenderCopyEx(renderer, itsTextureMap[id], &src_rect, &dest_rect, 0, 0, flip);
}

void
fom::TextureManager::draw_frame(const std::string & id, int x, int y, int width, int height,
	int current_row, int current_frame, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect src_rect;
	SDL_Rect dest_rect;
	src_rect.x = width * current_frame;
	src_rect.y = height * (current_row - 1);
	src_rect.w = dest_rect.w = width;
	src_rect.h = dest_rect.h = height;
	dest_rect.x = x;
	dest_rect.y = y;
	SDL_RenderCopyEx(pRenderer, itsTextureMap[id], &src_rect,
		&dest_rect, 0, 0, flip);
}
