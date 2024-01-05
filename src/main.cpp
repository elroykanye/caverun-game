#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <execinfo.h>
#include "engine/game_engine.hpp"

using namespace std;

GameEngine engine("Elroy", 10, 10);

static void activate(GtkApplication *app, gpointer data) {
    engine.render(app);
    engine.launch();
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.group2.cave-escape", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return EXIT_SUCCESS;
}