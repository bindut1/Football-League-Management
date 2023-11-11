#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
#include "LapLich/Algorithm.cpp"
using namespace std;

int main()
{   
   int lc; 
   do {
        system("cls");
        cout << "1. Them mot doi bong" << endl;
        cout << "2. Truy van thong tin " << endl;
        cout << "3. Cap nhat thong tin" << endl;
        cout << "4. Lap lich thi dau" << endl;
        cout << "0. Ket thuc" << endl;
        cout << "Nhap lua chon: "; cin >> lc;
        cin.ignore();
        if(lc == 1) {
            system("cls");
            Team t;
            t.createNewFootballTeam();
        }
        else if(lc==2) {
            int lc1;
            do {
            system("cls");
            cout << "1. Truy van thong tin cua mot doi bong" << endl;
            cout << "2. Truy van thong tin cau thu" << endl;
            cout << "3. Truy van thong tin HLV" << endl;
            cout << "0. Quay lai" << endl;
            cout << "Nhap lua chon: "; cin >> lc1; cin.ignore();
            if(lc1 == 1) {
                system("cls");
                Team t;
                t.findTeamByName();
            }
            else if(lc1 == 2) {
                int lc12;
                do {
                    system("cls");
                    cout << "1. Truy van thong tin cau thu theo ten doi bong" << endl;
                    cout << "2. Truy van cau thu theo ten cau thu" << endl;
                    cout << "3. Truy van cau thu theo CCCD cau thu" << endl;
                    cout << "0. Quay lai" << endl;
                    cout << "Nhap lua chon: "; cin >> lc12; cin.ignore();
                    Team t;
                    system("cls");
                    if(lc12 == 1) {
                        t.findPlayerByNameFootballTeam();
                    }
                    else if(lc12 == 2) {
                        t.findPlayerByName();
                    }
                    else if(lc12 == 3) {
                        t.findPlayerById();
                    }
                }while(lc12 != 0);
            }
            else if(lc1 == 3) {
                int lc12;
                do {
                system("cls");
                cout << "1. Truy van thong tin HLV theo ten doi bong" << endl;
                cout << "2. Truy van HLV theo CCCD " << endl;
                cout << "3. Truy van HLV theo ten HLV" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Nhap lua chon: "; cin >> lc12; cin.ignore();
                Team t;
                system("cls");
                if(lc12 == 1) {
                    t.findCoachByNameFootballTeam();
                }
                else if(lc12 == 2) {
                    t.findCoachByID();
                }
                else if(lc12 == 3) {
                    t.findCoachByName();
                }      
                }while(lc12!=0);

            }


            
            }while(lc1!=0);

        }
        else if(lc == 3) {
            int lc3;
            do {
                system("cls");
                cout << "1.Cap nhat thong tin doi bong" << endl;
                cout << "2.Cap nhat thong tin HLV" << endl;
                cout << "3.Cap nhat thong tin cau thu" << endl;
                cout << "0.Quay lai" << endl;
                cin >> lc3; cin.ignore();
                if(lc3 == 1) {
                    Team t; t.updateTeam();
                }
                else if(lc3 == 2) {
                    Coach c;
                    c.updateCoach();
                }
                else if(lc3 == 3) {
                    Player p;
                    p.updatePlayer();
                } 
            }while(lc3!=0);
        }
   }while(lc!=0);
}