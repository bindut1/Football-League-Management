#include "Human.h"

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