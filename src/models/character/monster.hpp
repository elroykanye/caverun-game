#ifndef MONSTER_H
#define MONSTER_H

#include "character.hpp"

class Monster: public Character {
    public:
        Monster();
        Monster(Position pos);
        Position sense(const Position &other, int x, int y) override;
        void move(const Position &next) override;
        Position getPosition() const override;

    private:
        int health = 100;
        int poisoned = 0;
        Position position;
};

#endif