#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;

Player::Player(string id,string name,string date,string address,string nameTeam,int age, int numberClothes,int goal,int yellowCard,int redCard)
    :Human(id,name,date,address,age)
{
    this->goal = goal;
    this-> numberClothes = numberClothes;
    this->nameFootballTeam = nameTeam;
    this->redCard = redCard;
    this->yellowCard = yellowCard;
}
Player::~Player() {

}

void Player::show() {
    cout << left << setw(10) << "ID" << setw(15) << "Name" << setw(15) << "DateOfBirth" << setw(20) << "Address" << setw(10) << "Age" << setw(15) << "NumberClothes" << setw(15) << "yellowCard"<< setw(10) << "redCard"<< setw(10) << "Goal" << setw(20) << "NameFootballTeam" <<endl; 
    cout << left << setw(10) << this->id << setw(15) << this->name << setw(15) << this->dateOfBirth << setw(20) << this->address << setw(10) << this->age << setw(15) << this->numberClothes<< setw(15) << this->yellowCard << setw(10) << this->redCard<< setw(10) << this->goal << setw(20) << this->nameFootballTeam << endl; 
}

int Player::getGoal() {
    return this->goal;
}

void Player::setGoal(int goal) {
    this->goal = goal;
}

void Player::setNumberClothes(int number) {
    this->numberClothes = number;
}

int Player::getNumberClothes() {
    return this->numberClothes;
}

void Player::updateGoal(int newGoal) {
    this->setGoal(newGoal);
}