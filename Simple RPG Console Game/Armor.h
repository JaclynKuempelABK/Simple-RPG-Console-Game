#pragma once
#include "Item.h"

class Armor :
	public Item
{
protected:
	int m_maxHealthMod;
	float m_dodgeMod;

public:
	Armor();

	Armor(std::string name);
};

