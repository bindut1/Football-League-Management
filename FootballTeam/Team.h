#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Coach.h"
#include "../CTDL/Vector.h"
#include <String.h>
using namespace std;

#ifndef Team_H
#define Team_H

class Team
{
private:
    String idTeamFootball;
    String nameFootballTeam;
    Vector<Player> listMember;
    Coach coach;
    int rank;
    int numberGoal;
    int numberLoseGoal;
    int point;
    int difference;
public: 
    Team();
    Team(String,Coach,int,int,int,int);
    ~Team();
    void createNewFootballTeam();
    String getIdTeam();
    void setIdTeam(String);
    void showAllMemberOfTeam();
    void showALLInforOfTeam();
    void addPlayer(Player&);
    void addCoach(Coach&);
    void findPlayerByName();
    void findPlayerByNameFootballTeam();
    Vector<Player> getListPlayerByNameFootballTeam(String);
    void findPlayerById();
    void deletePlayerById(ifstream&,ofstream&);
    void saveTeamToFile(ofstream&,int = 0);
    String getSizeTeamFromFile();
    Coach getCoachByNameFootballTeam(String);
    void findCoachByNameFootballTeam();
    void findCoachByID();
    void findCoachByName();
    void updateTeam();
    
    // Chuan hoa ten -> ngUyen van a -> Nguyen Van A
    String standardizeName(String);
    void showRankOfTeam();
    void showInforOfCoach();
    void testFile();
    int String_to_int(String);
    String getNameFootballTeam();
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
    void setNameFootballTeam(String);
    // void setRank(int);
    // void setNumberGoal(int);
    // void setNumberLoseGoal(int);
    // void setPoint(int);
    // void changePoint(int);
    // void setDifference(int);
    // Coach getCoach(int);
};

#endif 