#ifndef ROOM_H
#define ROOM_H

#include "../position.hpp"
#include "../character/player.hpp"

/**
 * @brief Structure representing the result of a room visit.
 */
struct RoomVisit {
    string message;  // Message describing the visit result
    Severity result; // Severity level of the visit result
};

/**
 * @brief The Room class represents a room in a game.
 */
class Room {
public:
    /**
     * @brief Default constructor for Room.
     */
    Room();

    /**
     * @brief Visits the room and returns the visit result for the given player.
     *
     * @param player The player visiting the room.
     * @return The visit result as a RoomVisit object.
     */
    virtual RoomVisit visit(Player &player);

    /**
     * @brief Retrieves the position of the room.
     *
     * @return The position of the room.
     */
    Position getPosition() const;

    /**
     * @brief Sets the position of the room.
     *
     * @param position The position to set.
     */
    void setPosition(const Position &position);

    /**
     * @brief Checks if the room is a normal room.
     *
     * @return True if the room is a normal room, false otherwise.
     */
    bool isNormal() const;

    /**
     * @brief Checks if the room is a poison room.
     *
     * @return True if the room is a poison room, false otherwise.
     */
    virtual bool isPoison() const;

    /**
     * @brief Checks if the room is a trap room.
     *
     * @return True if the room is a trap room, false otherwise.
     */
    virtual bool isTrap() const;

    /**
     * @brief Checks if the room is a bonus room.
     *
     * @return True if the room is a bonus room, false otherwise.
     */
    virtual bool isBonus() const;

    /**
     * @brief Checks if the room has been visited.
     *
     * @return True if the room has been visited, false otherwise.
     */
    virtual bool isVisited() const;

    /**
     * @brief Sets the visited status of the room.
     *
     * @param visited The visited status to set.
     */
    virtual void setVisited(bool visited);

private:
    Position position; // Position of the room
    bool visited = false; // Visited status of the room
};

#endif // ROOM_H