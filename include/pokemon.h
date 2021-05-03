#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/jogador.h" 
#include "../include/menu.h"

typedef struct pokemon Pokemon;

typedef struct listaPokemon ListaPokemon;

ListaPokemon *iniciaLista(Pokemon *pokemon);

ListaPokemon *insere(ListaPokemon *celulaAtual, Pokemon *pokemon);

void criaLista(ListaPokemon *lista);

void imprimeListaPokemon(ListaPokemon *lista);

ListaPokemon *removePokemonLista(ListaPokemon *lista, int posicaoPokemon);

void destroiListaPokemon(ListaPokemon *lista);

void destroiCelula(ListaPokemon *celula);

char *retornaNomePokemon(Pokemon *pokemon);

void inicializaTabelaPokemons();

Pokemon *selecionarPokemon(char code);

Pokemon *pikachu();

Pokemon *charizard();

Pokemon *blastoise();

Pokemon *venosauro();

Pokemon *steelix();

Pokemon *mew();

#endif