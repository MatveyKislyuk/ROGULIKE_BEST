#ifndef CONSOLE_ROGUELIKE_CPP_UTILITY_H
#define CONSOLE_ROGUELIKE_CPP_UTILITY_H

#include <typeinfo>
#include <string>
#include <iostream>
#include <windows.h>
#include <chrono>
#include <vector>
#include <conio.h>
#include <thread>
#include <future>
#include <cstdlib>
#include <algorithm>
#include <vector>



using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std::literals; //future  -   Enable standard literals as 2s and ""s.
using namespace std;


#define TurnBlack SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0)
#define TurnGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2)
#define TurnAqua SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3)
#define TurnLightRed SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)
#define TurnMagenta SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5)
#define TurnYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)
#define TurnWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#define TurnGrey   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8)
#define TurnBrightGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
#define TurnBrightAqua SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)


typedef struct InvSlot {
    string Name;
    int Point;
    int Price=0;
} InvSlot;

typedef struct Coords {
    int x;
    int y;
} Coords;

void InitializeSettings();
void gotoxy(int x, int y);
void wait();
int KeyCheck(int Key);
int Random(int First, int Second);




#endif //CONSOLE_ROGUELIKE_CPP_UTILITY_H
