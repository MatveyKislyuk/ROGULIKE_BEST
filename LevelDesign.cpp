#include "LevelDesign.h"

//#include "PlayerItems.h"
#include "Utility.h"

using namespace std;


//Room resolution 29/119
GameLevel::GameLevel(int RoomType) {
    this->RoomType = RoomType;
    for (auto &i: GameLevelArray) {
        for (auto &j: i) {
            j = " ";
        }
    }
    for (auto &i: MemorisedGameLevelArray) {
        for (auto &j: i) {
            j = " ";
        }
    }
    if (RoomType == 0) {
        Draw(2, 1, 117, 28, "░");
        Draw(10, 8, 50, 20, " ");
        Draw(50, 13, 60, 15, " ");
        Draw(59, 14, 62, 17, " ");
        Draw(61, 16, 64, 19, " ");
        Draw(63, 18, 66, 21, " ");
        Draw(60, 21, 69, 26, " ");
        Draw(59, 13, 75, 15, " ");
        Draw(59, 9, 61, 13, " ");
        Draw(60, 9, 67, 10, " ");
        Draw(65, 8, 69, 11, " ");
        Draw(74, 11, 80, 17, " ");
        Draw(76, 17, 78, 20, " ");
        Draw(72, 20, 82, 23, " ");
        Draw(79, 12, 86, 13, " ");
        Draw(85, 7, 87, 13, " ");
        Draw(82, 4, 89, 7, " ");
        Draw(85, 9, 98, 10, " ");
        Draw(97, 9, 99, 13, " ");
        Draw(94, 12, 102, 15, " ");
        Draw(97, 14, 99, 18, " ");
        Draw(98, 17, 100, 19, " ");
        Draw(99, 18, 101, 20, " ");
        Draw(100, 19, 102, 21, " ");
        Draw(99, 21, 101, 23, " ");
        Draw(100, 22, 105, 23, " ");
        Draw(104, 18, 113, 27, " ");
        Draw(113, 25, 116, 27, " ");
        Draw(115, 25, 116, 27, "#");
        BossRoom(104, 18, 113, 27);
        RandItemOrder();
        DrawFrame();
        //shop
        GameLevelArray[9][67] = "*";
        //quest
        GameLevelArray[12][98] = "?";
        //add enemy in lvl
        AddEnemyCoordinates(61, 23);
        AddEnemyCoordinates(67, 21);
        AddEnemyCoordinates(77, 22);
        AddEnemyCoordinates(76, 12);
        AddEnemyCoordinates(83, 5);
    }
    if (RoomType == 2) {
        Draw(2, 1, 117, 28, "░");
        Draw(3, 2, 7, 4, " ");
        Draw(3, 2, 4, 4, "░");
        Draw(6, 3, 8, 5, " ");
        Draw(7, 4, 9, 7, " ");
        Draw(6, 6, 8, 9, " ");
        Draw(6, 9, 22, 15, " ");
        Draw(13, 8, 17, 9, " ");
        Draw(11, 6, 19, 8, " ");
        Draw(20, 14, 22, 18, " ");
        Draw(16, 17, 21, 18, " ");
        Draw(13, 16, 18, 19, " ");
        Draw(15, 19, 16, 24, " ");
        Draw(16, 23, 88, 24, " ");
        Draw(22, 12, 40, 13, " ");
        Draw(23, 10, 27, 14, " ");
        Draw(35, 6, 55, 15, " ");
        Draw(33, 7, 35, 8, " ");
        Draw(29, 5, 33, 9, " ");
        Draw(35, 13, 38, 17, " ");
        Draw(33, 16, 36, 18, " ");
        Draw(31, 17, 34, 21, " ");
        Draw(33, 20, 36, 22, " ");
        Draw(35, 21, 38, 23, " ");
        Draw(46, 21, 54, 26, " ");
        Draw(55, 14, 57, 18, " ");
        Draw(54, 18, 62, 20, " ");
        Draw(62, 19, 85, 20, " ");
        Draw(85, 19, 88, 23, " ");
        Draw(55, 8, 57, 9, " ");
        Draw(57, 8, 63, 11, " ");
        Draw(63, 9, 80, 10, " ");
        Draw(80, 9, 83, 12, " ");
        Draw(82, 11, 86, 13, " ");
        Draw(85, 12, 90, 14, " ");
        Draw(89, 13, 100, 15, " ");
        Draw(99, 14, 114, 21, " ");
        Draw(110, 20, 112, 27, " ");
        Draw(110, 25, 116, 27, " ");
        Draw(115, 25, 116, 27, "#");
        BossRoom(99, 14, 114, 21);
        RandItemOrder();
        DrawFrame();
        //shop
        GameLevelArray[7][31] = "*";
        //quest
        GameLevelArray[13][93] = "?";
        //add enemy in lvl
//        AddEnemyCoordinates(15,6);
//        AddEnemyCoordinates(25,11);
//        AddEnemyCoordinates(47,21);
//        AddEnemyCoordinates(52,25);
//        AddEnemyCoordinates(59,19);
    }


    if (RoomType == 1) {
        Draw(2, 1, 117, 28, "░");
        Draw(3, 2, 13, 4, " ");
        Draw(3, 2, 4, 4, "░");
        Draw(9, 4, 13, 8, " ");
        Draw(6, 8, 26, 14, " ");
        Draw(14, 14, 18, 15, " ");
        Draw(12, 15, 20, 17, " ");
        Draw(20, 16, 30, 17, " ");
        Draw(30, 13, 55, 18, " ");
        Draw(55, 15, 58, 16, " ");
        Draw(58, 14, 65, 17, " ");
        Draw(30, 18, 32, 20, " ");
        Draw(25, 19, 32, 20, " ");
        Draw(25, 19, 27, 23, " ");
        Draw(26, 22, 45, 23, " ");
        Draw(44, 20, 45, 23, " ");
        Draw(44, 19, 55, 20, " ");
        Draw(54, 19, 56, 22, " ");
        Draw(55, 21, 66, 22, " ");
        Draw(65, 18, 67, 22, " ");
        Draw(66, 17, 78, 18, " ");
        Draw(77, 17, 80, 25, " ");
        Draw(79, 24, 90, 25, " ");
        Draw(89, 22, 95, 27, " ");
        Draw(38, 12, 41, 13, " ");
        Draw(33, 10, 44, 12, " ");
        Draw(42, 7, 43, 12, " ");
        Draw(42, 6, 85, 7, " ");
        Draw(85, 6, 106, 15, " ");
        Draw(83, 10, 85, 13, " ");
        Draw(75, 9, 83, 14, " ");
        Draw(106, 7, 110, 8, " ");
        Draw(110, 7, 115, 12, " ");
        Draw(87, 15, 91, 19, " ");
        Draw(91, 18, 93, 19, " ");
        Draw(93, 16, 96, 21, " ");
        Draw(106, 13, 110, 15, " ");
        Draw(108, 15, 109, 17, " ");
        Draw(103, 17, 114, 23, " ");
        Draw(109, 23, 111, 25, " ");
        Draw(110, 25, 116, 27, " ");
        Draw(115, 25, 116, 27, "#");
        BossRoom(103, 17, 114, 23);

        RandItemOrder();
        DrawFrame();
        //shop
        GameLevelArray[11][79] = "*";
        //quest
        GameLevelArray[9][112] = "?";
        //capybara
        GameLevelArray[24][92] = "~";
        //add enemy in lvl
        AddEnemyCoordinates(15, 16);
        AddEnemyCoordinates(35, 11);
        AddEnemyCoordinates(62, 15);
        AddEnemyCoordinates(95, 20);
        //капибара 92 24
    }
}

