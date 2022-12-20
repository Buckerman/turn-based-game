#include <iostream>
#include <string>
#include "gameInstructions.h"
#include "start.h"
#include "pokemonStats.h"

using std::cout;
using std::cin;
using std::endl;

/**
 *
 * @param choice
 * @return cyfre
 * zamienia wybor gracza ze stringa na cyfre, aby uzyc potem w switchu
 */
unsigned f(const string& choice) {
    if (choice == "game time") return 1;
    if (choice == "-h" || choice == "--help") return 2;
    if (choice == "pokemon stats") return 3;
    return 0;
}

int main() {

    cout<<"Welcome to the game."<<endl;
    string choice = " ";
    /**
     * gracz wybiera, co chce zrobic
     */
    while (f(choice) != 1) {
        cout << "Choose what you want to do: " << endl;
        cout << "--Start (type: game time)" << endl;
        cout << "--Instruction (type: -h OR --help) " << endl;
        cout << "--Pokemon Stats (type: pokemon stats)" << endl;
        std::getline(cin,choice);
        f(choice);
        switch (f(choice)) {
            case 1: {
                start();
                break;
            }
            case 2: {
                gameInstructions();
                break;
            }
            case 3:{
                cout << "Choose which pokemon stats would you like to see: (type: number)"<<endl;
                pokemonStats();
                break;
            }
            default:
                cout <<"Wrong choice"<<endl<<endl;
                break;
        }
    }
}
