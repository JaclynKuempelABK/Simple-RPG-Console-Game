#include "Player.h"
#include "Enemy.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


void PlayGame();

void PlayerCreationMenu(string& nameChoice, int& weaponChoice, int& armorChoice);

void Encounter(Player* player, Enemy* enemy);

void Round(Player* player, Enemy* enemy);

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
    
// --- ENEMY CREATION ---
    int eWeapon = 0 + (rand() % 3); //random number 0-3
    int eArmor = 0 + (rand() % 3); //random number 0-3
    Enemy* theEnemy = new Enemy(eWeapon, eArmor);

// --- PLAYER-ENEMY ENCOUNTER ---
    char resumeChoice = 'y';
    do
    {
        Encounter(thePlayer, theEnemy);

        //Rest(); // maybe put stuff in this to avoid the goto label?

        // someone has died at this point
        if (!theEnemy->IsAlive() && thePlayer->IsAlive())
        {
            cout << "The enemy has died!" << endl << endl;

            // REST OR NO?
            cout << "Rest and resume against a new enemy (y/n)?: ";
            cin >> resumeChoice;
            if (resumeChoice == 'y')
            {
                thePlayer->Rest();
                cout << "Resting has healed you for 20 health! You now have " << thePlayer->getCurrentHealth() << " health" << endl << endl;

                delete theEnemy;
                // NEW ENEMY
                eWeapon = 0 + (rand() % 3); //random number 0-3
                eArmor = 0 + (rand() % 3); //random number 0-3
                theEnemy = new Enemy(eWeapon, eArmor);
            }
            else if (resumeChoice == 'n')
            {
                cout << "Thanks for playing!";
                break;
            }

        }
        /*else if (!theEnemy->IsAlive() && !thePlayer->IsAlive())
        {
            // tied
        }*/

    } while (thePlayer->IsAlive() && resumeChoice == 'y');

    cout << "You have died! Game over";

// --- CLEAR POINTERS TO PLAYER AND ENEMY ---
    delete thePlayer;
    delete theEnemy;
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