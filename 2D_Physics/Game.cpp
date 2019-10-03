#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "subsystems live" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
            {
                std::cout <<"window live"<<std::endl;
            }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "renderer live" << std::endl;
        }
        isRunning = true;

    }else{
        isRunning = false;
        std::cout << "failet init" << std::endl;
    }




}

void Game::handlEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) 
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }


}

void Game::update()
{
    std::cout << CNTR << std::endl;
    CNTR++;

}

void Game::render()
{
    SDL_RenderClear(renderer);

    //ADD stuff to render.

    SDL_RenderPresent(renderer);
}

void Game::clean()
{

    std::cout << "Exiting" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Destroyed stuffs" << std::endl;


}
