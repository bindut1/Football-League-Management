#include "../FootballTeam/Team.h"
#include "../CTDL/Vector.cpp"
class Match
{
private:
    Vector<Team> v;
    string address;
    string time;
    string date;
public:
    Match();
    Match(Team,Team,string,string,string);
    ~Match();
    void addTeam(Team);
    void showMatch();
    void changeAddress(string);
    void changeTime(string);
    void enterResult();
    Vector<Team> getTwoTeam();
    string getAddress();
    void setAddress(string);
    string getTime();
    void setTime(string);
};

