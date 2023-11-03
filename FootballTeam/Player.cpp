#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;




Player::Player(string id,string name,string date,string address,string nameTeam,int age, int numberClothes,int goal,int yellowCard,int redCard)
    :Human(id,name,date,address,age)
{
    
    this->goal = goal;
    this-> numberClothes = numberClothes;
    this->nameFootballTeam = this->standardizeName(nameTeam);
    this->redCard = redCard;
    this->yellowCard = yellowCard;
}
Player::Player() {
    
}

Player::~Player() {

}

void Player::show() {
    cout << left << setw(10) << "ID" << setw(15) << "Ten" << setw(15) << "DateOfBirth" << setw(20) << "Address" << setw(10) << "Age" << setw(15) << "NumberClothes" << setw(15) << "yellowCard"<< setw(10) << "redCard"<< setw(10) << "Goal" << setw(20) << "NameFootballTeam" <<endl; 
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

void Player::savePlayerToFile(ofstream& o) {
    if(o.is_open()) {
        o << this->id << endl << this->name << endl << this->dateOfBirth << endl << this->address << endl << this->nameFootballTeam << endl << this->age << endl << this->numberClothes << endl << this->goal << endl << this->yellowCard << endl << this->redCard << endl;
        // o.close();
    }
}

void Player::getAllPlayerFromFile(ifstream& i) {
    if(i.is_open()) {
        while (!i.eof())
        {
            string id, name, date,address,nameTeam;
            int age, numberClothes, goal, yellowCard, redCard;
            getline(i,id);
            getline(i,name);
            getline(i,date);
            getline(i,address);
            getline(i,nameTeam);
            i >> age;
            i >> numberClothes;
            i >> goal;
            i >> yellowCard;
            i >> redCard;
            i.ignore(numeric_limits<streamsize>::max(), '\n');
            Player p(id,name,date,address,nameTeam,age,numberClothes,goal,yellowCard,redCard);
            if(i.eof()) break;
            p.show();
        }
        
    } 
}
void Player::setYellowCard(int ylcard) {
    this->yellowCard = ylcard;
}

void Player::setRedCard(int rcard) {
    this->redCard = rcard;
}

int Player::getYellowCard() {
    return this->yellowCard;
}
int Player::getRedCard() {
    return this->redCard;
}

void Player::enterInforPlayer() {
    string id, name, date,address,nameTeam;
    int age, numberClothes, goal, yellowCard, redCard;
    cout << "Nhap CCCD cua cau thu: ";
    getline(cin,id);
    cout << "Nhap ho va ten cua cau thu: ";
    getline(cin,name);
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    getline(cin,date);
    if(date[1] == '/') date = '0' + date;
    if(date[4]  == '/') date.insert(3,"0");
    cout << "Nhap dia chi cua cau thu: ";
    getline(cin,address);
    cout << "Nhap tuoi cua cau thu: ";
    cin >> age;
    cout << "Nhap so ao: ";
    cin >> numberClothes;
    cin.ignore();
    // Cap nhat thong tin cau thu
    this->setId(id);
    this->setName(name);
    this->setDateOfBirth(date);
    this->setAddress(address);
    this->setAge(age);
    this->setNumberClothes(numberClothes);
    this->setGoal(0);
    this->setYellowCard(0);
    this->setRedCard(0);
}

void Player::setNameFootballTeam(string nameFB) {
    this->nameFootballTeam = nameFB;
}

string Player::getNameFootballTeam() {
    return this->nameFootballTeam;
}