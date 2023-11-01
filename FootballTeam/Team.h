#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Coach.h"
#include "../CTDL/LLDB.h"
#include "../CTDL/LLDB.cpp"
#include "../CTDL/LLDB.cpp"
using namespace std;



class Team
{
private:
    node<Player>* head = NULL;
    string nameFootballTeam;
    LLDB<Player> mainTeam;
    LLDB<Player> supportTeam;
    Coach coach;
    int rank;
    int numberGoal;
    int numberLoseGoal;
    string homeYard;
    int point;
    int difference;
public:
    Team();
    Team(string,Coach,int,int,int,string,int,int);
    ~Team();
    void showMainTeam();
    void showSupportTeam();
    void showAllMemberOfTeam();
    void findPlayerByName(string);
    void showRankOfTeam();
    void showInforOfCoach();
    void showListMatch();
    void showHistoryMatch();
};

