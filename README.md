# Cub3D - Pokemon Edition

This project is a Pokemon-themed implementation of the 42 school cub3D project, which recreates a Wolfenstein 3D-style raycasting engine. The game features first-person navigation through a 3D environment with Pokemon-inspired textures, sprites, and atmosphere.

![gameplay](https://github.com/user-attachments/assets/4ccd578a-2a17-4b6d-9799-dbd2d4d2ab36)

## How to play
- **Movement:** WASD keys
- **Look Around:** Arrow keys or mouse movement
- **Interact:** Spacebar
- **Exit:** ESC key
- **To win:** Beat Team Rocket!

## Installation
- Clone the repo
- Run `make` to build
- Run `./cub3D maps/bonus.cub` to play the full-featured pokemon-themed bonus game
- Run `./cub3D maps/good/[map_name].cub` to play regular maps

### On macOS
macOS has no X11, which mlx depends on. The workaround:
1. Install XQuartz: `brew install --cask xquartz` (before running `make`)
2. Start the XQuartz server: `open -a XQuartz`
3. Point to XQuartz's display by running the game with: `DISPLAY=:0 ./cub3D maps/bonus.cub`

## Core vs Bonus
- The core game follows the project instructions laid out in en.subject.pdf.
- The bonus game follows the bonus instrucions from en.subject.pdf PLUS our own ideas for a pokemon-themed experience.

## Acknowledgements

This project is a collaborative effort of Karl Weihmann and Gabe Levin as part of the 42 School curriculum.

Map layouts and base textures were sourced from https://github.com/mcombeau/cub3D, with appreciation to Mia and her project contributors for providing these valuable resources.

The build system was adapted from https://github.com/tesla33io/awesome_makefile, with thanks to Tesla33io for the comprehensive Makefile structure.

Pokemon sprites utilized in this project are property of their respective copyright holders and are used solely for educational purposes in this non-commercial academic project.

