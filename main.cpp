#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
#include "Match/Match.h"
#include <iomanip>
// #include "LapLich/Algorithm.cpp"
using namespace std;
class Date_Time
{
    int minute, hour, day, month, year;
    String place;
public:
    Date_Time() {}
    Date_Time(int mi, int h, int d, int m, int y, String place)
    {
        this->minute = mi;
        this->hour = h;
        this->day = d;
        this->month = m;
        this->year = y;
        this->place = place;
    }
    friend ostream &operator<<(ostream &o, const Date_Time &dt)
    {
        String minute = String::tostring(dt.minute);
        if (minute.size() == 1) {
            String tmp('0');
            minute = tmp + minute;
        }
        if(dt.hour == 15 || dt.hour == 17) o << left <<dt.hour << "h" << setw(17) << minute + ",";
        else o << left <<dt.hour << "h" << setw(18) << minute + ",";
        o << left << dt.day << "/" << dt.month << "/" << setw(19) << String::tostring(dt.year) + "," << dt.place;
        return o;
    }
    void setHour(int h)
    {
        this->hour = h;
    }
    int getHour()
    {
        return this->hour;
    }
    void increaseTime()
    {
        if (this->hour != 17)
        {
            if (this->hour == 7)
                this->hour = 9;
            else if (this->hour == 9)
                this->hour = 15;
            else if (this->hour == 15)
                this->hour = 17;
        }
        else
        {
            this->hour = 7;
            if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
            {
                if (this->day < 31)
                    this->day++;
                else
                {
                    if (this->month < 12)
                    {
                        this->day = 1;
                        this->month++;
                    }
                    else
                    {
                        this->day = 1;
                        this->month = 1;
                        this->year++;
                    }
                }
            }
            else if (this->month == 2)
            {
                if (this->day < 28)
                    this->day++;
                else
                {
                    if (!((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0))
                    {
                        this->day = 1;
                        this->month++;
                    }
                    else
                    {
                        if (this->day == 28)
                            this->day++;
                        else
                        {
                            this->day = 1;
                            this->month++;
                        }
                    }
                }
            }
            else
            {
                if (this->day < 30)
                    this->day++;
                else
                {
                    this->day = 1;
                    this->month++;
                }
            }
        }
    }
};
Date_Time d;

void push_val(int a[], int n)
{
    int tmp = a[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        if (i > 1)
        {
            a[i] = a[i - 1];
        }
        else
        {
            a[i] = tmp;
        }
    }
}
void Doi_Chan(int a[], int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int j = 0;
        if (a[0] == 0)
            j = 1;
        for (j; j < size / 2; j++)
        {
            
            cout << left << setw(15) << String::tostring(i) + "," << setw(20) << String::tostring(a[j]) + "," << setw(20) <<String::tostring(a[size - 1 - j]) + "," << d << endl;
            d.increaseTime();
            //    this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << endl;
        if (d.getHour() != 7)
        {
            d.setHour(17);
            d.increaseTime();
        }
        d.setHour(17);
        d.increaseTime();
        push_val(a, size);
    }
}
void Doi_Le(int a[], int size)
{
    int b[size + 1];
    for (int i = size - 1; i >= 0; i--)
    {
        b[i + 1] = a[i];
    }
    b[0] = 0;
    Doi_Chan(b, size + 1);
}

void writetofile(ofstream &o, int check)
{
    ifstream f("Schedule.txt");
    if (check == 0)
    {
        f.seekg(0, ios::end);
        if (f.tellg() == 0)
        {
            o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
        }
        f.close();
    }
    if (check == 1)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    }
}


void func() {
    ofstream outFile("Schedule.txt");
    int size = 0;
    Vector<int> v;
    ifstream inf("Team.txt");
    if(inf.is_open()) {
        String tmp; String::getline(inf,tmp);
        while(!inf.eof()) {
            String::getline(inf,tmp); size++;
            String myId;
            for(int i=0;i<tmp.size();i++) {
                if(tmp[i] == ',') break;
                myId = myId + tmp[i];
            }
            v.push_back(String::toint(myId));
        }
    }
    int a[size];
    for(int i=0;i<size;i++) a[i] = v[i];
       // 1 10 2 3 4 5 6 7 8 9
    int day, m, y;
    cout << "Nhap thoi gian bat dau \n";
    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> m;
    cout << "Nhap nam: ";
    cin >> y;
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());
    writetofile(outFile, 1);
    if ((!((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && day == 29 && m == 2) || m > 12 || day > 31)
    {
        cout << "=> default"; return;
    }
    Date_Time d1(0, 7, day, m, y, "Dai hoc Bach Khoa Da Nang");
    d = d1;
    // int size = sizeof(a) / sizeof(int);
    if (size % 2 == 0)
        Doi_Chan(a, size);
    else
        Doi_Le(a, size);
    cout.rdbuf(coutbuf);
    outFile.close();
}



int main()
{   
   int lc; 
   do {
        system("cls");
        cout << "1. Them mot doi bong" << endl;
        cout << "2. Truy van thong tin " << endl;
        cout << "3. Cap nhat thong tin" << endl;
        cout << "4. Lap lich thi dau" << endl;
        cout << "5. Truy van va cap nhat thong tin tran dau" << endl;
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
        else if(lc == 4) {
            func();
            cout << "Lap lich thanh cong!" << endl;
            cout << "Nhan phim bat ki de tiep tuc"; getchar();

        }
        else if(lc == 5) {
            int lc5;
            do {
                system("cls");
                cout << "1.Truy van thong tin tran dau" << endl;
                cout << "2.Cap nhat thong tin tran dau" << endl;
                cout << "3.Nhap ket qua cho tran dau" << endl;
                cout << "0.Quay lai " << endl;
                cout << "Nhap lua chon: "; cin >> lc5; cin.ignore();
                Match m;
                if(lc5 == 1) {
                    int lc51;
                    do {
                        system("cls");
                        cout << "1.Tim tran dau theo ID doi" << endl;
                        cout << "2.Tim tran dau theo ngay" << endl;
                        cout << "3.Tim tran dau theo ten 1 doi" << endl;
                        cout << "4.Tim tran dau theo ten 2 doi" << endl;
                        cout << "0.Quay lai" << endl;
                        cout << "Nhap lua chon: "; cin >> lc51; cin.ignore();   
                        system("cls");                    
                        if(lc51 == 1) {
                            m.findMatchByIdTeam();
                        }
                        else if(lc51 == 2) {
                            m.findMatchByDay();
                        }
                        else if(lc51 == 3) {
                            m.findMatchByNameTeam();
                        }
                        else if(lc51 == 4) {
                            m.findMatchByTwoNameTeam();
                        }

                    }while(lc51 != 0);
                }
                else if(lc5==2) {
                    system("cls");
                    m.updateInforOfMatch();
                    cout << "Nhan phim bat ki de tiep tuc .." << endl;
                    getchar();
                }
                else if(lc5==3) {
                    m.enterResultMatch();
                }
            }while(lc5!=0);
        }
   }while(lc!=0);
}