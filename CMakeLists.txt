cmake_minimum_required(VERSION 3.30)
project(sdl_snake_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(sdl_snake_game main.cpp
        src/Game.cpp
        src/Game.h
        src/Renderer.cpp
        src/Renderer.h
        src/InputHandler.cpp
        src/InputHandler.h
        src/Snake.cpp
        src/Snake.h
        src/Food.cpp
        src/Food.h)
