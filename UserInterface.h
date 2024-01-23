#ifndef CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H
#define CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H

#include "Utility.h"

void OpenInventory(vector<InvSlot> Inventory);
void DrawGUI(int Health, int Stamina, int Armor, int Damage, int Gold);
void DrawGUIenemy(int Health, int Damage);
void ShowXY(int x, int y);

class UserInterface {
private:

public:
    string StartMenu();
};

#endif //CONSOLE_ROGUELIKE_CPP_USERINTERFACE_H
