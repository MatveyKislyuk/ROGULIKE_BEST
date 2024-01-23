#include "LevelDesign.h"
#include "Utility.h"

using namespace std;

void GameLevel::InitializeArrays() {
    for (auto &i : GameLevelArray) {
        for (auto &j : i) {
            j = " ";
        }
    }
    for (auto &i : MemorisedGameLevelArray) {
        for (auto &j : i) {
            j = " ";
        }
    }
}


GameLevel::GameLevel(int RoomType) {
    InitializeArrays();
    if (RoomType == 0) {
        Draw(2, 1, 117, 30, "░");
        Draw(10, 8, 38, 15, " ");
        Draw(13, 15, 16, 21, " ");
        Draw(9, 22, 19, 25, " ");
        Draw(27, 16, 30, 26, " ");

        Draw(31, 25, 50, 26, " ");

        Draw(31, 19, 50, 20, " ");
        Draw(48, 15, 50, 18, " ");
        AddEnemyCoordinates(11, 8);
        AddEnemyCoordinates(38, 13);
        AddEnemyCoordinates(49, 15);
        AddEnemyCoordinates(50, 25);
        AddEnemyCoordinates(30, 12);

        Draw(115, 25, 116, 27, "#");
        RandItemOrder();
        //shop
        GameLevelArray[24][14] = "*";
        GameLevelArray[27][13] = "S";
        GameLevelArray[27][14] = "H";
        GameLevelArray[27][15] = "O";
        GameLevelArray[27][16] = "P";
    }
}

void GameLevel::DrawVisibleField(int x, int y) {
    int r = 2;
    for (int i = -2 - r; i < r + 3; i++) {
        for (int j = -r; j < r + 1; j++) {
            int a = x + i;
            int b = y + j;
            if (a == x and b == y) { continue; }
            ColorCheck(a, b);
            gotoxy(a, b);
            cout << GetFromCoordinates(a, b);
            Memorise(a, b);
        }
    }
    gotoxy(0, 0);
}

void GameLevel::Memorise(int x, int y) {
    MemorisedGameLevelArray[y][x] = "!";
}

void GameLevel::DrawMemorised() {
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 119; j++) {
            if (MemorisedGameLevelArray[i][j] == "!") {
                cout << GameLevelArray[i][j];
            } else { cout << " "; }
        }
        cout << endl;
    }
}

void GameLevel::Draw(int x1, int y1, int x2, int y2, std::string symbol) {
    for (int i = y1; i < y2+1; i++) {
        for (int j = x1; j < x2+1; j++) {
            GameLevelArray[i][j] = symbol;
        }
    }
}


void GameLevel::RandItemOrder() {
    int amount = 50;
    for (int i = 0; i < amount; i++) {
        int x = Random(4, 115);
        int y = Random(1, 26);
        gotoxy(x, y);
        if (GameLevelArray[y][x] == " ") {
            GameLevelArray[y][x] = "$";
        } else { i--; }
    }
    gotoxy(0, 0);
}


string GameLevel::GetFromCoordinates(int x, int y) {
    return GameLevelArray[y][x];
}

void GameLevel::SetToCoordinates(string NewMapElement, int x, int y) {
    GameLevelArray[y][x] = std::move(NewMapElement);
}


void GameLevel::ColorCheck(int x, int y) {
    string str = GetFromCoordinates(x, y);
    if (str == "#" or str == "░" or str == "█"){
        TurnWhite;
        return;
    } else if(str == "&"){
        TurnLightRed;
        return;
    } else if(str == "!"){
        TurnBlack;
        return;
    } else if (str == "@"){
        TurnBrightGreen;
        return;
    } else if(str == "$"){
        TurnGreen;
        return;
    } else if(str == "?"){
        TurnMagenta;
        return;
    } else if (str == "*" ){
        TurnYellow;
        return;
    }
}


void GameLevel::AddEnemyCoordinates(int x, int y) {
    Coords EnemyCoords;
    EnemyCoords.x = x;
    EnemyCoords.y = y;
    EnemyCoordinates.push_back(EnemyCoords);
    GameLevelArray[y][x] = "%";
}