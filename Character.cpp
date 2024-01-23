#include "Character.h"
#include "LevelDesign.h"
#include "UserInterface.h"
#include <unistd.h>
#include "Utility.h"
void OpenInventory1(Player & Player, vector<Weapon> & WeaponSlots, vector<Armor> & ArmorSlots, vector<Potion> & PotionSlots);
int SoldWeaponItems[4] = {0, 0, 0, 0};
int SoldArmorItems[4] = {0, 0, 0, 0};
/*============================================================ Character ============================================================
===================================================================================================================================== */
int Character::GetHealth() {
    return Health;
}
void Character::SetHealth(int Health) {
    this -> Health = Health;
}
int Character::GetDamage() {
    return Damage;
}
void Character::SetDamage(int Damage) {
    this -> Damage = Damage;
}
int Character::GetArmor() {
    return Armor;
}
void Character::SetArmor(int Armor) {
    this -> Armor = Armor;
}
string Character::GetName() {
    return Name;
}
void Character::SetName(string Name) {
    this -> Name = Name;
}



/*============================================================ Player ============================================================
===================================================================================================================================== */

Player::Player() = default;


Player::Player(string ClassName) {
    if (ClassName == "Knight") {
        SetName(ClassName);
        SetHealth(130);
        SetStamina(100);
        SetArmor(30);
        SetDamage(20);
    }
}

int Player::GetStamina() {
    return Stamina;
}
void Player::SetStamina(int Stamina) {
    this -> Stamina = Stamina;
}
int Player::GetGold() {
    return Gold;
}
void Player::SetGold(int Gold) {
    this -> Gold = Gold;
}

int Player::GetStaminaPotions() {
    return StaminaPotions;
}

int Player::GetHealthPotions() {
    return HealthPotions;
}

void Player::SetStaminaPotions(int Value) {
    StaminaPotions = Value;
}

void Player::SetHealthPotions(int Value) {
    HealthPotions = Value;
}


/*============================================================ PlayerController ============================================================
===================================================================================================================================== */

void PlayerController::TakeItem(Player & Player, class Armor & Item) {
    Player.SetArmor(Player.GetArmor() + Item.GetArmorPoints());
    ArmorSlots.push_back(Item);
}

void PlayerController::TakeItem(Player & Player, Weapon & Item){
    Player.SetDamage(Player.GetDamage() + Item.GetWeaponDamage());
    WeaponSlots.push_back(Item);
}



void PlayerController::TakeItem(Player & Player, Potion & Item) {
    if (Item.GetName() == "HealthPotion") {
        Player.SetHealthPotions(Player.GetHealthPotions() + 1);
    } else if (Item.GetName() == "StaminaPotion") {
        Player.SetStaminaPotions(Player.GetStaminaPotions() + 1);
    }
}

void PlayerController::InteractWith(Player & Player, GameLevel & Level, int x, int y, int flag) {
    for (int i = -1; i < 3; i++) {
        for (int j = -1; j < 3; j++) {

            if (flag == 0 and Level.GetFromCoordinates(x+i, y+j) == "$") {
                Player.SetGold(Player.GetGold() + Random(20, 100));
                Level.SetToCoordinates(" ", x+i, y+j);
                Level.DrawVisibleField(x, y);
            }
            if (flag == 1 and Level.GetFromCoordinates(x+i, y+j) == "*") {
                OpenShop(Player);
            }
            else if (flag == 1 and Level.GetFromCoordinates(x+i, y+j) == "%") {
                int x_enemy = x+i;
                int y_enemy = y+j;
                int x_player = x;
                int y_player = y;
                Battle(Player, x_enemy, y_enemy, x_player, y_player);
            }
        }
    }

}

