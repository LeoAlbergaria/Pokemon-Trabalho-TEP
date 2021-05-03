#include "pokemon.h"

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

typedef Pokemon* (*fptrPokemon)();

fptrPokemon pokemons[128] = {NULL};

ListaPokemon *iniciaLista(Pokemon *pokemon)
{
    ListaPokemon *iniciais = (ListaPokemon*)malloc(sizeof(ListaPokemon));
    iniciais->pokemon = pokemon;
    iniciais->prox = NULL;
    return iniciais;
}

ListaPokemon *inserePokemon(ListaPokemon *celulaAtual, Pokemon *pokemon)
{
    celulaAtual->prox = (ListaPokemon*)malloc(sizeof(ListaPokemon));
    celulaAtual = celulaAtual->prox;
    celulaAtual->pokemon = pokemon;
    celulaAtual->prox = NULL;
    return celulaAtual;
}

void imprimeListaPokemon(ListaPokemon *lista)
{
    ListaPokemon * celula;
    celula = lista;

    int index = 1;
    do{
        printf("%d - %s\n", index,  retornaNomePokemon(celula->pokemon));
        celula = celula->prox;
        index++;
    }while (celula != NULL);
}

ListaPokemon *removePokemonLista(ListaPokemon *lista, int posicaoPokemon)
{
    ListaPokemon *celulaAnterior = NULL;
    ListaPokemon *celulaAtual = lista;
    int index = 0;
    while(celulaAtual != NULL && index != posicaoPokemon)
    {
        celulaAnterior = celulaAtual;
        celulaAtual = celulaAtual->prox;
        index++;
    }
    if(celulaAtual == NULL)
        return lista;
    if(index == posicaoPokemon)
    {
        if(index == 0)
        {
            lista = celulaAtual->prox;
            destroiCelula(celulaAtual);
        }
        else
        {
            celulaAnterior->prox = celulaAtual->prox;
            destroiCelula(celulaAtual);
        }
    }
    return lista;
}

void destroiListaPokemon(ListaPokemon *lista)
{   
    ListaPokemon *celulaAtual = lista;
    ListaPokemon *celulaProx;

    do
    {
        celulaProx = celulaAtual->prox;
        destroiCelula(celulaAtual);
        celulaAtual = celulaProx;
    }while(celulaAtual != NULL);
}

void destroiCelula(ListaPokemon *celula)
{
    destroiPokemon(celula->pokemon);
    free(celula);
}

void destroiPokemon(Pokemon *pokemon)
{
    free(pokemon->nome);
    free(pokemon->tipo);
    free(pokemon);
}

char *retornaNomePokemon(Pokemon *pokemon)
{
    return pokemon->nome;
}

char* retornaNomePokemonLista(ListaPokemon *lista, int posicaoPokemon)
{
    int index = 0;
    ListaPokemon *celulaAtual = lista;

    while(celulaAtual != NULL && index != posicaoPokemon)
    {
        celulaAtual = celulaAtual->prox;
        index++;
    }
    if(celulaAtual != NULL && index == posicaoPokemon)
        return retornaNomePokemon(celulaAtual->pokemon);
    printf("ERRO. Pokemon nao encontrado!!!\n");
    return NULL;
}

Pokemon *retornaPokemon(ListaPokemon* listaPokemon)
{
    return listaPokemon->pokemon;
}

int retornaHpPokemon(Pokemon* pokemon)
{
    return pokemon->hp;
}

void SetterPokemonHp(Pokemon *pokemon, int hp)
{
    pokemon->hp = hp;
}

void inicializaTabelaPokemons()
{
  pokemons['P'] = pikachu;
  pokemons['C'] = charizard;
  pokemons['B'] = blastoise;
  pokemons['V'] = venosauro;
  pokemons['S'] = steelix;
  pokemons['M'] = mew;
}

Pokemon *selecionaPokemon(char code)
{
   return pokemons[code]();
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