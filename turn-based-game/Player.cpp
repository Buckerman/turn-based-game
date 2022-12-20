#include "Player.h"

/**
 *
 * @param who - przeciwnik albo gracz
 * @param pokemon - aktualny pokemon
 * @return statystyki pokemona w trakcie walki
 * wyswietlenie statystyk
 */
int playerStats(string who, pokemon pokemon){
    if (who == "player"){
    cout<<"---"<<who<<"---"<<endl;
    cout << "Current Pokemon: " << pokemon.getName() << endl;
    cout << "Type: " << pokemon.getType() << endl << endl;
    cout << "Current level: " << pokemon.getLevel() << endl;
    cout << "Current EXP: " << pokemon.getCurrentExp() << "/10" << endl << endl;

    cout << "Health: " << pokemon.getHealth() << endl;
    cout << "Attack damage: " << pokemon.getAttack() << endl;
    cout << "Agility %: " << pokemon.getAgility() << endl << endl;
    }else{
        cout<<"---"<<who<<"---"<<endl;
        cout << "Enemy Pokemon: " << pokemon.getName() << endl;
        cout << "Type: " << pokemon.getType() << endl << endl;
        cout << "Level: " << pokemon.getLevel() << endl;
        cout << "Health: " << pokemon.getHealth() << endl;
        cout << "Attack damage: " << pokemon.getAttack() << endl;
        cout << "Agility %: " << pokemon.getAgility() << endl << endl;
    }
    return 0;
}