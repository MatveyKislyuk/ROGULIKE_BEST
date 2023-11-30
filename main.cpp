#include "Utility.h"
#include "AnimationAndSprites.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


    //изночальная сноряга
    Weapon Stick("Stick", 15, 0);
    Armor LeatherCoat("Leather Coat", 10, 0);
    Weapon Slingshot("Slingshot", 15, 0);

    //что может дать капибара
    Weapon Fuckel("FUCKel", 100000, 0);
    Weapon TopolM("RT-2PM2 Topol-M", 100000, 0);


// использовать предметы в окне боевки
// саня сказать мне фиксированные x y для того чтобы спавнить в лвле и чтобы выходить из негео, сделать края для лвла меньше к концу консоли чтобы не было бед аллока
// мне переделать на бекграунд фонт менюшки

int main() {
//
    InitializeSettings();
//    Player Player("Knight");
//    Enemy Enemy(0);
//    //FightInitialize(Player, Enemy);
//    PlayArcherAttackAnimation();
//    wait(); return 0;

    //--------------------------------------------------------------------------------------
    InitializeSettings();

    GameLevel FreeSpace(4);
    GameLevel HomeLevel(0);
    GameLevel FirstLevel(1);
    GameLevel SecondLevel(2);

    PlayerController PlayerController;
    UserInterface UserInterface;


    UserInterface.StartMenu();
    Player Player(UserInterface.ClassMenu());;
    //Add basic items
    PlayerController.TakeItem(Player, LeatherCoat);
    if (Player.GetName() == "Knight") {
        PlayerController.TakeItem(Player, Stick);
    } else if (Player.GetName() == "Archer") {
        PlayerController.TakeItem(Player, Slingshot);
    }

    PlayerController.MovementInit(Player,HomeLevel);
    PlayerController.MovementInit(Player, FirstLevel);
    PlayerController.MovementInit(Player, SecondLevel);

    wait();
}


