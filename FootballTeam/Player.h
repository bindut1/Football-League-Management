#include "Human.h"
class Player : public Human
{
private:
    int goal, numberClothes;
    string nameFootballTeam;  
public:
    Player();
    Player(string,string,string,string,int,int,int,string);
    ~Player();
    void show();
    void updateInfor(string,string,string,string,int,int,int,string);
    int getGoal();
    void setGoal(int);
    int getNumberClothes();
    void setNumberClothes(int);
    void updateGoal(int);
};
