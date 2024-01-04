#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>

#include "../engine/map.hpp"
#include "../models/room/room.hpp"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

class UI {
    public:
        UI(GtkApplication *app, int rows, int cols);
        ~UI();

        // Initialise the game window and the UI components
        void init();

        // Update the room colors based on player progress
        void refresh();

        // Display a message in the bottom bar
        void display(string message, Severity severity);

        // Destroy the game window and the UI components
        void destroy();

        Player* player;
        Monster* monster;
        Map* map;

    private:
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
