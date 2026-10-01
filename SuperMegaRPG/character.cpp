#include "character.h"
#include <iostream>
using namespace std;

character::character(string name, int hp, int damage)
{
    this->name = name;
    this->hp = hp;
    this->maxHp = hp;
    this->damage = damage;
}

character::~character()
{
}

string character::getName() const
{
    return name;
}

int character::getHp() const
{
    return hp;
}

int character::getDamage() const
{
    return damage;
}

void character::takeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
        hp = 0;
}

void character::heal(int amount)
{
    hp += amount;

    if (hp > maxHp)
        hp = maxHp;
}

void character::showInfo() const
{
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << "/" << maxHp << endl;
    cout << "Damage: " << damage << endl;
}