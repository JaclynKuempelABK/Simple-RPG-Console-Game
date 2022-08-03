#include "Player.h"
#include "Enemy.h"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


void PlayGame();

void PlayerCreationMenu(string& nameChoice, int& weaponChoice, int& armorChoice);

void Encounter(Player* player, Enemy* enemy);

void Round(Player* player, Enemy* enemy);

bool CheckGameOver(Player* player, Enemy* enemy);

bool DoResume()

int main()
{

    srand(time(0)); // set RNG seed for entire game
    
    PlayGame();

    
}

void PlayGame()
{
// --- PLAYER CREATION ---
    string pName;
    int pWeapon, pArmor = 0;
    PlayerCreationMenu(pName, pWeapon, pArmor); // gather player preferences
    Player* thePlayer = new Player(pName, pWeapon, pArmor);

// --- ENCOUNTERS AGAINST ENEMIES ---
    Enemy* theEnemy = nullptr;
    int eWeapon, eArmor = 0;
    bool isGameOver = false;
    do
    {
        // --- ENEMY CREATION (new enemy each enounter) ---
        eWeapon = 0 + (rand() % 3); //random number 0-3
        eArmor = 0 + (rand() % 3); //random number 0-3
        theEnemy = new Enemy(eWeapon, eArmor);

        Encounter(thePlayer, theEnemy); // encounter start
        isGameOver = CheckGameOver(thePlayer, theEnemy);

        delete theEnemy; // delete in prep for next enemy/end of game
    } while (!isGameOver);

    cout << "Game over!";

// --- CLEAR POINTERS TO PLAYER AND ENEMY ---
    delete thePlayer;
    thePlayer = nullptr;
    theEnemy = nullptr;
}

void PlayerCreationMenu(string& pName, int& pWeapon, int& pArmor)
{
    // choose name
    cout << "Welcome new player! Please choose a name: ";
    cin >> pName;

    system("CLS");

    // choose weapon
    cout << "---Weapons---" << endl;
    cout << "   1) sword" << endl;
    cout << "   2) axe" << endl;
    cout << "   3) bow" << endl;
    cout << "Choose your weapon: ";
    cin >> pWeapon;
    // VALIDATE CHOICE

    system("CLS");

    // choose armor
    cout << "---Armor---" << endl;
    cout << "   1) light" << endl;
    cout << "   2) medium" << endl;
    cout << "   3) heavy" << endl;
    cout << "Choose your armor: ";
    cin >> pArmor;
    // VALIDATE CHOICE

    system("CLS");
}

void Encounter(Player* player, Enemy* enemy)
{
    cout << "Encounter begins!" << endl << endl;
    do
    {
        Round(player, enemy);
    } while (player->IsAlive() && enemy->IsAlive());
}

void Round(Player* player, Enemy* enemy)
{
    int attemptedDmg = 0;

    // player attacks
    attemptedDmg = player->DealDamage();
    enemy->TakeDamage(attemptedDmg);

    // enemy attacks
    attemptedDmg = enemy->DealDamage();
    player->TakeDamage(attemptedDmg);

    // output current health for player & enemy
    cout << "Your health: " << player->getCurrentHealth() << endl;
    cout << "Enemy's health: " << enemy->getCurrentHealth() << endl << endl;
}

bool CheckGameOver(Player* player, Enemy* enemy)
{
    

    // someone has died at this point
    // figure out who
    if (!enemy->IsAlive() && !player->IsAlive()) // both died
    {
        cout << "You have tied!" << endl;
        return true;
    }
    else if (!player->IsAlive()) // player died
    {
        cout << "You have died!" << endl;
        return true;
    }
    else // enemy died
    {
        cout << "The enemy has died!" << endl << endl;

        if (!DoResume())
        {
            cout << "You win!" << endl;
            return true;
        }
        else
        {
            player->Rest();
            cout << "Resting has healed you for 20 health! You now have " << player->getCurrentHealth() << " health" << endl << endl;
            return false;
        }
    }
}

bool DoResume()
{
    char resumeChoice = 'y';

    // REST OR NO?
    cout << "Rest and resume against a new enemy (y/n)?: ";
    cin >> resumeChoice;

    if (resumeChoice == 'y')
        return true;
    else
        return false;
}