#include "Match.h"
#include "VectorPair.h"
class HistoryMatch : public Match
{
private:
        VectorPair v[2];
        Vector<VectorPair> cauThuDoiA;
        Vector<VectorPair> cauThuDoiB;
public:
    HistoryMatch();
    ~HistoryMatch();
    void showHistoryMatch();
};

