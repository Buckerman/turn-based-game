#pragma once
#ifndef TURN_BASED_GAME_POKEMON_H
#define TURN_BASED_GAME_POKEMON_H

#include <iostream>
#include <utility>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class pokemon {
public:
    pokemon();

    int level = 1;
    string name;
    string type;
    double health{};
    string attack_name;
    int attack{};
    int agility{};
    string ability_name;
    int currentEXP = 0;

    pokemon(const string &name, const string &type, double health, const string &attackName, int attack, int agility,
            const string &abilityName, int currentExp);

    void setHealth(double health);
    void setAttack(int attack);
    void setAgility(int agility);
    void setLevel(int level);
    void setCurrentExp(int currentExp);

    double getHealth() const;
    const string &getType() const;
    const string &getName() const;
    const string &getAttackName() const;
    const string &getAbilityName() const;
    int getAttack() const;
    int getAgility() const;
    int getCurrentExp() const;
    int getLevel() const;

    virtual ~pokemon();
};

#endif
