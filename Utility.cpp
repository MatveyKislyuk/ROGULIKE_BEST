#include "Utility.h"

void InitializeSettings() {
    SetConsoleOutputCP( 65001 );
    system("Roguelike");
}
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void wait() {
    int a;
    cin >> a;
}

int KeyCheck(int Key) {
    if (Key == 'w' or Key == 'W' or Key == 230 or Key == 150 or Key == 24) {
        return 1;
    }
    if (Key == 'a' or Key == 'A' or Key == 228 or Key == 148 or Key == 17)  {
        return 2;
    }
    if (Key == 's' or Key == 'S' or Key == 235 or Key == 155 or Key == 25) {
        return 3;
    }
    if (Key == 'd' or Key == 'D' or Key == 162 or Key == 130 or Key == 16) {
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
    if (Key == 6) {
        return 8;
    }
    if (Key == '1') {
        return 10;
    }
    if (Key == '2') {
        return 11;
    }
    else { return 1;}
}

int Random(int First, int Second) {
    return (First + (rand() % (First + Second + 1)));
}