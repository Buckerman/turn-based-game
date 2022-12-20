#include <fstream>
#include "ListOfPokemons.h"
#include "pokemon.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

/**
 *
 * @return wektor pokemonow
 * odczyt bazowych pokemonow z pliku
 */
std::vector<pokemon> ListOfPokemons(){

    fstream fin;
    fin.open(R"(..\pokemonList.txt)", std::ios::in);
    if (!fin) {
        std::cerr << "Error in opening the file" << endl;
    }
    std::vector<pokemon> pokemonList;
    pokemon temp;
    while (fin >> temp.name >> temp.type >> temp.health >> temp.attack_name >> temp.attack >> temp.agility >> temp.ability_name >> temp.currentEXP) {
        pokemonList.push_back(temp);
    }

    return pokemonList;
}