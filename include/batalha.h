#ifndef BATALHA_H
#define BATALHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jogador.h"
#include "ataque.h"

void menuBatalha();

void imprimeMenuOpcoes(Jogador *jogador, Pokemon *pokemon);

int turnoAtual(Jogador *jogador, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void turnoInimigo(Jogador *jogador, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void imprimeVidaBatalha(Pokemon *pokemonAtual, Pokemon *pokemonInimigo);

int numeroAleatorio(int randMax);

int probabilidade(float probabilidade);

#endif