#include "score_board.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>

ScoreBoard::ScoreBoard() {
    this->loadScores();
}

bool ScoreBoard::loadScores() {
    ifstream file(filename);

    if(!file.is_open()) {
        ofstream createFile(filename);
        if (!createFile.is_open()) return false;

        createFile.close();
        file.open(filename);
        if (!file.is_open()) return false;
    }

    scores.clear();

    string line;
    while (getline(file, line)) {
        std::vector<std::string> fields;
        size_t startPos = 0;
        size_t tabPos = line.find('\t');
        while (tabPos != std::string::npos) {
            fields.push_back(line.substr(startPos, tabPos - startPos));
            startPos = tabPos + 1;
            tabPos = line.find('\t', startPos);
        }
        fields.push_back(line.substr(startPos));

        // Process the fields
        if (fields.size() >= 2) {
            string player = fields[0];
            double score = stod(fields[1]);

            ScoreEntry entry;
            entry.player = player;
            entry.score = score;
            scores.push_back(entry);
        }
    }

    file.close();

    sort(scores.begin(), scores.end(), [](ScoreEntry& a, ScoreEntry& b){
        return a.score > b.score;
    });
    return true;
}

void ScoreBoard::addScore(const ScoreEntry& entry) {
    if (entry.score == 0)  return;
    
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        file << entry.player << "\t" << entry.score << "\n";
        file.close();
        this->loadScores();
    }
}

vector<ScoreEntry> ScoreBoard::getScores() const {
    return scores;
}

string ScoreBoard::toString() const {
    string str = "Highest Scores\n";
    int i = 0;
    for (const ScoreEntry& entry: scores) {
        if (i >= 10) break;
        str += entry.player + "\t[ score = " + to_string(entry.score) + " ]\n"; 
        i++;
    }
    return str;
}
