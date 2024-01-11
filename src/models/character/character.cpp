#include "character.hpp"
Character::Character() {}
Character::Character(const Position &pos): position(pos), original(pos) {
}

void Character::move(const Position &next) {
    Direction dir = this->position.getDirectionTo(next);
    this->position.update(dir);  
}
Position Character::sense(const Position &other, int x, int y) {
    return position;
}
void Character::runTurn() {}

Position Character::getPosition() const { return position; }
void Character::setPosition(const Position &position) {
    this->original = position;
    this->position = position;
}
void Character::resetPosition() {
    this->position.setX(original.getX());
    this->position.setY(original.getY());
}
