#ifndef JOGADOR_H
#define JOGADOR_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/pokemon.h" 
#include "../include/menu.h"

typedef struct jogador Jogador;

Jogador *criaJogador(char *nome);

int verificaNome(char *nome);

void escolherIniciais();

void destroiJogador(Jogador *jogador);

char *retornaNome(Jogador *jogador);

#endif