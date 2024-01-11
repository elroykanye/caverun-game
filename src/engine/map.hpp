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

/**
 * @brief Represents a map consisting of rooms.
 */
class Map {
public:
    /**
     * @brief Default constructor for Map.
     */
    Map();

    /**
     * @brief Constructor for Map with specified number of rows and columns.
     *
     * @param rows The number of rows in the map.
     * @param cols The number of columns in the map.
     */
    Map(int rows, int cols);

    /**
     * @brief Destructor for Map.
     */
    ~Map();

    /**
     * @brief Retrieves the 2D vector representing the map.
     *
     * @return A 2D vector of RoomPtr representing the map.
     */
    vector<vector<RoomPtr>> getMap();

    /**
     * @brief Retrieves a flattened version of the map.
     *
     * @return A vector of Room* representing the flattened map.
     */
    vector<Room*> getFlatMap();

    /**
     * @brief Retrieves the room at the specified position.
     *
     * @param pos The position of the room to retrieve.
     * @return The RoomPtr at the specified position.
     * @throws std::out_of_range if the position is out of bounds.
     */
    RoomPtr getRoom(const Position &pos);

    /**
     * @brief Resets the visited status of all rooms in the map.
     */
    void resetRooms();

private:
    vector<vector<RoomPtr>> grid; // The 2D vector representing the map.
    int size;                     // The total number of rooms in the map.
    int rows;                     // The number of rows in the map.
    int cols;                     // The number of columns in the map.
};

#endif
