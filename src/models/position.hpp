#ifndef POSITION_H
#define POSITION_H

#include "structs.hpp"

using namespace std;

/**
 * @brief Enumeration defining different directions.
 */
enum Direction {
    UP,     // Up direction
    DOWN,   // Down direction
    LEFT,   // Left direction
    RIGHT,  // Right direction
    STATIC  // Static direction (no movement)
};

/**
 * @brief The Position class represents a position in a grid.
 */
class Position {
public:
    /**
     * @brief Default constructor for Position.
     */
    Position();

    /**
     * @brief Constructor for Position with specified x and y coordinates and the number of rows in the grid.
     *
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     * @param rows The number of rows in the grid.
     */
    Position(int x, int y, int rows);

    /**
     * @brief Constructor for Position with a Vect object and the number of rows in the grid.
     *
     * @param vect The Vect object representing the position.
     * @param rows The number of rows in the grid.
     */
    Position(const Vect &vect, int rows);

    /**
     * @brief Copy constructor for Position.
     *
     * @param other The Position object to copy.
     */
    Position(const Position& other);

    /**
     * @brief Destructor for Position.
     */
    ~Position();

    /**
     * @brief Sets the x-coordinate of the position.
     *
     * @param x The x-coordinate to set.
     */
    void setX(int x);

    /**
     * @brief Sets the y-coordinate of the position.
     *
     * @param y The y-coordinate to set.
     */
    void setY(int y);

    /**
     * @brief Retrieves the x-coordinate of the position.
     *
     * @return The x-coordinate of the position.
     */
    int getX() const;

    /**
     * @brief Retrieves the y-coordinate of the position.
     *
     * @return The y-coordinate of the position.
     */
    int getY() const;

    /**
     * @brief Retrieves the Vect object representing the position.
     *
     * @return The Vect object representing the position.
     */
    Vect getVect() const;

    /**
     * @brief Checks if the position is the origin (0, 0).
     *
     * @return True if the position is the origin, false otherwise.
     */
    bool isOrigin();

    /**
     * @brief Updates the position based on the given direction.
     *
     * @param direction The direction of the update.
     */
    void update(const Direction &direction);

    /**
     * @brief Displays the position coordinates.
     */
    void display() const;

    /**
     * @brief Checks if the position is equal to the other position.
     *
     * @param other The other position to compare.
     * @return True if the positions are equal, false otherwise.
     */
    bool operator==(const Position &other) const;

    /**
     * @brief Checks if the position is not equal to the other position.
     *
     * @param other The other position to compare.
     * @return True if the positions are not equal, false otherwise.
     */
    bool operator!=(const Position &other) const;

    /**
     * @brief Calculates the distance between the current position and the other position.
     *
     * @param other The other position.
     * @return The distance between the positions.
     */
    double distance(const Position &other) const;

    /**
     * @brief Retrieves the direction from the current position to the other position.
     *
     * @param other The other position.
     * @return The direction from the current position to the other position.
     */
    Direction getDirectionTo(const Position &other);

    /**
     * @brief Retrieves the adjacent positions to the current position on the grid.
     *
     * @param maxX The maximum x-coordinate value.
     * @param maxY The maximum y-coordinate value.
     * @return A vector of adjacent positions.
     */
    vector<Position> getAdjacents(int maxX, int maxY) const;

    /**
     * @brief Retrieves the shortest adjacent position to the given position.
     *
     * @param other The other position.
     * @param maxX The maximum x-coordinate value.
     * @param maxY The maximum y-coordinate value.
     * @return The shortest adjacent position to the given position.
     */
    Position getShortestAdjacentTo(const Position &other, int maxX, int maxY) const;

    /**
     * @brief Retrieves the origin position (0, 0).
     *
     * @return The origin position.
     */
    static Position origin();

private:
    int x = 0;      // X-coordinate of the position
    int y = 0;      // Y-coordinateof the position
    int rows;      // Number of rows in the grid
    Vect vect;     // Vect object representing the position
};

#endif // POSITION_H