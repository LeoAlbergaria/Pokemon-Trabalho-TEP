#include "../include/jogador.h"
#include "../include/pokemon.h" 
#include "../include/menu.h"

struct jogador
{
    int id;
    char *nome;
    int qtdPokemons;
    int qtdPokebolas;
    int vitorias;
    Pokemon *listaPokemon;
};

Jogador *criaJogador(char *nome)
{
    Jogador *jogador = (Jogador*)calloc(1, sizeof(Jogador));

    jogador->id = 1;
    jogador->nome = strdup(nome);
    jogador->qtdPokemons = 0;
    jogador->qtdPokebolas = 3;
    jogador->vitorias = 0;
    jogador->listaPokemon = NULL;

    return jogador;
}

int verificaNome(char *nome)
{
    for(int i = 0; i < strlen(nome); i++)
    {
        if((isalpha(nome[i]) == 0) && (nome[i] != '_'))
        {
            printf("Digite um nome valido!!!\n");
            return 0;
        }
    }
    return 1;
}

// void escolherIniciais(Jogador *jogador, ListaPokemon *listaPokemon)
// {
    
// }

void destroiJogador(Jogador *jogador)
{
    // destroiListaPokemon(jogador->qtdPokemons, jogador->listaPokemon);
    free(jogador->listaPokemon);
    free(jogador->nome);
    free(jogador);
}

char *retornaNome(Jogador *jogador)
{
    return jogador->nome;
}