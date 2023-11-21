#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
#include "Match/Match.h"
#include "Algorithm.h"
#include <iomanip>
using namespace std;
int countLines(const char *filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Khong the mo file!" << endl;
        return -1; 
    }

    int lineCount = 0;
    String line;
    String::getline(file, line);
    while (!file.eof())
    {
        String::getline(file, line);
        lineCount++;
    }
    file.close();
    return lineCount;
}

bool isFileEmpty(const char *filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Khong the mo file!" << endl;
        return false;
    }
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}

int main()
{
    int lc;
    do
    {
        const char *filename = "Team.txt";
        system("cls");
        cout << "1. Them mot doi bong." << endl;
        cout << "2. Truy van thong tin doi bong, cau thu va HLV." << endl;
        cout << "3. Cap nhat thong tin doi bong, cau thu va HLV." << endl;
        cout << "4. Lap lich thi dau." << endl;
        cout << "5. Truy van va cap nhat thong tin tran dau." << endl;
        cout << "0. Ket thuc." << endl;
        cout << "Xin moi nhap lua chon: ";
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            system("cls");
            Team t;
            t.createNewFootballTeam();
            system("cls");
            cout << "Khoi tao doi bong thanh cong!" << endl;
            cout << "Nhan Enter de tiep tuc .." ; getchar();
        }
        else if (lc >= 2 && lc <= 5)
        {
            if (isFileEmpty(filename)) {
                system("cls");
                cout << "Nhap du lieu cho doi bong truoc khi thuc hien chuc nang nay" << endl;
                cout << "Nhan Enter de tiep tuc .."; getchar();
            }
            else
            {
                if (lc == 2)
                {
                    int lc1;
                    do
                    {
                        system("cls");
                        cout << "1. Truy van thong tin cua mot doi bong." << endl;
                        cout << "2. Truy van thong tin cau thu." << endl;
                        cout << "3. Truy van thong tin HLV." << endl;
                        cout << "0. Quay lai." << endl;
                        cout << "Nhap lua chon: ";
                        cin >> lc1;
                        cin.ignore();
                        if (lc1 == 1)
                        {
                            system("cls");
                            Team t;
                            t.findTeamByName();
                        }
                        else if (lc1 == 2)
                        {
                            int lc12;
                            do
                            {
                                system("cls");
                                cout << "1. Truy van thong tin cau thu theo ten doi bong." << endl;
                                cout << "2. Truy van cau thu theo ten cau thu." << endl;
                                cout << "3. Truy van cau thu theo CCCD cau thu." << endl;
                                cout << "0. Quay lai." << endl;
                                cout << "Nhap lua chon: ";
                                cin >> lc12;
                                cin.ignore();
                                Team t;
                                system("cls");
                                if (lc12 == 1)
                                {
                                    t.findPlayerByNameFootballTeam();
                                }
                                else if (lc12 == 2)
                                {
                                    t.findPlayerByName();
                                }
                                else if (lc12 == 3)
                                {
                                    t.findPlayerById();
                                }
                            } while (lc12 != 0);
                        }
                        else if (lc1 == 3)
                        {
                            int lc12;
                            do
                            {
                                system("cls");
                                cout << "1. Truy van thong tin HLV theo ten doi bong." << endl;
                                cout << "2. Truy van HLV theo CCCD." << endl;
                                cout << "3. Truy van HLV theo ten HLV." << endl;
                                cout << "0. Quay lai." << endl;
                                cout << "Nhap lua chon: ";
                                cin >> lc12;
                                cin.ignore();
                                Team t;
                                system("cls");
                                if (lc12 == 1)
                                {
                                    t.findCoachByNameFootballTeam();
                                }
                                else if (lc12 == 2)
                                {
                                    t.findCoachByID();
                                }
                                else if (lc12 == 3)
                                {
                                    t.findCoachByName();
                                }
                            } while (lc12 != 0);
                        }

                    } while (lc1 != 0);
                }
                else if (lc == 3)
                {
                    int lc3;
                    do
                    {
                        system("cls");
                        cout << "1. Cap nhat thong tin doi bong." << endl;
                        cout << "2. Cap nhat thong tin HLV." << endl;
                        cout << "3. Cap nhat thong tin cau thu." << endl;
                        cout << "4. Xoa doi bong." << endl;
                        cout << "5. Xoa HLV." << endl;
                        cout << "6. Xoa cau thu." << endl;
                        cout << "0. Quay lai" << endl;
                        cout << "Xin moi nhap lua chon: ";
                        cin >> lc3;
                        cin.ignore();
                        if (lc3 == 1)
                        {
                            Team t;
                            t.updateTeam();
                            system("cls");
                            cout << "Cap nhat thong tin doi bong thanh cong" << endl;
                        }
                        else if (lc3 == 2)
                        {
                            Coach c;
                            c.updateCoach();
                             system("cls");
                            cout << "Cap nhat thong tin HLV thanh cong" << endl;
                        }
                        else if (lc3 == 3)
                        {
                            Player p;
                            p.updatePlayer();
                            cout << "Cap nhat thong tin cau thu thanh cong" << endl;
                        }
                        else if (lc3 == 4)
                        {
                            Team t;
                            t.deleteTeamById();
                            cout << "Xoa doi bong thanh cong" << endl;
                        }
                        else if (lc3 == 5)
                        {
                            Coach c;
                            c.deleteCoachById();
                            cout << "Xoa HLV thanh cong" << endl;
                        }
                        else if (lc3 == 6)
                        {
                            Player p;
                            p.deletePlayerById();
                            cout << "Xoa cau thu thanh cong" << endl;
                        }
                      if(lc3!= 0)  {
                         cout << "Nhan Enter de tiep tuc .." ; getchar();
                      }
                    } while (lc3 != 0);
                }
                else if (lc == 4)
                {
                    if(countLines(filename)  <= 1) {
                        system("cls");
                        cout << "Phai co it nhat 2 doi de lap lich" << endl;
                    }
                    else {
                    system("cls");
                    func();
                    system("cls");
                    cout << "Lap lich thi dau thanh cong!" << endl;
                    }
                    cout << "Nhan Enter de tiep tuc .." ; getchar();
                }
                else if (lc == 5)
                {
                    int lc5;
                    do
                    {
                        system("cls");
                        cout << "1. Truy van thong tin tran dau" << endl;
                        cout << "2. Cap nhat thong tin tran dau" << endl;
                        cout << "3. Nhap ket qua cho tran dau" << endl;
                        cout << "0. Quay lai " << endl;
                        cout << "Nhap lua chon: ";
                        cin >> lc5;
                        cin.ignore();
                        Match m;
                        if (lc5 == 1)
                        {
                            int lc51;
                            do
                            {
                                system("cls");
                                cout << "1. Tim tran dau theo ID doi" << endl;
                                cout << "2. Tim tran dau theo ngay" << endl;
                                cout << "3. Tim tran dau theo ten 1 doi" << endl;
                                cout << "4. Tim tran dau theo ten 2 doi" << endl;
                                cout << "0. Quay lai" << endl;
                                cout << "Nhap lua chon: ";
                                cin >> lc51;
                                cin.ignore();
                                system("cls");
                                if (lc51 == 1)
                                {
                                    m.findMatchByIdTeam();
                                }
                                else if (lc51 == 2)
                                {
                                    m.findMatchByDay();
                                }
                                else if (lc51 == 3)
                                {
                                    m.findMatchByNameTeam();
                                }
                                else if (lc51 == 4)
                                {
                                    m.findMatchByTwoNameTeam();
                                }

                            } while (lc51 != 0);
                        }
                        else if (lc5 == 2)
                        {
                            system("cls");
                            m.updateInforOfMatch();
                            cout << "Cap nhat thong tin tran dau thanh cong" << endl;
                            cout << "Nhan phim bat ki de tiep tuc .." << endl;
                            getchar();
                        }
                        else if (lc5 == 3)
                        {
                            m.enterResultMatch();
                            cout << "Nhap ket qua tran dau thanh cong" << endl;
                            cout << "Nhan phim bat ki de tiep tuc .." << endl;
                        }
                    } while (lc5 != 0);
                }
            }
        }
    } while (lc != 0);
}