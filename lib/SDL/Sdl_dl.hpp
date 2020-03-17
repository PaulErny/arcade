#ifndef SDL_HPP
#define SDL_HPP

#include "SDL2/SDL.h"
#include <memory>

class Sdl_dl
{
private:
    /* data */
public:
    Sdl_dl(/* args */);
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    ~Sdl_dl();
    void menu();
};

#endif