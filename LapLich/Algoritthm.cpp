#include <iostream>
#include <iomanip>
#include <thread> 
#include <chrono>
using namespace std;
class Date_Time {
	int minute,hour,day,month,year;
	string place;
public:
	Date_Time() {}
	Date_Time(int mi,int h,int d,int m,int y,string place) {
		this->minute = mi;
		this->hour = h;
		this->day = d;
		this->month = m;
		this->year = y;
		this->place = place;
	}
	friend ostream& operator<<(ostream &o, const Date_Time& dt) {
//		int k = dt.minute; 
		string minute = to_string(dt.minute);
		if(minute.size() == 1) minute = "0" + minute;
		o << setw(15) << "TIME: " << setw(2) << dt.hour << "h" << minute << setw(20) << "DAY: " <<setw(2) << dt.day << "/" <<setw(2) << dt.month << "/" << dt.year << setw(15) << "DIA DIEM: " << dt.place<< endl;
		return o;  
	}
	void setHour(int h) {
		this->hour = h; 
	}
	int getHour() {
		return this->hour;
	}
 	void increaseTime() {
			if(this->hour != 17) {
				if(this->hour == 7) this->hour = 9;
				else if(this->hour == 9)  this->hour = 15;
				else if(this->hour == 15) this->hour = 17;
			}
			else {
				this->hour = 7;
					if(this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
						if(this->day < 31) this->day++;
						else {
							if(this->month < 12) {
								this->day = 1;
								this->month++;
							}
							else {
								this->day = 1;
								this->month = 1;
								this->year++;
							}
						}
					}
					else if(this->month == 2) {
						if(this->day < 28) this->day++;
						else {
							if(!(this->year%4 ==0 && this->hour%100!=0)) {
								this->day = 1;
								this->month++; 	
							}
							else {
								if(this->day == 28) this->day++;
								else {
									this->day = 1;
									this->month++;
								}
							}
						}
					}
					else {
						if(this->day < 30) this->day++;
						else {
							this->day = 1;
							this->month++;
						}
					}
			}
		}
	
};
Date_Time d;

void push_val(int a[],int n) {
	int tmp = a[n-1];
	for(int i=n-1;i>=1;i--) {
		if(i > 1) {
			a[i] = a[i-1];
		}
		else {
			a[i] = tmp;
		}
	}
}
void Doi_Chan(int a[],int size) {
	for(int i=1;i<=size-1;i++) {
			cout << "Vong " << i << ":" << endl;
			int j = 0;
			if(a[0] == 0) j =1;
			for(j;j<size/2;j++) {
				cout << "Doi " <<setw(3) << a[j] << " - " << "Doi "<< setw(3) <<a[size-1-j] << d << endl;
				d.increaseTime();
				this_thread::sleep_for(chrono::milliseconds(100));
			}
			cout<< endl;
			if(d.getHour() != 7) {
				d.setHour(17);
				d.increaseTime();
			}
			d.setHour(17);
			d.increaseTime();
			push_val(a,size);
	}
}
void Doi_Le(int a[],int size) {
	int b[size+1];
	for(int i=size-1;i>=0;i--) {
		b[i+1] = a[i];
	}
	b[0] = 0;
	Doi_Chan(b,size+1);
}


int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int day,m,y;
	cout << "Nhap thoi gian bat dau \n";
	cout << "Nhap ngay: "; cin >> day;
	cout << "Nhap thang: "; cin >> m;
	cout << "Nhap nam: "; cin >> y;
	Date_Time d1(0,7,day,m,y,"DUT");
	d = d1;
	int size = sizeof(a)/sizeof(int);
	if(size%2 == 0) {
		Doi_Chan(a,size);
 	}
 	else {
	 	Doi_Le(a,size);
	 
	}
//	Date_Time d(00,7,13,10,2023,"DUT");
//	cout << d;
	
}