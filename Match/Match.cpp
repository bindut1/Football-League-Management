#include "Match.h"
#include <iostream>
#include <iomanip>
using namespace std;

Match::Match()
{
}
Match::~Match()
{
}
Match::Match(const Team &a, const Team &b, String address, String time, String date)
{
    cout << "Constructor of Match" << endl;
    this->v.push_back(a);
    this->v.push_back(b);
    this->address = address;
    this->time = time;
    this->date = date;
    cout << "Khoi tao thanh cong" << endl;
}

void Match::showMatch()
{
    cout << "Vong dau so " << this->idRound << endl;
    cout << left << setw(50) << this->v[0].getNameFootballTeam() << this->v[1].getNameFootballTeam() << endl;
    cout << setw(20) << this->time << setw(20) << this->date << endl;
    cout << "DIEN RA TAI SVD: " << this->address << endl;
}

void Match::changeAddress(String newAddress)
{
    this->setAddress(newAddress);
}

void Match::changeTime(String newTime)
{
    this->setTime(newTime);
}

Vector<Team> Match::getTwoTeam()
{
    return this->v;
}

String Match::getAddress()
{
    return this->address;
}

void Match::setAddress(String address)
{
    this->address = address;
}

String Match::getTime()
{
    return this->time;
}

void Match::setTime(String time)
{
    this->time = time;
}
void Match::addTeam(const Team &t)
{
    this->v.push_back(t);
}
void Match::setDate(String d)
{
    this->date = d;
}
String Match::getDate()
{
    return this->date;
}
void Match::setIdRound(String idr)
{
    this->idRound = idr;
}
String Match::getIdRound()
{
    return this->idRound;
}

Vector<Match> Match::getAllMatchFromFile()
{
    ifstream f("Schedule.txt");
    Vector<Match> v;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Match m;
                m.setAddress(address);
                m.setTime(time);
                m.setDate(date);
                m.setIdRound(idRound);
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                m.addTeam(t1);
                m.addTeam(t2);
                m.showMatch();
            }
        }
    }
    else
    {
        cout << "Khong mo duoc";
    }
    return v;
}

void Match::findMatchByIdTeam()
{
    cout << "Nhap ID doi can tim: ";
    String idFind;
    String::getline(cin, idFind);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (idTeam1 == idFind || idTeam2 == idFind)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                }
            }
        }
    }
    cout << "Nhan phim bat ki de tiep tuc ..";
    getchar();
}

Vector<Match> Match::getListMatchByIdTeam()
{
    bool val = true;
    cout << "Nhap ID doi can tim: ";
    String idFind;
    String::getline(cin, idFind);
    Vector<Match> v;
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (idTeam1 == idFind || idTeam2 == idFind)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    // m.showMatch();
                    v.push_back(m);
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    return v;
}

void Match::findMatchByDay()
{
    bool val = true;
    cout << "Nhap ngay can tim (dd/mm/yyyy): ";
    String dayFind;
    String::getline(cin, dayFind);
    dayFind = String::standadizeDay(dayFind);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (dayFind == date)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    cout << "Nhan phim bat ki de tiep tuc ..";
    getchar();
}

void Match::findMatchByNameTeam()
{
    bool val = true;
    cout << "Nhap ten doi bong can tim: ";
    String nameTeamFind;
    String::getline(cin, nameTeamFind);
    nameTeamFind = String::standadizeString(nameTeamFind);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                if (t1.getNameFootballTeam() == nameTeamFind || t2.getNameFootballTeam() == nameTeamFind)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    cout << "Nhan phim bat ki de tiep tuc ..";
    getchar();
}

