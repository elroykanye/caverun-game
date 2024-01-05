#include "room_trap.hpp"

TrapRoom::TrapRoom() {
    int moves = 1 + rand() % 10;
    int value = (int) (1 + rand() % 10) * 2.5;
    damage = { moves, value };
}

bool TrapRoom::isTrap() const { return true; }
RoomVisit TrapRoom::visit(Player &player) {
    Room::visit(player);
    player.updateHealth(damage.value * -1);

    string str = "[Trap - " + to_string(damage.value) + " health ]";
    return {"You just got into a trap room! " + str, Severity::WARN};
}
