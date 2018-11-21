#ifndef FOREST_OF_MAGIC_GAME_HPP
#define FOREST_OF_MAGIC_GAME_HPP

#include <iostream>
#include <string>

#include <engine/GameObject.hpp>


void say_run()
{
    fom::GameObject gm;
    gm.update();
    std::cout << "RUN" << std::endl;
}



#endif //FOREST_OF_MAGIC_GAME_HPP
