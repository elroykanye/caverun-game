#include "room_bonus.hpp"

BonusRoom::BonusRoom() {
    int type = rand() % 2;
    int value = (1 + rand() % 10) * 2;

    this->bonus = { type == 0 ? BonusType::CURE : BonusType::HEALTH, value };
}

bool BonusRoom::isBonus() const { return true; }
RoomVisit BonusRoom::visit(Player &player) {
    Room::visit(player);
    if (bonus.type == BonusType::CURE) {
        player.damage = { 0, 0, DamageType::NONE };
    } else {
        player.updateHealth(bonus.value);
    }
    string bonusStr = bonus.type == BonusType::CURE ? "cure" : "health";
    string str = "[" + bonusStr +  " - " + to_string(bonus.value) + "]";
    return {"You just got a bonus! " + str, Severity::SUCCESS};
}