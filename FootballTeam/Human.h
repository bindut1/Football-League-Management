#include <iostream>
using namespace std;
#ifndef A_H
#define A_H
class Human
{
    protected:
        string id, name, dateOfBirth, address;
        int age;

    public:
        Human(string = "", string = "", string = "", string = "", int = 0);
        ~Human();
        virtual void show();
        string getId();
        void setId(string);
        string getName();
        void setName(string);
        string getDateOfBirth();
        void setDateOfBirth(string);
        string getAddress();
        void setAddress(string);
        int getAge();
        void setAge(int);
         string standardizeName(string);
};
#endif // A_H