#ifndef ROOM_SYSTEM_H
#define ROOM_SYSTEM_H

#include <cstdlib>
#include <vector>
#include "map.hpp"

/**
 * @brief The RoomSystem class represents the system for managing the game rooms.
 */
class RoomSystem {
public:
    /**
     * @brief Default constructor for RoomSystem.
     */
    RoomSystem();

    /**
     * @brief Constructor for RoomSystem with specified number of rows and columns.
     *
     * @param rows The number of rows in the game grid.
     * @param cols The number of columns in the game grid.
     */
    RoomSystem(int rows, int cols);

    /**
     * @brief Destructor for RoomSystem.
     */
    ~RoomSystem();

    /**
     * @brief Retrieves the game map.
     *
     * @return A pointer to the Map object representing the game map.
     */
    Map* getMap();

private:
    Map map; // The game map.
};

#endif