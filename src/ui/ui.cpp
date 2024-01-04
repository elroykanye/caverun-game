#include "ui.h"

using namespace std;

struct GameContext {
    Room* room;
    Player* player;
};
UI::UI(GtkApplication *application, int rows, int cols) {
    app = application;
    gridRows = rows;
    gridCols = cols;
}
UI::~UI() {
    delete player;
    delete monster;
    delete map;
}

void UI::init() {
    gtk_init();

    mainWindow = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainWindow), "Escape Game");
    gtk_window_set_default_size(GTK_WINDOW(mainWindow), 640, 480);

    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "./src/styles/main.css");
    gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_signal_connect(mainWindow, "destroy", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {
        UI* ui = static_cast<UI*>(data);
        ui->destroy();
    }), NULL);

    mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_window_set_child(GTK_WINDOW(mainWindow), mainBox);
    gtk_widget_set_margin_start(mainBox, 4);
    gtk_widget_set_margin_end(mainBox, 4);
    gtk_widget_set_margin_top(mainBox, 4);
    gtk_widget_set_margin_bottom(mainBox, 4);

    topBarBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(mainBox), topBarBox);

    healthLabel = gtk_label_new(player->getHealthLabel().c_str());
    playerLabel = gtk_label_new(player->getNameLabel().c_str());
    movesLabel = gtk_label_new(player->getMovesLabel().c_str());
    gtk_box_append(GTK_BOX(topBarBox), healthLabel);
    gtk_box_append(GTK_BOX(topBarBox), playerLabel);
    gtk_box_append(GTK_BOX(topBarBox), movesLabel);

    grid = gtk_grid_new();
    gtk_box_append(GTK_BOX(mainBox), grid);
    refresh();

    bottomBarBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(mainBox), bottomBarBox);

    messageLabel = gtk_label_new("Welcome to Escape!");
    gtk_widget_add_css_class(messageLabel, "message");
    gtk_box_append(GTK_BOX(bottomBarBox), messageLabel);

    gtk_window_present(GTK_WINDOW(mainWindow));
}

void UI::refresh() {
    for (int i = 0; i < gridRows; i++) {
        for (int j = 0; j < gridCols; j++) {
            Vect vect = {i, j};
            Position pos(vect, gridRows);

            Room* room = map->getRoom(pos);
            string roomType  = "";
            
            bool initial = false;
            GtkWidget* button;
            GtkWidget* existingButton = gtk_grid_get_child_at(GTK_GRID(grid), i, j);
            if (existingButton == nullptr) {
                initial = true;
                button = gtk_button_new();
            } else button = existingButton;
            string roomButtonClass = "";
            
            if (room->isBonus()) {
                roomType = "Bonus";
                roomButtonClass = "bonus-btn";
            } else if (room->isPoison()) {
                roomType = "Poison"; 
                roomButtonClass = "poison-btn";
            } else if (room->isTrap()) {
                roomType = "Trap";
                roomButtonClass = "trap-btn";
            } else {
                roomType = "Normal";
                roomButtonClass = "normal-btn";
            }

            if (room->isVisited()) {
                gtk_widget_add_css_class(button, roomButtonClass.c_str());
            } else {
                gtk_widget_add_css_class(button, "normal-btn");
            }

            gtk_widget_add_css_class(button, "btn");
            gtk_widget_remove_css_class(button, "player-indicator");
            gtk_widget_remove_css_class(button, "monster-indicator");
            gtk_button_set_label(GTK_BUTTON(button), "");

            if (this->player->getPosition().equals(room->getPosition())) {
                gtk_button_set_label(GTK_BUTTON(button), "P");
                gtk_widget_add_css_class(button, "player-indicator");
            }
            if (this->monster->getPosition().equals(room->getPosition())) {
                gtk_button_set_label(GTK_BUTTON(button), "M");
                gtk_widget_add_css_class(button, "monster-indicator");
            }

            gtk_label_set_text(GTK_LABEL(healthLabel), player->getHealthLabel().c_str());
            gtk_label_set_text(GTK_LABEL(movesLabel), player->getMovesLabel().c_str());

            if (initial) {
                gtk_grid_attach(GTK_GRID(grid), button, i, j, 1, 1);
            }
            gtk_widget_set_hexpand(button, TRUE);
            gtk_widget_set_vexpand(button, TRUE);

            if (initial) {
                GameContext* gameContext = new GameContext{room, player};
                g_signal_connect(button, "clicked", G_CALLBACK(+[](GtkWidget* widget, gpointer data){
                    GameContext* context = static_cast<GameContext*>(data);
                    if (context->player->getMoves() > 0) 
                        context->player->setNextPosition(context->room->getPosition());
                }), gameContext);
            }
           
        }
    }
}

void UI::display(string message, Severity severity = Severity::PRIMARY) {
    string classes[] = {"warn", "primary", "danger", "success"};
    for (string& c: classes) {
        gtk_widget_remove_css_class(messageLabel, ("message-" + c).c_str());
    }
    string newClass = "";
    gtk_label_set_text(GTK_LABEL(messageLabel), message.c_str());
    switch (severity) {
        case PRIMARY: newClass = "primary"; break;
        case SUCCESS: newClass = "success"; break;
        case DANGER: newClass = "danger"; break;
        case WARN: newClass = "warn"; break;
        default: break;
    }
    gtk_widget_add_css_class(messageLabel, ("message" + newClass).c_str());
}

void UI::destroy() {

}
