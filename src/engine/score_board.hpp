#if !defined(SCORE_BOARD_H)
#define SCORE_BOARD_H

#include <string>
#include <vector>

using namespace std;

struct ScoreEntry {
    string player;
    long score;
};

class ScoreBoard {
    public:
        ScoreBoard();
        bool loadScores();
        void addScore(const ScoreEntry& entry);
        vector<ScoreEntry> getScores() const;
        string toString() const;

    private:
        string filename = "scores.tsv";
        vector<ScoreEntry> scores;
};


#endif // SCORE_BOARD_H
