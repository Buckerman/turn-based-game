#include <iostream>
#include "pokemon.h"
pokemon::pokemon() = default;

int pokemon::getLevel() const {
    return level;
}

void pokemon::setLevel(int level) {
    pokemon::level = level;
}

int pokemon::getCurrentExp() const {
    return currentEXP;
}

void pokemon::setCurrentExp(int currentExp) {
    currentEXP = currentExp;
}

const string &pokemon::getType() const {
    return type;
}

void pokemon::setHealth(double health) {
    pokemon::health = health;
}


void pokemon::setAttack(int attack) {
    pokemon::attack = attack;
}

void pokemon::setAgility(int agility) {
    pokemon::agility = agility;
}

double pokemon::getHealth() const {
    return health;
}

int pokemon::getAttack() const {
    return attack;
}

int pokemon::getAgility() const {
    return agility;
}

const string &pokemon::getName() const {
    return name;
}

const string &pokemon::getAttackName() const {
    return attack_name;
}

const string &pokemon::getAbilityName() const {
    return ability_name;
}

pokemon::pokemon(const string &name, const string &type, double health, const string &attackName, int attack,
                 int agility, const string &abilityName, int currentExp) : name(name), type(type), health(health),
                                                                           attack_name(attackName), attack(attack),
                                                                           agility(agility), ability_name(abilityName),
                                                                           currentEXP(currentExp) {}
pokemon::~pokemon() = default;
