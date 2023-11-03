#include "Human.h"
string Human::standardizeName(string s) {
    string tmp = "";
    for(int i=0;i<s.size();i++) {
        if(i==0) tmp += toupper(s[0]);
        else {
            if(s[i-1]== ' ') tmp += toupper(s[i]);
            else tmp += tolower(s[i]);
        }
    }
    return tmp;
}

Human::Human(string m, string t, string ns, string ad, int a)
    : id(m), dateOfBirth(ns), address(ad), age(a)
{
    this->name = this->standardizeName(t);
}

Human::~Human()
{
    
}

void Human::show()
{
    cout << this->id << ", " << this->name << ", " << this->dateOfBirth << ", " << this->address << ", " << this->age;
}

string Human::getId() {
    return this->id;
}

void Human::setId(string id) {
    this->id = id;
}

string Human::getName() {
    return this->name;
}

void Human::setName(string name) {
    this->name = name;
}

string Human::getDateOfBirth() {
    return this->dateOfBirth;
}

void Human::setDateOfBirth(string dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

string Human::getAddress() {
    return this->address;
}

void Human::setAddress(string address) {
    this->address = address;
}

int Human::getAge() {
    return this->age;
}

void Human::setAge(int age) {
    this->age = age;
}