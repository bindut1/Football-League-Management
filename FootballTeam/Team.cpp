
#include "Team.h"
#include <iomanip>
#include <limits>
#include <fstream>
Team::Team()
{
    // cout << "Tao t";
    // this->idTeamFootball = this->getSizeTeamFromFile();
    this->numberGoal = 0;
    this->numberLoseGoal = 0;
    this->rank = 1;
    this->point = 0;
    this->difference = 0;
}
Team::~Team()
{
}
bool Team::cmp(Team t1, Team t2)
{
    int p1 = t1.getPoint(), p2 = t2.getPoint();
    if (p1 != p2)
    {
        return p1 > p2;
    }
    return t1.getDifference() > t2.getDifference();
}
void Team::setGoal(int goal)
{
    this->numberGoal = goal;
}
void Team::setLoseGoal(int loseGoal)
{
    this->numberLoseGoal = loseGoal;
}

int Team::getPoint()
{
    return this->point;
}

void Team::setPoint(int point)
{
    this->point = point;
}

int Team::getDifference()
{
    return this->difference;
}

void Team::setDifference(int difference)
{
    this->difference = difference;
}
void Team::setRank(int rank)
{
    this->rank = rank;
}
int Team::getGoal()
{
    return this->numberGoal;
}
int Team::getLoseGoal()
{
    return this->numberLoseGoal;
}

String Team::getSizeTeamFromFile()
{
    ifstream f("Team.txt");
    int size = 0;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String::getline(f, tmp);
            size++;
        }
    }
    char id[10];
    sprintf(id, "%d", size + 1);
    return String(id);
}

Team::Team(String nameTeam, Coach coach, int rank, int numberGoal, int numberLoseGoal, int point)
{
    this->nameFootballTeam = nameTeam;
    this->coach = coach;
    this->rank = rank;
    this->numberGoal = numberGoal;
    this->numberLoseGoal = numberLoseGoal;
    this->point = point;
    this->difference = numberGoal - numberLoseGoal;
    this->idTeamFootball = this->getSizeTeamFromFile();
}
void Team::setIdTeam(String id)
{
    this->idTeamFootball = id;
}

String Team::getIdTeam()
{
    return this->idTeamFootball;
}

void Team::showAllMemberOfTeam()
{
    cout << endl
         << "Danh Sach Cau Thu" << endl;
    for (int i = 0; i < this->listMember.size(); i++)
    {
        this->listMember[i].show();
    }
}

void Team::showALLInforOfTeam()
{
    cout << "DOI BONG " << this->nameFootballTeam << endl;
    cout << "Thong Tin HLV" << endl;
    this->coach.show();

    cout << endl
         << "Danh Sach Cau Thu" << endl;
    cout << left << setw(10) << "ID" << setw(15) << "Ten" << setw(15) << "DateOfBirth" << setw(20) << "Address" << setw(10) << "Age" << setw(15) << "NumberClothes" << setw(15) << "yellowCard" << setw(10) << "redCard" << setw(10) << "Goal" << setw(20) << "NameFootballTeam" << endl;
    for (int i = 0; i < this->listMember.size(); i++)
    {
        this->listMember[i].show2();
    }

    cout << "Rank: " << this->rank << endl;
    cout << "Point: " << this->point << endl;
    cout << "Difference: " << this->difference << endl;
    cout << "NumberGoal: " << this->numberGoal << endl;
    cout << "NumberLoseGoal: " << this->numberLoseGoal << endl;
}
// void Team::showHistoryMatch() {
//     this->supportTeam.duyetxuoi(this->head);
// }
void Team::addPlayer(Player &p)
{
    this->listMember.push_back(p);
}

void Team::addCoach(Coach &c)
{
    this->coach = c;
}

String Team::getNameFootballTeam()
{
    return this->nameFootballTeam;
}

void Team::setNameFootballTeam(String name)
{
    this->nameFootballTeam = name;
}

String Team::standardizeName(String s)
{
    String tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
            tmp = tmp + toupper(s[0]);
        else
        {
            if (s[i - 1] == ' ')
                tmp = tmp + toupper(s[i]);
            else
                tmp = tmp + tolower(s[i]);
        }
    }
    return tmp;
}

