#include "../include/pokemon.h"

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

struct listaPokemon
{
    Pokemon *pokemon;
    struct listaPokemon *prox;
};

ListaPokemon *Insere(ListaPokemon *le, Pokemon *pokemon)
{
    ListaPokemon *novo = (ListaPokemon*) malloc(sizeof(ListaPokemon));
    novo->pokemon = pokemon;
    novo->prox = le;
    return novo;
}

void ImprimeListaPokemon(ListaPokemon *le)
{
    ListaPokemon * celula;
    celula = le;

    int index = 1;
    do{
        printf("%d - %s\n", index,  retornaNomePokemon(celula->pokemon));
        celula = celula->prox;
        index++;
    }while (celula != NULL);
}

void destroiListaPokemon(int qtdPokemon, Pokemon* pokemon)
{
    for(int i = 0; i < qtdPokemon; i++)
    {
        free(pokemon->nome);
        free(pokemon->tipo);
    }
}

char *retornaNomePokemon(Pokemon *pokemon)
{
    return pokemon->nome;
}

Pokemon *pikachu()
{
    Pokemon* pikachu = (Pokemon*)malloc(sizeof(Pokemon));

    pikachu->nome = strdup("Pikachu");
    pikachu->hp = 200;
    pikachu->forca = 110;
    pikachu->defesa = 100;
    pikachu->tipo = strdup("Elétrico");

    return pikachu;
}

Pokemon *charizard()
{
    Pokemon* charizard = (Pokemon*)malloc(sizeof(Pokemon));

    charizard->nome = strdup("Charizard");
    charizard->hp = 260;
    charizard->forca = 160;
    charizard->defesa = 150;
    charizard->tipo = strdup("Fogo");

    return charizard;
}

Pokemon *blastoise()
{
    Pokemon* blastoise = (Pokemon*)malloc(sizeof(Pokemon));

    blastoise->nome = strdup("Blastoise");
    blastoise->hp = 280;
    blastoise->forca = 180;
    blastoise->defesa = 200;
    blastoise->tipo = strdup("Água");

    return blastoise;
}

Pokemon *venosauro()
{
    Pokemon* venosauro = (Pokemon*)malloc(sizeof(Pokemon));

    venosauro->nome = strdup("Venosauro");
    venosauro->hp = 300;
    venosauro->forca = 160;
    venosauro->defesa = 160;
    venosauro->tipo = strdup("Planta");

    return venosauro;
}

Pokemon *steelix()
{
    Pokemon* steelix = (Pokemon*)malloc(sizeof(Pokemon));

    steelix->nome = strdup("Steelix");
    steelix->hp = 280;
    steelix->forca = 170;
    steelix->defesa = 400;
    steelix->tipo = strdup("Metal");

    return steelix;
}

Pokemon *mew()
{
    Pokemon* mew = (Pokemon*)malloc(sizeof(Pokemon));

    mew->nome = strdup("Mew");
    mew->hp = 320;
    mew->forca = 200;
    mew->defesa = 200;
    mew->tipo = strdup("Psíquico");

    return mew;
}