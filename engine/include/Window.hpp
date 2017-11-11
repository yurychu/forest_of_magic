#ifndef FOREST_OF_MAGIC_WINDOW_HPP
#define FOREST_OF_MAGIC_WINDOW_HPP

#include <string>

#include "Project.hpp"

namespace fom {

    /*-------------------------------------------------------*/
    class Window {
    private:
        FOM_Window *itsWindow;

    public:
        Window(const std::string &title, int width, int height);

        ~Window();

        Window(const fom::Window &that) = delete;

        Window &operator=(const fom::Window &that) = delete;

        FOM_Window * get() const { return itsWindow; }
    };
}

#endif //FOREST_OF_MAGIC_WINDOW_HPP
