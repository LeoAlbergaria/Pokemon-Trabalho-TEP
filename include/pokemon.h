#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pokemon Pokemon;

typedef struct listaPokemon ListaPokemon; 

ListaPokemon *iniciaLista(Pokemon *pokemon);

ListaPokemon *inserePokemon(ListaPokemon *celulaAtual, Pokemon *pokemon);

void imprimeListaPokemon(ListaPokemon *lista);

ListaPokemon *removePokemonLista(ListaPokemon *lista, int posicaoPokemon);

void destroiListaPokemon(ListaPokemon *lista);

void destroiCelula(ListaPokemon *celula);

void destroiPokemon(Pokemon *pokemon);

int converteTipo(Pokemon *pokemon);

void retiraEfeitosPokemon(Pokemon *pokemon);

void imprimeEfeitosPokemon(Pokemon *pokemon);

int verificaEfeitos(Pokemon *pokemon);

void resetaEfeitosPokemon(Pokemon *pokemon);

char *retornaNomePokemon(Pokemon *pokemon);

char* retornaNomePokemonLista(ListaPokemon *lista, int posicaoPokemon);

Pokemon *retornaPokemon(ListaPokemon* listaPokemon);

float retornaHpPokemon(Pokemon* pokemon);

float retornaHpMaxPokemon(Pokemon* pokemon);

float retornaPocentagemHp(Pokemon* pokemon);

int retornaForca(Pokemon* pokemon);

int retornaDefesa(Pokemon* pokemon);

int retornaNumAtaque(Pokemon* pokemon, int num);

int retornaDomindo(Pokemon* pokemon);

int retornaSono(Pokemon* pokemon);

int retornaQueimar(Pokemon* pokemon);

int retornaParalisado(Pokemon* pokemon);

int retornaCavar(Pokemon* pokemon);

int retornaProtegido(Pokemon* pokemon);

void setterDormindo(Pokemon *pokemon, int turnos);

void setterSono(Pokemon *pokemon, int turnos);

void setterQueimar(Pokemon *pokemon, int turnos);

void setterParalisado(Pokemon *pokemon, int turnos);

void setterPokemonHp(Pokemon *pokemon, float hp);

void setterCavar(Pokemon *pokemon, int turnos);

void setterProtegido(Pokemon *pokemon, int turnos);

void inicializaTabelaPokemons();

Pokemon *selecionaPokemon(char code);

Pokemon *pikachu();

Pokemon *charizard();

Pokemon *blastoise();

Pokemon *venosauro();

Pokemon *steelix();

Pokemon *mew();

void desenhaPokemon(char letraPokemon);

#endif