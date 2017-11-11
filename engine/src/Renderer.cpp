#include <iostream>

#include "Renderer.hpp"
#include "Exceptions.hpp"


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
fom::Renderer::clear() const
{
    SDL_SetRenderDrawColor(itsRenderer, 0, 0, 0, 255);
    SDL_RenderClear(itsRenderer);
}

void
fom::Renderer::present() const
{
    SDL_RenderPresent(itsRenderer);
}
