#include "Human.h"
#include <fstream>
#ifndef COACH_H
#define COACH_H

class Coach : public Human
{
    private:
        String nameFootballTeam;

    public:
        Coach(String = "", String = "", String = "", String = "", int = 0, String = "");
        ~Coach();
        void show();
        void setNameFootballTeam(String);
        String getNameFootballTeam();
        void enterInforCoach();
        void saveInforIntoFile(ofstream&);
        Coach getCoachByNameFootballTeam(String);
        void updateCoach();
};

#endif