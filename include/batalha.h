#ifndef BATALHA_H 
#define BATALHA_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "jogador.h" 
#include "ataque.h" 
#include "placar.h" 

void menuBatalha(Jogador *jogador, int contadorPartidas, FILE *log, char *arquivoPlacar); 

void imprimeMenuOpcoes(Jogador *jogador, Pokemon *pokemon); 

int turnoAtual(Jogador *jogador, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor, FILE *log); 

void turnoInimigo(Jogador *jogador, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor, FILE *log); 

void imprimeVidaBatalha(Pokemon *pokemonAtual, Pokemon *pokemonInimigo); 
  
void imprimeArquivoVidaBatalha(Pokemon *pokemonAtual, Pokemon *pokemonInimigo, FILE *log); 

int numeroAleatorio(int randMax); 

int probabilidade(float probabilidade); 
 
#endif 