void Team::findPlayerByName()
{
    cout << "Nhap ten can tim: ";
    String nameFind;
    String::getline(cin, nameFind);
    nameFind = String::standadizeString(nameFind);
    ifstream i("Player.txt");
    bool val = true;
    if (i.is_open())
    {
        String tmp, nameTeam;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal;
            nameTeam = "";
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                    nameTeam = nameTeam + tmp[i];
                if (check > 2 && name != nameFind)
                    break;
            }
            if (name == nameFind)
            {
                Player p(id, name, date, address, nameTeam, String_to_int(numberClo), String_to_int(goal), String_to_int(yellowCard), String_to_int(redCard));
                // cout << this->nameFootballTeam << endl;
                p.show1();
                val = false;
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    if (val)
        cout << "Khong tim thay ket qua tuong ung" << endl;
    cout << "Nhan Enter de tiep tuc ...";
    getchar();
}

void Team::findPlayerByNameFootballTeam()
{
    bool kt = true;
    cout << "Nhap ten doi bong can tim: ";
    String nameFB;
    String::getline(cin, nameFB);
    nameFB = this->standardizeName(nameFB);
    bool val = true;
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (nameTeam != nameFB)
            
                kt = false;
                cout << "Doi bong " << nameFB << " khong ton tai" << endl;
                break;
            
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
        if(kt)
            cout << left << setw(10) << "ID" << setw(15) << "Ten" << setw(15) << "DateOfBirth" << setw(20) << "Address" << setw(10) << "Age" << setw(15) << "NumberClothes" << setw(15) << "yellowCard" << setw(10) << "redCard" << setw(10) << "Goal" << setw(20) << "NameFootballTeam" << endl;
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (nameTeam == nameFB)
            {
                Player p(id, name, date, address, nameTeam, String_to_int(numberClo), String_to_int(goal), String_to_int(yellowCard), String_to_int(redCard));
                p.show2();
                val = false;
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    i.close();
    cout << "Nhan Enter de tiep tuc ...";
    getchar();
    //if (val)
        //cout << "Khong tim thay ket qua!" << endl;
}

Vector<Player> Team::getListPlayerByNameFootballTeam(String nameFB)
{
    nameFB = this->standardizeName(nameFB);
    Vector<Player> v;
    bool val = true;
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            // cout << nameTeam <<" " << nameFB << endl;
            if (nameTeam == nameFB)
            {
                Player p(id, name, date, address, nameTeam, String_to_int(numberClo), String_to_int(goal), String_to_int(yellowCard), String_to_int(redCard));
                v.push_back(p);
                //  cout << "Func() : " ;p.show();
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    i.close();
    return v;
    // if(val) cout << "Khong tim thay ket qua!" << endl;
}

void Team::findPlayerById()
{
    cout << "Nhap ID cua cau thu: ";
    String idPlayer;
    String::getline(cin, idPlayer);
    bool val = true;
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (id == idPlayer)
            {
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                p.show1();
                val = false;
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    else
    {
        cout << "Khong mo duoc" << endl;
    }
    i.close();
    if (val)
        cout << "Khong tim thay ket qua!" << endl;
    cout << endl
         << "Nhan Enter de tiep tuc...";
    getchar();
}
void Team::createNewFootballTeam()
{
    system("cls");
    // cout << "Mo";
    String nameFootballTeam;
    cout << "Nhap ten doi bong can them: ";
    String::getline(cin, nameFootballTeam);
    nameFootballTeam = String::standadizeString(nameFootballTeam);
    this->setNameFootballTeam(nameFootballTeam);
    int lc;
    do
    {
        system("cls");
        cout << "Nhap lua chon cua ban\n";
        cout << "1. Them cau thu vao doi Bong\n";
        cout << "2. Them HLV cho doi bong (Toi da 1 HLV)\n";
        cout << "0. Ket thuc\n";
        cout << "Nhap lua chon: ";
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            Player p;
            p.enterInforPlayer();
            p.setNameFootballTeam(this->nameFootballTeam);
            ofstream o("Player.txt", ios::app);
            p.savePlayerToFile(o);
            this->listMember.push_back(p);
        }
        else if (lc == 2)
        {
            Coach c;
            c.enterInforCoach();
            c.setNameFootballTeam(this->nameFootballTeam);
            ofstream o("Coach.txt", ios::app);
            c.saveInforIntoFile(o);
            this->coach = c;
        }
        else
        {
            cout << "Ban co chac chan muon thoat (y/n)";
            String ctn;
            String::getline(cin, ctn);
            if (ctn == "y" || ctn == "Y")
            {
                this->setIdTeam(this->getSizeTeamFromFile());
                ofstream o("Team.txt", ios::app);
                this->saveTeamToFile(o);
                break;
            }
        }
    } while (true);
}

/* void Team::deletePlayerById(ifstream &i, ofstream &tmp2)
{

    cout << "Nhap ID cua cau thu: ";
    String idPlayer;
    String::getline(cin, idPlayer);
    bool check = true;
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (id != idPlayer)
            {
                Player p(id, name, date, address, nameTeam, String_to_int(numberClo), String_to_int(goal), String_to_int(yellowCard), String_to_int(redCard));
                p.savePlayerToFile(tmp2, 1);
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    i.close();
    tmp2.close();
    const char *i1("Player.txt");
    const char *tmp1("Tmp.txt");
    // Xoa file Player.txt chứa dữ liệu cũ
    remove(i1);
    // Đổi file Tmp.txt chứa dữ liệu mới thành file Player.txt
    rename(tmp1, "Player.txt");
} */

void Team::dkcDeleteTeamwithPlayer(String tt)
{
    fstream file("Player.txt", ios::in);
    fstream tempFile("tempPlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard," << setw(10) << "redCard," << setw(10) << "Goal," << setw(20) << "NameFootballTeam" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            // cout << tt;
            if (tt != nameTeam)
                tempFile << tmp << endl;
        }

        file.close();
        tempFile.close();
        remove("Player.txt");
        rename("tempPlayer.txt", "Player.txt");
    }
    else
        cout << "Khong mo dc file";
}

void Team::dkcDeleteTeamwithCoach(String tt)
{
    fstream file("Coach.txt", ios::in);
    fstream tempFile("tempCoach.txt", ios::out | ios::app);
    tempFile << left << setw(15) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(20) << "NameFootball Team" << endl;

    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }

            if (tt != nameTeam)
                tempFile << tmp << endl;
        }
        file.close();
        tempFile.close();
        remove("Coach.txt");
        rename("tempCoach.txt", "Coach.txt");
    }
    else
    {
        cout << "Khong mo dc file";
    }
}

