#include "position.hpp"

using namespace std;
Position::Position() {
    x = 0;
    y = 0;
    rows = 6;
    vect = { x, rows - 1 -y };
}

Position::Position(int x, int y, int rows = 6) {
    this->x = x;
    this->y = y;
    this->rows = rows;
    this->vect = { x, rows - 1 - y };
}
Position::Position(const Vect &vect, int rows) {
    this->y = rows - 1 - vect.i;
    this->x = vect.j; // todo check later
    this->vect = vect;
}
Position::Position(const Position& other) {
    x = other.x;
    y = other.y;
    rows = other.rows;
    vect = other.vect;
}

Position::~Position() {}

int Position::getX() const { return x; }
int Position::getY() const { return y; }
void Position::setX(int x) { this->x = x; }
void Position::setY(int y) { this->y = y; }

void Position::update(const Direction &direction) {
    
    switch (direction) {
        case Direction::UP: y++; break;
        case Direction::DOWN: y--; break;
        case Direction::LEFT: x--; break;
        case Direction::RIGHT: x++; break;
        default: break;
    }
}
void Position::display() {
    string str = "[x = " + to_string(x) + ", y = " + to_string(y) + ", i = " + to_string(vect.i) + ", j = " + to_string(vect.j) +  "]";
    cout << str << endl;
}

Vect Position::getVect() const { return this->vect; }

bool Position::isOrigin() { return this->x == 0 && this->y == 0; }

bool Position::equals(const Position &other) {
    bool val = getX() == other.getX() && getY() == other.getY();
    return val;
}

Direction Position::getDirectionTo(const Position &other) {
    int dx = getX() - other.getX();
    int dy = getY() - other.getY();
    bool val = abs(dx) == 0 && abs(dy) == 1 || abs(dx) == 1 && abs(dy) == 0;

    if (dx == 0 && dy == 1) {
        return Direction::UP;
    } else if (dx == 0 && dy == -1) {
        return Direction::DOWN;
    } else if (dx == -1 && dy == 0) {
        return Direction::RIGHT;
    } else if (dx == 1 && dy == 0) {
        return Direction::LEFT;
    } else {
        return Direction::STATIC;
    }
}

vector<Position> Position::getAdjacents(int maxX, int maxY) const {
    vector<Position> vec;
    vec.reserve(4);
    if (getX() - 1 >= 0) {
        Position adj(getX() - 1, getY(), rows);
        vec.push_back(adj);
    }
    if (getX() + 1  <= maxX) {
        Position adj(getX() + 1, getY(), rows);
        vec.push_back(adj);

    }
    if (getY() - 1  >= 0) {
        Position adj(getX(), getY() - 1, rows);
        vec.push_back(adj);
    }
    if (getY() + 1  <= maxY) {
        Position adj(getX(), getY() + 1, rows);
        vec.push_back(adj);
    }
    return vec;
}
double Position::distance(const Position &other) const {
    int dx = other.getX() - getX();
    int dy = other.getY() - getY();
    return sqrt((dx * dx) + (dy * dy));
}
Position Position::getShortestAdjacentTo(const Position &other, int maxX, int maxY) const {
    vector<Position> adjs = getAdjacents(maxX, maxY);
    map<int, vector<Position>> distsAdjs;
    Position curr(x, y, rows);
    if (adjs.empty()) return curr;
    int minDist = numeric_limits<int>::max();
    for (const Position& adj: adjs) {
        int dist = adj.distance(other);
        distsAdjs[dist].push_back(adj);
        
        if (dist < minDist) {
            minDist = dist;
        }
    }
    
    srand(time(NULL));
    int closest = rand() % distsAdjs[minDist].size();
    for (Position& adj: distsAdjs[minDist]) {
        if (adj.equals(other)) return adj;
    }
    
    return distsAdjs[minDist][closest];
}