//===============================================Draw Functions===========================================================
//========================================================================================================================

int GameLevel::BossRoom(int x1, int y1, int x2, int y2) {
    //TurnLightRed;
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            GameLevelArray[i][j] = "!";
        }
    }
    //TurnWhite;
    return 1;
}

void GameLevel::DrawVisibleField(int x, int y) {
    int r = 4;
    for (int i = -2 - r / 2; i < r / 2 + 3; i++) {
        for (int j = -r / 2; j < r / 2 + 1; j++) {
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

void GameLevel::DrawGameLevel() {
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 119; j++) {
            cout << GameLevelArray[i][j];
        }
        cout << endl;
    }
}

void GameLevel::Draw(int x1, int y1, int x2, int y2, std::string symbol) {
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            GameLevelArray[i][j] = symbol;
        }
    }
}

void GameLevel::DrawFrame() {
    Draw(0, 0, 2, 29, " ");
    Draw(0, 0, 119, 1, " ");
    Draw(117, 0, 119, 29, " ");
    Draw(0, 28, 119, 29, " ");
}


void GameLevel::RandItemOrder() {
    int amount = 12;
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

//========================================================================================================================
//========================================================================================================================

string GameLevel::GetFromCoordinates(int x, int y) {
    return GameLevelArray[y][x];
}

void GameLevel::SetToCoordinates(string NewMapElement, int x, int y) {
    GameLevelArray[y][x] = std::move(NewMapElement);
}


void GameLevel::ColorCheck(int x, int y) {
    string str = GetFromCoordinates(x, y);
    if (str == "#" or str == "░" or str == "█") {
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
    } else if (str == "*"){
        TurnYellow;
        return;
    }
}


void GameLevel::AddEnemyCoordinates(int x, int y) {
    Coords EnemyCoords;
    EnemyCoords.x = x;
    EnemyCoords.y = y;
    EnemyCoordinates.push_back(EnemyCoords);
}

void GameLevel::ShowEnemyCoordinates() {
    gotoxy(0, 29);
    for (auto i: EnemyCoordinates) {
        cout << i.x << " " << i.y << "  ";
    }
}
