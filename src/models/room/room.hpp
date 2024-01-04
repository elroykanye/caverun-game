#ifndef ROOM_H
#define ROOM_H

#include "../position.hpp"
#include "../character/player.hpp"

struct RoomVisit {
    string message;
    Severity result;
};

class Room {
    public:
        Room();
        virtual RoomVisit visit(Player &player);
        Position getPosition() const;
        void setPosition(const Position &position);

        bool isNormal() const;
        virtual bool isPoison() const;
        virtual bool isTrap() const;
        virtual bool isBonus() const;
        virtual bool isVisited() const;
        virtual void setVisited(bool visited);

    private:
        Position position;
        bool visited = false;
};

#endif // ROOM_H
