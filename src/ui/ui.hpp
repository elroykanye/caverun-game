#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>

#include "../engine/map.hpp"
#include "../models/room/room.hpp"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

class UI {
    public:
        /**
         * @brief Constructs a UI object.
         *
         * @param app Pointer to the GtkApplication object.
         * @param rows Number of rows in the grid.
         * @param cols Number of columns in the grid.
         */
        UI(GtkApplication* app, int rows, int cols);

        /**
         * @brief Destroys the UI object.
         */
        ~UI();

        /**
         * @brief Initializes the game window and the UI components.
         */
        void init();

        /**
         * @brief Updates the room colors based on player progress.
         */
        void refresh();

        /**
         * @brief Displays a message in the bottom bar.
         *
         * @param message The message to display.
         * @param severity The severity level of the message.
         */
        void display(string message, Severity severity);

        /**
         * @brief Destroys the game window and the UI components.
         */
        void destroy();

        // Public member variables
        Player* player;           // Pointer to the player object
        Monster* monster;         // Pointer to the monster object
        Map* map;                 // Pointer to the map object
        Position* exit;           // Pointer to the exit position object

    private:
        // Private member variables
        GtkApplication* app;      
        GtkWidget* mainWindow;    
        GtkWidget* mainBox;       
        GtkWidget* topBarBox;     
        GtkWidget* bottomBarBox;  
        GtkWidget* grid;          
        GtkWidget* playerLabel;   
        GtkWidget* healthLabel;   
        GtkWidget* movesLabel;    
        GtkWidget* messageLabel;  

        int gridRows;             
        int gridCols;
};

#endif