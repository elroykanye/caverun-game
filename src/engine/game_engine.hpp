#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "room_system.hpp"
#include "score_board.hpp"
#include "../ui/ui.hpp"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

/**
 * @brief The GameEngine class represents the game engine that manages the game's logic and UI.
 */
class GameEngine {
public:
    /**
     * @brief Constructs a GameEngine object.
     *
     * @param playerName The name of the player.
     * @param rows Number of rows in the game grid.
     * @param cols Number of columns in the game grid.
     */
    GameEngine(string playerName, int rows, int cols);

    /**
     * @brief Destroys the GameEngine object.
     */
    ~GameEngine();

    /**
     * @brief Renders the game UI.
     *
     * @param app Pointer to the GtkApplication object.
     */
    void render(GtkApplication* app);

    /**
     * @brief Launches the game.
     */
    void launch();

    /**
     * @brief Returns the size of the game board.
     *
     * @return The size of the game board (rows * cols).
     */
    double getBoardSize() const;

private:
    UI* ui;                     // Pointer to the UI object for rendering the game interface.
    RoomSystem* roomSys;        // Pointer to the RoomSystem object for managing the game rooms.
    ScoreBoard* scoreBoard;     // Pointer to the ScoreBoard object for tracking the game scores.
    Player player;              // The player character.
    Monster monster;            // The monster character.
    int rows;                   // Number of rows in the game grid.
    int cols;                   // Number of columns in the game grid.
    Position enter;             // The position of the entrance to the game grid.
    Position exit;              // The position of the exit from the game grid.
};

#endif