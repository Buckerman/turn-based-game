#include <iostream>
#include <fstream>
#include "start.h"
#include "ListOfPokemons.h"
#include "gameInstructions.h"
#include "Player.h"
#include "PlayerPokemonList.h"

using std::cout;
using std::cin;
using std::endl;

std::vector<pokemon> listPokemons = ListOfPokemons();
std::vector<pokemon> enemySet;
std::vector<pokemon> playerSet = PlayerPokemonList();
pokemon pokemon_in_hand;
int current_pokemon = 0;
bool endOfTurn = false;
int difficulty;

/**
 *
 * @return
 * cala mechanika gry :)
 */
int start() {

    int chosen_pokemon;
    int number = 0;
    int round = CurrentRound();

    string playerChoice;
    string saveChoice;

    cout << "Choose game difficulty: (type: number)" << endl;
    cout << "1. normal" << endl;
    cout << "2. medium" << endl;
    cout << "3. hard" << endl;
    cin >> difficulty;

    if (playerSet.empty()) {
        /**
         * wybor pokemonow do druzyny gracza
         */
        for (int i = 0; i < 6; i++) {

            cout << "\n" "Choose your pokemon: (type: number)" << endl;
            cout << "Pokemons in your inventory: " << playerSet.size() << "/6" << endl;
            int j = 0;
            for (const auto &pokemon: listPokemons) {
                cout << j << "." << pokemon.name << endl;
                j++;
            }
            cin >> chosen_pokemon;
            /**
             * sprawdza czy podany input gracza jest poprawny
             */
            while (!cin.good() || chosen_pokemon > listPokemons.size() - 1) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Wrong input, please type again." << endl;
                cin >> chosen_pokemon;
            }
            playerSet.push_back(listPokemons.at(chosen_pokemon));
        }
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
/**
 * zapetla gre do 4 rund
 */
    while (round < 4 && !playerSet.empty()) {

        bool start_game = true;
        shuffleEnemySet(difficulty);
        pokemon_in_hand = playerSet.at(current_pokemon);

        /**
         * rozpoczyna runde
         */
        while (start_game) {

            playerStats("player", pokemon_in_hand);
            playerStats("enemy", enemySet.at(0));

            cout << endl << "---Fight---" << endl;
            cout << "Choose what you want to do: " << endl;
            cout << "Attack enemy (type: attack)" << endl;
            cout << "Swap pokemon (type: swap)" << endl;
            cout << "Evolve pokemon (type: evo)" << endl;

            /**
             * pobiera cala linie jako wejsciowa
             */
            std::getline(cin, playerChoice);
            playerMenu(playerChoice);

            /**
             * atak przeciwnika oraz wymiana pokemona przez gracza jesli to konieczne
             */
            if (endOfTurn && !enemySet.empty()) {
                cout << "Enemy attacked you." << endl;
                if (!dodgePercentage(pokemon_in_hand)) {
                    pokemon_in_hand.setHealth(pokemon_in_hand.getHealth() -
                                              enemySet.at(0).getAttack() *
                                              interactions(enemySet.at(0), pokemon_in_hand));
                } else cout << pokemon_in_hand.getName() << " dodged enemy attack!" << endl;
                if (pokemon_in_hand.getHealth() <= 0) {
                    playerSet.erase(playerSet.begin() + getIndex(playerSet, pokemon_in_hand));
                    cout << "Your pokemon is down." << endl;
                    if (!playerSet.empty()) {
                        cout << "Swap to another one:" << endl;
                        for (const auto &pokemon: playerSet) {
                            cout << number << "." << pokemon.name << endl;
                            number++;
                        }
                        cin >> chosen_pokemon;
                        while (!cin.good() || chosen_pokemon > playerSet.size() - 1) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Wrong input, please type again." << endl;
                            cin >> chosen_pokemon;
                        }
                        pokemon_in_hand = playerSet.at(chosen_pokemon);

                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                endOfTurn = false;
            }
            number = 0;
            if (playerSet.empty()) {
                cout << "All your pokemons are down." << endl;
                start_game = false;
            }
            if (enemySet.empty() && round != 3) {
                cout << "You have defeated enemy." << endl;
                start_game = false;
                cout << "----------SAVE----------" << endl;
                cout << "Would you like to save current progress and leave? (type: yes/no)" << endl;
                cin >> saveChoice;
                if (saveChoice == "yes") {
                    cout << "Progress saved." << endl;
                    std::ofstream myfile;
                    myfile.open(
                            R"(..\PlayerPokemonList.txt)");
                    for (int i = 0; i < playerSet.size(); ++i) {
                        myfile << playerSet.at(i).getName() << ' ' << playerSet.at(i).getType() << ' '
                               << playerSet.at(i).getHealth() << ' ' << playerSet.at(i).getAttackName() << ' '
                               << playerSet.at(i).getAttack() << ' ' << playerSet.at(i).getAgility() << ' '
                               << playerSet.at(i).getAbilityName() <<' '<<playerSet.at(i).getCurrentExp() <<'\n';
                    }
                    myfile.close();
                    round++;
                    myfile.open(
                            R"(..\round.txt)");
                    myfile << round <<'\n';
                    myfile.close();
                    return 0;
                }
            }
        }
        round++;
    }

    if (playerSet.empty() && !enemySet.empty()) {
        cout << "You lose the game!" << endl;
        /**
         * tworze na nowo plik (reset danych)
         */
        fclose(fopen(
                R"(..\PlayerPokemonList.txt)",
                "w"));
        std::ofstream myfile;
        myfile.open(R"(..\round.txt)");
        myfile << "0\n";
        myfile.close();
    } else {
        cout << "Congrats you won!" << endl;
        /**
         * tworze na nowo plik (reset danych)
         */
        fclose(fopen(
                R"(..\PlayerPokemonList.txt)",
                "w"));
        std::ofstream myfile;
        myfile.open(R"(..\round.txt)");
        myfile << "0\n";
        myfile.close();
    }
    return 0;

}

/**
 *
 * @param pokemon
 * @return dodged or not
 * calculate percentage of dodging enemy attack
 */
int dodgePercentage(const pokemon &pokemon) {
    std::random_device rnd_device;
    std::uniform_int_distribution<int> dist(0, 100);
    bool TrueFalse = dist(rnd_device) < pokemon.getAgility();
    return TrueFalse;
}

/**
 *
 * @param v
 * @param pokemon
 * @return indeks pokemona w danym wektorze
 * szuka indeksu pokemona, aby móc go potem usunac z wektora
 */
int getIndex(std::vector<pokemon> v, const pokemon &pokemon) {
    int index = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).getName() == pokemon.getName())return index;
        else index++;
    }
    return 0;
}

