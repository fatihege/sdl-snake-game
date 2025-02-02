#pragma once

#include <memory>
#include <SDL.h>

class Game {
public:
    void run();

private:
    std::unique_ptr<SDL_Window*> window = nullptr;
    std::unique_ptr<SDL_Renderer*> renderer = nullptr;
    bool gameOver = false;
    double dt = 0;
    double lastFrame = 0;

    void init();
};
