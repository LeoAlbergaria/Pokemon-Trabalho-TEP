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

float calculaDano(int poder, int forca, int defesa, float mt, float relacaoTipo)
{
    float dano, critico, modificador;

    if(probabilidade(1/24.0))
        critico = 2.0;
    else
        critico = 1.0;

    modificador = critico * mt * relacaoTipo;
    dano = ((14.0*poder*forca/defesa)/50.0 + 2) * modificador;
    return dano;
}

void selecionaAtaque(int code, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    ataques[code](pokemonAtacante, pokemonDefensor);
}

char* retornaNomeAtaque(int ataque)
{
    switch(ataque)
    {
        case 0: return "Choque do Trovão";

        case 1: return "Onda de Choque";

        case 2: return "Bater";

        case 3: return "Lança Chamas";

        case 4: return "Dormir";

        case 5: return "Arma de Água";

        case 6: return "Proteger";

        case 7: return "Pó de Sono";

        case 8: return "Bomba de Semente";
            
        case 9: return "Dois Gumes";

        case 10: return "Rabo de Ferro";

        case 11: return "Cavar";

        case 12: return "Metronomo";

        case 13: return "Auto-Destruir";
    }
}

float relacaoTipos(Pokemon* pokemonAtacante, Pokemon* pokemonDefensor)
{
    float relacao[6][6] = {{0.5,0.5,2,1,1,2},
    {2,0.5,0.5,1,1,0.5},
    {0.5,2,0.5,1,1,0.5},
    {1,2,0.5,0.5,1,1},
    {1,1,1,1,0.5,0.5},
    {0.5,0.5,1,0.5,1,0.5}};

    int linha = converteTipo(pokemonAtacante);
    int coluna = converteTipo(pokemonDefensor);
    return relacao[linha][coluna];
}

void choqueDoTrovao(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 40;
    float mt = 1.5;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
    if(probabilidade(1/10.0))
        setterParalisado(pokemonDefensor, 1);
}

void ondaDeChoque(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    setterParalisado(pokemonDefensor, 1);
}

void bater(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 40;
    float mt = 1.0;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
}

void lancaChamas(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 90;
    float mt = 1.5;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
    if(probabilidade(1/10.0))
        setterQueimar(pokemonDefensor, 1);
}

void dormir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    setterDormindo(pokemonAtacante, 3);
}


void armaDeAgua(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 40;
    float mt = 1.5;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
}

void proteger(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    setterProtegido(pokemonAtacante, 1);
}

void poDeSono(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    setterSono(pokemonDefensor, numeroAleatorio(3));
}

void bombaDeSemente(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 80;
    float mt = 1.5;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
}

void doisGumes(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 120;
    float mt = 1.0;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
    setterPokemonHp(pokemonAtacante, retornaHpPokemon(pokemonAtacante) - (dano/3));
}

void raboDeFerro(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 100;
    float mt = 1.5;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
}

void cavar(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 80;
    float mt = 1.0;
    float dano;
    if(retornaCavar(pokemonAtacante))
    {
        dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
        setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
        setterCavar(pokemonAtacante, 0);
        setterProtegido(pokemonAtacante, 0);
    }
    else
    {
        setterCavar(pokemonAtacante, 2);
        setterProtegido(pokemonAtacante, 2);
    }
}

void metronomo(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int ataque = numeroAleatorio(14) - 1;
    selecionaAtaque(ataque, pokemonAtacante, pokemonDefensor);
}

void autoDestruir(Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int poder = 200;
    float mt = 1.0;
    float dano = calculaDano(poder, retornaForca(pokemonAtacante), retornaDefesa(pokemonDefensor), mt, relacaoTipos(pokemonAtacante, pokemonDefensor));
    setterPokemonHp(pokemonDefensor, retornaHpPokemon(pokemonDefensor) - dano);
    setterPokemonHp(pokemonAtacante, 0);
}