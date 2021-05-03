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
    ListaPokemon *listaPokemon;
    ListaPokemon *celulaAtual;
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
    jogador->celulaAtual = NULL;

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

void escolherIniciais(Jogador *jogador, ListaPokemon *pokemonsIniciais)
{
    int qtdIniciais = 6, opcao;
    while(jogador->qtdPokemons < 3)
    {
        // system("clear");
        printf("Escolha 1 dos %d pokemons iniciais!\n", qtdIniciais);
        imprimeListaPokemon(pokemonsIniciais);
        do
        {
            scanf("%d", &opcao);
        }
        while (opcao <= 0 && opcao >= qtdIniciais);

        char *nomePokemon = retornaNomePokemonLista(pokemonsIniciais, opcao - 1);
        printf("**%s**\n", nomePokemon);

        if(qtdIniciais == 6)
        {
            jogador->listaPokemon = iniciaLista(selecionaPokemon(nomePokemon[0]));
            jogador->celulaAtual = jogador->listaPokemon;
        }
        else
        {
            jogador->celulaAtual = inserePokemon(jogador->celulaAtual, selecionaPokemon(nomePokemon[0]));
        }
        imprimeListaPokemon(jogador->listaPokemon);
        pokemonsIniciais = removePokemonLista(pokemonsIniciais, opcao-1);
        jogador->qtdPokemons++;
        qtdIniciais--;
    }
    destroiListaPokemon(pokemonsIniciais);
}

void destroiJogador(Jogador *jogador)
{
    destroiListaPokemon(jogador->listaPokemon);
    free(jogador->nome);
    free(jogador);
}

char *retornaNome(Jogador *jogador)
{
    return jogador->nome;
}