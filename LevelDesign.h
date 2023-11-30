#ifndef CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#define CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
#include "Utility.h"

class GameLevel
{
private:
    string GameLevelArray[38][128];
    string MemorisedGameLevelArray[38][128];

public:
    vector<Coords> EnemyCoordinates;
    int RoomType;
    GameLevel(int RoomType);
    string GetFromCoordinates(int x, int y);
    void SetToCoordinates(string NewMapElement, int x, int y);
    void Memorise(int x, int y);
    void DrawMemorised();
    void DrawGameLevel();
    void Draw(int x1, int y1, int x2, int y2,string symbol);
    void DrawFrame();
    void DrawVisibleField(int x, int y);
    void ColorCheck(int x, int y);
    int BossRoom(int x1,int y1,int x2,int y2);
    void RandItemOrder();
    void AddEnemyCoordinates(int x, int y);
    void ShowEnemyCoordinates();
};

class TreasureBox {
private:
    int x; int y;
    string BoxSymbol{"$"};
public:
};

#endif //CONSOLE_ROGUELIKE_CPP_LEVELDESIGN_H
