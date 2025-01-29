# Snake Game Documentation

## Overview
This is a classic Snake game implemented in C++ using the SDL2 library for graphics, input handling, and audio. The game utilizes the following SDL2 extensions:
- **SDL2**: Core library for rendering and input handling.
- **SDL2_image**: For loading image files (e.g., PNG, JPEG).
- **SDL2_ttf**: For rendering TrueType fonts.
- **SDL2_mixer**: For handling audio playback.

The project uses **vcpkg** as the package manager to handle dependencies.

---

## Table of Contents
1. [Dependencies](#dependencies)
2. [Installation](#installation)
3. [Project Structure](#project-structure)
4. [Game Features](#game-features)
5. [How to Play](#how-to-play)
6. [Code Explanation](#code-explanation)

---

## Dependencies
The following libraries are required to build and run the game:
- **SDL2**: Core library for rendering and input handling.
- **SDL2_image**: For loading image files (e.g., PNG, JPEG).
- **SDL2_ttf**: For rendering TrueType fonts.
- **SDL2_mixer**: For handling audio playback.

These dependencies are managed using **vcpkg**, a C++ package manager.

---

## Installation

### Prerequisites
1. **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
2. **CMake**: The project uses CMake as the build system.
3. **vcpkg**: Install vcpkg by following the instructions at [vcpkg GitHub](https://github.com/microsoft/vcpkg).

### Steps to Install and Build
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/fatihege/sdl-snake-game.git
   cd snake-game
   ```

2. **Install Dependencies with vcpkg**:
   If you haven't already set up vcpkg, follow these steps:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   ./vcpkg/bootstrap-vcpkg.sh  # On Linux/MacOS
   .\vcpkg\bootstrap-vcpkg.bat # On Windows
   ```

   Then, install the required libraries:
   ```bash
   ./vcpkg install sdl2 sdl2-image sdl2-ttf sdl2-mixer
   ```

3. **Integrate vcpkg with CMake**:
   To integrate vcpkg with CMake, use the following command:
   ```bash
   cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
   ```

4. **Build the Project**:
   ```bash
   cmake --build build
   ```

5. **Run the Game**:
   After building, navigate to the `build` directory and run the executable:
   ```bash
   ./build/sdl_snake_game  # On Linux/MacOS
   .\build\sdl_snake_game.exe  # On Windows
   ```

---

## Project Structure
```
snake-game/
├── CMakeLists.txt          # CMake configuration file
├── assets/                 # Directory for game assets (images, fonts, sounds)
│   ├── fonts/              # TrueType fonts
│   ├── images/             # Image assets
│   └── sounds/             # Sound effects and music
├── src/                    # Source code directory
│   ├── Game.cpp            # Game logic implementation
│   ├── Game.h              # Game logic header
│   ├── Renderer.cpp        # Handles rendering of game objects (snake, food, score)
│   ├── Renderer.h          # Header for the Renderer class
│   ├── InputHandler.cpp    # Handles user input (keyboard controls)
│   ├── InputHandler.h      # Header for the InputHandler class
│   ├── Snake.cpp           # Snake logic implementation
│   ├── Snake.h             # Snake logic header
│   ├── Food.cpp            # Food logic implementation
│   ├── Food.h              # Food logic header
├── main.cpp                # Entry point of the application
└── README.md               # Project documentation
```

---

## Game Features
- **Classic Snake Gameplay**: Control the snake to eat food and grow longer.
- **Score Tracking**: Displays the player's score on the screen.
- **Game Over Condition**: The game ends if the snake collides with itself or the wall.
- **Audio Effects**: Sound effects for eating food and game over.
- **Graphics**: Uses SDL2 for rendering the game grid, snake, and food.

---

## How to Play
1. **Controls**:
    - Use the **Arrow Keys** (Up, Down, Left, Right) or **WASD** to control the direction of the snake.
    - Press **ESC** to quit the game.

2. **Objective**:
    - Move the snake to eat the food that appears on the screen.
    - Each time the snake eats food, it grows longer, and your score increases.
    - Avoid running into the walls or yourself; doing so will end the game.

3. **Restarting the Game**:
    - After a game over, press any key to restart the game.

---

## Code Explanation

### Main Components
1. **Game Loop**:
   The game loop handles the following tasks:
    - Processing user input.
    - Updating the game state (snake movement, collision detection).
    - Rendering the game objects (snake, food, score).
    - Playing sound effects and music.

2. **Snake Logic**:
    - The snake is represented as a list of segments.
    - Movement is handled by updating the position of the head and shifting the rest of the body.
    - Collision detection checks if the snake hits itself or the wall.

3. **Food Logic**:
    - Food is randomly placed on the grid.
    - When the snake eats the food, a new piece of food is generated, and the snake grows.

4. **Rendering**:
    - The game grid, snake, and food are rendered using SDL2.
    - Text (e.g., score) is rendered using SDL2_ttf.

5. **Audio**:
    - Sound effects for eating food and game over are played using SDL2_mixer.

--- 

This documentation provides a comprehensive guide to understanding, installing, and playing the Snake game. Enjoy coding and gaming! 🎮