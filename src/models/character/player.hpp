#ifndef PLAYER_H
#define PLAYER_H

#include "character.hpp"
#include <string>

using namespace std;

class Player: public Character {
    public:
        Player();
        Player(const Position& pos);
        bool isPoisoned();
        string getHealthLabel();
        string getMovesLabel();
        string getNameLabel();
        string getName() const;
        void setName(string name);
        Position getNextPosition() const;
        void updateHealth(int val);
        int getHealth() const;
        int getMoves() const;
        long getScore(double boardsize) const;
        int getTotalMoves() const;
        void setMoves(int moves);
        void setNextPosition(Position next);
        bool isDone();
        void setDone(bool done);
        Position sense(const Position &other, int x, int y) override;
        void move(const Position &next) override;

        Damage damage{ 0, 0, DamageType::NONE };

    private:
        string name = "P";
        int health = 100;
        int moves = 2;
        int totalMoves = 0;
        bool done = false;
        //Position position;
        Position nextPosition;

    friend class Room;
};

#endif