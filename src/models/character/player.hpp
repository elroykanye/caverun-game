#ifndef PLAYER_H
#define PLAYER_H

#include "character.hpp"
#include <string>

using namespace std;

class Player: public Character {
    public:
        Player();
        Player(string name, Position pos);
        bool isPoisoned();
        string getHealthLabel();
        string getMovesLabel();
        string getNameLabel();
        Position getPosition() const override;
        Position getNextPosition() const;
        void updateHealth(int val);
        int getHealth() const;
        int getMoves() const;
        void setMoves(int moves);
        void setNextPosition(Position next);
        Position sense(const Position &other, int x, int y) override;
        void move(const Position &next) override;

        Damage damage{ 0, 0, DamageType::NONE };

    private:
        string name = "P";
        int health = 100;
        int moves = 2;
        int totalMoves = 0;
        Position position;
        Position nextPosition;

    friend class Room;
};

#endif