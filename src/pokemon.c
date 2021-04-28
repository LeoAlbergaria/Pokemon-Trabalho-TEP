#include "pokemon.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pokemon
{
    char *nome;
    char *tipo;
    //Ataque;
    int forca;
    int defesa;
    int hp;
    char estador;
};

Pokemon *criaListaPokemon()
{
    Pokemon *pokemon = (Pokemon*)calloc(1, 3 * sizeof(Pokemon));
    return pokemon;
}

void destroiListaPokemon(int qtdPokemon, Pokemon* pokemon)
{
    for(int i = 0; i < qtdPokemon; i++)
    {
        free(pokemon->nome);
        free(pokemon->tipo);
    }
}