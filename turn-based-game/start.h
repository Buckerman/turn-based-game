#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include "pokemon.h"

#ifndef TURN_BASED_GAME_START_H
#define TURN_BASED_GAME_START_H

int start();
int shuffleEnemySet(int diff);
int evolution(const std::string& type, pokemon& pokemon,int diff);
int playerMenu(const string& input);
unsigned fun(const string& choice);
int getIndex(std::vector<pokemon>v,const pokemon& pokemon);
int dodgePercentage(const pokemon& pokemon);
double interactions(const pokemon& attacker, const pokemon& victim);
int CurrentRound();
#endif
