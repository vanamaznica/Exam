#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(string name)
    : character(name, 100, 35)
{
}

void Mage::attack(character& target)
{
    cout << name << " casts a spell at " << target.getName() << "!" << endl;
    target.takeDamage(damage);
}

void Mage::showInfo() const
{
    cout << "Mage: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
}