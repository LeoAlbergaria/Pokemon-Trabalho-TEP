#ifndef BATALHA_H
#define BATALHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jogador.h"
#include "ataque.h"

void menuBatalha();

void imprimeMenuOpcoes(Jogador *jogador);

int numeroAleatorio(int randMax);

int probabilidade(float probabilidade);

#endif