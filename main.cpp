#include <iostream>
#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
using namespace std;

int main() {
    Player p("123","Ngo Van Danh","13/10/2004","VN",19,0,9,"DUT");
    p.show();
    Coach p1("123","Ngo Van Danh 2","13/10/2004","VN",19,"MU");
    p1.show();
}
