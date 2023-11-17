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
};
