#include <iostream>
#include "gameInstructions.h"

using std::cout;
using std::cin;
using std::endl;

/**
 *
 * @return instrukcja gry
 */
int gameInstructions(){
    cout<<"\nRozpoczecie gry:\n"
          "Aby rozpoczac lub kontynuowac gre wpisz \"game time\", po powrocie do menu glownego.\n"
          "Po rozpoczeniu gry, wybierz 6 pokemonow sposrod 15 do swojej druzyny kolejno wpisujac ich numerki po enterze.\n(Pokemony moga sie powtarzac.)"<<endl;
    cout<<"\nCel gry:\n"
          "Po skompletowaniu druzyny, bedziesz walczyl przeciwko 4 przeciwnikom. Kazdy z nich posiada 4 losowe pokemony z puli. Pokonaj ich wszystkich, aby wygrac gre.\n"
          "Ataki, umiejetnosci czy tez zamiana pokemonow nastepuje poprzez wpisanie odpowiedniej cyfry w konsoli. Po pokonaniu pokemona przeciwnika, twoj otrzymuje punkty EXP, ktore posluza do wyewoluowania pokemona jak i ulepszenia jego statystyk oraz odnowienia punktow zdrowia.(UWAGA: Pokonane pokemony z druzyny beda wykluczone z dalszych walk.)"<<endl;
    cout<<"\nOddzialywania zywiolow:\n"
          "woda = 150% efektywnosci na ziemia|ogien\n"
          "woda = 50% efektywnosci na woda\n"
          "ziema = 150% efektywnosci na ogien|lod|stal\n"
          "ziemia = 50% efektywnosci na powietrze\n"
          "powietrze = 150% efektywnosci na lod\n"
          "powietrze = 50% efektywnosci na ziemia|stal\n"
          "ogien = 150% efektywnosci na lod|stal\n"
          "ogien = 50% efektywnosci na woda|ziemia\n"
          "lod = 150% efektywnosci na ziemia\n"
          "lod = 50% efektywnosci na woda|ogien|lod\n"
          "stal = 150% efektywnosci na woda|powietrze\n"
          "stal = 50% efektywnosci na ogien|stal"<<endl;
    cout<<"\nDodatkowe informacje:\n"
          "Po kazdej zwycieskiej walce mozesz zapisac gre i wrocic do rozgrywki kiedy indziej lub kontynuowac.\n"
          "Do instrukcji gry mozesz zawsze wrocic wpisujac w konsoli -h / --help."<<endl<<endl;
}