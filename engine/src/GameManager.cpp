#include <SDL2/SDL.h>

#include "GameManager.hpp"


/*-------------------------------------------------------*/
fom::GameManager::GameManager()
    :itsRunning(true)
{

}

fom::GameManager::~GameManager()
{

}

void
fom::GameManager::handle_events()
{
    SDL_Event event = {};

    while (SDL_PollEvent( &event )){
        if (event.type == SDL_QUIT){
            itsRunning = false;
        }
    }
}

void
fom::GameManager::update_objects()
{

}


void
fom::GameManager::render(const fom::Renderer & renderer)
{
    renderer.clear();
    renderer.present();
}



/*-------------------------------------------------------*/

