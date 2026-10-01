#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string name)
    :  character(name, 150, 25)
{
}

void Warrior::attack(character& target)
{
    cout << name << " attacks " << target.getName() << "!" << endl;
    target.takeDamage(damage);
}

void Warrior::showInfo() const
{
    cout << "Warrior: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
}