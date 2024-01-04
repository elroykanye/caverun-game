#ifndef CHARACTER_H
#define CHARACTER_H

#include "../position.hpp"

class Character {
    public:
        virtual Position sense(const Position &other, int x, int y);
        virtual void move(const Position &next);
        virtual void runTurn();
        virtual Position getPosition() const;

    private:
        Position position;
};

#endif // CHARACTER_H
