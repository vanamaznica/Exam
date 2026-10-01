#pragma once
#include "character.h"

class Warrior : public character
{
public:
    Warrior(string name);

    void attack(character& target) override;
    void showInfo() const override;
};