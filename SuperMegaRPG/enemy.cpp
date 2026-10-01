#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(string name, int hp, int damage)
    : character(name, hp, damage)
{
}

void Enemy::attack(character& target)
{
    cout << name << " attacks " << target.getName() << "!" << endl;
    target.takeDamage(damage);
}