/**
 *
 * @param input
 * @return cyfre
 * zamienia wybor gracza ze stringa na cyfre, aby uzyc potem w switchu
 */
unsigned fun(const string &input) {

    if (input == "attack") return 1;
    if (input == "swap") return 2;
    if (input == "evo") return 3;
    if (input == "-h" || input == "--help") return 4;

    return 0;
}

/**
 *
 * @param attacker - pokemon atakujacy
 * @param victim - pokemon przyjmujacy obrazenia
 * @return mnoznik ataku
 * sprawdza oddzialywania typow pokemonow na siebie
 */
double interactions(const pokemon &attacker, const pokemon &victim) {
    if (attacker.getType() == "water" && victim.getType() == "earth" ||
        attacker.getType() == "water" && victim.getType() == "fire" ||
        attacker.getType() == "earth" && victim.getType() == "fire" ||
        attacker.getType() == "earth" && victim.getType() == "ice" ||
        attacker.getType() == "earth" && victim.getType() == "steel" ||
        attacker.getType() == "air" && victim.getType() == "ice" ||
        attacker.getType() == "fire" && victim.getType() == "ice" ||
        attacker.getType() == "fire" && victim.getType() == "steel" ||
        attacker.getType() == "ice" && victim.getType() == "ground" ||
        attacker.getType() == "steel" && victim.getType() == "water" ||
        attacker.getType() == "steel" && victim.getType() == "air") {
        return 1.5;
    } else if (attacker.getType() == "water" && victim.getType() == "water" ||
               attacker.getType() == "earth" && victim.getType() == "air" ||
               attacker.getType() == "air" && victim.getType() == "earth" ||
               attacker.getType() == "air" && victim.getType() == "steel" ||
               attacker.getType() == "fire" && victim.getType() == "water" ||
               attacker.getType() == "fire" && victim.getType() == "earth" ||
               attacker.getType() == "ice" && victim.getType() == "water" ||
               attacker.getType() == "ice" && victim.getType() == "fire" ||
               attacker.getType() == "ice" && victim.getType() == "ice" ||
               attacker.getType() == "steel" && victim.getType() == "steel" ||
               attacker.getType() == "steel" && victim.getType() == "fire") {
        return 0.5;
    } else return 1;

}

