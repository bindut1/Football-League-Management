#include "Human.h"
class Player : public Human
{
private:
    int goal, yellowCard, redCard, numberClothes;    
public:
    Player();
    Player(string,string,string,string,int,int,int,int,int);
    ~Player();
    void Show();
    void updateInfor(string,string,string,string,int,int,int,int,int);
};

Player::Player()
{
}

Player::~Player()
{
}
