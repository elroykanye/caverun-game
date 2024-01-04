#include "character.hpp"

void Character::move(const Position &next) {
    Direction dir = this->position.getDirectionTo(next);
    this->position.update(dir);  
}
Position Character::sense(const Position &other, int x, int y) {
    return position;
}
void Character::runTurn() {}
Position Character::getPosition() const { return position; }