#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "room_system.hpp"
#include "score_board.hpp"
#include "../ui/ui.hpp"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

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

        double getBoardSize() const;

    private:
        UI* ui;              
        RoomSystem* roomSys;  
        ScoreBoard* scoreBoard;
        Player player;        
        Monster monster;     
        int rows;             
        int cols; 
        Position enter;
        Position exit;
};

#endif