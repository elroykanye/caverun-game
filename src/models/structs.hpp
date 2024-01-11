#include <vector>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <map>
#include <string>

/**
 * @brief Enumeration defining different severity levels.
 */
enum Severity {
    PRIMARY, // Primary severity level
    WARN,    // Warning severity level
    DANGER,  // Danger severity level
    SUCCESS  // Success severity level
};

/**
 * @brief Enumeration defining different types of damage.
 */
enum DamageType {
    POISON, // Poison damage type
    TRAP,   // Trap damage type
    NONE    // No damage type
};

/**
 * @brief Structure representing damage information.
 */
struct Damage {
    int moves;       // Number of moves required to trigger the damage
    int value;       // Value of the damage
    DamageType type; // Type of the damage
};

/**
 * @brief Enumeration defining different types of bonuses.
 */
enum BonusType {
    HEALTH, // Health bonus type
    CURE    // Cure bonus type
};

/**
 * @brief Structure representing bonus information.
 */
struct Bonus {
    BonusType type; // Type of the bonus
    int value;      // Value of the bonus
};

/**
 * @brief Structure representing a 2D vector.
 */
struct Vect {
    int i; // X coordinate
    int j; // Y coordinate
};
