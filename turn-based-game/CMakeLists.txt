cmake_minimum_required(VERSION 3.21)
project(turn_based_game)
add_link_options(-static -static-libgcc -static-libstdc++)

set(CMAKE_CXX_STANDARD 14)

add_executable(turn_based_game main.cpp gameInstructions.cpp gameInstructions.h start.cpp start.h pokemon.cpp pokemon.h ListOfPokemons.cpp ListOfPokemons.h pokemonStats.cpp pokemonStats.h Player.cpp Player.h PlayerPokemonList.cpp PlayerPokemonList.h)
