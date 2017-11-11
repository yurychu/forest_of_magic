#ifndef FOREST_OF_MAGIC_RENDERER_HPP
#define FOREST_OF_MAGIC_RENDERER_HPP

#include "Project.hpp"
#include "Window.hpp"

namespace fom {

    /*-------------------------------------------------------*/
    class Renderer
    {
    private:
        FOM_Renderer * itsRenderer;

    public:
        explicit Renderer(const fom::Window & window);
        ~Renderer();
        Renderer(const Renderer & that) = delete;
        Renderer& operator=(const Renderer & that) = delete;

        void clear() const;
        void present() const;

    };

}


#endif //FOREST_OF_MAGIC_RENDERER_HPP
