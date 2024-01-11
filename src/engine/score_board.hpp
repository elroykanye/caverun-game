#if !defined(SCORE_BOARD_H)
#define SCORE_BOARD_H

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Represents a score entry for a player, containing the player's name and score.
 */
struct ScoreEntry {
    string player;  // The name of the player.
    long score;     // The score achieved by the player.
};

/**
 * @brief Represents a scoreboard that manages and displays score entries.
 */
class ScoreBoard {
public:
    /**
     * @brief Constructs a ScoreBoard object.
     */
    ScoreBoard();

    /**
     * @brief Loads scores from a file into the scoreboard.
     * 
     * The scores are loaded from a tab-separated values (TSV) file,
     * where each line represents a score entry with the player's name
     * and score. The file path is determined by the 'filename' member
     * variable.
     * 
     * @return True if the scores are successfully loaded, false otherwise.
     */
    bool loadScores();

    /**
     * @brief Adds a score entry to the scoreboard.
     * 
     * @param entry The score entry to be added.
     */
    void addScore(const ScoreEntry& entry);

    /**
     * @brief Retrieves the scores from the scoreboard.
     * 
     * @return A vector containing all the score entries in the scoreboard.
     */
    vector<ScoreEntry> getScores() const;

    /**
     * @brief Converts the scoreboard to a string representation.
     * 
     * The scoreboard is converted to a string representation in the
     * following format:
     * 
     * Player 1: Score 1
     * Player 2: Score 2
     * ...
     * 
     * @return A string containing the scoreboard information.
     */
    string toString() const;

private:
    string filename = "scores.tsv";  // The name of the file to load scores from.
    vector<ScoreEntry> scores;       // The collection of score entries stored in the scoreboard.
};

#endif // SCORE_BOARD_H
