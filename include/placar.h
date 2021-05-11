#ifndef PLACAR_H
#define PLACAR_H

#include "jogador.h"

typedef struct listaPlacar ListaPlacar;

void resultadoPlacar(Jogador *jogador, char *arquivoPlacar);

ListaPlacar *criaListaPlacar(char *arquivoPlacar);

void imprimeListaPlacarArquivo(ListaPlacar *listaPlacar, char *arquivoPlacar);

void imprimePlacar(char *arquivoPlacar);

ListaPlacar *inserePlacar(Jogador *jogador, ListaPlacar *listaPlacar);

void destroiListaPlacar(ListaPlacar *listaPlacar);

void destroiCelulaPlacar(ListaPlacar *celula);

#endif