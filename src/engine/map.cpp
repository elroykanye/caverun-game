#include "map.hpp"

Map::Map() {}
Map::Map(int rows, int cols) {
    srand (time(NULL));
    grid.resize(rows, vector<RoomPtr>(cols));

    int size = rows * cols;
    int average = (int) (rows + cols) / 2;
    int step = (int) average / 2;
    int ub = average + step;
    int lb = average - step;
    if (lb < 0) lb = 0;
    if (ub >= size && ub > 0) ub = size - 1;
    int numberOfPoison = (rand() % (ub - lb + 1)) + lb + 1;
    int numberOfTrap = (rand() % (ub - lb + 1)) + lb + 1;
    int numberOfBonus = (int) ((rand() % (ub - lb + 1)) + lb) / 2;
    
    for (int yi = 0; yi < grid.size(); yi++) {
        for (int xi = 0; xi < grid[yi].size(); xi++) {
            RoomPtr room;
            int roomType = rand() % average;
            if (roomType == 0 && numberOfPoison > 0) { // poison
                room = new PoisonRoom();
                numberOfPoison--;
            } else if (roomType == 1 && numberOfTrap > 0) { // trap
                room = new TrapRoom();
                numberOfTrap--;
            } else if (roomType == 2 && numberOfBonus > 0) { // bonus
                room = new BonusRoom();
                numberOfBonus--;
            } else {
                room = new Room();
            }
            
            Vect vect = { yi, xi };
            Position pos(vect, grid.size());

            if (pos.isOrigin()) {
                room = new Room();
            }

            room->setPosition(pos);
            grid[yi].at(xi) = room;
        }
    }
    this->size = size;
};
Map::~Map() {
    for (const auto& row : grid) {
        for (RoomPtr room : row) {
            //delete room;
        }
    }
}

vector<vector<RoomPtr>> Map::getMap() { return grid; }

vector<Room*> Map::getFlatMap() {
    vector<Room*> flatMap;
    flatMap.resize(this->size);
    int curr = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            flatMap.at(curr) = grid[i][j];
            curr++;
        }
    }
    return flatMap;
}

RoomPtr Map::getRoom(const Position &pos) {
    int row = pos.getVect().j;
    int col = pos.getVect().i;

    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size()) {
        // Index out of bounds, handle the error here
        // For example, you can throw an exception or return a default room
        throw std::out_of_range("Index out of bounds");
    }
    return grid[row][col];
}