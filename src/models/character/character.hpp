#ifndef CHARACTER_H
#define CHARACTER_H

#include "../position.hpp"

class Character {
    public:
        Character();
        Character(const Position& pos);
        virtual Position sense(const Position &other, int x, int y);
        virtual void move(const Position &next);
        virtual void runTurn();
        Position getPosition() const;
        void setPosition(const Position &position);
        void resetPosition();

    protected:
        Position position;
        Position original;
};

#endif // CHARACTER_H
