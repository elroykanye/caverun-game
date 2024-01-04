#include "room.hpp"

Room::Room() {
}

bool Room::isNormal() const {return !isTrap() && !isBonus() && !isPoison(); }
bool Room::isTrap() const { return false; }
bool Room::isBonus() const { return false; }
bool Room::isPoison() const { return false; }
bool Room::isVisited() const { return visited; }
void Room::setVisited(bool visited) { this->visited = visited; }

RoomVisit Room::visit(Player &player) {
    setVisited(true);
    return {"You just got into a normal room!", Severity::PRIMARY};
}

Position Room::getPosition() const { return this->position;}
void Room::setPosition(const Position &position) { this->position = position; }
