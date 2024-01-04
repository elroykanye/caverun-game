#ifndef ROOM_BONUS_H
#define ROOM_BONUS_H

#include "room.hpp"

class BonusRoom: public Room {
    public:
        BonusRoom();
        bool isBonus() const override;
        RoomVisit visit(Player &player) override;
    
    private:
        Bonus bonus;
};

#endif