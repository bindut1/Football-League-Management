
#include "Team.h"

Team::Team() {

}

Team::Team(string nameTeam,Coach coach,int rank,int numberGoal,int numberLoseGoal,string homeYard, int point,int differrence) {
    this->nameFootballTeam = nameTeam;
    this->coach = coach;
    this->rank = rank;
    this->numberGoal = numberGoal;
    this->numberLoseGoal = numberLoseGoal;  
    this->homeYard = homeYard;
    this->point = point;
    this->difference = difference;
}

void Team::showMainTeam() {
    this->mainTeam.duyetxuoi(this->head);
}

void Team::showHistoryMatch() {
    this->supportTeam.duyetxuoi(this->head);
}

void Team::showAllMemberOfTeam() {
    this->showMainTeam();
    this->showSupportTeam();
}