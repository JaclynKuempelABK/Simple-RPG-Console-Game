#pragma once

// weapon constants
const int g_WEAPON_NONE = 0;
const int g_WEAPON_SWORD = 1;
const int g_WEAPON_AXE = 2;
const int g_WEAPON_BOW = 3;

// armor constants
const int g_ARMOR_NONE = 0;
const int g_ARMOR_LIGHT = 1;
const int g_ARMOR_MEDIUM = 2;
const int g_ARMOR_HEAVY = 3;


class Character
{
protected:

    int m_currentHealth;
    int m_maxHealth;
    int m_weapon;
    int m_armor;
    //bool m_isAlive;

public:

    Character(int weapon, int armor);

    int getCurrentHealth();
   
    int DealDamage();

    void TakeDamage(int dmg);

    bool IsAlive();
};