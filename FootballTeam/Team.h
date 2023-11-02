#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Coach.h"
#include "../CTDL/Vector.cpp"
using namespace std;

#ifndef Team_H
#define Team_H

class Team
{
private:
    string nameFootballTeam;
    Vector<Player> mainTeam;
    Vector<Player> supportTeam;
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
    // void showMainTeam();
    // void showSupportTeam();
    // void showAllMemberOfTeam();
    // void findPlayerByName(string);
    // void showRankOfTeam();
    // void showInforOfCoach();
    // void showListMatch();
    // void showHistoryMatch();
    string getNameFootballTeam();
    // int getRank();
    // int getNumberGoal();
    // int getNumberLoseGoal();
    // int getPoint();
    // int getDifference();
    // Coach getCoach();
    void setNameFootballTeam(string);
    // void setRank(int);
    // void setNumberGoal(int);
    // void setNumberLoseGoal(int);
    // void setPoint(int);
    // void changePoint(int);
    // void setDifference(int);
    // Coach getCoach(int);
};

#endif 