#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
using namespace std;

int main() {
   // Player p1,p2;
   // p1.enterInforPlayer();
   // p2.enterInforPlayer();
   // ofstream o("Player.txt");
   // p1.savePlayerToFile(o);
   // p2.savePlayerToFile(o);
   Team t;
   ifstream i("Player.txt"); ofstream o("Tmp.txt");
   t.deletePlayerById(i,o);
}