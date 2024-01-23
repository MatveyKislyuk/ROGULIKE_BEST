#include "Utility.h"
#include "Character.h"
#include "PlayerItems.h"
#include "UserInterface.h"
#include "LevelDesign.h"


    //изночальная сноряга
    Weapon Stick("Stick", 30, 0);
    Armor LeatherCoat("Leather Coat", 10, 0);
    Weapon Slingshot("Slingshot", 30, 0);


int main() {
    InitializeSettings();

    GameLevel FreeSpace(4);
    GameLevel HomeLevel(0);
    GameLevel FirstLevel(1);
    GameLevel SecondLevel(2);

    PlayerController PlayerController;
    UserInterface UserInterface;

    Player Player(UserInterface.StartMenu());;

    if (Player.GetName() == "Рыцарь") {
        PlayerController.TakeItem(Player, LeatherCoat);
        PlayerController.TakeItem(Player, Stick);}

    PlayerController.MovementInit(Player,HomeLevel);
    PlayerController.MovementInit(Player, FirstLevel);
    PlayerController.MovementInit(Player, SecondLevel);

    wait();
}


