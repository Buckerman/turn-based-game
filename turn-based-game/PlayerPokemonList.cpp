#include <fstream>
#include "PlayerPokemonList.h"
#include "pokemon.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

/**
 *
 * @return wektor z zapisanymi z poprzedniej gry pokemonami
 * wczytuje z pliku pokemony gracza z poprzedniej gry
 */
std::vector<pokemon> PlayerPokemonList(){

    fstream fin;
    fin.open(R"(..\PlayerPokemonList.txt)", std::ios::in);
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