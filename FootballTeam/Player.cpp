#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;

Player::Player(string id,string name,string date,string address,int age, int goal,int numberClothes,string nameTeam)
    :Human(id,name,date,address,age)
{
    this->goal = goal;
    this-> numberClothes = numberClothes;
    this->nameFootballTeam = nameTeam;
}
Player::~Player() {

}

void Player::show() {
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "DateOfBirth" << setw(30) << "Address" << setw(20) << "Age" << setw(20) << "NumberClothes" << setw(20) << "NameFootballTeam" <<endl; 
    cout << left << setw(10) << this->id << setw(20) << this->name << setw(20) << this->dateOfBirth << setw(30) << this->address << setw(20) << this->age << setw(20) << this->numberClothes<< setw(20) << this->nameFootballTeam << endl; 
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