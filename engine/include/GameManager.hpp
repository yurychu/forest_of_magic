#ifndef FOREST_OF_MAGIC_GAMEMANAGER_HPP
#define FOREST_OF_MAGIC_GAMEMANAGER_HPP

#include "Renderer.hpp"


namespace fom {

    /*-------------------------------------------------------*/
    class GameManager
    {
    private:
        bool itsRunning;

    public:
        GameManager();
        ~GameManager();
        GameManager(const GameManager & that) = delete;
        GameManager& operator=(const GameManager & that) = delete;

        void handle_events();
        void update_objects();
        void render(const fom::Renderer & renderer);

        bool is_running() const { return itsRunning; }

    };

}
#endif //FOREST_OF_MAGIC_GAMEMANAGER_HPP
