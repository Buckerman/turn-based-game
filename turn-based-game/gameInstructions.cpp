#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 * @return instrukcja gry
 */
int gameInstructions(){
    cout<<"\nRozpoczecie gry:\n"
          "Aby rozpoczac lub kontynuowac gre wpisz \"game time\", po powrocie do menu glownego.\n"
          "Po rozpoczeniu gry, wybierz 6 pokemonow sposrod 15 do swojej druzyny kolejno wpisujac ich numerki po enterze.\n(Pokemony moga sie powtarzac.)"<<endl;
    cout<<"\nStarting the game:\n"
          "To start or continue the game, type \"game time\" after returning to the main menu.\n"
          "After starting the game, select 6 Pokémon from the 15 for your team by entering their numbers one by one after entering.\n(Pokémons may be repeated.)"<<endl;
    cout<<"\nGame Objective:\n"
          "After completing your team, you will fight against 4 opponents. Each of them has 4 random Pokémon from the pool. Defeat them all to win the game.\n"
          "Attacks, skills or Pokémon swaps are done by entering the appropriate number in the console. After defeating the opponent's Pokémon, yours receives EXP points, which will be used to evolve the Pokémon, improve its statistics and restore health points. (NOTE: Defeated Pokémon from the team will be excluded from further battles.)"<<endl;
    cout<<"\nElemental effects:\n"
          "water = 150% effectiveness on earth|fire\n"
          "water = 50% effectiveness on water\n"
          "earth = 150% effectiveness on fire|ice|steel\n"
          "earth = 50% effectiveness on air\n"
          "air = 150% effectiveness on ice\n"
          "air = 50% effectiveness on earth|steel\n"
          "fire = 150% effectiveness on ice|steel\n"
          "fire = 50% effectiveness on water|earth\n"
          "ice = 150% effectiveness on earth\n"
          "ice = 50% effectiveness on water|fire|ice\n"
          "steel = 150% effectiveness on water|air\n"
          "steel = 50% fire|steel effectiveness"<<endl;
    cout<<"\nAdditional information:\n"
          "After each victorious battle, you can save the game and return to the game at another time or continue.\n"
          "You can always return to the game instructions by typing -h / --help in the console."<<endl<<endl;

    return 0; // Ensure the function returns an integer
}
