#include "Match.h"

class HistoryMatch : public Match
{
private:
    int numGoalTeam1, numGoalTeam2;

public:
    HistoryMatch();
    HistoryMatch(Match, int, int);
    ~HistoryMatch();
    void showHistoryMatch();
    void saveHistoryMatchToFile(ofstream &);
    void updateHistoryMatch();
    void updateGoalandLostGoalofTeam(String, String, String);
    void showHMbydate(String);
    void showHMbyidoneteam(String);
    void showHMbyidtwoteam(String, String);
    void showHMbyidround(String);
};
