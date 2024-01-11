#ifndef CHARACTER_H
#define CHARACTER_H

#include "../position.hpp"

/**
 * @brief The Character class represents a character in a game.
 */
class Character {
public:
    /**
     * @brief Default constructor for Character.
     */
    Character();

    /**
     * @brief Constructor for Character with a specified position.
     *
     * @param pos The initial position of the character.
     */
    Character(const Position& pos);

    /**
     * @brief Sense the position of another character and determine the next position to move.
     *
     * @param other The position of the other character.
     * @param x The maximum x-coordinate value.
     * @param y The maximum y-coordinate value.
     * @return The next position to move as determined by the character's senses.
     */
    virtual Position sense(const Position &other, int x, int y);

    /**
     * @brief Move the character to the specified position.
     *
     * @param next The position to move to.
     */
    virtual void move(const Position &next);

    /**
     * @brief Perform a turn for the character.
     */
    virtual void runTurn();

    /**
     * @brief Retrieve the current position of the character.
     *
     * @return The current position of the character.
     */
    Position getPosition() const;

    /**
     * @brief Set the current position of the character.
     *
     * @param position The position to set.
     */
    void setPosition(const Position &position);

    /**
     * @brief Set the original position of the character.
     *
     * @param position The original position to set.
     */
    void setOriginalPosition(const Position &position);

    /**
     * @brief Reset the character's position to the original position.
     */
    void resetPosition();

protected:
    Position position;        // Current position of the character
    Position original;        // Original position of the character
    Position nextPosition;    // Next position to move
};

#endif // CHARACTER_H