void PlayerController::Battle(Player & Player, int x_enemy, int y_enemy, int x_player, int y_player){
    int Enemy_Damage = 30;
    int Enemy_Health = 40;
    int x_enm = x_enemy;
    int y_enm = y_enemy;
    int x = x_player;
    int y = y_player;
    DrawGUIenemy(Enemy_Health, Enemy_Damage);
    while (Enemy_Health >=0 and Player.GetHealth() >=0){
        if (_kbhit()) {
            auto Key = _getch();
            if (KeyCheck(Key) == 10) {
                gotoxy(x-1, y-1);
                cout << "###";
                gotoxy(x-1, y+1);
                cout << "###";
                gotoxy(x-1, y);
                cout << "#";
                gotoxy(x+1, y);
                cout << "#";
                sleep(1);
                gotoxy(x-1, y-1);
                cout << "   ";
                gotoxy(x-1, y+1);
                cout << "   ";
                gotoxy(x-1, y);
                cout << " ";
                gotoxy(x+1, y);
                cout << " ";
                gotoxy(x-2, y-2);
                cout << "#####";
                gotoxy(x-2, y+2);
                cout << "#####";
                gotoxy(x-2, y);
                cout << "#";
                gotoxy(x-2, y+1);
                cout << "#";
                gotoxy(x-2, y-1);
                cout << "#";
                gotoxy(x+2, y);
                cout << "#";
                gotoxy(x+2, y-1);
                cout << "#";
                gotoxy(x+2, y+1);
                cout << "#";
                sleep(1);
                gotoxy(x-2, y-2);
                cout << "     ";
                gotoxy(x-2, y+2);
                cout << "     ";
                gotoxy(x-2, y);
                cout << " ";
                gotoxy(x-2, y+1);
                cout << " ";
                gotoxy(x-2, y-1);
                cout << " ";
                gotoxy(x+2, y);
                cout << " ";
                gotoxy(x+2, y-1);
                cout << " ";
                gotoxy(x+2, y+1);
                cout << " ";
                Player.SetHealth(Player.GetHealth() + Player.GetArmor() - Enemy_Damage);
                Enemy_Health = (Enemy_Health - (Enemy_Health + 1));
                DrawGUIenemy(Enemy_Health, Enemy_Damage);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());

            }
            if (KeyCheck(Key) == 11) {
                Player.SetHealth(Player.GetHealth() + Player.GetArmor() - Enemy_Damage);
                Enemy_Health = (Enemy_Health - Player.GetDamage());
                DrawGUIenemy(Enemy_Health, Enemy_Damage);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
            }

            }
    }
    TurnGreen;
    gotoxy(9, 2);
    cout << "Вы победитель!                 ";

}


void PlayerController::MovementInit(Player & Player, GameLevel & Level) {
    Level.DrawVisibleField(x, y);
    DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());

    string PlayerSymbol = GetPlayerSymbol();

    gotoxy(x, y);
    cout << PlayerSymbol;
    gotoxy(x, y);

    for (;;) {
        if (_kbhit()) {
            auto Key = _getch();

            InteractWith(Player, Level, x, y, 0);
            if (KeyCheck(Key) == 1 and WallCheck(Level, x, y - 1) == 0) {
                gotoxy(x, y - 1); cout << PlayerSymbol; Level.SetToCoordinates("@", x, y-1);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y--;
            }
            if (KeyCheck(Key) == 2 and WallCheck(Level, x - 1, y) == 0) {
                gotoxy(x - 1, y); cout << PlayerSymbol; Level.SetToCoordinates("@", x-1, y);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x--;
            }
            if (KeyCheck(Key) == 3 and WallCheck(Level, x, y + 1) == 0) {
                gotoxy(x, y + 1); cout << PlayerSymbol; Level.SetToCoordinates("@", x, y+1);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                y++;
            }
            if (KeyCheck(Key) == 4 and WallCheck(Level, x + 1, y) == 0) {
                gotoxy(x + 1, y); cout << PlayerSymbol; Level.SetToCoordinates("@", x+1, y);
                gotoxy(x, y); cout << " ";
                Level.SetToCoordinates(" ", x, y);
                x++;
            }


            if (KeyCheck(Key) == 6) {
                InteractWith(Player, Level, x, y, 1);
            }
            if (KeyCheck(Key) == 7) {
                OpenInventory1(Player, WeaponSlots, ArmorSlots, PotionSlots);
            }

            if ((x == 115 and y == 24) or (x == 115 and y == 23) or (x == 115 and y == 28) or (x == 115 and y == 25) or (x == 115 and y == 26) or (x == 115 and y == 27)) {
                system("cls");
                cout << "gratz u win"; wait();
                exit(1);
            }

            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                ShowXY(x, y);
                Level.DrawVisibleField(x, y);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
                gotoxy(x, y);
            }

            if (KeyCheck(Key) == 10) {
                ShowXY(x, y);
                Level.DrawVisibleField(x, y);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
                gotoxy(x, y);
            }
        }
    }
}

string PlayerController::GetPlayerSymbol() {
    return PlayerSymbol;
}

