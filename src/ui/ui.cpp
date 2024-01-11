#include "ui.hpp"

UI::UI(GtkApplication *application, int rows, int cols) {
    app = application;
    gridRows = rows;
    gridCols = cols;
}
UI::~UI() {
    cout << "\n\n\nUI DESTROYED\n\n\n" << endl;
}

GtkWidget* UI::getStack() {
    return this->stack;
}

void UI::init() {
    gtk_init();

    mainWindow = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainWindow), "Cave Escape");
    gtk_window_set_default_size(GTK_WINDOW(mainWindow), 1024, 720);

    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "main.css");
    gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_signal_connect(mainWindow, "destroy", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {
        UI* ui = static_cast<UI*>(data);
    }), NULL);  

    this->setupWelcomeBox();
    this->setupGameBox();
    gtk_window_present(GTK_WINDOW(mainWindow));
}

void UI::setup() {
    stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);
    
    gtk_stack_add_named(GTK_STACK(stack), welcomeBox, "stackWelcome");
    gtk_stack_add_named(GTK_STACK(stack), gameBox, "stackGame");
    
    stackSwitcher = gtk_stack_switcher_new();
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(stackSwitcher), GTK_STACK(stack));

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_append(GTK_BOX(box), stackSwitcher);
    gtk_box_append(GTK_BOX(box), stack);

    gtk_window_set_child(GTK_WINDOW(mainWindow), box);

    gtk_stack_set_visible_child_name(GTK_STACK(stack), "stackWelcome");
}

void UI::setupGameBox() {
    gameBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_start(gameBox, 4);
    gtk_widget_set_margin_end(gameBox, 4);
    gtk_widget_set_margin_top(gameBox, 4);
    gtk_widget_set_margin_bottom(gameBox, 4);

    topBarBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

    healthLabel = gtk_label_new(player->getHealthLabel().c_str());
    playerLabel = gtk_label_new(player->getNameLabel().c_str());
    movesLabel = gtk_label_new(player->getMovesLabel().c_str());
    gtk_box_append(GTK_BOX(topBarBox), healthLabel);
    gtk_box_append(GTK_BOX(topBarBox), playerLabel);
    gtk_box_append(GTK_BOX(topBarBox), movesLabel);

    grid = gtk_grid_new();
    refresh();

    messageBarBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

    messageLabel = gtk_label_new("Welcome to Escape!");
    gtk_widget_add_css_class(messageBarBox, "message");
    gtk_widget_add_css_class(topBarBox, "message");
    gtk_box_append(GTK_BOX(messageBarBox), messageLabel);

    GtkWidget* closeBtn = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(closeBtn), "Close");
    GtkWidget* restartBtn = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(restartBtn), "Restart");

    bottomBarBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(bottomBarBox), closeBtn);
    gtk_box_append(GTK_BOX(bottomBarBox), restartBtn);
    gtk_widget_add_css_class(bottomBarBox, "bottom-bar-box");

    g_signal_connect(closeBtn, "clicked", G_CALLBACK(+[](GtkWidget* widget, gpointer data){
        UI* ui = static_cast<UI*>(data);
        GtkWidget* stack = ui->getStack();
        gtk_stack_set_visible_child_name(GTK_STACK(stack), "stackWelcome");
    }), this);
    g_signal_connect(restartBtn, "clicked", G_CALLBACK(+[](GtkWidget* widget, gpointer data){
        UI* ui = static_cast<UI*>(data);
        ui->map->resetRooms();
        ui->player->setMoves(2);
        ui->player->setTotalMoves(0);
        ui->player->setDone(false);
        ui->player->resetPosition();
        ui->monster->resetPosition();
        ui->refresh(true);
    }), this);

    gtk_box_append(GTK_BOX(gameBox), topBarBox);
    gtk_box_append(GTK_BOX(gameBox), grid);
    gtk_box_append(GTK_BOX(gameBox), messageBarBox);
    gtk_box_append(GTK_BOX(gameBox), bottomBarBox);

    gtk_widget_add_css_class(gameBox, "main");
}

