#ifndef POSITION_H
#define POSITION_H

#include "structs.hpp"

using namespace std;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STATIC
};

class Position {
    public:
        Position();
        Position(int x, int y, int rows);
        Position(const Vect &vect, int rows);
        Position(const Position& other);
        ~Position();
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        Vect getVect() const;
        bool isOrigin();
        void update(const Direction &direction);
        void display();
        bool equals(const Position &other);
        double distance(const Position &other) const;
        Direction getDirectionTo(const Position &other);
        vector<Position> getAdjacents(int maxX, int maxY) const;
        Position getShortestAdjacentTo(const Position &other, int maxX, int maxY) const;

    private:
        int x = 0;
        int y = 0;
        int rows;
        Vect vect;
};

#endif // POSITION_H
