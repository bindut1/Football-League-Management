#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Coach.h"
#include "../CTDL/Vector.h"
using namespace std;

#ifndef Team_H
#define Team_H

class Team
{
private:
    string idTeamFootball;
    string nameFootballTeam;
    Vector<Player> listMember;
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
    void createNewFootballTeam();
    string getIdTeam();
    void setIdTeam(int);
    void showAllMemberOfTeam();
    void showALLInforOfTeam();
    void addPlayer(Player&);
    void addCoach(Coach&);
    void findPlayerByName();
    void findPlayerByNameFootballTeam();
    void findPlayerById();
    void deletePlayerById(ifstream&,ofstream&);
    // Chuan hoa ten -> ngUyen van a -> Nguyen Van A
    string standardizeName(string);
    void showRankOfTeam();
    void showInforOfCoach();
    void testFile();
    int string_to_int(string);
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