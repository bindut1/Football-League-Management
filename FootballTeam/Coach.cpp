#include "Coach.h"
#include <iomanip>
#include <iostream>
using namespace std;


Coach::Coach(String m, String t, String ns, String ad, String nameTeam)
    : Human(m, t, ns, ad), nameFootballTeam(nameTeam)
{
    // cout << "Call Constructor of Coach" << endl;
}

Coach::~Coach()
{
    // cout << "Call Destructor of Coach" << endl;
}

void Coach::show()
{
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "DateOfBirth" << setw(30) << "Address" << setw(20) << "Age" << setw(20) << "NameFootballTeam" <<endl; 
    cout << left << setw(10) << this->id << setw(20) << this->name << setw(20) << this->dateOfBirth << setw(30) << this->address << setw(20) << this->age << setw(20) <<  this->nameFootballTeam << endl; 
}

void Coach::setNameFootballTeam(String name) {
    this->nameFootballTeam = name;
}

String Coach::getNameFootballTeam() {
    return this->nameFootballTeam;
}

void Coach::enterInforCoach() {
    String id, name, date,address;
    cout << "Nhap CCCD cua HLV: ";
    String::getline(cin,id);
    cout << "Nhap ho va ten cua HLV: ";
    String::getline(cin,name);
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    String::getline(cin,date);
    if(date[1] == '/') {
        String tmp("0");
        date = tmp + date;
    }
    if(date[4]  == '/') date.insert(3,"0");
    cout << "Nhap dia chi cua hlv: ";
    String::getline(cin,address);
    // cin.ignore();
    // Cap nhat thong tin HLV
    this->setId(id);
    this->setName(String::standadizeString(name));
    this->setDateOfBirth(date);
    this->setAddress(address);
    this->setAgeByDateOfBirth(date);
    this->setNameFootballTeam("ABC");
}

void Coach::saveInforIntoFile(ofstream& o) {
    char arrAge[10],numberClo[10],ylCard[10],rCard[10],goal[10];
    sprintf(arrAge,"%d",this->age);
    String myage(arrAge);
    ifstream f("Coach.txt");
    if(f) {
        f.seekg(0,ios::end);
        if(f.tellg() == 0) {
            o << left << setw(15) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(20) << "NameFootball Team" ;
        }
        f.close();
    }
    else {
        cout << "K mo tep duoc";
    }
    if(o.is_open()) {
        o <<endl<< left << setw(15) << this->id  + "," << setw(15) << this->name + "," << setw(15) << this->dateOfBirth + "," << setw(20) << this->address + "," << setw(10) << myage +","<< setw(20) << this->nameFootballTeam;
    }
}

Coach Coach::getCoachByNameFootballTeam(String nameFB) {
    ifstream i("Coach.txt");
    String tmp; String::getline(i,tmp);
    if(i.is_open()) {
            String::getline(i,tmp);
                int check = 1;
                bool status = false;
                String id,name,date,address,age,nameTeam;
                for(int i = 0; i < tmp.size() ; i++ ) {
                    if(tmp[i] != ' ') status = true;
                    if(tmp[i] == ',') {
                        status = false;
                        check++;
                        continue;
                    }
                    if(check == 1 &&  status) id = id +  tmp[i];
                    else if(check == 2 && status) name = name +  tmp[i];
                    else if(check == 3 && status) date = date +  tmp[i];
                    else if(check == 4 && status) address = address + tmp[i];
                    else if(check == 5 && status) age = age + tmp[i];
                    else if(check == 6 && status) {
                        nameTeam = nameTeam + tmp[i];
                        if((tmp[i+1] == ' ' &&  tmp[i+2] == ' ') || (tmp[i+1] == ' ' && i+1 == tmp.size()-1)) break;
                    } 
                }
                if(nameFB == nameTeam) {
                    Coach c(id,name,date,address,nameTeam);
                }
    }
    return Coach();
} 

void Coach::updateCoach()
{
    system("cls");
    String ma;
    cout << "Nhap CCCD cua HLV can chinh sua: ";
    String::getline(cin, ma);

    fstream file("Coach.txt", ios::in);
    fstream tempFile("tempCoach.txt", ios::out | ios::app);
    tempFile << left << setw(15) << "ID," << setw(15) << "Ten," << setw(15) << "DateOfBirth," << setw(20) << "Address," << setw(10) << "Age," << setw(20) << "NameFootball Team" << endl;

    if (file.is_open() && tempFile.is_open())
    {
        String tmp; String::getline(file, tmp); 
        while(!file.eof()) {
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

            if (ma == id)
            {
                int k, u;
                do
                {
                    system("cls");
                    cout << "1. Chinh sua Ten cua HLV" << endl;
                    cout << "2. Chinh sua Ngay sinh cua HLV" << endl;
                    cout << "3. Chinh sua Dia chi cua HLV" << endl;
                    cout << "4. Chinh sua Tuoi cua HLV" << endl;
                    cout << "5. Chinh sua doi bong HLV quan ly" << endl;
                    cout << "Moi nhap lua chon: ";
                    cin >> k;
                    cin.ignore();
                    String newName, newDate, newAddress, newNameTeam;
                    int newAge;
                    switch (k)
                    {
                    case 1:
                        cout << "Nhap ten HLV: ";
                        String::getline(cin, newName);
                        name = newName;
                        break;
                    case 2:
                        cout << "Nhap ngay sinh cua HLV: ";
                        String::getline(cin, newDate);
                        if (newDate[1] == '/') {
                            String tmp("0");
                            newDate = tmp + newDate;

                        }
                        if (newDate[4] == '/')
                            newDate.insert(3, "0");
                        date = newDate;
                        break;
                    case 3:
                        "Nhap dia chi cua HLV: ";
                        String::getline(cin, newAddress);
                        address = newAddress;
                        break;
                    case 4:
                        cout << "Nhap tuoi cua HLV: ";
                        cin >> newAge;
                        age = String::tostring(newAge);
                        break;
                    case 5:
                        cout << "Nhap doi bong HLV quan ly: ";
                        String::getline(cin, newNameTeam);
                        nameTeam = newNameTeam;
                        break;
                    default:
                        break;
                    }
                    cout << "Nhap 1 neu ban muon tiep tuc chinh sua, 0 neu muon thoat: ";
                    cin >> u;

                } while (u == 1);
                // Ghi du lieu da sua vo file tam
                tempFile << left << setw(15) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(20) << nameTeam << endl;
            }
            else
            {
                //Ghi du lieu cua may thang ko cap nhat
                tempFile << tmp << endl;
            }
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
