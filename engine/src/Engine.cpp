#include <iostream>
#include <stdexcept>

#include "Engine.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "GameManager.hpp"
#include "Exceptions.hpp"


/*-------------------------------------------------------*/
void
fom::init_engine()
{
    std::cout << "Making engine!" << std::endl;

    const auto flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO;

    if(SDL_Init(flags) < 0)
    {
        const std::string err_msg = SDL_GetError();
        throw fom::ExceptionEngine("Could not initialize SDL! Error: " + err_msg);
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags))
    {
        const std::string err_msg = IMG_GetError();
        throw fom::ExceptionEngine("Could not initialize SDL_IMG! Error: " + err_msg);
    }

    //Initialize SDL_ttf
    if(TTF_Init() < 0)
    {
        const std::string err_msg = TTF_GetError();
        throw fom::ExceptionEngine("Could not initialize SDL_TTF! Error: " + err_msg);
    }

    //Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        const std::string err_msg = Mix_GetError();
        throw fom::ExceptionEngine("Could not initialize SDL_MIXER! Error: " + err_msg);
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
    }

}

void
fom::run_engine()
{
    fom::GameManager gm;
    fom::Window window("Some title", 800, 600);
    fom::Renderer renderer(window);

    while (gm.is_running()){
        gm.handle_events();
        gm.update_objects();
        gm.render(renderer);
    }
}

void
fom::quit_engine()
{
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


