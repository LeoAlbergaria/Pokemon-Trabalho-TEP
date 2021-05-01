#include "../include/menu.h"
#include "../include/jogador.h" 
#include "../include/pokemon.h"

void menuPrincipal()
{
    inicializaTabelaPokemons();
    char opcao[10];
    char nome[20];
    Jogador *jogador = NULL;
    do
    {
        imprimeMenuPrincipal();
        scanf("%s", opcao); 
        switch(atoi(opcao))
        {
        case 1:
            printf("Digite seu nome:\n");
            do
            {
                scanf("%s", nome);     
            }while(verificaNome(nome) != 1);
            if(jogador == NULL)
                 jogador = criaJogador(nome);
            // menuIniciais(jogador);
            break;

        case 2:
            break;

        case 3:
            break;
        }
    }
    while(atoi(opcao) != 3);
    destroiJogador(jogador);
}

void imprimeMenuPrincipal()
{
  printf("1 - Jogar\n2 - Ranking\n3 - Sair\n");
}

void menuIniciais(Jogador *jogador)
{
    ListaPokemon *iniciais = NULL;
    ListaPokemon *celulaAtual;

    iniciais = iniciaLista(selecionarPokemon('p'));

    celulaAtual = iniciais;

    celulaAtual = insere(celulaAtual, selecionarPokemon('c'));
    celulaAtual = insere(celulaAtual, selecionarPokemon('b'));
    celulaAtual = insere(celulaAtual, selecionarPokemon('v'));
    celulaAtual = insere(celulaAtual, selecionarPokemon('s'));
    celulaAtual = insere(celulaAtual, selecionarPokemon('m'));
    ImprimeListaPokemon(iniciais);

    printf("***%s***\n", retornaNome(jogador));
    // escolherIniciais(jogador, iniciais);
}