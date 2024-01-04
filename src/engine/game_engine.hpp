#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "room_system.hpp"
#include "../ui/ui.h"
#include "../models/character/player.hpp"
#include "../models/character/monster.hpp"

class GameEngine {
    public:
        GameEngine(string player, int rows, int cols);
        ~GameEngine();
        void render(GtkApplication *app);
        void launch();

    private:
        UI* ui;
        RoomSystem* roomSys;
        Player player;
        Monster monster;
        int rows;
        int cols;
        Position enter;
        Position exit;
};

#endif