void Match::findMatchByTwoNameTeam()
{
    bool val = true;
    cout << "Nhap ten doi thu nhat: ";
    String nameTeam1;
    String::getline(cin, nameTeam1);
    nameTeam1 = String::standadizeString(nameTeam1);
    cout << "Nhap ten doi thu hai: ";
    String nameTeam2;
    String::getline(cin, nameTeam2);
    nameTeam2 = String::standadizeString(nameTeam2);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                if ((t1.getNameFootballTeam() == nameTeam1 && t2.getNameFootballTeam() == nameTeam2) || (t1.getNameFootballTeam() == nameTeam2 && t2.getNameFootballTeam() == nameTeam1))
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    cout << "Nhan phim bat ki de tiep tuc ..";
    getchar();
}
Match Match::getMatchByIdRoundAndIdTwoTeam(String idR, String id1, String id2)
{
    bool val = true;
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                // cout << idRound << " " << idTeam1 << " " << idTeam2 << " " << time << " " << date << " " << address << endl;
                if (idRound == idR && ((idTeam1 == id1 && idTeam2 == id2) || (idTeam1 == id2 && idTeam2 == id1)))
                {
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    // m.showMatch();
                    val = false;
                    return m;
                }
            }
        }
    }
    Match m;
    m.setIdRound("0");
    if (val)
        cout << "Khong tim thay tran dau nao!";
    return m;
}
void Match::updateMatch(String t, Match m1, int checkCase, String td)
{
    ifstream f("Schedule.txt");
    ofstream o("Tmp.txt");
    o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                Match m;
                m.setAddress(address);
                m.setTime(time);
                m.setDate(date);
                m.setIdRound(idRound);
                m.addTeam(t1);
                m.addTeam(t2);
                if (idRound == m1.getIdRound() && ((idTeam1 == m1.getIdTeam1() && idTeam2 == m1.getIdTeam2()) || (idTeam1 == m1.getIdTeam2() && idTeam2 == m1.getIdTeam1())))
                {
                    if (checkCase == 0)
                        m.setTime(t);
                    else if (checkCase == 1)
                        m.setDate(t);
                    else if (checkCase == 2)
                    {
                        m.setTime(t);
                        m.setDate(td);
                    }
                    else if (checkCase == 3)
                    {
                        m.setAddress(t);
                    }
                    m.showMatch();
                }
                o << left << setw(15) << m.getIdRound() + "," << setw(20) << m.getIdTeam1() + "," << setw(20) << m.getIdTeam2() + "," << setw(20) << m.getTime() + "," << setw(25) << m.getDate() + "," << setw(20) << m.getAddress() << endl;
            }
            else
            {
                o << "                                " << endl;
            }
        }
    }
    f.close();
    o.close();

    const char *i1("Schedule.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Schedule.txt");
}

void Match::updateInforOfMatch()
{
    String idRound, idTeam1, idTeam2;
    cout << "Nhap so vong dau: ";
    String::getline(cin, idRound);
    cout << "Nhap id doi thu nhat: ";
    String::getline(cin, idTeam1);
    cout << "Nhap id doi thu hai: ";
    String::getline(cin, idTeam2);
    system("cls");
    Match m = Match::getMatchByIdRoundAndIdTwoTeam(idRound, idTeam1, idTeam2);
    int lc;
    do
    {
        cout << "1.Thay doi thoi gian thi dau" << endl;
        cout << "2.Thay doi ngay thi dau" << endl;
        cout << "3.Thay doi thoi gian va ngay thi dau" << endl;
        cout << "4.Thay doi dia diem thi dau" << endl;
        cout << "0.Quay lai" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            cout << "Nhap thoi gian thi dau moi: ";
            String timeNew;
            String::getline(cin, timeNew);
            this->updateMatch(timeNew, m, 0);
        }
        else if (lc == 2)
        {
            cout << "Nhap ngay thi dau moi (dd/mm/yyyy): ";
            String dateNew;
            String::getline(cin, dateNew);
            this->updateMatch(dateNew, m, 1);
        }
        else if (lc == 3)
        {
            String timeNew, dateNew;
            cout << "Nhap thoi gian thi dau moi: ";
            String::getline(cin, timeNew);
            cout << "Nhap ngay thi dau moi (dd/mm/yyyy): ";
            String::getline(cin, dateNew);
            this->updateMatch(timeNew, m, 2, dateNew);
        }
        else if (lc == 4)
        {
            String addressNew;
            cout << "Nhap dia chi thi dau moi: ";
            String::getline(cin, addressNew);
            this->updateMatch(addressNew, m, 3);
        }

    } while (lc != 0);
}

