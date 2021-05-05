#include "ataque.h"

typedef void (*fptrAtaque)(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor);

fptrAtaque ataques[14] = {NULL};

void inicializaTabelaAtaques()
{
  ataques[0] = choqueDoTrovao;
  ataques[1] = ondaDeChoque;
  ataques[2] = bater;
  ataques[3] = lancaChamas;
  ataques[4] = dormir;
  ataques[5] = armaDeAgua;
  ataques[6] = proteger;
  ataques[7] = poDeSono;
  ataques[8] = bombaDeSemente;
  ataques[9] = doisGumes;
  ataques[10] = raboDeFerro;
  ataques[11] = cavar;
  ataques[12] = metronomo;
  ataques[13] = autoDestruir;
}

int calculaDano(int poder, int forca, int defesa, int mt, int relacaoTipo)
{
    int dano, modificador, critico;

    if(probabilidade(24) == 1)
        critico = 2;
    else
        critico = 1;

    modificador = critico * mt * relacaoTipo;
    dano = ((14*poder*forca/defesa)/50 + 2) * modificador;
    return dano;
}

void selecionaAtaque(int code, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    ataques[code](pokemonAtacante, pokemonDefensor);
}

void choqueDoTrovao(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 40;
    int mt;
}

void ondaDeChoque(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    
}

void bater(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 40;
    int mt;
}

void lancaChamas(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 90;
    int mt;
}

void dormir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    
}


void armaDeAgua(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 40;
    int mt;
}

void proteger(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    
}

void poDeSono(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    
}

void bombaDeSemente(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 80;
    int mt;
}

void doisGumes(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 120;
    int mt;
}

void raboDeFerro(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 100;
    int mt;
}

void cavar(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 80;
    int mt;
}

void metronomo(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    
}

void autoDestruir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 200;
    int mt;
}