#include <string>

#include <SDL2/SDL.h>

namespace fom {

    typedef SDL_Window FOM_Window;
    typedef SDL_Renderer FOM_Renderer;

    void init_engine();
    void run_engine();
    void quit_engine();

    class Window
    {
    private:
        FOM_Window * itsWindow;

    public:
        Window(const std::string &title, int width, int height);
        ~Window();
        Window(const fom::Window & that) = delete;
        Window& operator=(const fom::Window & that) = delete;

        FOM_Window* get() const { return itsWindow; }
    };

    class Renderer
    {
    private:
        FOM_Renderer * itsRenderer;

    public:
        Renderer(const fom::Window & window);
        ~Renderer();
        Renderer(const Renderer & that) = delete;
        Renderer& operator=(const Renderer & that) = delete;

        void clear();
        void present();

    };

}

