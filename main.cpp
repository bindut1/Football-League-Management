#include <iostream>
#include <fstream>
#include "FootballTeam/Team.h"
#include "Match/Match.h"
#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"

using namespace std;

int main() {
    // Player p("123","Ngo Van A","13/10/2004","QN","MC",19,9);
    // Player p1("123","Ngo Van A","13/10/2004","QN","MC",19,9);
    // Player p2("123","Ngo Van A","13/10/2004","QN","MC",19,9);
    // ofstream f("Player.txt",ios::app);
    // p.savePlayerToFile(f);
    // p1.savePlayerToFile(f);
    // p2.savePlayerToFile(f);
    Team t;
    // t.findPlayerById();
    // t.findPlayerByName();
    // t.findPlayerByNameFootballTeam();
    ifstream i("Player.txt"); ofstream o("Tmp.txt",ios::app);
    t.deletePlayerById(i,o);
    t.findPlayerById();
}