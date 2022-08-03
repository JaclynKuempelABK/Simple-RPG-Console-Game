#include "Weapon.h"

// alternatively I can have 1 constructor that takes in an int value and converts that below. For a random weapon, you'd just pass in a random value (from ran). For a selected weapon, you'd pass in the chosen value (from cin).

Weapon::Weapon() // random weapon generated, used for drops
{
	int randomWeapon = 0 + (rand() % 3);

	switch (randomWeapon)
	{
	case 0:
		m_name = "sword";
		m_minDmg = 4;
		m_maxDmg = 6;
		break;
	case 1:
		m_name = "axe";
		m_minDmg = 2;
		m_maxDmg = 8;
		break;
	case 3:
		m_name = "bow";
		m_minDmg = 1;
		m_maxDmg = 9;
		break;
	}

	// SHOULD ALL OF THESE BE A CHILD OF WEAPON? LIKE A SWORD, AXE, BOW CHILD???
}

Weapon::Weapon(std::string name) // specific weapon generated, used only at beginning of game
{
	m_name = name;

	if (m_name == "sword")
	{
		m_minDmg = 4;
		m_maxDmg = 6;
	}
	else if (m_name == "axe")
	{
		m_minDmg = 2;
		m_maxDmg = 8;
	}
	else if (m_name == "bow")
	{
		m_minDmg = 1;
		m_maxDmg = 9;
	}
}
