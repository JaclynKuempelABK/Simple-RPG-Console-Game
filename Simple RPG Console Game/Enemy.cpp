#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int weapon, int armor) :
    Character(weapon, armor)
{
    // announce character creation
    std::cout << "Enemy character (wielding ";
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

/*void Enemy::Attack() override
{

}*/