void Team::deleteTeamById()
{
    bool ck = false;
    String ma, thaythe;
    cout << "Nhap ID doi bong can xoa: ";
    String::getline(cin, ma);
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Rank" << endl;
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
                thaythe = nameTeam;
            else
            {
                tempFile << tmp << endl;
                ck = true;
            }
               
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Khong mo dc file";
    dkcDeleteTeamwithPlayer(thaythe);
    dkcDeleteTeamwithCoach(thaythe);
    if(ck) cout << "Doi bong co ID " << ma << " khong ton tai" << endl << endl;
}

void Team::saveTeamToFile(ofstream &o, int check)
{
    char arrRank[10], numberGo[10], arrNumMember[10], numberLose[10], numPoint[10], numDiffer[10];
    sprintf(arrRank, "%d", this->rank);
    sprintf(numberGo, "%d", this->numberGoal);
    sprintf(arrNumMember, "%d", this->listMember.size());
    sprintf(numberLose, "%d", this->numberLoseGoal);
    sprintf(numPoint, "%d", this->point);
    sprintf(numDiffer, "%d", this->difference);
    String myRank(arrRank);
    String myGoal(numberGo);
    String myLoseGoal(numberLose);
    String myPoint(numPoint);
    String myDifference(numDiffer);
    String myNumMember(arrNumMember);
    ifstream f("Team.txt");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Rank";
        f.close();
    }
    if (check == 1)
    {
        o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Rank";
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(10) << this->idTeamFootball + "," << setw(20) << this->nameFootballTeam + "," << setw(20) << myNumMember + "," << setw(15) << this->coach.getName() + "," << setw(15) << myGoal + "," << setw(15) << myLoseGoal + "," << setw(15) << myDifference + "," << setw(15) << myPoint + "," << setw(15) << myRank;
    }
    else
    {
        cout << "K mo duoc";
    }
}

Coach Team::getCoachByNameFootballTeam(String nameFB)
{
    ifstream i("Coach.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (nameFB == nameTeam)
            {
                Coach c(id, name, date, address, nameTeam);
                return c;
            }
        }
    }
    return Coach();
}
void Team::setListMember(Vector<Player> v)
{
    this->listMember = v;
}

