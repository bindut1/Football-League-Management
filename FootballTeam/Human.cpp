#include "Human.h"
String Human::standardizeName(String s) {
    String tmp = "";
    for(int i=0;i<s.size();i++) {
        if(i==0) tmp = tmp +  toupper(s[0]);
        else {
            if(s[i-1]== ' ') tmp = tmp + toupper(s[i]);
            else tmp = tmp + tolower(s[i]);
        }
    }
    return tmp;
}

Human::Human(String m, String t, String ns, String ad, int a)
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

String Human::getId() {
    return this->id;
}

void Human::setId(String id) {
    this->id = id;
}

String Human::getName() {
    return this->name;
}

void Human::setName(String name) {
    this->name = name;
}

String Human::getDateOfBirth() {
    return this->dateOfBirth;
}

void Human::setDateOfBirth(String dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

String Human::getAddress() {
    return this->address;
}

void Human::setAddress(String address) {
    this->address = address;
}

int Human::getAge() {
    return this->age;
}

void Human::setAge(int age) {
    this->age = age;
}

int Human::string_to_int(String x) {
    char a[x.size()];
    for(int i=0;i<x.size();i++) {
        a[i] = x[i];
    }
    return atoi(a);
}