int PlayerController::WallCheck(GameLevel & Level, int x, int y) {
    string MapElement = Level.GetFromCoordinates(x, y);
    if (MapElement == "█") {
       return 1;
    } else if (MapElement == "░") {
       return 2;
    } else if (MapElement == "*") {
        return 3;
    } else return 0;
}

/*=============================================================== Enemy ===============================================================
===================================================================================================================================== */

Enemy::Enemy() = default;

Enemy::Enemy(int EnemyType) {
    if (EnemyType == 0) {
        SetName("DefaultEnemy");
        SetDamage(35);
        SetHealth(140);
    }
}

/*============================================================== EnemyAI ==============================================================
===================================================================================================================================== */

void PlayerController::OpenShop(Player & Player) {

    //POTION
    Potion BluePotion("Stamina potion",40);
    Potion HealingPotion("Healing potion",40);

//лёгкая броня,тяжёлая броня,броня единорога,божественная броня
    class Armor LightArmor("Light armor", 30,60);
    class Armor HeavyArmor("Heavy Armor", 50,120);
    class Armor UnicornArmor("Unicorn armor", 70,180);
    class Armor GodArmor("God armor", 90,240);

//WEAPON
    Weapon Knife("Knife", 10,60);
    Weapon OldKatana("Old Katana", 20,120);
    Weapon HeavenlySword("Heavenly sword", 30,180);
    Weapon ChaosEaterSword("Chaos eater sword", 40,240);


    TurnYellow;
    if (KeyCheck(6)) {
        gotoxy(0, 130);
        for (int i = 0; i < 120; i++) {
            gotoxy(0 + i, 130);
            cout << "▀";
            gotoxy(0 + i, 158);
            cout << "▄";
        }
        for (int i = 0; i < 29; i++) {
            gotoxy(0, 130 + i);
            cout << "█";
            gotoxy(119, 130 + i);
            cout << "█";
        }
    }

    gotoxy(7, 132);
    TurnYellow;
    cout << " Магазин ";
    gotoxy(7, 133);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(100,131);
    TurnWhite;
    cout << "Твое золото : "<< Player.GetGold();
    TurnYellow;
    gotoxy(98,130);
    for (int i = 0; i < 3; i++) {
        gotoxy(98, 130 + i);
        cout << "█";
    }
    gotoxy(99,132);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

    gotoxy(25, 135);
    cout << "Предмет";
    gotoxy(21,136);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(71, 135);
    cout << "Цена";
    gotoxy(65,136);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(99, 135);
    cout << "Описание";
    gotoxy(95,136);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(0, 130);
    int currentY = 138;
    gotoxy(6, currentY);
    cout << "=>";

    vector<class Armor> ArmorVector = {
            LightArmor,
            HeavyArmor,
            UnicornArmor,
            GodArmor
    };

    vector<Weapon> KnightWeaponVector = {
            Knife,
            OldKatana,
            HeavenlySword,
            ChaosEaterSword
    };

    int Y=138;int X=101;int Z=72;
    gotoxy(23,Y);
    cout<<"(w)" << Knife.GetName(); gotoxy(X,Y); cout<< Knife.GetWeaponDamage(); gotoxy(Z,Y); cout << Knife.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(w)" << OldKatana.GetName();gotoxy(X,Y);cout<<OldKatana.GetWeaponDamage();gotoxy(Z,Y);cout<<OldKatana.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(w)" <<HeavenlySword.GetName();gotoxy(X,Y);cout<<HeavenlySword.GetWeaponDamage();gotoxy(Z,Y);cout<<HeavenlySword.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(w)" <<ChaosEaterSword.GetName();gotoxy(X,Y);cout<<ChaosEaterSword.GetWeaponDamage();gotoxy(Z,Y);cout<<ChaosEaterSword.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(a)" <<LightArmor.GetName();gotoxy(X,Y);cout<<LightArmor.GetArmorPoints();gotoxy(Z,Y);cout<<LightArmor.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(a)" <<HeavyArmor.GetName();gotoxy(X,Y);cout<<HeavyArmor.GetArmorPoints();gotoxy(Z,Y);cout<<HeavyArmor.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(a)" <<UnicornArmor.GetName();gotoxy(X,Y);cout<<UnicornArmor.GetArmorPoints();gotoxy(Z,Y);cout<<UnicornArmor.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(a)" <<GodArmor.GetName();gotoxy(X,Y);cout<<GodArmor.GetArmorPoints();gotoxy(Z,Y);cout<<GodArmor.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(p)" <<HealingPotion.GetName();gotoxy(X,Y);;cout<<HealingPotion.GetHealth();gotoxy(Z,Y);cout<<HealingPotion.GetPrice();
    Y++;Y++;gotoxy(23,Y);
    cout<<"(p)" <<BluePotion.GetName();gotoxy(X,Y);cout<<BluePotion.GetStamina();gotoxy(Z,Y);cout<<BluePotion.GetPrice();

    int Selector = 0;

    while (true) {
        int Key = _getch();

        if (KeyCheck(Key) == 3 and currentY < 156) {

            Selector++;
            gotoxy(6, currentY);
            cout << "  ";
            currentY++;
            currentY++;
            gotoxy(6, currentY);
            cout << "=>";

        } else if (KeyCheck(Key) == 1 and currentY > 138) {
            Selector--;
            gotoxy(6, currentY);
            cout << "  ";
            currentY--;
            currentY--;
            gotoxy(6, currentY);
            cout << "=>";
        } else if (KeyCheck(Key) == 5) {

            //Weapons
            if ( 0 <= Selector and Selector <= 3) {
                gotoxy(0, 130); cout << "                     "; gotoxy(0, 130);
                cout << KnightWeaponVector[Selector].GetName();

                if ((SoldWeaponItems[Selector] != 1) and Player.GetGold() > KnightWeaponVector[Selector].GetPrice()) {
                    Player.SetGold(Player.GetGold() - KnightWeaponVector[Selector].GetPrice());
                    gotoxy(100,131); TurnWhite; cout << "Твое золото : "<< Player.GetGold(); TurnYellow;
                    TakeItem(Player, KnightWeaponVector[Selector]);
                    SoldWeaponItems[Selector] = 1;
                    gotoxy(30,132);cout<< "                                        ";
                    gotoxy(30,132);cout<< "Успешная покупка";
                } else {
                    gotoxy(30,132);cout<< "Вы не можете купить больше 1 предмета или у Вас недостаточно золота";
                }

            }
                //Armor
            else if ( 4 <= Selector and Selector <= 7) {
//                gotoxy(0, 30); cout << "                     "; gotoxy(0, 30);
//                cout << ArmorVector[Selector-4].GetName();
                if ((SoldArmorItems[Selector-4] != 1) and Player.GetGold() > ArmorVector[Selector-4].GetPrice()) {
                    Player.SetGold(Player.GetGold() - ArmorVector[Selector-4].GetPrice());
                    gotoxy(100,131); TurnWhite; cout << "Твое золото : "<< Player.GetGold(); TurnYellow;
                    TakeItem(Player, ArmorVector[Selector-4]);
                    SoldArmorItems[Selector-4] = 1;
                    gotoxy(30,132);cout<< "                                        ";
                    gotoxy(30,132);cout<< "Успешная покупка";
                } else {
                    gotoxy(30,132);cout<< "Вы не можете купить больше 1 предмета или у Вас недостаточно золота";
                }
            }
            else if (Selector == 8) {
                if (Player.GetGold() > 30) {
                    Player.SetHealthPotions(Player.GetHealthPotions()+1);
                } else {
                    gotoxy(30,132); cout<< "Недостаточно золота";
                }
            } else if (Selector == 9) {
                if (Player.GetGold() > 40) {
                    Player.SetStaminaPotions(Player.GetStaminaPotions()+1);
                } else {
                    gotoxy(30,132); cout<< "Недостаточно золота";
                }
            }
        } else if (KeyCheck(Key)==6){
            gotoxy(0,0);
            return;
        }
    }
}


