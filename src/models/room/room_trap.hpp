#ifndef ROOM_TRAP_H
#define ROOM_TRAP_H

#include "room.hpp"

class TrapRoom: public Room {
    public:
        TrapRoom();
        bool isTrap() const override;
        RoomVisit visit(Player &player) override;

    private:
        Damage damage;
};

#endif
