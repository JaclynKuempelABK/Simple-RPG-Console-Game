#include "Player.h"
#include <iostream>
#include <algorithm>

Player::Player(std::string name, int weapon, int armor) :
    Character(weapon, armor)
{
    m_name = name;

    // announce character creation with player choices (name, weapon, armor)
    std::cout << "Player character " << m_name;
    std::cout << " (wielding ";
    switch (m_weapon)
    {
    case g_WEAPON_NONE:
        std::cout << "nothing";
        break;
    case g_WEAPON_SWORD:
        std::cout << "a sword";
        break;
    case g_WEAPON_AXE:
        std::cout << "an axe";
        break;
    }
    std::cout << " and wearing ";
    switch (m_armor)
    {
    case g_ARMOR_NONE:
        std::cout << "nothing";
        break;
    case g_ARMOR_LIGHT:
        std::cout << "light armor";
        break;
    case g_ARMOR_MEDIUM:
        std::cout << "medium armor";
        break;
    case g_ARMOR_HEAVY:
        std::cout << "heavy armor";
        break;
    }
    std::cout << ") has been created" << std::endl;
}
void Player::Rest()
{
    m_currentHealth += 20;
    m_currentHealth = std::clamp(m_currentHealth, 0, m_maxHealth); // clamp current health from 0 to max health
}
// insert destructor

/*void Player::Attack() override
{

}*/

