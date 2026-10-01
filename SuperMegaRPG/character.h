#pragma once
#include <string>
using namespace std;

class character
{
protected:
    string name;
    int hp;
    int maxHp;
    int damage;

public:
    character(string name, int hp, int damage);
    virtual ~character();

    string getName() const;
    int getHp() const;
    int getDamage() const;

    void takeDamage(int damage);
    void heal(int amount);

    virtual void attack(character& target) = 0;
    virtual void showInfo() const;
};