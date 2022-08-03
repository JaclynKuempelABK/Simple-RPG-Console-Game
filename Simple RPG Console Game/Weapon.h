#pragma once
#include "Item.h"

class Weapon :
	public Item
{
protected:
	int m_minDmg;
	int m_maxDmg;

public:
	Weapon();

	Weapon(std::string name);

	virtual ItemType GetType() override { return ItemType::Weapon;  }

};

