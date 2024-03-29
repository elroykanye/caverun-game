#ifndef MONSTER_H
#define MONSTER_H

#include "character.hpp"

class Monster: public Character {
    public:
        Monster();
        Monster(const Position& pos);
        Position sense(const Position &other, int x, int y) override;
        void move(const Position &next) override;
};

#endif