//
// Created by kolonist on 18.03.2023.
//

#include "PlayerItems.h"
#include "Utility.h"

PlayerItem::PlayerItem(string Name, int Price) {
    this->Name = Name;
    this->Price = Price;
}


string PlayerItem::GetName() {
    return Name;
}
int PlayerItem::GetPrice() {
    return Price;
}

Armor::Armor(string Name, int ArmorPoints, int ArmorPrice) : PlayerItem(Name, ArmorPrice) {
    this->ArmorPoints = ArmorPoints;
}

int Armor::GetArmorPoints() {
    return ArmorPoints;
}

void Armor::SetArmorPoints(int ArmorPoints) {
    this->ArmorPoints = ArmorPoints;
}

Weapon::Weapon(string Name, int WeaponDamage, int WeaponPrice) : PlayerItem(Name, WeaponPrice) {
    this->WeaponDamage = WeaponDamage;

}

int Weapon::GetWeaponDamage() {
    return WeaponDamage;
}

void Weapon::SetWeaponDamage(int WeaponDamage) {
    this->WeaponDamage = WeaponDamage;
}

int Potion::GetHealth() {
    return Health;
}


int Potion::GetStamina() {
    return Stamina;
}

Potion::Potion(string Name,int PotionPrice) : PlayerItem(Name, PotionPrice) {

}
