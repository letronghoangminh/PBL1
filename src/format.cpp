#include <Windows.h>

using namespace std;

void SetUnicode();
void SetColor();
void clrscr();
void pause();

/******************************************************/

void SetUnicode() {
     SetConsoleOutputCP(65001);
}

void SetColor(int background_color, int text_color)
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
    cout << "Nhấn phím bất kỳ để tiếp tục..." << endl;
    system("pause > nul");
}
