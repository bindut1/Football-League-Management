#include "Coach.h"
#include <iomanip>
#include <iostream>
using namespace std;


Coach::Coach(string m, string t, string ns, string ad, int a, string nameTeam)
    : Human(m, t, ns, ad, a), nameFootballTeam(nameTeam)
{
    // cout << "Call Constructor of Coach" << endl;
}

Coach::~Coach()
{
    // cout << "Call Destructor of Coach" << endl;
}

void Coach::show()
{
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "DateOfBirth" << setw(30) << "Address" << setw(20) << "Age" << setw(20) << "NameFootballTeam" <<endl; 
    cout << left << setw(10) << this->id << setw(20) << this->name << setw(20) << this->dateOfBirth << setw(30) << this->address << setw(20) << this->age << setw(20) <<  this->nameFootballTeam << endl; 
}

void Coach::setNameFootballTeam(string name) {
    this->nameFootballTeam = name;
}

string Coach::getNameFootballTeam() {
    return this->nameFootballTeam;
}

void Coach::enterInforCoach() {
    string id, name, date,address;
    int age;
    cout << "Nhap CCCD cua HLV: ";
    getline(cin,id);
    cout << "Nhap ho va ten cua HLV: ";
    getline(cin,name);
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    getline(cin,date);
    if(date[1] == '/') date = '0' + date;
    if(date[4]  == '/') date.insert(3,"0");
    cout << "Nhap dia chi cua hlv: ";
    getline(cin,address);
    cout << "Nhap tuoi cua HLV: ";
    cin >> age;
    cin.ignore();
    // Cap nhat thong tin HLV
    this->setId(id);
    this->setName(name);
    this->setDateOfBirth(date);
    this->setAddress(address);
    this->setAge(age);
    this->setNameFootballTeam("ABC");
}

void Coach::saveInforIntoFile(ofstream& o) {
    char arrAge[10],numberClo[10],ylCard[10],rCard[10],goal[10];
    sprintf(arrAge,"%d",this->age);
    string myage(arrAge);
    ifstream f("Coach.txt");
    if(f) {
        f.seekg(0,ios::end);
        if(f.tellg() == 0) {
            o << left << setw(15) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(20) << "NameFootball Team" << endl; 
        }
        f.close();
    }
    else {
        cout << "K mo tep duoc";
    }
    if(o.is_open()) {
        o << left << setw(15) << this->id  + "," << setw(15) << this->name + "," << setw(15) << this->dateOfBirth + "," << setw(20) << this->address + "," << setw(10) << myage +","<< setw(20) << this->nameFootballTeam << endl;
    }
}