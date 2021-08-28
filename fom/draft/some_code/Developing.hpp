#ifndef FOREST_OF_MAGIC_DEVELOPING_HPP
#define FOREST_OF_MAGIC_DEVELOPING_HPP


#include <SDL2/SDL.h>


bool handle_event(SDL_Event *Event)
{
    bool we_need_exit = false;

    switch(Event->type)
    {
        case SDL_QUIT:
        {
            printf("SDL_QUIT\n");
            we_need_exit = true;
        } break;

        case SDL_WINDOWEVENT:
        {
            switch(Event->window.event)
            {
                case SDL_WINDOWEVENT_RESIZED:
                {
                    printf("SDL_WINDOWEVENT_RESIZED (%d, %d)\n", Event->window.data1, Event->window.data2);
                } break;

                default:
                {
                    // empty
                }
            }
            default:
            {
                // empty
            }

        } break;
    }

    return we_need_exit;
}


void run_all()
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        // SDL_Init didn't work!
        printf("Err init");
        return;
    }

    SDL_Window * window;
    window = SDL_CreateWindow("AB", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              SDL_WINDOW_RESIZABLE);

    for(;;)
    {
        SDL_Event Event;
        SDL_WaitEvent(&Event);
        if (handle_event(&Event))
        {
            break;
        }
    }

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Exit msg", "We will be exiting!", window);

    SDL_Quit();
}


#endif //FOREST_OF_MAGIC_DEVELOPING_HPP
