#include "pokemonStats.h"
#include "pokemon.h"
#include "ListOfPokemons.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 *
 * @return wyswietla statystki wybranego pokemona
 * pobiera pelna liste bazowych pokemonow
 * wyswietla je wszystkie
 * sprawdza czy wybor gracza jest poprawny
 * wyswietla pelne statystki pokemona
 */
int pokemonStats() {
    std::vector<pokemon> listPokemons = ListOfPokemons();
    int chosen_pokemon;
    int i = 0;


    for (const auto &pokemon: listPokemons) {
        cout << i << "." << pokemon.name << endl;
        i++;
    }
    cin >> chosen_pokemon;
    /**
         * sprawdza czy podany input gracza jest poprawny
         */
    while (!cin.good() || chosen_pokemon > listPokemons.size() - 1) {
        cin.clear();//clear all the errors - set back to goodbit
        cin.ignore(std::numeric_limits<std::streamsize>::max()/*upper limit of streamsize*/,
                   '\n');//sets the number of characters to ignore, stop ignoring after \n
        cout << "Wrong input, please type again." << endl;
        cin >> chosen_pokemon;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    pokemon pokemon = listPokemons.at(chosen_pokemon);
    cout << "Name: " << pokemon.getName() << endl;
    cout << "Type: " << pokemon.getType() << endl << endl;
    cout << "Level: " << pokemon.getLevel() << endl;
    cout << "Current EXP: " << pokemon.getCurrentExp() << "/10" << endl << endl;

    cout << "Health: " << pokemon.getHealth() << endl;
    cout << "Attack damage: " << pokemon.getAttack() << endl;
    cout << "Ability name: " << pokemon.getAbilityName() << endl;
    cout << "Agility %: " << pokemon.getAgility() << endl << endl;

    return 0;
}