#include "monster.hpp"

Monster::Monster(){}
Monster::Monster(const Position& pos): Character(pos) {
}

Position Monster::sense(const Position &other, int x, int y) {
    return position.getShortestAdjacentTo(other, x, y);
}
void Monster::move(const Position &next) {
    position.setX(next.getX());  
    position.setY(next.getY());
}
