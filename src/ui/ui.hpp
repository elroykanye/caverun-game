#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>
#include <memory>
#include "../engine/map.hpp"
#include "../models/room/room.hpp"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

using namespace std;

/**
 * @brief Structure representing the game context containing the current room and player.
 */
struct GameContext {
    Room* room;    // Pointer to the current room
    Player* player;  // Pointer to the player
};

/**
 * @brief The UI class represents the user interface for the game.
 */
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
     *
     * @param restart Flag indicating whether the game should be restarted.
     */
    void refresh(bool restart = false);

    /**
     * @brief Sets up the game components.
     */
    void setup();

    /**
     * @brief Displays a message in the bottom bar.
     *
     * @param message The message to display.
     * @param severity The severity level of the message.
     */
    void display(string message, Severity severity);

    /**
     * @brief Displays the scores in the UI.
     *
     * @param content The content to display.
     */
    void displayScores(string content);

    /**
     * @brief Destroys the game window and the UI components.
     */
    void destroy();

    /**
     * @brief Displays the help information in the UI.
     */
    void displayHelp();

    /**
     * @brief Retrieves the stack widget.
     *
     * @return The stack widget.
     */
    GtkWidget* getStack();

    // Public member variables
    Player* player;             // Pointer to the player object
    Monster* monster;           // Pointer to the monster object
    Map* map;                   // Pointer to the map object
    Position* enter;            // Pointer to the enter position object
    Position* exit;             // Pointer to the exit position object
    vector<GameContext*> gameContexts;  // Vector of game contexts

private:
    // Private member variables
    GtkWidget* stack;           // Stack widget
    GtkWidget* stackSwitcher;   // Stack switcher widget

    GtkApplication* app;        // Pointer to the GtkApplication object
    GtkWidget* mainWindow;      // Main window widget
    GtkWidget* gameBox;         // Game box widget
    GtkWidget* topBarBox;       // Top bar box widget
    GtkWidget* messageBarBox;   // Message bar box widget
    GtkWidget* bottomBarBox;    // Bottom bar box widget
    GtkWidget* grid;            // Grid widget
    GtkWidget* playerLabel;     // Player label widget
    GtkWidget* healthLabel;     // Health label widget
    GtkWidget* movesLabel;      // Moves label widget
    GtkWidget* messageLabel;    // Message label widget

    GtkWidget* welcomeBtnHelp;  // Welcome button for help
    GtkWidget* welcomeBox;      // Welcome box widget
    GtkWidget* scoresLabel;     // Scores label widget
    GtkWidget* scoresTextView;  // Scores text view widget
    GtkTextBuffer* scoresTextBuffer;  // Scores text buffer

    int gridRows;               // Number of rows in the grid
    int gridCols;               // Number of columns in the grid

    bool showHelp = false;      // Flag indicating whether help should be displayed

    /**
     * @brief Sets up the game box.
     */
    void setupGameBox();

    /**
     * @brief Sets up the welcome box.
     */
    void setupWelcomeBox();
};

#endif // UI_H