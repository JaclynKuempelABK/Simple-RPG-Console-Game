#include "Character.h"
#include <iostream>
#include <algorithm>

Character::Character(int weapon, int armor)
{
    m_currentHealth = 100;
    //m_isAlive = true;
    m_weapon = weapon;
    m_armor = armor;
    //m_maxHealth = 100;

    // max health modifiers (based on armor)
    switch (m_armor)
    {
    case (g_ARMOR_NONE):
        m_maxHealth = 100;
        break;
    case (g_ARMOR_LIGHT):
        m_maxHealth = 110;
        break;
    case (g_ARMOR_MEDIUM):
        m_maxHealth = 125;
        break;
    case (g_ARMOR_HEAVY):
        m_maxHealth = 150;
        break;
    }
}
int Character::getCurrentHealth()
{
    return m_currentHealth;
}
int Character::DealDamage()
{
    switch (m_weapon)
    {
    case (g_WEAPON_NONE):
        return 1 + (rand() % 3); //random number 1-3
    case (g_WEAPON_SWORD):
        return 4 + (rand() % 6); //random number 4-6
    case (g_WEAPON_AXE):
        return 2 + (rand() % 8); //random number 2-8
    case (g_WEAPON_BOW):
        return 1 + (rand() % 9); //random number 1-9
    }
}
void Character::TakeDamage(int dmg)
{
    switch (m_armor)
    {
    //case (g_ARMOR_NONE):
        //break;
    case (g_ARMOR_LIGHT):
        dmg = int(dmg*0.8); // +20% dodge (20% damage reduction)
        break;
    case (g_ARMOR_MEDIUM):
        dmg = int(dmg*0.9); // +10% dodge (10% damage reduction)
        break;
    //case (g_ARMOR_HEAVY):
        //break;
    }

    m_currentHealth -= dmg; // apply damage
    m_currentHealth = std::clamp(m_currentHealth, 0, m_maxHealth); // clamp current health from 0 to max health
}

bool Character::IsAlive() {
    if (m_currentHealth == 0)
        return false;
    else
        return true;
}

// insert destructor
        // this is what to do when the object is destroyed. 

//virtual void Character::Attack() = 0;