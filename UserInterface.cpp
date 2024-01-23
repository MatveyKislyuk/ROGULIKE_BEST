#include "UserInterface.h"
#include "Utility.h"
using namespace std;

string UserInterface::StartMenu() {
    int flag = 0;
    string choice = "Рыцарь";
    TurnBrightAqua;
    if (KeyCheck(6)) {
        gotoxy(0, 30);
        for (int i = 0; i < 120; i++) {
            gotoxy(0 + i, 0);
            cout << "▀";
            gotoxy(0 + i, 29);
            cout << "▄";
        }
        for (int i = 0; i < 30; i++) {
            gotoxy(0,  i);
            cout << "█";
            gotoxy(119, i);
            cout << "█";
        }
    }
    gotoxy(58, 5);
    cout<< "ROGULIKE BEST";
    TurnWhite;
    gotoxy(60, 24);
    cout << "Выход";
    TurnBrightAqua;
    gotoxy(60, 14);
    cout << "Начать";
    gotoxy(64, 14);
    TurnWhite;
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 1) {
            TurnWhite;
            gotoxy(60, 24);
            cout << "Выход";
            TurnBrightAqua;
            gotoxy(60, 14);
            cout << "Начать";
            gotoxy(64, 14);
            TurnWhite;
            flag=0;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "Начать";
            TurnBrightAqua;
            gotoxy(60, 24);
            cout << "Выход";
            gotoxy(63, 24);
            TurnWhite;
            flag=1;
        }
        if (flag == 0 and KeyCheck(Key) == 5) {
            system("cls");
            return choice;
        } else if (flag == 1 and KeyCheck(Key) == 5) {
            exit(0);
        }
    }
}




void DrawGUI(int Health, int Stamina, int Armor, int Damage, int Gold) {
    TurnGreen;
    gotoxy(9, 1);
    cout << "Здоровье:" << Health;
    TurnBrightAqua;
    gotoxy(22, 1);
    cout << "Бодрость:" << Stamina;
    TurnMagenta;
    gotoxy(35, 1);
    cout << "Броня:" << Armor;
    TurnLightRed;
    gotoxy(43, 1);
    cout << "Урон:" << Damage;
    TurnYellow;
    gotoxy(50, 1);
    cout << "Золото:" << Gold;
    TurnLightRed;
    gotoxy(62, 1);
    cout << "[";
    TurnBrightAqua;
    gotoxy(63, 1);
    cout << "Инвентарь: I";
    TurnYellow;
    gotoxy(77, 1);
    cout << "Взаимодействие: E";
    TurnLightRed;
    gotoxy(94, 1);
    cout << "]";
    TurnLightRed;
    gotoxy(55, 3);
    cout << "Удары: [Граната: 1 Меч: 2 ]";
}

void DrawGUIenemy(int Health, int Damage) {
    TurnGreen;
    gotoxy(9, 2);
    cout << "Здоровье:" << Health;
    TurnBrightAqua;
    gotoxy(22, 2);
    cout << "Урон:" << Damage;
}

void ShowXY(int x, int y) {
    TurnLightRed;
    gotoxy(1, 1);
    cout << "{" << x << " " << y << "}";
}
