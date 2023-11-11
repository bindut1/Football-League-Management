#include "Human.h"
#include <fstream>
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Human
{
private:
    int goal, numberClothes, yellowCard , redCard;
    String nameFootballTeam;
public:
    Player();
    Player(String,String,String,String,String,int,int,int = 0,int  = 0,int  = 0);
    ~Player();
    void show();
    void updateInfor(String,String,String,String,int,int,int,String);
    int getGoal();
    void setGoal(int);
    int getNumberClothes();
    void setNumberClothes(int);
    void updateGoal(int);
    int getYellowCard();
    void setYellowCard(int);
    int getRedCard();
    void setRedCard(int);
    void setNameFootballTeam(String);
    String getNameFootballTeam();
    // Luu cau thu vao file
    void savePlayerToFile(ofstream&,int  = 0);
    void getAllPlayerFromFile();
    //nhap cau thu
    void enterInforPlayer();
    void updatePlayer();
};
#endif