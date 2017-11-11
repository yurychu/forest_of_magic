#include <iostream>

#include "Window.hpp"
#include "Exceptions.hpp"

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

