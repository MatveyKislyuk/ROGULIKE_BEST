//
// Created by kolonist on 18.03.2023.
//

#ifndef CONSOLE_ROGUELIKE_CPP_PLAYERITEMS_H
#define CONSOLE_ROGUELIKE_CPP_PLAYERITEMS_H
#include "Utility.h"


class PlayerItem
{
private:
    string Name;
    int Price;
public:
    PlayerItem(string Name, int Price);
    string GetName();
    int GetPrice();

};
class Armor: public PlayerItem
{
private:
    int ArmorPoints;
public:
    Armor(string Name, int ArmorPoints,int ArmorPrice);
    int GetArmorPoints();
    void SetArmorPoints(int ArmorPoints);
};

class Weapon: public PlayerItem
{
private:
    int WeaponDamage;
public:
    Weapon(string Name, int WeaponDamage,int WeaponPrice);
    int GetWeaponDamage();
    void SetWeaponDamage(int WeaponDamage);
};

class Potion: public PlayerItem
{
private:
    int Health{30};
    int Stamina{40};
public:
    Potion(string Name,int PotionPrice);
    int GetHealth();
    int GetStamina();
};











#endif //CONSOLE_ROGUELIKE_CPP_PLAYERITEMS_H

