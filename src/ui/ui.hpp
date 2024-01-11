#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>
#include <memory>
#include "../engine/map.hpp"
#include "../models/room/room.hpp"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

using namespace std;

struct GameContext {
    Room* room;
    Player* player;
};

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

        void setup();

        /**
         * @brief Displays a message in the bottom bar.
         *
         * @param message The message to display.
         * @param severity The severity level of the message.
         */
        void display(string message, Severity severity);

        void displayScores(string content);

        /**
         * @brief Destroys the game window and the UI components.
         */
        void destroy();


        GtkWidget* getStack();

        // Public member variables
        Player* player;           // Pointer to the player object
        Monster* monster;         // Pointer to the monster object
        Map* map;                 // Pointer to the map object
        Position* enter;          // Pointer to the enter position object
        Position* exit;           // Pointer to the exit position object

    private:
        // Private member variables
        vector<GameContext*> gameContexts;

        GtkWidget* stack;
        GtkWidget* stackSwitcher;

        GtkApplication* app;      
        GtkWidget* mainWindow;    
        GtkWidget* gameBox;       
        GtkWidget* topBarBox;     
        GtkWidget* messageBarBox;  
        GtkWidget* bottomBarBox;  
        GtkWidget* grid;          
        GtkWidget* playerLabel;   
        GtkWidget* healthLabel;   
        GtkWidget* movesLabel;    
        GtkWidget* messageLabel;  

        GtkWidget* welcomeBox;
        GtkWidget* scoresLabel;
        GtkWidget* scoresTextView;
        GtkTextBuffer* scoresTextBuffer;

        int gridRows;             
        int gridCols;
        bool initial;

        void setupGameBox();
        void setupWelcomeBox();
};

#endif