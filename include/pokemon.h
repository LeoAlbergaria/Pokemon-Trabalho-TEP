#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pokemon Pokemon;

typedef struct listaPokemon ListaPokemon; 

ListaPokemon *iniciaLista(Pokemon *pokemon);

ListaPokemon *inserePokemon(ListaPokemon *celulaAtual, Pokemon *pokemon);

void imprimeListaPokemon(ListaPokemon *lista);

ListaPokemon *removePokemonLista(ListaPokemon *lista, int posicaoPokemon);

void destroiListaPokemon(ListaPokemon *lista);

void destroiCelula(ListaPokemon *celula);

void destroiPokemon(Pokemon *pokemon);

char *retornaNomePokemon(Pokemon *pokemon);

char* retornaNomePokemonLista(ListaPokemon *lista, int posicaoPokemon);

Pokemon *retornaPokemon(ListaPokemon* listaPokemon);

int retornaHpPokemon(Pokemon* pokemon);

int retornaHpMaxPokemon(Pokemon* pokemon);

void SetterPokemonHp(Pokemon *pokemon, int hp);

void inicializaTabelaPokemons();

Pokemon *selecionaPokemon(char code);

Pokemon *pikachu();

Pokemon *charizard();

Pokemon *blastoise();

Pokemon *venosauro();

Pokemon *steelix();

Pokemon *mew();

#endif