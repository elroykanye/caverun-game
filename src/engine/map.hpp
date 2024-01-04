#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <vector>
#include <random>
#include <iostream>
#include <time.h>

#include "../models/room/room_poison.hpp"
#include "../models/room/room_bonus.hpp"
#include "../models/room/room_trap.hpp"

using namespace std;
using RoomPtr = Room*;

class Map {
    public:
        Map();
        Map(int rows, int cols);
        ~Map();
        vector<vector<RoomPtr>> getMap();
        vector<Room*> getFlatMap();
        RoomPtr getRoom(const Position &pos);

    private:
        vector<vector<RoomPtr>> grid;
        int size;
};

#endif