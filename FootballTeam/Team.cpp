
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



void Team::findPlayerByName(ifstream& i) {
    cout << "Nhap ten muon tim kiem: ";
    string nameFind; getline(cin,nameFind);
    nameFind = this->standardizeName(nameFind);
    bool check = true;
    if(i.is_open()) {
        while (!i.eof())
        {
            string id, name, date,address,nameTeam;
            int age, numberClothes, goal, yellowCard, redCard;
            getline(i,id);
            getline(i,name);
            getline(i,date);
            getline(i,address);
            getline(i,nameTeam);
            i >> age;
            i >> numberClothes;
            i >> goal;
            i >> yellowCard;
            i >> redCard;
            i.ignore(numeric_limits<streamsize>::max(), '\n');
            Player p(id,name,date,address,nameTeam,age,numberClothes,goal,yellowCard,redCard);
            if(i.eof()) break;
            if(name == nameFind)  {
                check = false;
                p.show();
            }
        }
        
    } 
    i.close();
    if(check) cout << "Khong tim thay ket qua!" << endl;
}

void Team::findPlayerByNameFootballTeam(ifstream& i) {
    cout << "Nhap ten doi bong can tim: ";
    string nameFB; getline(cin,nameFB);
    nameFB = this->standardizeName(nameFB);
    bool check = true;
    if(i.is_open()) {
        while (!i.eof())
        {
            string id, name, date,address,nameTeam;
            int age, numberClothes, goal, yellowCard, redCard;
            getline(i,id);
            getline(i,name);
            getline(i,date);
            getline(i,address);
            getline(i,nameTeam);
            i >> age;
            i >> numberClothes;
            i >> goal;
            i >> yellowCard;
            i >> redCard;
            i.ignore(numeric_limits<streamsize>::max(), '\n');
            Player p(id,name,date,address,nameTeam,age,numberClothes,goal,yellowCard,redCard);
            if(i.eof()) break;
            if(nameTeam == nameFB)  {
                check = false;
                p.show();
            }
        }
        
    } 
    i.close();
    if(check) cout << "Khong tim thay ket qua!" << endl;
}

void Team::findPlayerById() {
    cout << "Nhap ID cua cau thu: ";
    string nameFB; getline(cin,nameFB);
    bool check = true;
    ifstream i("Player.txt");
    if(i.is_open()) {
        while (!i.eof())
        {
            string id, name, date,address,nameTeam;
            int age, numberClothes, goal, yellowCard, redCard;
            getline(i,id);
            getline(i,name);
            getline(i,date);
            getline(i,address);
            getline(i,nameTeam);
            i >> age;
            i >> numberClothes;
            i >> goal;
            i >> yellowCard;
            i >> redCard;
            i.ignore(numeric_limits<streamsize>::max(), '\n');
            Player p(id,name,date,address,nameTeam,age,numberClothes,goal,yellowCard,redCard);
            if(i.eof()) break;
            if(id == nameFB)  {
                check = false;
                p.show();
            }
        }
        
    } 
    else {
        cout << "Khong mo duoc" << endl;
    }
    i.close();
    if(check) cout << "Khong tim thay ket qua!" << endl;
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

void Team::deletePlayerById(ifstream& i,ofstream& tmp) {
    cout << "Nhap ID cua cau thu: ";
    string nameFB; getline(cin,nameFB);
    bool check = true;
    if(i.is_open()) {
        while (!i.eof())
        {
            string id, name, date,address,nameTeam;
            int age, numberClothes, goal, yellowCard, redCard;
            getline(i,id);
            getline(i,name);
            getline(i,date);
            getline(i,address);
            getline(i,nameTeam);
            i >> age;
            i >> numberClothes;
            i >> goal;
            i >> yellowCard;
            i >> redCard;
            i.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo ki tu \n du thua
            Player p(id,name,date,address,nameTeam,age,numberClothes,goal,yellowCard,redCard);
            if(i.eof()) break;
            if(id == nameFB)  {
                check = false;
            }
            else {
                // Luu cau thu khong trung ID sang file khac -> doi ten file nay thanh file ban dau
                p.savePlayerToFile(tmp);
            }
        }     
    }
    i.close();
    tmp.close();
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