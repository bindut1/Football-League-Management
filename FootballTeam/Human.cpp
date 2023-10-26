#include "Human.h"

Human::Human(string m, string t, string ns, string ad, int a)
    : id(m), name(t), dateOfBirth(ns), address(ad), age(a)
{
   
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