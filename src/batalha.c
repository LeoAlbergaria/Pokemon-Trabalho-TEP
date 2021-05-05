#include "batalha.h"

void menuBatalha(Jogador *jogador)
{
    inicializaTabelaAtaques();
    int turnoJogador = 1, opcao;

    int chanceMew = 0, chancePokebola;

    Pokemon *pokemonInimigo = selecionaPokemon(numeroAleatorio(5) + 48);
    Pokemon *pokemonAtual = retornaListaJogador(jogador);

    system("clear");
    printf("Um %s selvagem apareceu!!!\n\n", retornaNomePokemon(pokemonInimigo));
    while(pokemonAtual != NULL)
    {
        while(retornaHpPokemon(pokemonAtual) > 0 && retornaHpPokemon(pokemonInimigo) > 0)
        {
            printf("%s - %d  HP\n", retornaNomePokemon(pokemonInimigo), retornaHpPokemon(pokemonInimigo));
            printf("%s - %d  HP\n\n", retornaNomePokemon(pokemonAtual), retornaHpPokemon(pokemonAtual));
            if(turnoJogador)
            {
                imprimeMenuOpcoes(jogador);
                do
                {
                    scanf("%d", &opcao);
                } while(opcao < 1 || opcao > 5);
                
                switch(opcao)
                {
                    case 1:
                        // SetterPokemonHp(pokemonInimigo, retornaHpPokemon(pokemonInimigo) - 100);
                        break;

                    case 2:
                        selecionaAtaque(1, pokemonAtual, pokemonInimigo);
                        break;

                    case 3:
                        break;

                    case 4:
                        break;

                    case 5:
                        break;
                }
                turnoJogador = 0;
            }
            else
            {
                opcao = numeroAleatorio(3);
                // SetterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) - 50);
                turnoJogador = 1;
            }
            system("clear");
        }
        if(retornaHpPokemon(pokemonAtual) <= 0)
        {
            SetterQtdPokemon(jogador, -1);
            if(retornaQtdPokemons(jogador) != 0)
            {
                removePokemonListaJogador(jogador);
                pokemonAtual = retornaListaJogador(jogador);
            }
            else    
                break;
        }
        else
        {
            destroiPokemon(pokemonInimigo);
            if(probabilidade(chanceMew/128))
            {
                pokemonInimigo = selecionaPokemon('M');
                chanceMew = 0;
            }
            else
                pokemonInimigo = selecionaPokemon(numeroAleatorio(5) + 48);
            SetterQtdVitoria(jogador);
            SetterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) + 10);
            chanceMew++;
        }
    }
    destroiPokemon(pokemonInimigo);
    printf("GAME OVER!!! Voce fez %d pontos\n", retornaVitorias(jogador));
}

void imprimeMenuOpcoes(Jogador *jogador)
{
    printf("1- Ataque 1\n2- Ataque 2\n3- Ataque 3\n4- Pokebolas (%d disponiveis)\n5- Fugir\n", retornaQtdPokebolas(jogador));
}

int numeroAleatorio(int randMax)
{
    int aleatorio =  rand() % randMax + 1;
    return aleatorio;
}

int probabilidade(float probabilidade)
{
    float aleatorio = (float)rand()/(float)(RAND_MAX);
    if(aleatorio <= probabilidade)
        return 1;
    else
        return 0;
}