#include "HistoryMatch.h"
#include <iostream>
#include <iomanip>
using namespace std;

HistoryMatch::HistoryMatch()
{
}
HistoryMatch::HistoryMatch(Match m, int g1, int g2)
    : Match(m)
{
    this->numGoalTeam1 = g1;
    this->numGoalTeam2 = g2;
}
HistoryMatch::~HistoryMatch()
{
}
void HistoryMatch::showHistoryMatch()
{
    Team t, t1, t2;
    t1 = t.getTeamById(this->getIdTeam1());
    t2 = t.getTeamById(this->getIdTeam2());
    cout << "Vong dau so: " << this->getIdRound() << endl;
    cout << left << setw(30) << t1.getNameFootballTeam() << setw(15) << this->numGoalTeam1 << setw(15) << "-" << setw(50) << this->numGoalTeam2 << t2.getNameFootballTeam() << endl;
    cout << "Ngay thi dau: " << this->getDate() << endl;
    cout << "Dia chi thi dau: " << this->getAddress() << endl;
}
void HistoryMatch::saveHistoryMatchToFile(ofstream &o)
{
    ifstream f("HistoryMatch.txt");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem";
        f.close();
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(15) << this->getIdRound() + "," << setw(20) << this->getIdTeam1() + "," << setw(20) << String::tostring(this->numGoalTeam1) + "," << setw(20) << this->getIdTeam2() + "," << setw(20) << String::tostring(this->numGoalTeam2) + "," << setw(20) << this->getTime() + "," << setw(25) << this->getDate() + "," << setw(20) << this->getAddress();
    }
}