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
    char arrAge[10],numberClo[10],ylCard[10],rCard[10],goal[10];
    sprintf(arrAge,"%d",this->age);
    sprintf(numberClo,"%d",this->numberClothes);
    sprintf(ylCard,"%d",this->yellowCard);
    sprintf(rCard,"%d",this->redCard);
    sprintf(goal,"%d",this->goal);
    string myage(arrAge);
    string myNumberClo(numberClo);
    string myYlCard(ylCard);
    string myRCard(rCard);
    string myGoal(goal);
    cout << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard,"<< setw(10) << "redCard,"<< setw(10) << "Goal," << setw(20) << "NameFootballTeam" <<endl; 
    cout << left << setw(10) << this->id  + "," << setw(15) << this->name + "," << setw(15) << this->dateOfBirth + "," << setw(20) << this->address + "," << setw(10) << myage +","<< setw(15) << myNumberClo + "," << setw(15) << myYlCard + "," << setw(10) << myRCard + ","<< setw(10) << myGoal + "," << setw(20) << this->nameFootballTeam << endl; 
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

void Player::savePlayerToFile(ofstream& o,int check ) {
    char arrAge[10],numberClo[10],ylCard[10],rCard[10],goal[10];
    sprintf(arrAge,"%d",this->age);
    sprintf(numberClo,"%d",this->numberClothes);
    sprintf(ylCard,"%d",this->yellowCard);
    sprintf(rCard,"%d",this->redCard);
    sprintf(goal,"%d",this->goal);
    string myage(arrAge);
    string myNumberClo(numberClo);
    string myYlCard(ylCard);
    string myRCard(rCard);
    string myGoal(goal);
    ifstream f("Player.txt");
    if(check == 0) {
        f.seekg(0,ios::end);
        if(f.tellg() == 0) {
            o << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard,"<< setw(10) << "redCard,"<< setw(10) << "Goal," << setw(20) << "NameFootballTeam" <<endl;         }
        f.close();
    }
    if(check == 1) {
             o << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard,"<< setw(10) << "redCard,"<< setw(10) << "Goal," << setw(20) << "NameFootballTeam" <<endl;
    }

    if(o.is_open()) {
        o << left << setw(10) << this->id  + "," << setw(15) << this->name + "," << setw(15) << this->dateOfBirth + "," << setw(20) << this->address + "," << setw(10) << myage +","<< setw(15) << myNumberClo + "," << setw(15) << myYlCard + "," << setw(10) << myRCard + ","<< setw(10) << myGoal + "," << setw(20) << this->nameFootballTeam << endl; 
    }
}

void Player::getAllPlayerFromFile() {
    ifstream i("Player.txt");
    if(i.is_open()) {
        while (!i.eof())
        {
            string tmp; getline(i,tmp);
            while(getline(i,tmp)) {
                int check = 1;
                bool status = false;
                string id,name,date,address,age,numberClo,yellowCard,redCard,goal,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id += tmp[i];
                    else if(check == 2 && status) name += tmp[i];
                    else if(check == 3 && status) date += tmp[i];
                    else if(check == 4 && status) address += tmp[i];
                    else if(check == 5 && status) age += tmp[i];
                    else if(check == 6 && status) numberClo += tmp[i];
                    else if(check == 7 && status) yellowCard += tmp[i];
                    else if(check == 8 && status) redCard += tmp[i];
                    else if(check == 9 && status) goal += tmp[i];
                    else if(check == 10 && status && tmp[i] != '\n') nameTeam += tmp[i];
                }
                Player p(id,name,date,address,nameTeam,string_to_int(age),string_to_int(numberClo),string_to_int(goal),string_to_int(yellowCard),string_to_int(redCard));
                p.show();
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }
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


