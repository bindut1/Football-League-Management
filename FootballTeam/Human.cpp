#include "Human.h"

Human::Human(string m, string t, string ns, string ad, int a)
    : id(m), name(t), dateOfBirth(ns), address(ad), age(a)
{
    cout << "Call Constructor of Human" << endl;
}

Human::~Human()
{
    cout << "Call Destructor of Human" << endl;
}

void Human::show()
{
    cout << this->id << ", " << this->name << ", " << this->dateOfBirth << ", " << this->address << ", " << this->age;
}
