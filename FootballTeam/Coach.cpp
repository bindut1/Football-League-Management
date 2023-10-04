#include "Coach.h"

Coach::Coach(string m, string t, string ns, string ad, int a, string mh)
    : Human(m, t, ns, ad, a), idHLV(mh)
{
    cout << "Call Constructor of Coach" << endl;
}

Coach::~Coach()
{
    cout << "Call Destructor of Coach" << endl;
}

void Coach::show()
{
    cout << this->id << ", " << this->idHLV << ", " << this->name << ", " << this->dateOfBirth << ", " << this->address << ", " << this->age;
}