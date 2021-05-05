#include "pokemon.h"

struct pokemon
{
    char *nome;
    char *tipo;
    int ataque[3];
    int forca;
    int defesa;
    float hpMax;
    float hp;
    int paralisado;
    int sono;
    int dormindo;
    int queimar;
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

int converteTipo(Pokemon *pokemon)
{
    if(strcmp(pokemon->tipo, "Fogo") == 0) return 0;
    if(strcmp(pokemon->tipo, "Agua") == 0) return 1;
    if(strcmp(pokemon->tipo, "Planta") == 0) return 2;
    if(strcmp(pokemon->tipo, "Eletrico") == 0) return 3;
    if(strcmp(pokemon->tipo, "Psiquico") == 0) return 4;
    if(strcmp(pokemon->tipo, "Metal") == 0) return 5;
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

float retornaHpPokemon(Pokemon* pokemon)
{
    return pokemon->hp;
}

float retornaHpMaxPokemon(Pokemon* pokemon)
{
    return pokemon->hpMax;
}

float retornaPocentagemHp(Pokemon* pokemon)
{
    return (pokemon->hp/pokemon->hpMax)*100.0;
}

int retornaForca(Pokemon* pokemon)
{
    return pokemon->forca;
}

int retornaDefesa(Pokemon* pokemon)
{
    return pokemon->defesa;
}


int retornaNumAtaque(Pokemon* pokemon, int num)
{
    return pokemon->ataque[num];
}

int retornaDomindo(Pokemon* pokemon)
{
    return pokemon->dormindo;
}

int retornaSono(Pokemon* pokemon)
{
    return pokemon->sono;
}

int retornaQueimar(Pokemon* pokemon)
{
    return pokemon->queimar;
}

int retornaParalisado(Pokemon* pokemon)
{
    return pokemon->paralisado;
}

void setterDormindo(Pokemon *pokemon, int turnos)
{
    if(turnos > pokemon->dormindo)
        pokemon->dormindo = turnos;
}

void setterSono(Pokemon *pokemon, int turnos)
{
    if(turnos > pokemon->sono)
        pokemon->sono = turnos;
}

void setterQueimar(Pokemon *pokemon, int turnos)
{
    if(strcmp(pokemon->tipo, "Fogo") != 0)
        if(turnos > pokemon->queimar)
            pokemon->queimar = turnos;
}

void setterParalisado(Pokemon *pokemon, int turnos)
{
    if(turnos > pokemon->paralisado)
        pokemon->paralisado = turnos;
}

void setterPokemonHp(Pokemon *pokemon, float hp)
{
    pokemon->hp = hp;
}

void inicializaTabelaPokemons()
{
  pokemons['P'] = pikachu;
  pokemons['1'] = pikachu;

  pokemons['C'] = charizard;
  pokemons['2'] = charizard;

  pokemons['B'] = blastoise;
  pokemons['3'] = blastoise;

  pokemons['V'] = venosauro;
  pokemons['4'] = venosauro;

  pokemons['S'] = steelix;
  pokemons['5'] = steelix;
  
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
    pikachu->hpMax = 200;
    pikachu->hp = 200;
    pikachu->forca = 110;
    pikachu->defesa = 100;
    pikachu->tipo = strdup("Eletrico");
    pikachu->ataque[0] = 0;
    pikachu->ataque[1] = 1;
    pikachu->ataque[2] = 2;
    pikachu->paralisado = 0;
    pikachu->sono = 0;
    pikachu->dormindo = 0;
    pikachu->queimar = 0;

    return pikachu;
}

Pokemon *charizard()
{
    Pokemon* charizard = (Pokemon*)malloc(sizeof(Pokemon));

    charizard->nome = strdup("Charizard");
    charizard->hpMax = 260;
    charizard->hp = 260;
    charizard->forca = 160;
    charizard->defesa = 150;
    charizard->tipo = strdup("Fogo");
    charizard->ataque[0] = 3;
    charizard->ataque[1] = 4;
    charizard->ataque[2] = 2;
    charizard->paralisado = 0;
    charizard->sono = 0;
    charizard->dormindo = 0;
    charizard->queimar = 0;

    return charizard;
}

Pokemon *blastoise()
{
    Pokemon* blastoise = (Pokemon*)malloc(sizeof(Pokemon));

    blastoise->nome = strdup("Blastoise");
    blastoise->hpMax = 280;
    blastoise->hp = 280;
    blastoise->forca = 180;
    blastoise->defesa = 200;
    blastoise->tipo = strdup("Agua");
    blastoise->ataque[0] = 5;
    blastoise->ataque[1] = 6;
    blastoise->ataque[2] = 2;
    blastoise->paralisado = 0;
    blastoise->sono = 0;
    blastoise->dormindo = 0;
    blastoise->queimar = 0;

    return blastoise;
}

Pokemon *venosauro()
{
    Pokemon* venosauro = (Pokemon*)malloc(sizeof(Pokemon));

    venosauro->nome = strdup("Venosauro");
    venosauro->hpMax = 300;
    venosauro->hp = 300;
    venosauro->forca = 160;
    venosauro->defesa = 160;
    venosauro->tipo = strdup("Planta");
    venosauro->ataque[0] = 7;
    venosauro->ataque[1] = 8;
    venosauro->ataque[2] = 9;
    venosauro->paralisado = 0;
    venosauro->sono = 0;
    venosauro->dormindo = 0;
    venosauro->queimar = 0;

    return venosauro;
}

Pokemon *steelix()
{
    Pokemon* steelix = (Pokemon*)malloc(sizeof(Pokemon));

    steelix->nome = strdup("Steelix");
    steelix->hpMax = 280;
    steelix->hp = 280;
    steelix->forca = 170;
    steelix->defesa = 400;
    steelix->tipo = strdup("Metal");
    steelix->ataque[0] = 10;
    steelix->ataque[1] = 4;
    steelix->ataque[2] = 11;
    steelix->paralisado = 0;
    steelix->sono = 0;
    steelix->dormindo = 0;
    steelix->queimar = 0;

    return steelix;
}

Pokemon *mew()
{
    Pokemon* mew = (Pokemon*)malloc(sizeof(Pokemon));

    mew->nome = strdup("Mew");
    mew->hpMax = 320;
    mew->hp = 320;
    mew->forca = 200;
    mew->defesa = 200;
    mew->tipo = strdup("Psiquico");
    mew->ataque[0] = 12;
    mew->ataque[1] = 2;
    mew->ataque[2] = 13;
    mew->paralisado = 0;
    mew->sono = 0;
    mew->dormindo = 0;
    mew->queimar = 0;

    return mew;
}