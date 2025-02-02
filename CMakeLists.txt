cmake_minimum_required(VERSION 3.30)
project(sdl_snake_game)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

add_executable(sdl_snake_game main.cpp
        src/Game.cpp
        src/Game.h
        src/Renderer.cpp
        src/Renderer.h
        src/Snake.cpp
        src/Snake.h
        src/Food.cpp
        src/Food.h)

target_link_libraries(sdl_snake_game
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)
