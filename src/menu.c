#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/menu.h"
#include "../include/jogador.h"

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