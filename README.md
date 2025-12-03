# XO Game

**Developed:** 2024
**Technologies:** C++, SDL2

## Overview

XO Game is a graphical implementation of the classic Tic-Tac-Toe game. It features both Player vs Player (PVP) and Player vs Computer (PVC) modes. The game is developed using **C++** and **SDL2**, providing a smooth and interactive graphical interface.

## Features

* PVP mode: Two players can compete locally on the same machine.
* PVC mode: Play against the computer with an AI that chooses optimal moves.
* 3x3 classic grid gameplay with a 5x5 internal grid system for advanced logic handling.
* Smooth graphical interface with background animations and interactive buttons.
* Undo functionality to revert the last move.
* Customizable themes and background images.

## Technologies Used

* **C++**: Core game logic, AI, and grid management.
* **SDL2**: Window creation, rendering, event handling, text rendering (via SDL_ttf), and graphics management.
* Modular project structure for easy maintenance and scalability.

## Project Structure

* `main.cpp` – Entry point of the game.
* `HomePage` – Main menu and navigation.
* `GameManager` – Handles gameplay logic for both PVP and PVC modes.
* `XOGrid` – Manages the grid and player moves.
* `Referee` – Checks game status and win conditions.
* `ButtonController` – Manages interactive buttons with smooth scaling and hover effects.
* `BackGroundManager` – Handles static and animated backgrounds.
* `TextManager` – Renders all text using SDL_ttf.

## How to Run

1. Make sure SDL2 and SDL2_ttf are installed on your system.
2. Clone the repository:

   ```bash
   git clone <repository-url>
   ```
3. Build the project using your preferred C++ compiler. Example with `g++`:

   ```bash
   g++ -o XOGame main.cpp ... -lSDL2 -lSDL2_ttf
   ```
4. Run the executable:

   ```bash
   ./XOGame
   ```

