#ifndef ATAQUE_H
#define ATAQUE_H

#include "pokemon.h"

void inicializaTabelaAtaques();

int calculaDano(int poder, int forca, int defesa, int mt, int relacaoTipo);

void selecionaAtaque(int code, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void choqueDoTrovao(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void ondaDeChoque(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void bater(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void lancaChamas(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void dormir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void armaDeAgua(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void proteger(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void poDeSono(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void bombaDeSemente(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void doisGumes(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void raboDeFerro(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void cavar(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void metronomo(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

void autoDestruir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

#endif