#include <iostream>
#include <stdexcept>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Engine.hpp"
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
    fom::Window window("Some title", 800, 600);
    fom::Renderer renderer(window);
    renderer.clear();
    renderer.present();
    SDL_Delay(5000);
}

void
fom::quit_engine()
{
    SDL_Quit();
}


/*-------------------------------------------------------*/
fom::Window::Window(const std::string &title, int width, int height)
    :itsWindow(nullptr)
{
    const auto flags = SDL_WINDOW_SHOWN;
    itsWindow = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            flags
    );

    if(itsWindow == nullptr)
    {
        const std::string err_msg = SDL_GetError();
        throw fom::ExceptionEngine("Could not create window! Error: " + err_msg);
    }
}

fom::Window::~Window()
{
    std::cout << "Window destructing" << std::endl;
    SDL_DestroyWindow(itsWindow);
    itsWindow = nullptr;
}


/*-------------------------------------------------------*/
fom::Renderer::Renderer(const fom::Window & window)
    :itsRenderer(nullptr)
{
    const auto flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    itsRenderer = SDL_CreateRenderer(window.get(), -1, flags);

    if(itsRenderer == nullptr)
    {
        const std::string err_msg = SDL_GetError();
        throw fom::ExceptionEngine("Could not create renderer! Error: " + err_msg);
    }
}

fom::Renderer::~Renderer()
{
    std::cout << "Renderer destructing" << std::endl;
    SDL_DestroyRenderer(itsRenderer);
    itsRenderer = nullptr;
};

void
fom::Renderer::clear()
{
    SDL_SetRenderDrawColor(itsRenderer, 0, 0, 0, 255);
    SDL_RenderClear(itsRenderer);
}

void
fom::Renderer::present()
{
    SDL_RenderPresent(itsRenderer);
}