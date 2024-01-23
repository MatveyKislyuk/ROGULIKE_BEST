#ifndef CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#define CONSOLE_ROGUELIKE_CPP_CHARACTER_H
#include "Utility.h"
#include "LevelDesign.h"
#include "PlayerItems.h"

class Character {
private:
    int Health{100};
    int Damage{1};
    int Armor{1};
    string Name{"NonClassified"};

public:
    int GetHealth();
    void SetHealth(int Health);

    int GetDamage();
    void SetDamage(int Damage);

    int GetArmor();
    void SetArmor(int Armor);

    void SetName(string Name);
    string GetName();
};


class Player : public Character {
protected:
    int MaxStamina{100}; int Stamina{100};
    int Gold{0};
    int StaminaPotions{1};
    int HealthPotions{1};

public:
    Player(string ClassName);

    Player();

    int GetStaminaPotions();
    int GetHealthPotions();
    void SetStaminaPotions(int Value);
    void SetHealthPotions(int Value);

    int GetStamina();
    void SetStamina(int Stamina);

    int GetGold();
    void SetGold(int Gold);
};

class PlayerController : public Player {
private:
    string PlayerSymbol{"@"};

public:
    vector<InvSlot> Inventory; //Utility.h

    vector<Weapon> WeaponSlots;
    vector<class Armor> ArmorSlots;
    vector<Potion> PotionSlots;



    void TakeItem(Player & Player, class Armor & Item);
    void TakeItem(Player & Player, Weapon & Item);
    void TakeItem(Player & Player, Potion & Item);


    void InteractWith(Player & Player, GameLevel & Level, int x, int y, int flag);
    string GetPlayerSymbol();
    void MovementInit(Player & Player, GameLevel & Level);
    void Battle(Player & Player, int x_enemy, int y_enemy, int x_player, int y_player);
    int WallCheck(GameLevel & Level, int x, int y);
    void CheckForEnemiesAround(GameLevel & Level, Player & Player, int x, int y);
    void Capybara(Player & Player);
    void OpenShop(Player & Player);
    int x{28}; int y{14}; //current position
};

/*=============================================================== Enemy ===============================================================
===================================================================================================================================== */

class Enemy : public Character {
public:
    Enemy(int EnemyType);
    Enemy();
};

/*=====================================================================================================================================
===================================================================================================================================== */

#endif //CONSOLE_ROGUELIKE_CPP_CHARACTER_H
