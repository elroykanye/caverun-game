#include "player.hpp"

Player::Player() {
}

Player::Player(string name, Position pos) {
    position = pos;
    nextPosition = pos;
    name = name;
}

bool Player::isPoisoned() {
    return damage.type == DamageType::NONE;
}

string Player::getHealthLabel() { return "Health Points: " + to_string(health); }
string Player::getMovesLabel() { return "Moves: " + to_string(moves); }
string Player::getNameLabel() { return "Player: " + name; }
Position Player::getPosition() const { return position; }
Position Player::getNextPosition() const { return nextPosition; }
void Player::updateHealth(int val) {
    health += val;
    if (health > 100) health = 100;
}
int Player::getHealth() const { return health; }
int Player::getMoves() const { return moves; }
void Player::setMoves(int moves) { this->moves = moves; }
void Player::setNextPosition(Position next) { 
    nextPosition = next;
}


Position Player::sense(const Position &other, int x, int y) {
    vector<Position> adjs = position.getAdjacents(x, y);
    for (Position& adj: adjs) {
        if (adj.equals(other)) return adj;
    }
    nextPosition = position;
    return position;
}

void Player::move(const Position &next) {
    Position nextNC = const_cast<Position&>(next);
    if (!nextNC.equals(position)) {
        position.setX(next.getX());  
        position.setY(next.getY());
        this->moves--;
        this->totalMoves++;
    }
}


