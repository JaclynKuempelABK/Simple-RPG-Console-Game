#include <iostream>
using namespace std;

// weapon constants
const int SWORD_WEAPON = 1;
const int AXE_WEAPON = 2;

// armor constants
const int LIGHT_ARMOR = 1;
const int MEDIUM_ARMOR = 2;
const int HEAVY_ARMOR = 3;

class Character
{
private:
    int health = 100;
    int weapon = 1;
    int armor = 1;
    bool isAlive = true;

public:
   
};

class Player : public Character
{
private:
    string name = "Nooby";

public:

};

class Enemy : public Character
{

};

int main()
{
    Player thePlayer;

    
}

/*
// choose name
cout << "Welcome new player! Please choose a name: " << endl;
cin >> name;
cout << endl << endl;

// choose weapon
cout << "---Weapons---" << endl;
cout << "   1) sword" << endl;
cout << "   2) axe" << endl;
cout << "Choose your weapon!: ";
cin >> weapon;
    // VALIDATE CHOICE

// choose armor
cout << "---Armor---" << endl;
cout << "   1) light" << endl;
cout << "   2) medium" << endl;
cout << "   2) heavy" << endl;
cout << "Choose your armor!: ";
    // VALIDATE CHOICE

*/