#include "Armor.h"

Armor::Armor() // random armor generated, used for drops
{
	
}

Armor::Armor(std::string name) // specific armor generated, used only at beginning of game
{
	m_name = name;

    if (m_name == "light armor")
    {
        m_maxHealthMod = 10; // +10 max health
        m_dodgeMod = 0.8; // +20% dodge (20% damage reduction)
    }
    else if (m_name == "medium armor")
    {
        m_maxHealthMod = 25; // +25 max health
        m_dodgeMod = 0.9; // +10% dodge (10% damage reduction)
    }
    else if (m_name == "heavy armor")
    {
        m_maxHealthMod = 50; // +50 max health
        m_dodgeMod = 1.0; // +0% dodge (0% damage reduction)
    }
}