#include "UserInterface.h"
#include "Utility.h"
#include "PlayerItems.h"
//using namespace std;

/*
  */
int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
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
    gotoxy(5, 5);
    cout<< "SUPER DUPER ROGULIKE 2001 MINI XS MAX 3310 PRO ELITE EXPERIENCE ROYAL 1.6 DELUXE VERSION EDITION 1ST GENERATION";
    TurnWhite;
    gotoxy(60, 24);
    cout << "EXIT";
    TurnBrightAqua;
    gotoxy(60, 14);
    cout << "START";
    gotoxy(64, 14);
    TurnWhite;
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 1) {
            TurnWhite;
            gotoxy(60, 24);
            cout << "EXIT";
            TurnBrightAqua;
            gotoxy(60, 14);
            cout << "START";
            gotoxy(64, 14);
            TurnWhite;
            flag=0;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "START";
            TurnBrightAqua;
            gotoxy(60, 24);
            cout << "EXIT";
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


string UserInterface::ClassMenu() {
    int flag = 0;
    string choice;
    TurnAqua;
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
    gotoxy(50, 5);
    cout << "SELECT CHARACTER`S CLASS";
    TurnWhite;
    gotoxy(60, 24);
    cout << "ARCHER";
    TurnAqua;
    gotoxy(60, 14);
    cout << "KNIGHT";
    gotoxy(64, 14);
    TurnWhite;
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == 1) {
            TurnWhite;
            gotoxy(60, 24);
            cout << "ARCHER";
            TurnAqua;
            gotoxy(60, 14);
            cout << "KNIGHT";
            gotoxy(64, 14);
            TurnWhite;

            flag=0;
        } else if (KeyCheck(Key) == 3) {

            TurnWhite;
            gotoxy(60, 14);
            cout << "KNIGHT";
            TurnAqua;
            gotoxy(60, 24);
            cout << "ARCHER";
            gotoxy(63, 24);
            TurnWhite;
            flag=1;
        }
        if (flag == 0 and KeyCheck(Key) == 5) {
            system("cls");
            return "Knight";
        } else if (flag == 1 and KeyCheck(Key) == 5) {
            system("cls");
            return "Archer";
        }
    }
}



void DrawGUI(int Health, int Stamina, int Armor, int Damage, int Gold) {
    gotoxy(8, 0);
    cout << "HP:" << Health;
    TurnBrightAqua;
    gotoxy(15, 0);
    cout << "STM:" << Stamina;
    TurnMagenta;
    gotoxy(23, 0);
    cout << "ARM:" << Armor;
    TurnLightRed;
    gotoxy(31, 0);
    cout << "DMG:" << Damage;
    TurnYellow;
    gotoxy(40, 0);
    cout << "GOLD:" << Gold;
    TurnMagenta;
    gotoxy(50, 0);
    cout << "Press I to open inventory, Press E to interact with something";
}

void ShowXY(int x, int y) {
    gotoxy(0, 28);
    cout << "        ";
    gotoxy(0, 28);
    cout << x << " " << y;
}
