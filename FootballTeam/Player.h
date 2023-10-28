#include "Human.h"
class Player : public Human
{
private:
    int goal, numberClothes, yellowCard , redCard;
    string nameFootballTeam;  
public:
    Player();
    Player(string,string,string,string,string,int,int,int = 0,int  = 0,int  = 0);
    ~Player();
    void show();
    void updateInfor(string,string,string,string,int,int,int,string);
    int getGoal();
    void setGoal(int);
    int getNumberClothes();
    void setNumberClothes(int);
    void updateGoal(int);
};
