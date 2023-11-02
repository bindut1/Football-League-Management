#include "Human.h"
#ifndef COACH_H
#define COACH_H

class Coach : public Human
{
    private:
        string nameFootballTeam;

    public:
        Coach(string = "", string = "", string = "", string = "", int = 0, string = "");
        ~Coach();
        void show();
        void setNameFootballTeam(string);
        string getNameFootballTeam();
};

#endif