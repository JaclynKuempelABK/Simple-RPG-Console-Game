#pragma once
#include <string>

/*enum class ItemType
{
	Weapon,
	Armor,
	
};*/

class Item
{
protected:
	std::string m_name;

	virtual:
	virtual ItemType GetType() = 0; // NEED TO PLACE THIS IN EACH OF THE SUB ITEMS
};

