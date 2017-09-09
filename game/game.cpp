#include <iostream>

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char *argv[], char *envp[])
{
    SDL_Window* window = NULL;
    SDL_Surface* screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
    }
    else {
        window = SDL_CreateWindow("Sdl hi!", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (window == NULL){
            std::cout << "Window not created! SDL_error: " << SDL_GetError() << std::endl;
        }
        else {
            screen_surface = SDL_GetWindowSurface(window);
            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    

    return(0);
}

