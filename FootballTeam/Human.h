#include <iostream>
using namespace std;

class Human
{
    protected:
        string id, name, dateOfBirth, address;
        int age;

    public:
        Human(string = "", string = "", string = "", string = "", int = 0);
        ~Human();
        virtual void show();
};