void OpenInventory1(Player & Player, vector<Weapon> & WeaponSlots, vector<Armor> & ArmorSlots, vector<Potion> & PotionSlots) {
    TurnAqua;
    for (int i = 0; i < 120; i++) {
        gotoxy(0+i, 30);
        cout << "▀";
        gotoxy(0+i, 58);
        cout << "▄";
    }
    for (int i = 0; i < 29; i++) {
        gotoxy(0, 30+i);
        cout << "█";
        gotoxy(119, 30+i);
        cout << "█";
    }
    for (int i = 0; i < 19; i++) {
        gotoxy(95, 34+i); cout << "█";
    }
    for (int i = 0; i < 24; i++) {
        gotoxy(95+i, 34); cout << "▄";
    }
    for (int i = 0; i < 24; i++) {
        gotoxy(95+i, 53); cout << "▀";
    }
    TurnWhite;
    gotoxy(101, 37); cout << "Статистика";
    TurnGreen;
    gotoxy(101, 41); cout << "Здоровье: " << Player.GetHealth();
    TurnBrightAqua;
    gotoxy(101, 43); cout << "Бодрость: " << Player.GetStamina();
    TurnGrey;
    gotoxy(101, 45); cout << "Броня: " << Player.GetArmor();
    TurnLightRed;
    gotoxy(101, 47); cout << "Урон: " << Player.GetDamage();
    TurnYellow;
    gotoxy(101, 49); cout << "Золото: " << Player.GetGold();
    TurnWhite;

    gotoxy(7, 34); TurnWhite; cout << " Предметы ";
    gotoxy(7, 35); TurnAqua; cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

    gotoxy(14, 37); cout << "Оружие"; gotoxy(39, 37); cout << "Броня"; gotoxy(63, 37); cout << "Зелья";
    gotoxy(12, 38); cout << "▄▄▄▄▄▄▄▄▄▄▄"; gotoxy(36, 38); cout << "▄▄▄▄▄▄▄▄▄▄▄"; gotoxy(60, 38); cout << "▄▄▄▄▄▄▄▄▄▄▄";

    int WeaponLimit = 0; int ArmorLimit = 0;
    for (int i = 0; i < WeaponSlots.capacity() and WeaponLimit != 6; i++) {
        WeaponLimit++;
        gotoxy(8, 40+2*i);
        TurnAqua; cout << "*" << WeaponSlots[i].GetName() << " "; TurnLightRed;
        cout << WeaponSlots[i].GetWeaponDamage();
    }
    for (int i = 0; i < ArmorSlots.capacity() and ArmorLimit != 6; i++) {
        ArmorLimit++;
        gotoxy(34, 40+2*i);
        TurnAqua; cout << "*" << ArmorSlots[i].GetName() << " "; TurnGrey;
        cout << ArmorSlots[i].GetArmorPoints();
    }
    TurnAqua;
    gotoxy(58, 40); cout << "В наличие: "; TurnGreen; cout << "HP"; TurnAqua; cout << " Potions - " << Player.GetHealthPotions();
    gotoxy(58, 42); cout << "В наличие: "; TurnBrightAqua; cout << "STM"; TurnAqua; cout << " Potions - " << Player.GetStaminaPotions();

    gotoxy(6, 55); cout << "Нажмите 1 для использования Health Potion";
    gotoxy(6, 56); cout << "Нажмите 2 для использования Stamina Potion";

    for (;;) {
        if (_kbhit()) {
            gotoxy(73, 55); cout << "                                   ";
            int Key = _getch();
            if (KeyCheck(Key) == 8 or KeyCheck(Key) == 7) {
                gotoxy(0, 0);
                return;
            }
            if (Key == 49) {
                if (Player.GetHealthPotions() > 0) {
                    Player.SetHealthPotions(Player.GetHealthPotions() - 1);
                    if (Player.GetHealth() < 100) {
                        Player.SetHealth(Player.GetHealth() + 20);
                    }
                    TurnAqua; gotoxy(58, 40); cout << "В наличие: "; TurnGreen; cout << "HP"; TurnAqua; cout << " Potions - " << Player.GetHealthPotions();
                    TurnGreen; gotoxy(101, 41); cout << "Здоровье: " << Player.GetHealth();
                    continue;
                } else {
                    TurnLightRed; gotoxy(73, 55); cout << "У тебя нет этих зелек, дурак!"; TurnAqua;
                }
            }
            if (Key == 50) {
                if (Player.GetStaminaPotions() > 0) {
                    Player.SetStaminaPotions(Player.GetStaminaPotions() - 1);
                    if (Player.GetStamina() < 80) {
                        Player.SetStamina(Player.GetStamina() + 20);
                    }
                    TurnAqua; gotoxy(58, 42); cout << "В наличие: "; TurnBrightAqua; cout << "STM"; TurnAqua; cout << " Potions - " << Player.GetStaminaPotions();
                    TurnBrightAqua; gotoxy(101, 43); cout << "Бодрость: " << Player.GetStamina();
                    continue;
                } else {
                    TurnLightRed; gotoxy(73, 55); cout << "У тебя нет этих зелек, дурак!"; TurnAqua;
                }
            }
        }
    }
}


