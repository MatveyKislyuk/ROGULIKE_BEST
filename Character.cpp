#include "Character.h"
#include "LevelDesign.h"
#include "UserInterface.h"
#include "AnimationAndSprites.h"
#include "Utility.h"
#include "TextQuest.h"
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
    if (ClassName == "Archer") {
        SetName(ClassName);
        SetHealth(100);
        SetStamina(100);
        SetArmor(10);
        SetDamage(30);
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
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            //gotoxy(x+i, y+j); cout << "2";
            if (flag == 0 and Level.GetFromCoordinates(x+i, y+j) == "$") {
                Player.SetGold(Player.GetGold() + Random(20, 100));
                Level.SetToCoordinates(" ", x+i, y+j);
                Level.DrawVisibleField(x, y);
            }
            if (flag == 1 and Level.GetFromCoordinates(x+i, y+j) == "*") {
                OpenShop(Player);
            }
            if (flag == 1 and Level.GetFromCoordinates(x+i, y+j) == "?") {
                //Level.SetToCoordinates(" ", x+i, y+j);
                //Level.DrawVisibleField(x, y);
                quest();
            }
            if (flag == 0 and Level.GetFromCoordinates(x+i,y+j)=="~"){
                TurnWhite;
                PlayerController::Capybara(Player);
            }
        }
    }

}

void PlayerController::MovementInit(Player & Player, GameLevel & Level) {
    Level.DrawVisibleField(x, y);
    DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());

    EnemyAI EnemyAI;
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
                if (Level.RoomType == 3) {
                    cout << "gratz u win"; wait();
                    exit(1);
                }
                x = 5; y = 2;
                return;
            }

            if (KeyCheck(Key) == 1 or KeyCheck(Key) == 2 or KeyCheck(Key) == 3 or KeyCheck(Key) == 4) {
                ShowXY(x, y);
                EnemyAI.AutoMovement(Level, x, y);
                Level.DrawVisibleField(x, y);
                DrawGUI(Player.GetHealth(), Player.GetStamina(), Player.GetArmor(), Player.GetDamage(), Player.GetGold());
                CheckForEnemiesAround(Level, Player, x, y);
                gotoxy(x, y);
                continue;
            }
        }
    }
}

string PlayerController::GetPlayerSymbol() {
    return PlayerSymbol;
}

int PlayerController::WallCheck(GameLevel & Level, int x, int y) {
    string MapElement = Level.GetFromCoordinates(x, y);
    if (MapElement == "█") { //old wall
       return 1;
    } else if (MapElement == "░") { //wall
       return 2;
    } else if (MapElement == "*") { //shopkeeper
        return 3;
    } else if (MapElement == "?") { //textquest
        return 4;
    } else return 0;
}


void PlayerController::Capybara(Player & Player) {
    //что может дать капибара
    Weapon Fuckel("FUCKel", 100000, 0);
    Weapon TopolM("RT-2PM2 Topol-M", 100000, 0);

    if (Player.GetName()=="Knight"){
        TakeItem(Player,Fuckel);
    } else if (Player.GetName()=="Archer"){
        TakeItem(Player,TopolM);
    }
    while (true){
        gotoxy(0,200);
        capy();
        int Key=_getch();
        if(KeyCheck(Key)==8){
            gotoxy(0,0);
            return;
        }
    }
}

/*=============================================================== Enemy ===============================================================
===================================================================================================================================== */

Enemy::Enemy(int EnemyType) {
    if (EnemyType == 0) {
        SetName("DefaultEnemy");
        SetDamage(35);
        SetHealth(140);
    }
    if (EnemyType == 1) {
        SetName("Boss");
        SetDamage(55);
        SetHealth(300);
    }
}

Enemy::Enemy() = default;

/*============================================================== EnemyAI ==============================================================
===================================================================================================================================== */

EnemyAI::EnemyAI() = default;

