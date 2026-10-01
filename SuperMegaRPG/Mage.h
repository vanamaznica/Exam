#pragma once
#include "character.h"

class Mage : public character
{
public:
    Mage(string name);

    void attack(character& target) override;
    void showInfo() const override;
};