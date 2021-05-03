#ifndef JOGADOR_H
#define JOGADOR_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokemon.h"

typedef struct jogador Jogador;

Jogador *criaJogador(char *nome);

int verificaNome(char *nome);

void escolherIniciais(Jogador *jogador, ListaPokemon *pokemonsIniciais);

void removePokemonListaJogador(Jogador *jogador);

void destroiJogador(Jogador *jogador);

char *retornaNome(Jogador *jogador);

Pokemon *retornaListaJogador(Jogador *jogador);

int retornaPokebolas(Jogador *jogador);

int retornaQtdPokemons(Jogador *jogador);

int retornaVitorias(Jogador *jogador);

void SetterQtdVitoria(Jogador *jogador);

void SetterQtdPokemon(Jogador *jogador, int qtd);

#endif