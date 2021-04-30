#ifndef Pokemon_h
#define Pokemon_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/jogador.h" 
#include "../include/menu.h"

typedef struct pokemon Pokemon;

typedef struct listaPokemon ListaPokemon;

ListaPokemon *Insere(ListaPokemon *le, Pokemon *pokemon);

void ImprimeListaPokemon(ListaPokemon *le);

void destroiListaPokemon(int qtdPokemon, Pokemon* pokemon);

char *retornaNomePokemon(Pokemon *pokemon);

Pokemon *pikachu();

Pokemon *charizard();

Pokemon *blastoise();

Pokemon *venosauro();

Pokemon *steelix();

Pokemon *mew();

#endif