#include "Game.h"
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"
#include "Orc.h"
#include <iostream>
using namespace std;

Game::Game()
{
    player = nullptr;
}

Game::~Game()
{
    delete player;
}

void Game::chooseCharacter()
{
    string name;
    int choice;

    cout << "Enter your name: ";
    cin >> name;
    cout << endl;
    cout << "Choose your character:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "> ";
    cin >> choice;

    delete player;

    if (choice == 2)
        player = new Mage(name);
    else
        player = new Warrior(name);
}

void Game::fight(character& enemy)
{
    int choice;

    cout << endl;
    cout << "You met " << enemy.getName() << "!" << endl;

    while (player->getHp() > 0 && enemy.getHp() > 0)
    {
        cout << endl;
        cout << "Your HP: " << player->getHp() << endl;
        cout << enemy.getName() << " HP: " << enemy.getHp() << endl;
        cout << endl;
        cout << "1. Attack" << endl;
        cout << "2. Heal" << endl;
        cout << "3. Run" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == 1)
        {
            player->attack(enemy);

            if (enemy.getHp() > 0)
                enemy.attack(*player);
        }
        else if (choice == 2)
        {
            player->heal(25);
            cout << "You restored 25 HP." << endl;

            if (enemy.getHp() > 0)
                enemy.attack(*player);
        }
        else if (choice == 3)
        {
            cout << "You ran away." << endl;
            return;
        }
        else
        {
            cout << "Wrong choice." << endl;
        }
    }

    if (player->getHp() > 0)
    {
        cout << endl;
        cout << "You defeated " << enemy.getName() << "!" << endl;
    }
    else
    {
        cout << endl;
        cout << "You died." << endl;
    }
}

void Game::showMenu()
{
    int choice;

    while (true)
    {
        cout << endl;
        cout << "========= Super Mega RPG ==========" << endl;
        cout << "1. Find an enemy" << endl;
        cout << "2. Show character" << endl;
        cout << "0. Exit" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == 1)
        {
            int enemyChoice;

            cout << endl;
            cout << "Choose an enemy:" << endl;
            cout << "1. Goblin" << endl;
            cout << "2. Orc" << endl;
            cout << "> ";
            cin >> enemyChoice;

            if (enemyChoice == 1)
            {
                Goblin enemy;
                fight(enemy);
            }
            else if (enemyChoice == 2)
            {
                Orc enemy;
                fight(enemy);
            }
            else
            {
                cout << "Wrong choice." << endl;
            }

            if (player->getHp() <= 0)
                break;
        }
        else if (choice == 2)
        {
            player->showInfo();
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Wrong choice." << endl;
        }
    }
}

void Game::start()
{
    chooseCharacter();
    showMenu();
}