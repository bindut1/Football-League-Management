#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
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

int maxgoal()
{
    int m = -1e9;
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
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            m = max(m, String::toint(goal));
        }
    }
    i.close();
    return m;
}

//IN THEM CAU "CAP NHAT HLV/DOIBONG/CAU THU CHI DO BLA BLA ... THANH CONG O MAY CHUC NANG CAP NHAT", QUA MET KHONG CHINH NUA

main()
{
    int lc;
    do
    {
        system("cls");
        const char *filename1 = "Team.txt";
        const char *filename2 = "Coach.txt";
        const char *filename3 = "Player.txt";
        cout << "1. KHOI TAO GIAI DAU." << endl;
        cout << "2. QUAN LY GIAI DAU." << endl;
        cout << "0. Thoat." << endl;
        cout << "Xin moi nhap lua chon: ";
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            int lc1;
            do
            {
                system("cls");
                cout << "KHOI TAO GIAI DAU" << endl << endl;
                cout << "1. Them mot doi bong." << endl;
                cout << "2. Lap lich thi dau." << endl;
                cout << "0. Thoat." << endl;
                cout << "Xin moi nhap lua chon: ";
                cin >> lc1;
                cin.ignore();
                if (lc1 == 1)
                {
                    int lc11;
                    do
                    {
                        system("cls");
                        cout << "KHOI TAO GIAI DAU/Them mot doi bong" << endl << endl;
                        cout << "1. Them doi bong thu cong." << endl;
                        cout << "2. Them doi bong voi du lieu tu file." << endl;
                        cout << "0. Thoat." << endl;
                        cout << "Xin moi nhap lua chon: ";
                        cin >> lc11;
                        cin.ignore();
                        if (lc11 == 1)
                        {
                            Team t;
                            t.createNewFootballTeam();
                            cout << "Them doi bong thanh cong!" << endl;
                            cout << "Nhan Enter de tiep tuc . .";
                            getchar();
                        }
                        else if (lc11 == 2)
                        {
                            Team t;
                            Player p;
                            Coach c;
                            t.addTeamFromFile();
                            p.addPlayerFromFile();
                            c.addCoachFromFile();
                            cout << "Them doi bong thanh cong!" << endl;
                            cout << "Nhan Enter de tiep tuc . .";
                            getchar();
                        }
                    } while (lc11 != 0);
                }
                else if (lc1 == 2)
                {
                    system("cls");
                    if (countLines(filename1) <= 1)
                    {
                        cout << "KHOI TAO GIAI DAU/Lap lich thi dau" << endl << endl;
                        cout << "Phai co it nhat 2 doi bong de lap lich!" << endl;
                        cout << "Nhan Enter de tiep tuc . . .";
                        getchar();
                    }
                    else
                    {
                        func();
                        cout << endl << "Lap lich thi dau thanh cong!" << endl;
                        Match m;
                        m.getAllMatchFromFile();
                        cout << "Nhan Enter de tiep tuc . . .";
                        getchar();
                    }
                }

            } while (lc1 != 0);
        }
        else if (lc == 2)
        {
            if (isFileEmpty(filename1))
            {
                system("cls");
                cout << "Khoi tao du lieu cho giai dau truoc khi thuc hien chuc nang nay!" << endl;
                cout << "Nhan Enter de tiep tuc ..";
                getchar();
            }
            else
            {
                int lc2;
                do
                {
                    system("cls");
                    cout << "QUAN LY GIAI DAU" << endl << endl;
                    cout << "1. Truy van thong tin doi bong, cau thu va HLV." << endl;
                    cout << "2. Cap nhat thong tin doi bong, cau thu va HLV." << endl;
                    cout << "3. Truy van thong tin tran dau." << endl;
                    cout << "4. Cap nhat thong tin tran dau." << endl;
                    cout << "5. Truy van thong tin lich su tran dau." << endl;
                    cout << "6. Cap nhat thong tin lich su tran dau." << endl;
                    cout << "7. Tong ket giai dau." << endl;
                    cout << "0. Thoat." << endl;
                    cout << "Xin moi nhap lua chon: ";
                    cin >> lc2;
                    cin.ignore();
                    if (lc2 == 1)
                    {
                        int lc21;
                        do
                        {
                            system("cls");
                            cout << "QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV" << endl << endl;
                            cout << "1. Truy van thong tin cua mot doi bong." << endl;
                            cout << "2. Truy van thong tin cua HLV." << endl;
                            cout << "3. Truy van thong tin cua cau thu." << endl;
                            cout << "0. Thoat." << endl;
                            cout << "Xin moi nhap lua chon: ";
                            cin >> lc21;
                            cin.ignore();
                            if (lc21 == 1)
                            {
                                Team t;
                                t.findTeamByName();
                            }
                            else if (lc21 == 2)
                            {
                                int lc212;
                                do
                                {
                                    system("cls");
                                    cout << "QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV/Truy van thong tin cua HLV" << endl << endl;
                                    cout << "1. Truy van thong tin HLV theo ten doi bong." << endl;
                                    cout << "2. Truy van HLV theo CCCD." << endl;
                                    cout << "3. Truy van HLV theo ten HLV." << endl;
                                    cout << "0. Thoat." << endl;
                                    cout << "Xin moi nhap lua chon: ";
                                    cin >> lc212;
                                    cin.ignore();
                                    Team t;
                                    if (lc212 == 1)
                                    {
                                        t.findCoachByNameFootballTeam();
                                    }
                                    else if (lc212 == 2)
                                    {
                                        t.findCoachByID();
                                    }
                                    else if (lc212 == 3)
                                    {
                                        t.findCoachByName();
                                    }
                                } while (lc212 != 0);
                            }
                            else if (lc21 == 3)
                            {
                                int lc213;
                                do
                                {
                                    system("cls");
                                    cout << "QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV/Truy van thong tin cua cau thu" << endl << endl;
                                    cout << "1. Truy van thong tin cau thu theo ten doi bong." << endl;
                                    cout << "2. Truy van cau thu theo ten cau thu." << endl;
                                    cout << "3. Truy van cau thu theo CCCD cau thu." << endl;
                                    cout << "0. Thoat." << endl;
                                    cout << "Xin moi nhap lua chon: ";
                                    cin >> lc213;
                                    cin.ignore();
                                    Team t;
                                    if (lc213 == 1)
                                    {
                                        t.findPlayerByNameFootballTeam();
                                    }
                                    else if (lc213 == 2)
                                    {
                                        t.findPlayerByName();
                                    }
                                    else if (lc213 == 3)
                                    {
                                        t.findPlayerById();
                                    }
                                } while (lc213 != 0);
                            }
                        } while (lc21 != 0);
                    }
                    else if (lc2 == 2)
                    {
                        int lc22;
                        do
                        {
                            system("cls");
                            cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV" << endl << endl;
                            cout << "1. Cap nhat thong tin doi bong." << endl;
                            cout << "2. Cap nhat thong tin HLV." << endl;
                            cout << "3. Cap nhat thong tin cau thu." << endl;
                            cout << "4. Xoa doi bong." << endl;
                            cout << "5. Xoa HLV." << endl;
                            cout << "6. Xoa cau thu." << endl;
                            cout << "0. Thoat. " << endl;
                            cout << "Xin moi nhap lua chon: ";
                            cin >> lc22;
                            cin.ignore();
                            if (lc22 == 1)
                            {
                                int lc221;
                                do
                                {
                                    system("cls");
                                    cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin doi bong" << endl << endl;
                                    cout << "1. Them cau thu vao doi bong." << endl;
                                    cout << "2. Chinh sua thong tin doi bong." << endl;
                                    cout << "0. Thoat." << endl;
                                    cout << "Xin moi nhap lua chon: ";
                                    cin >> lc221;
                                    cin.ignore();
                                    Team t;
                                    if (lc221 == 1)
                                    {
                                        t.addPlayerToTeam();
                                    }
                                    else if (lc221 == 2)
                                    {
                                        t.updateTeam();
                                    }
                                } while (lc221 != 0);
                            }
                            else if (lc22 == 2)
                            {
                                Coach c;
                                c.updateCoach();
                            }
                            else if (lc22 == 3)
                            {
                                Player p;
                                p.updatePlayer();
                            }
                            else if (lc22 == 4)
                            {
                                Team t;
                                t.deleteTeamById();
                            }
                            else if (lc22 == 5)
                            {
                                Coach c;
                                c.deleteCoachById();
                            }
                            else if (lc22 == 6)
                            {
                                Player p;
                                p.deletePlayerById();
                            }
                        } while (lc22 != 0);
                    }
                    else if (lc2 == 3)
                    {
                        int lc23;
                        Match m;
                        do
                        {
                            system("cls");
                            cout << "QUAN LY GIAI DAU/Truy van thong tin tran dau" << endl << endl;
                            cout << "1. Truy van thong tin tran dau theo ID doi." << endl;
                            cout << "2. Truy van thong tin tran dau theo ngay." << endl;
                            cout << "3. Truy van thong tin tran dau theo ten 1 doi." << endl;
                            cout << "4. Truy van thong tin tran dau theo ten 2 doi." << endl;
                            cout << "0. Thoat." << endl;
                            cout << "Xin moi nhap lua chon: ";
                            cin >> lc23;
                            cin.ignore();
                            if (lc23 == 1)
                            {
                                m.findMatchByIdTeam();
                            }
                            else if (lc23 == 2)
                            {
                                m.findMatchByDay();
                            }
                            else if (lc23 == 3)
                            {
                                m.findMatchByNameTeam();
                            }
                            else if (lc23 == 4)
                            {
                                m.findMatchByTwoNameTeam();
                            }

                        } while (lc23 != 0);
                    }
                    else if (lc2 == 4)
                    {
                        int lc24;
                        do
                        {
                            system("cls");
                            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau" << endl << endl;
                            cout << "1. Chinh sua thong tin tran dau." << endl;
                            cout << "2. Them ket qua cho tran dau." << endl;
                            cout << "0. Thoat" << endl;
                            cout << "Xin moi nhap lua chon: ";
                            cin >> lc24;
                            cin.ignore();
                            if (lc24 == 1)
                            {
                                Match m;
                                m.updateInforOfMatch();
                            }
                            else if (lc24 == 2)
                            {
                                Match m;
                                m.enterResultMatch();
                            }
                        } while (lc24 != 0);
                    }
                    else if (lc2 == 5)
                    {
                        //XEM LAI
                        HistoryMatch h;
                        h.showHistoryMatch();
                    }
                    else if (lc2 == 6)
                    {
                        //XEM LAI
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau" << endl << endl;
                        HistoryMatch h;
                        h.updateHistoryMatch();
                    }
                    else if (lc2 == 7)
                    {
                        int lc27;
                        do
                        {
                            system("cls");
                            cout << "QUAN LY GIAI DAU/Tong ket giai dau" << endl << endl;
                            cout << "1. Tong so tran dau da dien ra." << endl;
                            cout << "2. Tong so doi bong tham gia giai dau." << endl;
                            cout << "3. Tong so cau thu tham gia giai dau." << endl;
                            cout << "4. Tong so HLV cua giai dau." << endl;
                            cout << "5. Doi bong co thu hang cao nhat (Doi vo dich)." << endl;
                            cout << "6. Cau thu co nhieu ban thang nhat (Vua pha luoi)." << endl;
                            cout << "0. Thoat." << endl;
                            cout << "Xin moi nhap lua chon: ";
                            cin >> lc27;
                            cin.ignore();
                            if (lc27 == 1)
                            {
                                int line = countLines(filename1);
                                int kq = (line * (line - 1)) / 2;
                                system("cls");
                                cout << "QUAN LY GIAI DAU/Tong ket giai dau/Tong so tran dau da dien ra" << endl << endl;
                                cout << "Tong so tran dau da dien ra la: " << kq << endl;
                                cout << "Nhan Enter de tiep tuc . . ";
                                getchar();
                            }
                            else if (lc27 == 2)
                            {
                                int line = countLines(filename1);
                                system("cls");
                                cout << "QUAN LY GIAI DAU/Tong ket giai dau/Tong so doi bong tham gia giai dau" << endl << endl;
                                cout << "Tong so doi bong tham gia giai dau la: " << line << endl;
                                cout << "Nhan Enter de tiep tuc . . ";
                                getchar();
                            }
                            else if (lc27 == 3)
                            {
                                int line = countLines(filename3);
                                system("cls");
                                cout << "QUAN LY GIAI DAU/Tong ket giai dau/Tong so cau thu tham gia giai dau" << endl << endl;
                                cout << "Tong so cau thu tham gia giai dau la: " << line << endl;
                                cout << "Nhan Enter de tiep tuc . . ";
                                getchar();
                            }
                            else if (lc27 == 4)
                            {
                                int line = countLines(filename2);
                                system("cls");
                                cout << "QUAN LY GIAI DAU/Tong ket giai dau/Tong so HLV cua giai dau" << endl << endl;
                                cout << "Tong so HLV tham gia giai dau la: " << line << endl;
                                cout << "Nhan Enter de tiep tuc . . ";
                                getchar();
                            }
                            else if (lc27 == 5)
                            {
                                system("cls");
                                cout << "QUAN LY GIAI DAU/Tong ket giai dau/Doi bong co thu hang cao nhat (Doi vo dich)" << endl << endl;
                                cout << "Doi bong co thu hang cao nhat (Doi vo dich) la: " << endl;
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
                                        if (rank == "1")
                                        {
                                            cout << nameTeam << endl;
                                        }
                                    }
                                }
                                cout << "Nhan Enter de tiep tuc . .";
                                getchar();
                            }
                            else if (lc27 == 6)
                            {
                                system("cls");
                                cout << "QUAN LY GIAI DAU/Tong ket giai dau/Cau thu co nhieu ban thang nhat (Vua pha luoi)" << endl << endl;
                                cout << "Cau thu co nhieu ban thang nhat (Vua pha luoi) la: " << endl;
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
                                            else if (check == 10 && status && tmp[i] != '\n')
                                            {
                                                nameTeam = nameTeam + tmp[i];
                                                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                                                    break;
                                            }
                                        } 
                                        if (goal == String::tostring(maxgoal()))
                                        {
                                            cout << name << " voi " << maxgoal() << " ban thang." << endl;
                                        }
                                    }
                                }
                                cout << "Nhan Enter de tiep tuc . .";
                                getchar();
                            }
                        } while (lc27 != 0);
                    }
                } while (lc2 != 0);
            }
        }
    } while (lc != 0);
}
