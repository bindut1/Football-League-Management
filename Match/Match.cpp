#include "Match.h"
#include <iostream>
#include <iomanip>
using namespace std;
Match::Match() {

}
Match::~Match() {
    cout << "Destructor of Match" << endl;
}
Match::Match(const Team& a,const Team& b,string address,string time,string date) {
    cout << "Constructor of Match" << endl;
    this->v.push_back(a);
    this->v.push_back(b);
    this->address = address;
    this->time = time ;
    this->date = date;
    cout << "Khoi tao thanh cong" << endl;
}

void Match::showMatch() {
    cout << "Da den day" << endl;
    cout << this->v[0].getNameFootballTeam() << setw(100) << this->v[1].getNameFootballTeam() << endl;
    cout << setw(20) << this->time << setw(20) << this->date << endl;
    cout << "DIEN RA TAI SVD: " << this->address << endl; 
}

void Match::changeAddress(string newAddress) {
    this->setAddress(newAddress);
}

void Match::changeTime(string newTime) {
    this->setTime(newTime);
}

void Match::enterResult() {

}

Vector<Team> Match::getTwoTeam() {
    return this->v;
}

string Match::getAddress() {
    return this->address;
}

void Match::setAddress(string address) {
    this->address = address;
}

string Match::getTime() {
    return this->time;
}

void Match::setTime(string time) {
    this->time = time;
}