#include "Game.h"

#include <SDL.h>
#include <iostream>

void Game::run() {
    init();

    SDL_Event event;

    while (!gameOver) {
        dt = (SDL_GetTicks() - lastFrame) / 1000.0;

        std::cout << "Delta time: " << dt << '\n';

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) gameOver = true;
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        std::cout << "W\n";
                        break;
                    case SDLK_a:
                        std::cout << "A\n";
                        break;
                    case SDLK_s:
                        std::cout << "S\n";
                        break;
                    case SDLK_d:
                        std::cout << "D\n";
                        break;
                    case SDLK_ESCAPE:
                        gameOver = true;
                        break;
                    default: ;
                }
            }
        }

        SDL_RenderPresent(*renderer);

        lastFrame = SDL_GetTicks();
        SDL_Delay(1000 / 30.0);
    }
}

void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << '\n';
        exit(1);
    }

    window = std::make_unique<SDL_Window *>(SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                                             SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN));
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << '\n';
        exit(1);
    }

    renderer = std::make_unique<SDL_Renderer *>(SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED));
    if (renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << '\n';
        exit(1);
    }

    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
    SDL_RenderClear(*renderer);
}
