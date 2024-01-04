#include "room_system.hpp"

RoomSystem::RoomSystem(int rows, int cols) {
    map = Map(rows, cols);
};

RoomSystem::~RoomSystem() {
    
}

Map* RoomSystem::getMap() { return &map; }
