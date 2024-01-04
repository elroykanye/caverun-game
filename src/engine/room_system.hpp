#ifndef ROOM_SYSTEM_H
#define ROOM_SYSTEM_H

#include <cstdlib>
#include <vector>
#include "map.hpp"


using namespace std;

class RoomSystem {
    public:
        RoomSystem();
        RoomSystem(int rows, int cols);
        ~RoomSystem();
        Map* getMap();

    private:
        Map map;

};

#endif