# Cave Run

## Description
This game is a cave escape adventure where the player needs to navigate through rooms, avoid a malicious monster, and reach the exit while managing their health points. The game provides a graphical user interface (GUI) using Gtk4 and is built using C++.

## System Requirements
- Linux or macOS operating system
- GCC compiler with C++11 support
- Gtk4 library

## Installation
1. Clone the repository: `git clone https://github.com/elroykanye/escape-game.git`
2. Change to the game directory: `cd escape-game`
3. Build the game using Make: `make`

## Running the Game
1. Build and run the game in one go using the helper script available in the source directory.
   - Linux: `./build.sh`
   Or directly execute the resulting binary:
   - Linux: `./run.sh`
2. The game window will open, and you can start playing.

## Gameplay Instructions
- The objective of the game is to escape from the cave by reaching the top-right corner.
- You start in the bottom-left corner of the cave.
- Use the mouse to make up to two moves on each turn.
- Avoid the malicious monster (marked as "M") in the cave.
- Normal rooms do not cause the player to lose health points.
- Poisonous rooms (shown in green) cause the player to lose health points after each move until the player is cured.
- Trap rooms (shown in dark red) decrease the player's health points by a fixed amount and end the player's turn.
- The game ends if the monster catches the player or if the player's health points are fully depleted.

## Troubleshooting
- If you encounter any issues running the game, make sure you have met the system requirements mentioned above.
- Ensure that the necessary libraries, such as Gtk4, are installed on your system.