void Match::deleteMatchByIdRoundAndTwoTeam(Match &m1)
{
    ifstream f("Schedule.txt");
    ofstream o("Tmp.txt");
    o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                Match m;
                m.setAddress(address);
                m.setTime(time);
                m.setDate(date);
                m.setIdRound(idRound);
                m.addTeam(t1);
                m.addTeam(t2);
                if (!(idRound == m1.getIdRound() && ((idTeam1 == m1.getIdTeam1() && idTeam2 == m1.getIdTeam2()) || (idTeam1 == m1.getIdTeam2() && idTeam2 == m1.getIdTeam1()))))
                {
                    o << left << setw(15) << m.getIdRound() + "," << setw(20) << m.getIdTeam1() + "," << setw(20) << m.getIdTeam2() + "," << setw(20) << m.getTime() + "," << setw(25) << m.getDate() + "," << setw(20) << m.getAddress() << endl;
                }
            }
            else
            {
                o << "                                " << endl;
            }
        }
    }
    f.close();
    o.close();

    const char *i1("Schedule.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Schedule.txt");
}

void Match::enterResultMatch()
{
    String idRound, idTeam1, idTeam2;
    cout << "Nhap ID vong dau: ";
    String::getline(cin, idRound);
    cout << "Nhap ID doi thu nhat: ";
    String::getline(cin, idTeam1);
    cout << "Nhap ID doi thu hai: ";
    String::getline(cin, idTeam2);
    Match m = Match::getMatchByIdRoundAndIdTwoTeam(idRound, idTeam1, idTeam2);
    int lc;
    int g1, g2;
    cout << "Nhap so ban thang cua doi thu nhat: ";
    cin >> g1;
    cout << "Nhap so ban thang cua doi thu hai: ";
    cin >> g2;
    cin.ignore();
    Team t;
    if (g1 > g2)
    {
        t.updateTeamAfterMatch(idTeam1, g1, g2, 3);
        t.updateTeamAfterMatch(idTeam2, g2, g1, 0);
        t.sortRankAllTeam();
    }
    else if (g1 < g2)
    {
        t.updateTeamAfterMatch(idTeam1, g1, g2, 0);
        t.updateTeamAfterMatch(idTeam2, g2, g1, 3);
        t.sortRankAllTeam();
    }
    else
    {
        t.updateTeamAfterMatch(idTeam1, g1, g2, 1);
        t.updateTeamAfterMatch(idTeam2, g2, g1, 1);
        t.sortRankAllTeam();
    }
    m.deleteMatchByIdRoundAndTwoTeam(m);
    m.saveToHistoryMatch(idTeam1, idTeam2, g1, g2);
    do
    {
        system("cls");
        cout << "1.Nhap ban thang cho cau thu" << endl;
        cout << "2.Nhap the vang cho cau thu" << endl;
        cout << "3.Nhap the do cho cau thu" << endl;
        cout << "0.Quay lai" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            String id, goal;
            cout << "Nhap ID cau thu ghi ban: ";
            String::getline(cin, id);
            cout << "Nhap so bang thang: ";
            String::getline(cin, goal);
            Player::updatePlayerAfterMatch(id, 0, 0, String::toint(goal));
        }
        else if (lc == 2)
        {
            String id, numYlCard;
            cout << "Nhap ID cau thu bi the vang: ";
            String::getline(cin, id);
            cout << "Nhap so the vang: ";
            String::getline(cin, numYlCard);
            Player::updatePlayerAfterMatch(id, String::toint(numYlCard), 0, 0);
        }
        else if (lc == 3)
        {
            String id;
            cout << "Nhap ID cau thu bi the do: ";
            String::getline(cin, id);
            Player::updatePlayerAfterMatch(id, 0, 1, 0);
        }

    } while (lc != 0);
    Player::sortAllPlayer();
}
void Match::saveToHistoryMatch(String idT1, String idT2, int g1, int g2)
{
    ofstream o("HistoryMatch.txt", ios::app);
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
          << left << setw(15) << this->getIdRound() + "," << setw(20) << idT1 + "," << setw(20) << String::tostring(g1) + "," << setw(20) << idT2 + "," << setw(20) << String::tostring(g2) + "," << setw(20) << this->getTime() + "," << setw(25) << this->getDate() + "," << setw(20) << this->getAddress();
    }
}
String Match::getIdTeam1()
{
    return this->v[0].getIdTeam();
}

String Match::getIdTeam2()
{
    return this->v[1].getIdTeam();
}