/**
 *
 * @param input - jaki ruch gracz wykonal
 * @return w zaleznosci jaka czynnosc gracz wykonal taka sie wykonala
 * sprawdza jaka opcje wybral gracz atak,zmiana pokemona,ewolucja,instrukcja gry
 */
int playerMenu(const string &input) {
    int i = 0;
    switch (fun(input)) {
        case 1:
            cout << "You have used " << pokemon_in_hand.getAttackName() << " on enemy." << endl;

            /**
             * atack w przeciwnika
             */
            if (!dodgePercentage(enemySet.at(0))) {
                enemySet.at(0).setHealth(
                        enemySet.at(0).getHealth() -
                        pokemon_in_hand.getAttack() * interactions(pokemon_in_hand, enemySet.at(0)));
                endOfTurn = true;
            } else cout << "Enemy dodged your attack!" << endl;
            /**
             * przeciwnik pokonany, dodajemy EXP
             */
            if (enemySet.at(0).getHealth() <= 0) {
                cout << "You have downed enemy pokemon." << endl;
                pokemon_in_hand.setCurrentExp(pokemon_in_hand.getCurrentExp() + 3 * difficulty);
                enemySet.erase(enemySet.begin());
                endOfTurn = false;
            }
            break;
        case 2:
            /**
             * zamiana pokemonow
             */
            cout << "Your current pokemon: " << pokemon_in_hand.getName() << endl;
            for (const auto &pokemon: playerSet) {
                cout << i << "." << pokemon.name << endl;
                i++;
            }
            cin >> current_pokemon;

            while (!cin.good() || current_pokemon > playerSet.size() - 1) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Wrong input, please type again." << endl;
                cin >> current_pokemon;
            }
            pokemon_in_hand = playerSet.at(current_pokemon);
            cout << "You have swapped your pokemon to " << pokemon_in_hand.getName() << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 3:
            /**
             * ewolucja pokemona
             */
            if (pokemon_in_hand.getCurrentExp() >= 10) {
                cout << "You are evolving " << pokemon_in_hand.getName() << endl;
                pokemon_in_hand.setLevel(pokemon_in_hand.getLevel() + 1);
                evolution(pokemon_in_hand.getType(), pokemon_in_hand, pokemon_in_hand.getLevel());
                pokemon_in_hand.setCurrentExp(0);
            } else cout << "You cant evolve " << pokemon_in_hand.getName() << " yet." << endl;
            break;
        case 4: {
            /**
             * instrukcja gry
             */
            gameInstructions();
            break;
        }
        default:
            cout << "Wrong choice" << endl << endl;
            break;
    }
    return 0;
}

/**
 *
 * @param diff - poziom trudnosci
 * @return losowe pokemony przeciwnika
 * losujemy pokemony,ich ilosc i poziom w zaleznosci od trudnosci gry
 */
