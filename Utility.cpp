#include "Utility.h"

void InitializeSettings() {
    SetConsoleOutputCP( 65001 );
    system("title Rogueliek Rogulik Guguglik");
    //system("mode con cols=129 lines=32");
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void wait() {
    int a;
    cin >> a;
}

int KeyCheck(int Key) {
    if (Key == 'w' or Key == 'W' or Key == 230 or Key == 150) {
        return 1;
    }
    if (Key == 'a' or Key == 'A' or Key == 228 or Key == 148)  {
        return 2;
    }
    if (Key == 's' or Key == 'S' or Key == 235 or Key == 155) {
        return 3;
    }
    if (Key == 'd' or Key == 'D' or Key == 162 or Key == 130) {
        return 4;
    }
    if (Key == 13){
        return 5;
    }
    if (Key == 'e' or Key == 'E' or Key == 227 or Key == 147) {
        return 6;
    }
    if (Key == 'i' or Key == 'I' or Key == 232 or Key == 152) {
        return 7;
    }
    if (Key == 27) {
        return 8;
    }
}

int Random(int First, int Second) {
    return (First + (rand() % (First + Second + 1)));
}