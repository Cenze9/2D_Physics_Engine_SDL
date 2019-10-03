#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <stdio.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handlEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:
    bool isRunning = false;
    SDL_Window *window;
    SDL_Renderer* renderer;

    int CNTR = 0;
};


#endif