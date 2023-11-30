#ifndef CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H
#define CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H

#include "Utility.h"

void OpenInventory(vector<InvSlot> Inventory);
void DrawGUI(int Health, int Stamina, int Armor, int Damage, int Gold);
void ShowXY(int x, int y);

class UserInterface {
private:

public:
    int StartMenu();
    string ClassMenu();
};

#endif //CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H
