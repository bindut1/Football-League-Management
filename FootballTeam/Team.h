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
    int point;
    int difference;
public: 
    Team();
    Team(string,Coach,int,int,int,int);
    ~Team();
    void createNewFootballTeam();
    string getIdTeam();
    void setIdTeam(string);
    void showAllMemberOfTeam();
    void showALLInforOfTeam();
    void addPlayer(Player&);
    void addCoach(Coach&);
    void findPlayerByName();
    void findPlayerByNameFootballTeam();
    Vector<Player> getListPlayerByNameFootballTeam(string);
    void findPlayerById();
    void deletePlayerById(ifstream&,ofstream&);
    void saveTeamToFile(ofstream&,int = 0);
    string getSizeTeamFromFile();
    Coach getCoachByNameFootballTeam(string);
    // Chuan hoa ten -> ngUyen van a -> Nguyen Van A
    string standardizeName(string);
    void showRankOfTeam();
    void showInforOfCoach();
    void testFile();
    int string_to_int(string);
    string getNameFootballTeam();
    Team findTeamByName();
    void setListMember(Vector<Player>);
    // void showListMatch();
    // void showHistoryMatch();
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