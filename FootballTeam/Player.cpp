#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "../CTDL/String.h"
using namespace std;




Player::Player(String id,String name,String date,String address,String nameTeam,int age, int numberClothes,int goal,int yellowCard,int redCard)
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
    String myage(arrAge);
    String myNumberClo(numberClo);
    String myYlCard(ylCard);
    String myRCard(rCard);
    String myGoal(goal);
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
    String myage(arrAge);
    String myNumberClo(numberClo);
    String myYlCard(ylCard);
    String myRCard(rCard);
    String myGoal(goal);
    ifstream f("Player.txt");
    if(check == 0) {
        f.seekg(0,ios::end);
        if(f.tellg() == 0) {
            o << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard,"<< setw(10) << "redCard,"<< setw(10) << "Goal," << setw(20) << "NameFootballTeam";;         }
        f.close();
    }
    if(check == 1) {
             o << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard,"<< setw(10) << "redCard,"<< setw(10) << "Goal," << setw(20) << "NameFootballTeam";;
    }

    if(o.is_open()) {
        o << endl<< left << setw(10) << this->id  + "," << setw(15) << this->name + "," << setw(15) << this->dateOfBirth + "," << setw(20) << this->address + "," << setw(10) << myage +","<< setw(15) << myNumberClo + "," << setw(15) << myYlCard + "," << setw(10) << myRCard + ","<< setw(10) << myGoal + "," << setw(20) << this->nameFootballTeam ;
    }
}

void Player::getAllPlayerFromFile() {
    ifstream i("Player.txt");
    if(i.is_open()) {
        String tmp; String::getline(i,tmp);
        while (!i.eof())
        {       
                String::getline(i,tmp);
                int check = 1;
                bool status = false;
                String id,name,date,address,age,numberClo,yellowCard,redCard,goal,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id = id +  tmp[i];
                    else if(check == 2 && status) name = name + tmp[i];
                    else if(check == 3 && status) date = date + tmp[i];
                    else if(check == 4 && status) address = address + tmp[i];
                    else if(check == 5 && status) age = age +  tmp[i];
                    else if(check == 6 && status) numberClo = numberClo + tmp[i];
                    else if(check == 7 && status) yellowCard = yellowCard + tmp[i];
                    else if(check == 8 && status) redCard = redCard + tmp[i];
                    else if(check == 9 && status) goal = goal + tmp[i];
                    else if(check == 10 && status && tmp[i] != '\n') nameTeam = nameTeam + tmp[i];
                }
                Player p(id,name,date,address,nameTeam,String::toint(age),String::toint(numberClo),String::toint(goal),String::toint(yellowCard),String::toint(redCard));
                p.show();
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
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
    String id, name, date,address,nameTeam;
    int age, numberClothes, goal, yellowCard, redCard;
    cout << "Nhap CCCD cua cau thu: ";
    String::getline(cin,id);
    cout << "Nhap ho va ten cua cau thu: ";
    String::getline(cin,name);
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    String::getline(cin,date);
    if(date[1] == '/') date = date +  '0'  ;
    //if(date[4]  == '/') date.String::insert(3,"0");
    cout << "Nhap dia chi cua cau thu: ";
    String::getline(cin,address);
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

void Player::setNameFootballTeam(String nameFB) {
    this->nameFootballTeam = nameFB;
}

String Player::getNameFootballTeam() {
    return this->nameFootballTeam;
}


void Player::updatePlayer()
{
    system("cls");
    String ma;
    cout << "Nhap CCCD cua cau thu can chinh sua: ";
    String::getline(cin, ma);
    fstream file("Player.txt", ios::in);
    fstream tempFile("tempPlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard," << setw(10) << "redCard," << setw(10) << "Goal," << setw(20) << "NameFootballTeam" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp; String::getline(file, tmp);
        while(!file.eof()) {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard  = redCard +  tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                    nameTeam = nameTeam + tmp[i];
            }
            if (ma == id)
            {
                int u;
                do
                {
                    system("cls");
                    String newname, newdate, newadd, newnamefb;
                    int newage, newnum, newyl, newr, newg;
                    cout << "1. Chinh sua Ten cua cau thu" << endl;
                    cout << "2. Chinh sua Ngay sinh cua cau thu" << endl;
                    cout << "3. Chinh sua Dia chi cua cau thu" << endl;
                    cout << "4. Chinh sua Tuoi cua cau thu" << endl;
                    cout << "5. Chinh sua So ao cua cau thu" << endl;
                    cout << "6. Chinh sua The vang cua cau thu" << endl;
                    cout << "7. Chinh sua The do cua cau thu" << endl;
                    cout << "8. Chinh sua so ban thang cua cau thu" << endl;
                    cout << "9. Chinh sua ten doi bong cua cau thu" << endl; // chinh sua o day thi ben team cung phai update theo va nguoc lai
                    cout << "Moi nhap lua chon: ";
                    int t;
                    cin >> t;
                    cin.ignore();
                    switch (t)
                    {
                    case 1:
                        cout << "Nhap ten cau thu: ";
                        String::getline(cin, newname);
                        name = newname;
                        break;
                    case 2:
                        cout << "Nhap ngay sinh cau thu: ";
                        String::getline(cin, newdate);
                        if (newdate[1] == '/') {
                            String tmp("0");
                            newdate = tmp + date;
                        }
                        if (newdate[4] == '/')
                            newdate.insert(3, "0");
                        date = newdate;
                        break;
                    case 3:
                        cout << "Nhap dia chi cau thu: ";
                        String::getline(cin, newadd);
                        address = newadd;
                        break;
                    case 4:
                        cout << "Nhap tuoi cau thu: ";
                        cin >> newage;
                        age = String::tostring(newage);
                        break;
                    case 5:
                        cout << "Nhap so ao cua cau thu: ";
                        cin >> newnum;
                        numberClo = String::tostring(newnum);
                        break;
                    case 6:
                        cout << "Nhap so the vang cua cau thu: ";
                        cin >> newyl;
                        yellowCard = String::tostring(newyl);
                        break;
                    case 7:
                        cout << "Nhap so the do cua cau thu: ";
                        cin >> newr;
                        redCard = String::tostring(newr);
                        break;
                    case 8:
                        cout << "Nhap so ban thang cua cau thu: ";
                        cin >> newg;
                        goal = String::tostring(newg);
                        break;
                    case 9:
                        cout << "Nhap ten doi bong moi cua cau thu: ";
                        String::getline(cin, newnamefb);
                        nameTeam = newnamefb;
                        break;
                    default:
                        break;
                    }

                    cout << "Go 1 ban muon tiep tuc chinh sua, 0 neu muon thoat: ";
                    cin >> u;
                } while (u == 1);
                tempFile << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        
        file.close();
        tempFile.close();
        remove("Player.txt");
        rename("tempPlayer.txt", "Player.txt");
    }
    else
        cout << "Khong mo dc file";
}