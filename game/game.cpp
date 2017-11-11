#include <iostream>

#include "Engine.hpp"


int main(int argc, char *argv[], char *envp[])
{
    fom::init_engine();

    fom::run_engine();

    fom::quit_engine();

    return(0);
}
