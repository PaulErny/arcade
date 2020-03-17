#include "Sdl_dl.hpp"

Sdl_dl::Sdl_dl()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow("Laucher SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(3000);
}

Sdl_dl::~Sdl_dl()
{

}

extern "C" std::unique_ptr<Sdl_dl> create_object()
{
    return std::make_unique<Sdl_dl>();
}

void Sdl_dl::menu()
{
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while ( SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_UpdateWindowSurface(m_window);
    }
}