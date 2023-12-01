#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
// #include "LapLich/Algorithm.cpp"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
#include "Algorithm.h"
#include "CTDL/String.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
// #include "mylib.h"
// using namespace std;
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}


void printCentered(String text,int check  = 1) {
    // Lấy độ rộng của màn hình console
    int screenWidth = getConsoleWidth(); // Đặt độ rộng màn hình console của bạn tại đây

    // Tính độ dài của dòng văn bản
    int textLength = static_cast<int>(text.size());

    // Tính toán vị trí để in ra giữa màn hình
    int padding = (screenWidth - textLength) / 2;

    // In ra khoảng trắng đầu tiên để căn giữa
    cout << setw(padding + textLength) << text ;
    if(check) cout << endl;
}
String drawBorder(int size) {
   String tmp = "";
   for(int i=1;i<=size;i++) {
      tmp = tmp + "-";
   }
   return tmp;
}
String drawOption(String opt,int size) {
   opt = String("|") + opt;
   String tmp = "";
   for(int i=1;i<(size-opt.size());i++) {
      tmp = tmp + " ";
   }
   opt = opt + tmp + "|";
   return opt;
}
// String drawSelectOption(String opt,int size) {
//    String tmp = "";
//    for(int i=1;i<=(size-opt.size());i++) {
//       tmp = tmp + " ";
//    }
//    return opt + tmp;
// }
int main() {
    // Ví dụ sử dụng hàm in dòng văn bản ở giữa màn hình
   String tmp = drawBorder(50);
   String lc1 = drawOption("1. KHOI TAO GIAI DAU.",50);
   String lc2 = drawOption("2. QUAN LY GIAI DAU.",50);
   String lc3 = drawOption("0. THOAT.",50);
   String lc  = "Nhap lua chon cua ban: ";
   printCentered("KHOI TAO GIAI DAU/Lap lich thi dau");
   printCentered(tmp);
   printCentered(lc1);
   printCentered(lc2);
   printCentered(lc3);
   printCentered(tmp);
   printCentered(lc,0);
   getchar();


    return 0;
}
// #include <iostream>
// #include <iomanip>


