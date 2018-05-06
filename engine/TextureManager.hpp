#ifndef FOM_TEXTURE_MANAGER_HPP
#define FOM_TEXTURE_MANAGER_HPP

#include <string>
#include <map>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>


namespace fom {

	void cout_message(const std::string & msg);

	class Texture
	{
	private:
		std::string itsName;

	public:
		Texture(const std::string & name)
			:itsName(name)
		{
		}
		~Texture() = default;

	};

	class TextureManager
	{
	private:
		std::map <std::string, SDL_Texture * > itsTextureMap;

	private:
		TextureManager();
		~TextureManager();
	public:
		TextureManager(TextureManager const&) = delete;
		void operator=(TextureManager const&) = delete;

		static TextureManager & instance()
		{
			static TextureManager obj;
			return obj;
		}
		
		bool load(const std::string & file_name, const std::string & id,
			SDL_Renderer * renderer);

		void draw(const std::string & id, int x, int y, int width, int height,
			SDL_Renderer * renderer, SDL_RendererFlip flip=SDL_FLIP_NONE);

		void draw_frame(const std::string & id, int x, int y, int width, int height,
			int current_row, int current_frame,
			SDL_Renderer * pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);

	};

}

#endif  // !FOM_TEXTURE_MANAGER_HPP