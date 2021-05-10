#ifndef ATAQUE_H
#define ATAQUE_H

#include "pokemon.h"
#include "batalha.h"

void inicializaTabelaAtaques();

float calculaDano(int poder, int forca, int defesa, float mt, float relacaoTipo);

char* retornaNomeAtaque(int ataque);

float relacaoTipos(Pokemon* pokemonAtacamte, Pokemon* pokemonDefensor);

void selecionaAtaque(int code, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void imprimeLogAtaque(Pokemon *pokemon, int numeroAtaque,FILE *log);

void choqueDoTrovao(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void ondaDeChoque(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void bater(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void lancaChamas(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void dormir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void armaDeAgua(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void proteger(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void poDeSono(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void bombaDeSemente(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void doisGumes(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void raboDeFerro(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void cavar(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void metronomo(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

void autoDestruir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor,FILE *log);

#endif