void EnemyAI::AutoMovement(GameLevel & Level, int x, int y) {
    for (auto & i: Level.EnemyCoordinates) {
        int v = i.x; int d = i.y;
        string EnemySymbol = GetEnemySymbol();
        TurnGreen;
        if (((v - x) ^ 2 + (d - y) ^ 2) < 2) {
            if (v < x and d < y and WallCheck(Level, v + 1, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++; d++;
            } else if (v > x and d < y and WallCheck(Level, v - 1, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--; d++;
            } else if (v < x and d > y and WallCheck(Level, v + 1, d - 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++; d--;
            } else if (v > x and d > y and WallCheck(Level, v - 1, d - 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--; d--;
            } else if (v == x and d < y and WallCheck(Level, v, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d++;
            } else if (v == x and d > y and WallCheck(Level, v, d-1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d--;
            } else if (v < x and d == y and WallCheck(Level, v + 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++;
            } else if (v > x and d == y and WallCheck(Level, v - 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--;
            }
        } else {
            int move = 1 + rand() % 4;
            if (move == 1 and WallCheck(Level, v, d - 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d-1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d--;
            }
            if (move == 2 and WallCheck(Level, v - 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v-1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v--;
            }
            if (move == 3 and WallCheck(Level, v, d + 1) == 0) {
                Level.SetToCoordinates(EnemySymbol, v, d+1);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                d++;
            }
            if (move == 4 and WallCheck(Level, v + 1, d) == 0) {
                Level.SetToCoordinates(EnemySymbol, v+1, d);
                Level.SetToCoordinates(" ", v, d);
                //gotoxy(v, d); cout << " ";
                v++;
            }
        }
        i.x = v; i.y = d;
    }
}

string EnemyAI::GetEnemySymbol() {
    return EnemySymbol;
}

void PlayerController::CheckForEnemiesAround(GameLevel & Level, Player & Player, int x, int y) {
    int r = 3;
    for (int i = 0; i < r + 1; i++) {
        for (int j = 0; j < r; j++) {
            string EnemySymbol = Level.GetFromCoordinates(x-r/2+i, y-r/2+j);
            if (EnemySymbol == "&") {
                Enemy Enemy(0);
                //ZAMENITB!
                int Result = FightInitialize(Player, Enemy);
                if (Result) {
                    Level.SetToCoordinates(" ", x-r/2+i, y-r/2+j);
                    for (int k = 0; k < Level.EnemyCoordinates.capacity() ; k++) {
                        if ((Level.EnemyCoordinates[k].x == x-r/2+i) and (Level.EnemyCoordinates[k].y == y-r/2+j)) {
                            Level.EnemyCoordinates.erase(Level.EnemyCoordinates.begin() + k);
                        }
                    }
                    system("cls");
                    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
                    gotoxy(0,0);
                    Level.DrawMemorised();
                    gotoxy(x, y);
                    return;
                } else if (Result == 0) {
                    system("cls"); cout << "U lose"; wait(); exit(1);
                }
            } else if (EnemySymbol == "!") {
                Enemy Enemy(1);
                //ZAMENITB!
                int Result = FightInitialize(Player, Enemy);
                if (Result) {
                    Level.SetToCoordinates(" ", x-r/2+i, y-r/2+j);
                    for (int k = 0; k < Level.EnemyCoordinates.capacity() ; k++) {
                        if ((Level.EnemyCoordinates[k].x == x-r/2+i) and (Level.EnemyCoordinates[k].y == y-r/2+j)) {
                            Level.EnemyCoordinates.erase(Level.EnemyCoordinates.begin() + k);
                        }
                    }
                    system("cls");
                    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
                    gotoxy(0,0);
                    Level.DrawMemorised();
                    gotoxy(x, y);
                    if (Level.RoomType == 0) {
                        Level.Draw(104, 18, 113, 27," ");
                    } else if (Level.RoomType == 1) {
                        Level.Draw(103,14,114,23," ");
                    } else if (Level.RoomType == 2) {
                        Level.Draw(99, 14, 114, 21," ");
                    }

                    return;
                } else if (Result == 0) {
                    system("cls"); cout << "U lose"; wait(); exit(1);
                }
            }
        }
    }
    gotoxy(0,0);
}



void PlayerController::OpenShop(Player & Player) {

    //POTION
    Potion BluePotion("Blue potion",40);
    Potion HealingPotion("Healing potion",40);

//ARMOR
//лёгкая броня,тяжёлая броня,броня единорога,божественная броня
    class Armor LightArmor("Light armor", 30,60);
    class Armor HeavyArmor("Heavy Armor", 50,120);
    class Armor UnicornArmor("Unicorn armor", 70,180);
    class Armor GodArmor("God armor", 90,240);

//WEAPON
//sword
//нож,старая катана,небесный меч,меч пожерателя хаоса
    Weapon Knife("Knife", 10,60);
    Weapon OldKatana("Old Katana", 20,120);
    Weapon HeavenlySword("Heavenly sword", 30,180);
    Weapon ChaosEaterSword("Chaos eater sword", 40,240);

//bow
//арбалет,,кор.лук,лук повелителя времени,лук тёмного пламени
    Weapon Crossbow("Crossbow", 10,60);
    Weapon RoyalBow("Royal bow", 20,120);
    Weapon TimeLordsBow("Time Lord's Bow", 30,180);
    Weapon ShadowFlameBow("Shadow Flame Bow", 40,240);


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
    cout << " SHOP ";
    gotoxy(7, 133);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(100,131);
    TurnWhite;
    cout << "YOUR GOLD : "<< Player.GetGold();
    TurnYellow;
    gotoxy(98,130);
    for (int i = 0; i < 3; i++) {
        gotoxy(98, 130 + i);
        cout << "█";
    }
    gotoxy(99,132);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

    //header for colum
    gotoxy(26, 135);
    cout << "ITEM";
    gotoxy(21,136);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(70, 135);
    cout << "PRICE";
    gotoxy(65,136);
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    gotoxy(98, 135);
    cout << "ATTRIBUTE";
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

    vector<Weapon> ArcherWeaponVector = {
            Crossbow,
            RoyalBow,
            TimeLordsBow,
            ShadowFlameBow
    };

    if(Player.GetName() =="Knight"){
        gotoxy(13,132);
        cout<<"FOR KNIGHT";
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



    }
    else if(Player.GetName() == "Archer"){
        gotoxy(13,132);
        cout<<"FOR ARCHER";
        int Y=138;int X=101;int Z=72;
        gotoxy(23,Y);
        cout<<"(w)" << Crossbow.GetName(); gotoxy(X,Y); cout<< Crossbow.GetWeaponDamage(); gotoxy(Z,Y); cout << Crossbow.GetPrice();
        Y++;Y++;gotoxy(23,Y);
        cout<<"(w)" << RoyalBow.GetName();gotoxy(X,Y);cout<<RoyalBow.GetWeaponDamage();gotoxy(Z,Y);cout<<RoyalBow.GetPrice();
        Y++;Y++;gotoxy(23,Y);
        cout<<"(w)" <<TimeLordsBow.GetName();gotoxy(X,Y);cout<<TimeLordsBow.GetWeaponDamage();gotoxy(Z,Y);cout<<TimeLordsBow.GetPrice();
        Y++;Y++;gotoxy(23,Y);
        cout<<"(w)" <<ShadowFlameBow.GetName();gotoxy(X,Y);cout<<ShadowFlameBow.GetWeaponDamage();gotoxy(Z,Y);cout<<ShadowFlameBow.GetPrice();
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


    }

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
                if (Player.GetName() == "Archer") {
//                    gotoxy(0, 30); cout << "                     "; gotoxy(0, 30);
//                    cout << ArcherWeaponVector[Selector].GetName();

                    if ((SoldWeaponItems[Selector] != 1) and Player.GetGold() > ArcherWeaponVector[Selector].GetPrice()) {
                        Player.SetGold(Player.GetGold() - ArcherWeaponVector[Selector].GetPrice());
                        gotoxy(100,131); TurnWhite; cout << "YOUR GOLD : "<< Player.GetGold(); TurnYellow;
                        TakeItem(Player, ArcherWeaponVector[Selector]);
                        SoldWeaponItems[Selector] = 1;
                        gotoxy(30,132);cout<< "                                        ";
                        gotoxy(30,132);cout<< "BUY SUCCESSFUL";
                    } else {
                        gotoxy(30,132);cout<< "YOU CANT BUY 1 ITEM TWICE OR LITTLE CASH";

                    }

                } else if (Player.GetName() == "Knight") {
                    gotoxy(0, 130); cout << "                     "; gotoxy(0, 130);
                    cout << KnightWeaponVector[Selector].GetName();

                    if ((SoldWeaponItems[Selector] != 1) and Player.GetGold() > KnightWeaponVector[Selector].GetPrice()) {
                        Player.SetGold(Player.GetGold() - KnightWeaponVector[Selector].GetPrice());
                        gotoxy(100,131); TurnWhite; cout << "YOUR GOLD : "<< Player.GetGold(); TurnYellow;
                        TakeItem(Player, KnightWeaponVector[Selector]);
                        SoldWeaponItems[Selector] = 1;
                        gotoxy(30,132);cout<< "                                        ";
                        gotoxy(30,132);cout<< "BUY SUCCESSFUL";
                    } else {
                        gotoxy(30,132);cout<< "YOU CANT BUY 1 ITEM TWICE OR LITTLE CASH";
                    }
                }
            }
                //Armor
            else if ( 4 <= Selector and Selector <= 7) {
//                gotoxy(0, 30); cout << "                     "; gotoxy(0, 30);
//                cout << ArmorVector[Selector-4].GetName();
                if ((SoldArmorItems[Selector-4] != 1) and Player.GetGold() > ArmorVector[Selector-4].GetPrice()) {
                    Player.SetGold(Player.GetGold() - ArmorVector[Selector-4].GetPrice());
                    gotoxy(100,131); TurnWhite; cout << "YOUR GOLD : "<< Player.GetGold(); TurnYellow;
                    TakeItem(Player, ArmorVector[Selector-4]);
                    SoldArmorItems[Selector-4] = 1;
                    gotoxy(30,132);cout<< "                                        ";
                    gotoxy(30,132);cout<< "BUY SUCCESSFUL";
                } else {
                    gotoxy(30,132);cout<< "YOU CANT BUY 1 ITEM TWICE OR LITTLE CASH";
                }
            }
            else if (Selector == 8) {
                if (Player.GetGold() > 30) {
                    Player.SetHealthPotions(Player.GetHealthPotions()+1);
                } else {
                    gotoxy(30,132); cout<< "NOT ENOUGHT MONEY";
                }
            } else if (Selector == 9) {
                if (Player.GetGold() > 40) {
                    Player.SetStaminaPotions(Player.GetStaminaPotions()+1);
                } else {
                    gotoxy(30,132); cout<< "NOT ENOUGHT MONEY";
                }
            }
        } else if (KeyCheck(Key)==8){
            gotoxy(0,0);
            return;
        }
    }
}

void Buy(string ItemName, int ItemPrice) {

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
    gotoxy(101, 37); cout << "PLAYER STATS";
    TurnGreen;
    gotoxy(101, 41); cout << "Health: " << Player.GetHealth();
    TurnBrightAqua;
    gotoxy(101, 43); cout << "Stamina: " << Player.GetStamina();
    TurnGrey;
    gotoxy(101, 45); cout << "Armor: " << Player.GetArmor();
    TurnLightRed;
    gotoxy(101, 47); cout << "Damage: " << Player.GetDamage();
    TurnYellow;
    gotoxy(101, 49); cout << "Gold: " << Player.GetGold();
    TurnWhite;

    gotoxy(7, 34); TurnWhite; cout << " PLAYER ITEMS ";
    gotoxy(7, 35); TurnAqua; cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

    gotoxy(14, 37); cout << "WEAPONS"; gotoxy(39, 37); cout << "ARMOR"; gotoxy(62, 37); cout << "POTIONS";
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
    gotoxy(58, 40); cout << "Remaining "; TurnGreen; cout << "HP"; TurnAqua; cout << " Potions: " << Player.GetHealthPotions();
    gotoxy(58, 42); cout << "Remaining "; TurnBrightAqua; cout << "STM"; TurnAqua; cout << " Potions: " << Player.GetStaminaPotions();

    gotoxy(7, 55); cout << "Press 1 to use Health Potion";
    gotoxy(40, 55); cout << "Press 2 to use Stamina Potion";

    for (;;) {
        if (_kbhit()) {
            gotoxy(73, 55); cout << "                                   ";
            int Key = _getch();
            if (KeyCheck(Key) == 8 or KeyCheck(Key) == 7) {
                gotoxy(0, 0);
                return;
            }
            if (Key == 49) { //1
                if (Player.GetHealthPotions() > 0) {
                    Player.SetHealthPotions(Player.GetHealthPotions() - 1);
                    if (Player.GetHealth() < 100) {
                        Player.SetHealth(Player.GetHealth() + 20);
                    }
                    TurnAqua; gotoxy(58, 40); cout << "Remaining "; TurnGreen; cout << "HP"; TurnAqua; cout << " Potions: " << Player.GetHealthPotions();
                    TurnGreen; gotoxy(101, 41); cout << "Health: " << Player.GetHealth();
                    continue;
                } else {
                    TurnLightRed; gotoxy(73, 55); cout << "Y tebya net etix zelek, durak!"; TurnAqua;
                }
            }
            if (Key == 50) {
                if (Player.GetStaminaPotions() > 0) {
                    Player.SetStaminaPotions(Player.GetStaminaPotions() - 1);
                    if (Player.GetStamina() < 80) {
                        Player.SetStamina(Player.GetStamina() + 20);
                    }
                    TurnAqua; gotoxy(58, 42); cout << "Remaining "; TurnBrightAqua; cout << "STM"; TurnAqua; cout << " Potions: " << Player.GetStaminaPotions();
                    TurnBrightAqua; gotoxy(101, 43); cout << "Stamina: " << Player.GetStamina();
                    continue;
                } else {
                    TurnLightRed; gotoxy(73, 55); cout << "Y tebya net etix zelek, durak!"; TurnAqua;
                }
            }
        }
    }
}


