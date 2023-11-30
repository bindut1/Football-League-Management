#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
// #include "LapLich/Algorithm.cpp"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
#include "Algorithm.h"

int main() {
   // Player p1("123","Ngo Van D","13/10/2004","QN","MC",9);
   // Player p2("124","Tran Vu L","11/1/2004","QS","MU",10);
   // Coach c("111","Park Hang Seo","1/11/2000","Korean","Ars");
   // Team t;
   // t.setNameFootballTeam("MC");
   // Team t1;
   // t1.setNameFootballTeam("LIV");
   // Match m;
   // m.addTeam(t);
   // m.addTeam(t1);
   // m.showMatch();
   HistoryMatch h;
   h.updateHistoryMatch();
   Team t;
   t.sortRankAllTeam();
}