void UI::setupWelcomeBox() {
    welcomeBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget* welcomeLabelBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 16);
    GtkWidget* welcomeLabel = gtk_label_new("Welcome to Cave Run");
    gtk_box_append(GTK_BOX(welcomeLabelBox), welcomeLabel);

    GtkWidget* welcomeBtnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 16);
    GtkWidget* welcomeBtnStart = gtk_button_new();
    welcomeBtnHelp = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(welcomeBtnStart), "Start");
    gtk_button_set_label(GTK_BUTTON(welcomeBtnHelp), "Help");
    gtk_box_append(GTK_BOX(welcomeBtnBox), welcomeBtnStart);
    gtk_box_append(GTK_BOX(welcomeBtnBox), welcomeBtnHelp);

    gtk_widget_set_hexpand(welcomeBtnStart, TRUE);
    gtk_widget_set_vexpand(welcomeBtnHelp, TRUE);

    GtkWidget* scoresBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 4);
    scoresTextView = gtk_text_view_new();
    scoresTextBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(scoresTextView));
    scoresLabel = gtk_label_new("");
    gtk_box_append(GTK_BOX(scoresBox), scoresLabel);


    gtk_box_append(GTK_BOX(welcomeBox), welcomeLabelBox);
    gtk_box_append(GTK_BOX(welcomeBox), welcomeBtnBox);

    gtk_box_append(GTK_BOX(welcomeBox), scoresBox);

    gtk_widget_add_css_class(welcomeBtnBox, "welcome-button-box");
    gtk_widget_add_css_class(welcomeLabel, "welcome-label");
    gtk_widget_set_valign(welcomeBox, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(welcomeBox, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(welcomeLabelBox, GTK_ALIGN_CENTER);

    g_signal_connect(welcomeBtnStart, "clicked", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {
        UI* ui = static_cast<UI*>(data);
        GtkWidget* stack = ui->getStack();
        gtk_stack_set_visible_child_name(GTK_STACK(stack), "stackGame");
    }), this);

    g_signal_connect(welcomeBtnHelp, "clicked", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {
        UI* ui = static_cast<UI*>(data);   
        ui->displayHelp();
    }), this);
}

void UI::refresh(bool restart) {
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

            gtk_widget_remove_css_class(button, "trap-btn");
            gtk_widget_remove_css_class(button, "bonus-btn");
            gtk_widget_remove_css_class(button, "poison-btn");
            if (room->isVisited() || player->isDone()) {
                gtk_widget_add_css_class(button, roomButtonClass.c_str());
            } else {
                gtk_widget_add_css_class(button, "normal-btn");
            }

            gtk_widget_add_css_class(button, "btn");
            gtk_widget_remove_css_class(button, "player-indicator");
            gtk_widget_remove_css_class(button, "monster-indicator");
            gtk_button_set_label(GTK_BUTTON(button), "");

            if (this->player->getPosition() == room->getPosition()) {
                gtk_button_set_label(GTK_BUTTON(button), "P");
            }

            if (this->monster->getPosition() == room->getPosition()) {
                gtk_button_set_label(GTK_BUTTON(button), "M");
            }

            if (*exit == room->getPosition()) {
                if (this->monster->getPosition() == *exit) {
                    gtk_button_set_label(GTK_BUTTON(button), "Exit\nM");
                } else {
                    gtk_button_set_label(GTK_BUTTON(button), "Exit");
                }
                if (initial) gtk_widget_add_css_class(button, "exit-btn");
            }

            gtk_label_set_text(GTK_LABEL(healthLabel), player->getHealthLabel().c_str());
            gtk_label_set_text(GTK_LABEL(movesLabel), player->getMovesLabel().c_str());

            if (initial) {
                gtk_grid_attach(GTK_GRID(grid), button, i, j, 1, 1);
                gtk_widget_set_hexpand(button, TRUE);
                gtk_widget_set_vexpand(button, TRUE);
            }


            if (initial || restart) {
                GameContext* gameContext = new GameContext{room, player};
                g_signal_connect(button, "clicked", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {
                    GameContext* context = static_cast<GameContext*>(data);
                    if (context->player->getMoves() > 0) {
                        context->player->setNextPosition(context->room->getPosition());
                    }
                }), gameContext);

                gameContexts.push_back(std::move(gameContext));
            }
        }
    }
}

void UI::display(string message, Severity severity = Severity::PRIMARY) {
    string classes[] = {"warn", "primary", "danger", "success"};
    for (string& c: classes) {
        gtk_widget_remove_css_class(messageBarBox, ("message-" + c).c_str());
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
    gtk_widget_add_css_class(messageBarBox, ("message-" + newClass).c_str());
}

void UI::displayScores(string content) {
    if (!showHelp) {
        gtk_label_set_text(GTK_LABEL(scoresLabel), content.c_str());
    }
}

void UI::displayHelp() {
    showHelp = !showHelp;
    string labelText = "";
    string buttonText = "";
    if (showHelp) {
        labelText = "1. Escape from the cave by reaching the top-right corner.\n"
                    "2. Avoid the malicious monster (marked as 'M') in the cave.\n"
                    "3. You start in the bottom-left corner (marked as 'P').\n"
                    "4. Move through normal rooms without losing health points.\n"
                    "5. Watch out for poisonous and trap rooms that decrease health points.";
        buttonText = "High Scores";
    } else {
        labelText = "";
        buttonText = "Help";
    }
    gtk_label_set_text(GTK_LABEL(scoresLabel), labelText.c_str());
    gtk_button_set_label(GTK_BUTTON(welcomeBtnHelp), buttonText.c_str());
}

void UI::destroy() {
    
}
