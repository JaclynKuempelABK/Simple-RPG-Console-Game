#pragma once
#include "Character.h"
#include <string>

class Player : 
    public Character
{
private:
    std::string m_name;

public:
    Player(std::string name, int weapon, int armor);
    void Rest();
};