int shuffleEnemySet(int diff) {

    std::random_device rnd_device;
    std::uniform_int_distribution<int> dist(0, listPokemons.size() - 1);

    switch (diff) {
        case 1 :
            enemySet.reserve(4);
            for (int i = 0; i < 4; i++)enemySet.push_back(listPokemons.at(dist(rnd_device)));
            break;
        case 2:
            enemySet.reserve(2);
            for (int i = 0; i < 2; i++) {
                pokemon pokemon = listPokemons.at(dist(rnd_device));
                pokemon.setLevel(2);
                evolution(pokemon.getType(), pokemon, difficulty);
                enemySet.push_back(pokemon);
            }
            break;
        case 3:
            enemySet.reserve(1);
            pokemon pokemon = listPokemons.at(dist(rnd_device));
            pokemon.setLevel(3);
            evolution(pokemon.getType(), pokemon, difficulty);
            enemySet.push_back(pokemon);
            break;
    }

    return 0;
}

/**
 *
 * @param type - typ pokemona
 * @param pokemon - pokemon
 * @param diff - poziom trudnosci gry/poziom ewolucji
 * @return ulepszone atrybuty pokemona
 * ulepsza atrybuty w zaleznosci od typu pokemona
 */
int evolution(const string &type, pokemon &pokemon, int diff) {
    switch (diff) {
        case 2:
            if (type == "water") {
                pokemon.setHealth(pokemon.getHealth() + 200);
                pokemon.setAttack(pokemon.getAttack() + 30);
                pokemon.setAgility(pokemon.getAgility() + 2);
            } else if (type == "fire") {
                pokemon.setHealth(pokemon.getHealth() + 130);
                pokemon.setAttack(pokemon.getAttack() + 50);
                pokemon.setAgility(pokemon.getAgility() + 2);
            } else if (type == "air") {
                pokemon.setHealth(pokemon.getHealth() + 150);
                pokemon.setAttack(pokemon.getAttack() + 30);
                pokemon.setAgility(pokemon.getAgility() + 4);
            } else if (type == "earth") {
                pokemon.setHealth(pokemon.getHealth() + 130);
                pokemon.setAttack(pokemon.getAttack() + 30);
                pokemon.setAgility(pokemon.getAgility() + 1);
            } else if (type == "ice") {
                pokemon.setHealth(pokemon.getHealth() + 120);
                pokemon.setAttack(pokemon.getAttack() + 20);
                pokemon.setAgility(pokemon.getAgility() + 2);
            } else if (type == "steel") {
                pokemon.setHealth(pokemon.getHealth() + 200);
                pokemon.setAttack(pokemon.getAttack() * 2);
                pokemon.setAgility(pokemon.getAgility() + 1);
            }
            pokemon.setLevel(2);
            break;
        case 3:
            if (type == "water") {
                pokemon.setHealth(pokemon.getHealth() + 400);
                pokemon.setAttack(pokemon.getAttack() + 50);
                pokemon.setAgility(pokemon.getAgility() + 5);
            } else if (type == "fire") {
                pokemon.setHealth(pokemon.getHealth() + 330);
                pokemon.setAttack(pokemon.getAttack() + 75);
                pokemon.setAgility(pokemon.getAgility() + 5);
            } else if (type == "air") {
                pokemon.setHealth(pokemon.getHealth() + 270);
                pokemon.setAttack(pokemon.getAttack() + 45);
                pokemon.setAgility(pokemon.getAgility() + 10);
            } else if (type == "earth") {
                pokemon.setHealth(pokemon.getHealth() + 330);
                pokemon.setAttack(pokemon.getAttack() + 40);
                pokemon.setAgility(pokemon.getAgility() + 3);
            } else if (type == "ice") {
                pokemon.setHealth(pokemon.getHealth() + 310);
                pokemon.setAttack(pokemon.getAttack() + 40);
                pokemon.setAgility(pokemon.getAgility() + 4);
            } else if (type == "steel") {
                pokemon.setHealth(pokemon.getHealth() + 506);
                pokemon.setAttack(pokemon.getAttack() + 40);
                pokemon.setAgility(pokemon.getAgility() + 2);
            }
            pokemon.setLevel(3);
            break;
    }

    return 0;
}

int CurrentRound() {
    std::fstream fin;
    int round;
    std::ifstream file(R"(..\round.txt)",
                       std::ios::in);
    file >> round;
    file.close();
    return round;
}

