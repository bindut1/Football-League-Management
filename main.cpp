#include <iostream>
#include <fstream>
#include "FootballTeam/Team.h"
#include "Match/Match.h"

using namespace std;

int main() {
    Team t;
    t.setNameFootballTeam("MANCHESTER UNITED");
    Team t1;
    t.setNameFootballTeam("MANCHESTER CITY");
    Match m(t,t1,"DUT","7h00","13/10/2023");
    m.showMatch();
} 