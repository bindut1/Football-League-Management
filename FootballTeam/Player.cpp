#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;

Player::Player(string id,string name,string date,string address,int age, int goal,int yellowCard,int redCard,int number)
    :Human(id,name,date,address,age)
{
    this->goal = goal;
    this-> yellowCard = yellowCard;
    this-> redCard = redCard;
    this->numberClothes = number;
}

Player::~Player() {

}

void Player::Show() {
    cout << left << setw(20) << "ID" << setw(30) << "Name" << setw(20) << "DateOfBirth" << setw(30) << "Address" << setw(10) << "Age" << setw(15) << "YellowCard" << setw(15) << "RedCard" << setw(15) << "NumberClothes" << endl; 
    cout << left << setw(20) << this->id << setw(30) << this->name << setw(20) << this->dateOfBirth << setw(30) << this->address << setw(10) << this->age << setw(15) << this->yellowCard << setw(15) << this->redCard << setw(15) << this->numberClothes << endl; 
}