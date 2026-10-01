#pragma once
#include "character.h"

class Enemy : public character
{
public:
    Enemy(string name, int hp, int damage);

    void attack(character& target) override;
};