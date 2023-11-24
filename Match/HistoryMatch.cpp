#include "HistoryMatch.h"
#include <iostream>
#include <iomanip>
using namespace std;

HistoryMatch::HistoryMatch()
{
}
HistoryMatch::HistoryMatch(Match m, int g1, int g2)
    : Match(m)
{
    this->numGoalTeam1 = g1;
    this->numGoalTeam2 = g2;
}
HistoryMatch::~HistoryMatch()
{
}

void HistoryMatch::showHistoryMatch()
{
    system("cls");
    Team t, t1, t2;
    t1 = t.getTeamById(this->getIdTeam1());
    t2 = t.getTeamById(this->getIdTeam2());
    cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau" << endl
         << endl;
    cout << "Vong dau so: " << this->getIdRound() << endl;
    cout << left << setw(30) << t1.getNameFootballTeam() << setw(15) << this->numGoalTeam1 << setw(15) << "-" << setw(50) << this->numGoalTeam2 << t2.getNameFootballTeam() << endl;
    cout << "Ngay thi dau: " << this->getDate() << endl;
    cout << "Dia chi thi dau: " << this->getAddress() << endl;
    getchar();
}

void HistoryMatch::saveHistoryMatchToFile(ofstream &o)
{
    ifstream f("HistoryMatch.txt");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem";
        f.close();
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(15) << this->getIdRound() + "," << setw(20) << this->getIdTeam1() + "," << setw(20) << String::tostring(this->numGoalTeam1) + "," << setw(20) << this->getIdTeam2() + "," << setw(20) << String::tostring(this->numGoalTeam2) + "," << setw(20) << this->getTime() + "," << setw(25) << this->getDate() + "," << setw(20) << this->getAddress();
    }
}

void HistoryMatch::updateGoalandLostGoalofTeam(String ma, String goal, String lostgoal)
{
    system("cls");
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    nameTeam = nameTeam + tmp[i];
                else if (check == 3 && status)
                    numMember = numMember + tmp[i];
                else if (check == 4 && status)
                    nameCoach = nameCoach + tmp[i];
                else if (check == 5 && status)
                    numberGoal = numberGoal + tmp[i];
                else if (check == 6 && status)
                    numberLoseGoal = numberLoseGoal + tmp[i];
                else if (check == 7 && status)
                    difference = difference + tmp[i];
                else if (check == 8 && status)
                    point = point + tmp[i];
                else if (check == 9 && status && tmp[i] != '\n')
                {
                    rank = rank + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (ma == id)
            {
                numberGoal = goal;
                numberLoseGoal = lostgoal;
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Khong mo dc file";
}

void HistoryMatch::updateHistoryMatch()
{
    //Xem lai 
    system("cls");
    bool kt = true;
    String idvong, idm, idh;
    String name1 = returnNameTeamByID(idm);
    String name2 = returnNameTeamByID(idh);
    cout << "Nhap ID vong dau: ";
    String::getline(cin, idvong);
    cout << "Nhap ID doi thu nhat: ";
    String::getline(cin, idm);
    cout << "Nhap ID doi thu hai: ";
    String::getline(cin, idh);
    fstream file("HistoryMatch.txt", ios::in);
    fstream tempFile("tempHistoryMatch.txt", ios::out | ios::app);
    tempFile << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String idr, id1, goal1, id2, goal2, time, date, address;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    idr = idr + tmp[i];
                else if (check == 2 && status)
                    id1 = id1 + tmp[i];
                else if (check == 3 && status)
                    goal1 = goal1 + tmp[i];
                else if (check == 4 && status)
                    id2 = id2 + tmp[i];
                else if (check == 5 && status)
                    goal2 = goal2 + tmp[i];
                else if (check == 6 && status)
                    time = time + tmp[i];
                else if (check == 7 && status)
                    date = date + tmp[i];
                else if (check == 8 && status && tmp[i] != '\n')
                {
                    address = address + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idvong == idr && idm == id1 && idh == id2)
            {
                kt = false;
                int lc;
                do
                {
                    system("cls");
                    String banthang1, banthang2;
                    Team t;
                    int g1 = String::toint(banthang1);
                    int onegoal = String::toint(goal1);
                    int g2 = String::toint(banthang2);
                    int twogoal = String::toint(goal2);
                    cout << "1. Chinh sua so ban thang cua doi thu nhat." << endl;
                    cout << "2. Chinh sua so ban thang cua doi thu hai." << endl;
                    cout << "0. Thoat." << endl;
                    cout << "Xin moi nhap lua chon: ";
                    cin >> lc;
                    String bt1 = goal1;
                    String bt2 = goal2;
                    String am1;
                    String am2;
                    cin.ignore();
                    if (lc == 1)
                    {
                        system("cls");
                        cout << "Nhap so ban thang moi: ";
                        String::getline(cin, banthang1);
                        goal1 = banthang1;
                        am1 = String::tostring(-String::toint(banthang1));
                        // cout << am1;
                        // getchar();
                        updateGoalandLostGoalofTeam(idm, banthang1, bt2);
                        updateGoalandLostGoalofTeam(idh, bt2, am1);
                        if (g1 > twogoal)
                        {
                            t.updateTeamAfterMatch(id1, g1, twogoal, 3);
                            t.updateTeamAfterMatch(id2, twogoal, g1, 0);
                            t.sortRankAllTeam();
                        }
                        else if (g1 < twogoal)
                        {
                            t.updateTeamAfterMatch(id1, g1, twogoal, 0);
                            t.updateTeamAfterMatch(id2, twogoal, g1, 3);
                            t.sortRankAllTeam();
                        }
                        else
                        {
                            t.updateTeamAfterMatch(id1, g1, twogoal, 1);
                            t.updateTeamAfterMatch(id2, twogoal, g1, 1);
                            t.sortRankAllTeam();
                        }
                    }
                    else if (lc == 2)
                    {
                        system("cls");
                        cout << "Nhap so ban thang moi: ";
                        String::getline(cin, banthang2);
                        goal2 = banthang2;
                        am2 = String::tostring(-String::toint(banthang2));
                        //updateGoalandLostGoalofTeam(idh, banthang2, bt1);
                        //updateGoalandLostGoalofTeam(idm, bt1, am2);
                        if (onegoal > g2)
                        {
                            t.updateTeamAfterMatch(id1, onegoal, g2, 3);
                            t.updateTeamAfterMatch(id2, g2, onegoal, 0);
                            t.sortRankAllTeam();
                        }
                        else if (g1 < twogoal)
                        {
                            t.updateTeamAfterMatch(id1, onegoal, g2, 0);
                            t.updateTeamAfterMatch(id2, g2, onegoal, 3);
                            t.sortRankAllTeam();
                        }
                        else
                        {
                            t.updateTeamAfterMatch(id1, onegoal, g2, 1);
                            t.updateTeamAfterMatch(id2, g2, onegoal, 1);
                            t.sortRankAllTeam();
                        }
                    }
                } while (lc != 0);
                tempFile << left << setw(15) << idr + "," << setw(20) << id1 + "," << setw(20) << goal1 + "," << setw(20) << id2 + "," << setw(20) << goal2 + "," << setw(20) << time + "," << setw(25) << date + "," << setw(20) << address << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("HistoryMatch.txt");
        rename("tempHistoryMatch.txt", "HistoryMatch.txt");
    }
    else
        cout << "Khong mo duoc file";
    if (kt)
        cout << "Khong tim thay tran dau nao!" << endl;
}