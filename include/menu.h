#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jogador.h"
#include "batalha.h"

void menuPrincipal(char* arquivoPlacar, char* arquivoLog);

void imprimeMenuPrincipal();

void menuIniciais(Jogador *jogador);

#endif