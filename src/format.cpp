#pragma once
#include <Windows.h>

using namespace std;

void setUnicode();
void setColor();
void clrscr();
void pause();

/******************************************************/

void setUnicode() {
     SetConsoleOutputCP(65001);
}

void setColor(int background_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = background_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
    /*-----------------------------------------------------------
    0 = Black       1 = Blue        2 = Green       3 = Aqua
    4 = Red         5 = Purple      6 = Yellow      7 = White
    8 = Gray        9 = Li Blue     10 = LiGreen    11 = Li Aqua
    12 = Li Red     13 = Li Purple  14 = Li Yellow  15 = Bri White
    -------------------------------------------------------------*/
}

void clrscr() {
    system("cls");
}
void pause() {
    setColor(0,10);
    cout << "Nhấn phím bất kỳ để tiếp tục..." << endl;
    setColor(0,15);
    system("pause > nul");
}
