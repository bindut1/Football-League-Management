#include "Coach.h"
#include <iomanip>
#include <iostream>
using namespace std;
Coach::Coach(string m, string t, string ns, string ad, int a, string nameTeam)
    : Human(m, t, ns, ad, a), nameFootballTeam(nameTeam)
{
    cout << "Call Constructor of Coach" << endl;
}

Coach::~Coach()
{
    cout << "Call Destructor of Coach" << endl;
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