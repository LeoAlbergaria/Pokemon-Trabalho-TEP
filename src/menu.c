#include "menu.h"

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
            menuIniciais(jogador);
            menuBatalha(jogador);
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

    iniciais = iniciaLista(selecionaPokemon('P')); 
    celulaAtual = iniciais;

    celulaAtual = inserePokemon(celulaAtual, selecionaPokemon('C'));
    celulaAtual = inserePokemon(celulaAtual, selecionaPokemon('B'));
    celulaAtual = inserePokemon(celulaAtual, selecionaPokemon('V'));
    celulaAtual = inserePokemon(celulaAtual, selecionaPokemon('S'));
    celulaAtual = inserePokemon(celulaAtual, selecionaPokemon('M'));

    escolherIniciais(jogador, iniciais);
}