#include "room_poison.hpp"

PoisonRoom::PoisonRoom() {
    int moves = 1 + rand() % 10;
    int value = (int) (1 + rand() % 8);
    this->damage = { moves, value, DamageType::POISON };
}

bool PoisonRoom::isPoison() const { return true; }
RoomVisit PoisonRoom::visit(Player &player) {
    Room::visit(player);
    if (player.isPoisoned()) {
        player.updateHealth(player.damage.value * -1);
        player.damage.moves += damage.moves;
        player.damage.value = damage.value;
    } else player.damage = damage;

    string str = "[Poison - " + to_string(damage.value) + " health - " + to_string(damage.moves) + " moves]";
    return {"You just got into a poisoned room! " + str, Severity::WARN };
}
