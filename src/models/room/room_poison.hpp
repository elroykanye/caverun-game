#ifndef ROOM_POISON_H
#define ROOM_POISON_H

#include "room.hpp"

class PoisonRoom: public Room {
    public:
        PoisonRoom();
        bool isPoison() const override;
        RoomVisit visit(Player &player) override;

    private:
        Damage damage;
};

#endif
