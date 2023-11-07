
#include "Team.h"
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
Team::Team() {

}
Team::~Team() {
    
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
void Team::setIdTeam(int id) {
    this->idTeamFootball = id;
}

string Team::getIdTeam() {
    return this->idTeamFootball;
}

void Team::showAllMemberOfTeam() {
    cout << endl << "Danh Sach Cau Thu" << endl;
    for(int i=0;i<this->listMember.size();i++) {
        this->listMember[i].show();
    }
}

void Team::showALLInforOfTeam() {
    cout << "DOI BONG " << this->nameFootballTeam << endl; 
    cout << "Thong Tin HLV" << endl;
    this->coach.show();

    cout << endl << "Danh Sach Cau Thu" << endl;
    for(int i=0;i<this->listMember.size();i++) {
        this->listMember[i].show();
    }
}
// void Team::showHistoryMatch() {
//     this->supportTeam.duyetxuoi(this->head);
// }
void Team::addPlayer(Player& p) {
    this->listMember.push_back(p);
}

void Team::addCoach(Coach& c) {
    this->coach = c;
}


string Team::getNameFootballTeam() {
    return this->nameFootballTeam;
}

void Team::setNameFootballTeam(string name) {
    this->nameFootballTeam = name;
}

string Team::standardizeName(string s) {
    string tmp = "";
    for(int i=0;i<s.size();i++) {
        if(i==0) tmp += toupper(s[0]);
        else {
            if(s[i-1]== ' ') tmp += toupper(s[i]);
            else tmp += tolower(s[i]);
        }
    }
    return tmp;
}



void Team::findPlayerByName() {
    cout << "Nhap ten can tim: ";
    string nameFind; getline(cin,nameFind);
    ifstream i("Player.txt");
    bool val = true;
    if(i.is_open()) {
        while (!i.eof())
        {
            string tmp; getline(i,tmp);
            while(getline(i,tmp)) {
                int check = 1;
                bool status = false;
                string id,name,date,address,age,numberClo,yellowCard,redCard,goal,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id += tmp[i];
                    else if(check == 2 && status) name += tmp[i];
                    else if(check == 3 && status) date += tmp[i];
                    else if(check == 4 && status) address += tmp[i];
                    else if(check == 5 && status) age += tmp[i];
                    else if(check == 6 && status) numberClo += tmp[i];
                    else if(check == 7 && status) yellowCard += tmp[i];
                    else if(check == 8 && status) redCard += tmp[i];
                    else if(check == 9 && status) goal += tmp[i];
                    else if(check == 10 && status && tmp[i] != '\n') nameTeam += tmp[i];
                    if(check > 2 && name != nameFind) break;
                }
                if(name == nameFind) {
                Player p(id,name,date,address,nameFootballTeam,string_to_int(age),string_to_int(numberClo),string_to_int(goal),string_to_int(yellowCard),string_to_int(redCard));
                p.show();
                val = false;
                }
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }
        }
        
    } 
    if(val) cout << "Khong tim thay ket qua tuong ung" << endl;
}

void Team::findPlayerByNameFootballTeam() {
    cout << "Nhap ten doi bong can tim: ";
    string nameFB; getline(cin,nameFB);
    nameFB = this->standardizeName(nameFB);
    bool val = true;
    ifstream i("Player.txt");
    if(i.is_open()) {
        while (!i.eof())
        {
            string tmp; getline(i,tmp);
            while(getline(i,tmp)) {
                int check = 1;
                bool status = false;
                string id,name,date,address,age,numberClo,yellowCard,redCard,goal,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id += tmp[i];
                    else if(check == 2 && status) name += tmp[i];
                    else if(check == 3 && status) date += tmp[i];
                    else if(check == 4 && status) address += tmp[i];
                    else if(check == 5 && status) age += tmp[i];
                    else if(check == 6 && status) numberClo += tmp[i];
                    else if(check == 7 && status) yellowCard += tmp[i];
                    else if(check == 8 && status) redCard += tmp[i];
                    else if(check == 9 && status) goal += tmp[i];
                    else if(check == 10 && status) {
                        nameTeam += tmp[i];
                        if((tmp[i+1] == ' ' &&  tmp[i+2] == ' ') || (tmp[i+1] == ' ' && i+1 == tmp.size()-1)) break;
                    }
                }
                if(nameTeam == nameFB) {
                Player p(id,name,date,address,nameTeam,string_to_int(age),string_to_int(numberClo),string_to_int(goal),string_to_int(yellowCard),string_to_int(redCard));
                p.show();
                val = false;
                }
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }
        }
        
    } 
    i.close();
    if(val) cout << "Khong tim thay ket qua!" << endl;
}

