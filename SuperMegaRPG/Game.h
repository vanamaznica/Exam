#pragma once
#include "character.h"

class Game
{
private:
    character* player;

public:
    Game();
    ~Game();
    void start();
    void chooseCharacter();
    void fight(character& enemy);
    void showMenu();
};