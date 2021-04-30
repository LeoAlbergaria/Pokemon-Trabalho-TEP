#include "../include/menu.h"

void menuPrincipal()
{
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
            menuIniciais();
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

void menuIniciais()
{
    ListaPokemon *iniciais = NULL;

    iniciais = Insere(iniciais, pikachu());
    iniciais = Insere(iniciais, charizard());
    iniciais = Insere(iniciais, blastoise());
    iniciais = Insere(iniciais, venosauro());
    iniciais = Insere(iniciais, steelix());
    iniciais = Insere(iniciais, mew());
    ImprimeListaPokemon(iniciais);
}