void Team::findPlayerById() {
    cout << "Nhap ID cua cau thu: ";
    string idPlayer; getline(cin,idPlayer);
    bool val = true;
    ifstream i("Player.txt");
    if(i.is_open()) {
        while (!i.eof())
        {
            string tmp; getline(i,tmp);
            while(getline(i,tmp)) {
                int check = 1;
                bool status = false;
                string id,name,date,address,age,numberClo,yellowCard,redCard,goal,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id += tmp[i];
                    else if(check == 2 && status) name += tmp[i];
                    else if(check == 3 && status) date += tmp[i];
                    else if(check == 4 && status) address += tmp[i];
                    else if(check == 5 && status) age += tmp[i];
                    else if(check == 6 && status) numberClo += tmp[i];
                    else if(check == 7 && status) yellowCard += tmp[i];
                    else if(check == 8 && status) redCard += tmp[i];
                    else if(check == 9 && status) goal += tmp[i];
                    else if(check == 10 && status && tmp[i] != '\n') nameTeam += tmp[i];
                    
                }
                if(id == idPlayer) {
                    val = false;
                    Player p(id,name,date,address,nameTeam,string_to_int(age),string_to_int(numberClo),string_to_int(goal),string_to_int(yellowCard),string_to_int(redCard));
                    p.show();
                }
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }
        }
        
    } 
    else {
        cout << "Khong mo duoc" << endl;
    }
    i.close();
    if(val) cout << "Khong tim thay ket qua!" << endl;
}
void Team::createNewFootballTeam() {
    string nameFootballTeam;
    cout << "Nhap ten doi bong can them: ";
    getline(cin,nameFootballTeam);  
    this->setNameFootballTeam(nameFootballTeam);
    int lc;
    do {
        cout << "Nhap lua chon cua ban\n";
        cout << "1. Them cau thu vao doi Bong\n";
        cout << "2. Them HLV cho doi bong (Toi da 1 HLV)\n";
        cout << "0. Ket thuc\n";
        cout << "Nhap lua chon: ";
        cin >> lc; cin.ignore();
        if(lc == 1) {
            Player p;
            p.enterInforPlayer();
            this->listMember.push_back(p);
        }
        else if(lc == 2) {
            Coach c;
            c.enterInforCoach();
            this->coach = c;
        }
        else {
            cout << "Ban co chac chan muon thoat (y/n)";
            string ctn; getline(cin,ctn);
            if(ctn == "y" || ctn == "Y") break;
        }
    }
    while(true);
}

void Team::deletePlayerById(ifstream& i,ofstream& tmp2) {
    
    cout << "Nhap ID cua cau thu: ";
    string idPlayer; getline(cin,idPlayer);
    bool check = true;
    if(i.is_open()) {
        while (!i.eof())
        {
            string tmp; getline(i,tmp);
            while(getline(i,tmp)) {
                int check = 1;
                bool status = false;
                string id,name,date,address,age,numberClo,yellowCard,redCard,goal,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id += tmp[i];
                    else if(check == 2 && status) name += tmp[i];
                    else if(check == 3 && status) date += tmp[i];
                    else if(check == 4 && status) address += tmp[i];
                    else if(check == 5 && status) age += tmp[i];
                    else if(check == 6 && status) numberClo += tmp[i];
                    else if(check == 7 && status) yellowCard += tmp[i];
                    else if(check == 8 && status) redCard += tmp[i];
                    else if(check == 9 && status) goal += tmp[i];
                    else if(check == 10 && status && tmp[i] != '\n') nameTeam += tmp[i];
                }
                if(id != idPlayer) {
                    Player p(id,name,date,address,nameTeam,string_to_int(age),string_to_int(numberClo),string_to_int(goal),string_to_int(yellowCard),string_to_int(redCard));
                    p.savePlayerToFile(tmp2);

                }
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }
        }     
    }
    i.close();
    tmp2.close();
    const char* i1("Player.txt");
    const char* tmp1("Tmp.txt");
    // Xoa file Player.txt chứa dữ liệu cũ
    remove(i1);
    // Đổi file Tmp.txt chứa dữ liệu mới thành file Player.txt 
    rename(tmp1,"Player.txt");
}

void Team::showRankOfTeam() {
    cout << setw(20) << "Doi Bong: " << this->nameFootballTeam << setw(20) << "Rank: " << this->rank << endl;
}

void Team::showInforOfCoach() {
    this->coach.show();
}

void Team::testFile() {
    // ifstream f("Player.txt");
    // if(f.is_open()) {
    //     cout << "Mo duoc" << endl;
    // }
    // else {
    //     cout << "Ko mo duoc" << endl;
    // }
    this->findPlayerById();
}

int Team::string_to_int(string x) {
    char a[x.size()];
    for(int i=0;i<x.size();i++) {
        a[i] = x[i];
    }
    return atoi(a);
}