#ifndef Jogador_h
#define Jogador_h

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/pokemon.h" 
#include "../include/menu.h"

typedef struct jogador Jogador;

Jogador *criaJogador(char *nome);

int verificaNome(char *nome);

void destroiJogador(Jogador *jogador);

char *retornaNome(Jogador *jogador);

#endif