Team Team::findTeamByName()
{
    bool kt = true;
    cout << "Nhap ten doi bong can tim: ";
    String tenDb;
    String::getline(cin, tenDb);
    tenDb = String::standadizeString(tenDb);
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            //  cout << nameTeam << " " << tenDb << endl;
            if (nameTeam == tenDb)
            {
                kt = false;
                Coach c = this->getCoachByNameFootballTeam(tenDb);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                t.setIdTeam(id);
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                t.showALLInforOfTeam();
                // cout << "Nhan Enter de tiep tuc ..."; getchar();
                // return t;
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }

        }
    }
    if(kt) cout << "Doi bong " << tenDb << " khong ton tai!" << endl;
    cout << "Nhan Enter de tiep tuc ...";
    getchar();
    
    return Team();
    
}

Team Team::getTeamById(String idF)
{
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            //  cout << nameTeam << " " << tenDb << endl;
            if (id == idF)
            {
                Coach c = this->getCoachByNameFootballTeam(nameTeam);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                t.setIdTeam(id);
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                return t;
            }
        }
    }
    return Team();
}
void Team::showRankOfTeam()
{
    cout << setw(20) << "Doi Bong: " << this->nameFootballTeam << setw(20) << "Rank: " << this->rank << endl;
}

void Team::showInforOfCoach()
{
    this->coach.show();
}

void Team::testFile()
{
    // ifstream f("Player.txt");
    // if(f.is_open()) {
    //     cout << "Mo duoc" << endl;
    // }
    // else {
    //     cout << "Ko mo duoc" << endl;
    // }
    this->findPlayerById();
}
void Team::findCoachByNameFootballTeam()
{
    cout << "Nhap ten doi bong can tim: ";
    String nameFB;
    String::getline(cin, nameFB);
    nameFB = String::standadizeString(nameFB);
    ifstream i("Coach.txt");
    String tmp;
    String::getline(i, tmp);
    if (i.is_open())
    {
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            // cout << nameTeam << " " << nameFB << endl;
            if (nameFB == nameTeam)
            {
                Coach c(id, name, date, address, nameTeam);
                c.show();
            }
            else
            {
                cout << "Doi bong " << nameFB << " khong ton tai" << endl;
                break;
            }
        }
    }
    cout << "Nhan Enter de tiep tuc";
    getchar();
}
void Team::findCoachByID()
{
    cout << "Nhap ID HLV can tim: ";
    String idHLV;
    String::getline(cin, idHLV);
    ifstream i("Coach.txt");
    String tmp;
    String::getline(i, tmp);
    if (i.is_open())
    {
        String::getline(i, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, nameTeam;
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
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (idHLV == id)
        {
            Coach c(id, name, date, address, nameTeam);
            c.show();
        }
        else
        {
            cout << "HVL co ID " << idHLV << " khong ton tai" << endl;
            
        }
    }
    cout << "Nhan Enter de tiep tuc ...";
    getchar();
}

void Team::findCoachByName()
{
    cout << "Nhap ten HLV can tim: ";
    String tenHLV;
    String::getline(cin, tenHLV);
    tenHLV = String::standadizeString(tenHLV);
    ifstream i("Coach.txt");
    String tmp;
    String::getline(i, tmp);
    if (i.is_open())
    {
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (tenHLV == name)
            {
                Coach c(id, name, date, address, nameTeam);
                c.show();
            }
            else
            {
                cout << "HLV co ten " << tenHLV << " khong ton tai" << endl;
                break;
            }
        }
    }
    cout << "Nhan Enter de tiep tuc ...";
    getchar();
}
void Team::updateTeam()
{
    bool ktra = false;
    system("cls");
    String ma;
    cout << "Nhap ID doi bong can chinh sua: ";
    String::getline(cin, ma);
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Rank" << endl;
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
                int u;
                do
                {
                    system("cls");
                    String newname, newhlv;
                    int newgoal, newlgoal, newhso, newpoint, newrank;
                    cout << "1. Chinh sua Ten doi bong" << endl;
                    cout << "2. Chinh sua Tong so ban thang" << endl;
                    cout << "3. Chinh sua Tong so ban thua" << endl;
                    cout << "4. Chinh sua Hieu so" << endl;
                    cout << "5. Chinh sua Diem" << endl;
                    cout << "6. Chinh sua Thu hang" << endl;
                    cout << "Moi nhap lua chon: ";
                    int t;
                    cin >> t;
                    cin.ignore();
                    int kt;
                    bool trangthai;
                    fstream file1("Coach.txt", ios::in);
                    fstream tempFile1("tempCoach.txt", ios::out | ios::app);
                    int kiemtra;
                    bool tt;
                    fstream file2("Player.txt", ios::in);
                    fstream tempFile2("tempPlayer.txt", ios::out | ios::app);
                    String thaythe;
                    switch (t)
                    {
                    case 1:
                        thaythe = nameTeam;
                        cout << "Nhap Ten doi bong: ";
                        String::getline(cin, newname);
                        nameTeam = newname;

                        tempFile1 << left << setw(15) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(20) << "NameFootball Team" << endl;

                        if (file1.is_open() && tempFile1.is_open())
                        {
                            String temp;
                            String::getline(file1, temp);
                            while (!file1.eof())
                            {
                                String::getline(file1, temp);
                                kt = 1;
                                trangthai = false;
                                String idc, namec, datec, addressc, agec, nameTeamc;
                                for (int i = 0; i < temp.size(); i++)
                                {
                                    if (temp[i] != ' ')
                                        trangthai = true;
                                    if (temp[i] == ',')
                                    {
                                        trangthai = false;
                                        kt++;
                                        continue;
                                    }
                                    if (kt == 1 && trangthai)
                                        idc = idc + temp[i];
                                    else if (kt == 2 && trangthai)
                                        namec = namec + temp[i];
                                    else if (kt == 3 && trangthai)
                                        datec = datec + temp[i];
                                    else if (kt == 4 && trangthai)
                                        addressc = addressc + temp[i];
                                    else if (kt == 5 && trangthai)
                                        agec = agec + temp[i];
                                    else if (kt == 6 && trangthai)
                                    {
                                        nameTeamc = nameTeamc + temp[i];
                                        if ((temp[i + 1] == ' ' && temp[i + 2] == ' ') || (temp[i + 1] == ' ' && i + 1 == temp.size() - 1))
                                            break;
                                    }
                                }

                                if (thaythe == nameTeamc)
                                {
                                    nameTeamc = newname;
                                    // Ghi du lieu da sua vo file tam
                                    tempFile1 << left << setw(15) << idc + "," << setw(15) << namec + "," << setw(15) << datec + "," << setw(20) << addressc + "," << setw(10) << agec + "," << setw(20) << nameTeamc << endl;
                                }
                                else
                                {
                                    // Ghi du lieu cua may thang ko cap nhat
                                    tempFile1 << temp << endl;
                                }
                            }
                            file1.close();
                            tempFile1.close();
                            remove("Coach.txt");
                            rename("tempCoach.txt", "Coach.txt");
                        }
                        else
                        {
                            cout << "Khong mo dc file";
                        }

                        tempFile2 << left << setw(10) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(15) << "NumberClothes," << setw(15) << "yellowCard," << setw(10) << "redCard," << setw(10) << "Goal," << setw(20) << "NameFootballTeam" << endl;
                        if (file2.is_open() && tempFile2.is_open())
                        {
                            String tam;
                            String::getline(file2, tam);
                            while (!file2.eof())
                            {
                                String::getline(file2, tam);
                                kiemtra = 1;
                                tt = false;
                                String idp, namep, datep, addressp, agep, numberClop, yellowCardp, redCardp, goalp, nameTeamp;
                                for (int i = 0; i < tam.size(); i++)
                                {
                                    if (tam[i] != ' ')
                                        tt = true;
                                    if (tam[i] == ',')
                                    {
                                        tt = false;
                                        kiemtra++;
                                        continue;
                                    }
                                    if (kiemtra == 1 && tt)
                                        idp = idp + tam[i];
                                    else if (kiemtra == 2 && tt)
                                        namep = namep + tam[i];
                                    else if (kiemtra == 3 && tt)
                                        datep = datep + tam[i];
                                    else if (kiemtra == 4 && tt)
                                        addressp = addressp + tam[i];
                                    else if (kiemtra == 5 && tt)
                                        agep = agep + tam[i];
                                    else if (kiemtra == 6 && tt)
                                        numberClop = numberClop + tam[i];
                                    else if (kiemtra == 7 && tt)
                                        yellowCardp = yellowCardp + tam[i];
                                    else if (kiemtra == 8 && tt)
                                        redCardp = redCardp + tam[i];
                                    else if (kiemtra == 9 && tt)
                                        goalp = goalp + tam[i];
                                    else if (kiemtra == 10 && tt && tam[i] != '\n')
                                    {
                                        nameTeamp = nameTeamp + tam[i];
                                        if ((tam[i + 1] == ' ' && tam[i + 2] == ' ') || (tam[i + 1] == ' ' && i + 1 == tam.size() - 1))
                                            break;
                                    }
                                }
                                if (thaythe == nameTeamp)
                                {
                                    nameTeamp = newname;

                                    tempFile2 << left << setw(10) << idp + "," << setw(15) << namep + "," << setw(15) << datep + "," << setw(20) << addressp + "," << setw(10) << agep + "," << setw(15) << numberClop + "," << setw(15) << yellowCardp + "," << setw(10) << redCardp + "," << setw(10) << goalp + "," << setw(20) << nameTeamp << endl;
                                }
                                else
                                {
                                    tempFile2 << tam << endl;
                                }
                            }
                            file2.close();
                            tempFile2.close();
                            remove("Player.txt");
                            rename("tempPlayer.txt", "Player.txt");
                        }
                        else
                            cout << "Khong mo dc file";

                        break;
                    // case 2:
                    //     cout << "Nhap Ten HLV: ";
                    //     getline(cin, newhlv);
                    //     nameCoach = newhlv;
                    //     break;
                    case 2:
                        cout << "Nhap Tong so ban thang: ";
                        cin >> newgoal;
                        numberGoal = String::tostring(newgoal);
                        break;
                    case 3:
                        cout << "Nhap Tong so ban thua: ";
                        cin >> newlgoal;
                        numberLoseGoal = String::tostring(newlgoal);
                        break;
                    case 4:
                        cout << "Nhap Hieu so: ";
                        cin >> newhso;
                        difference = String::tostring(newhso);
                        break;
                    case 5:
                        cout << "Nhap Diem: ";
                        cin >> newpoint;
                        point = String::tostring(newpoint);
                        break;
                    case 6:
                        cout << "Nhap thu hang: ";
                        cin >> newrank;
                        rank = String::tostring(newrank);
                        break;
                    default:
                        break;
                    }
                    cout << "Go 1 ban muon tiep tuc chinh sua, 0 neu muon thoat: ";
                    cin >> u;
                } while (u == 1);
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
            }
            else
            {
                tempFile << tmp << endl;
                ktra = true;
                // cout << "Doi bong co ID " << ma << " khong ton tai" << endl;
                // break;
            }
                 
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Khong mo dc file";
    if(ktra) cout << "Doi bong co ID " << ma << " khong ton tai" << endl << endl;
}
void Team::sortRankAllTeam()
{
    Vector<Team> v;
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            Coach c = this->getCoachByNameFootballTeam(nameTeam);
            Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
            t.setIdTeam(id);
            t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
            v.push_back(t);
        }
    }
    ofstream o("Tmp.txt");
    Vector<Team>::sort(v, cmp);
    o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Rank";
    for (int i = 0; i < v.size(); i++)
    {
        v[i].setRank(i + 1);
        v[i].saveTeamToFile(o);
    }
    o.close();
    i.close();
    const char *i1("Team.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Team.txt");
}

void Team::updateTeamAfterMatch(String idCheck, int goal, int loseGoal, int bonusPoint)
{

    ifstream i("Team.txt");
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Rank";
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            Coach c = this->getCoachByNameFootballTeam(nameTeam);
            Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
            t.setIdTeam(id);
            t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
            if (id == idCheck)
            {
                t.setGoal(String::toint(numberGoal) + goal);
                t.setLoseGoal(String::toint(numberLoseGoal) + loseGoal);
                t.setDifference(t.getGoal() - t.getLoseGoal());
                t.setPoint(String::toint(point) + bonusPoint);
            }
            if (id != ' ')
                t.saveTeamToFile(o);
        }
    }
    o.close();
    i.close();
    const char *i1("Team.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Team.txt");
}

int Team::String_to_int(String x)
{
    char a[x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        a[i] = x[i];
    }
    return atoi(a);
}