#include "batalha.h"

void menuBatalha(Jogador *jogador)
{
    inicializaTabelaAtaques();
    int turnoJogador = 1, opcao;

    int chanceMew = 0, chancePokebola;

    Pokemon *pokemonInimigo = selecionaPokemon(numeroAleatorio(5) + 48);
    Pokemon *pokemonAtual = retornaListaJogador(jogador);

    printf("Um %s selvagem apareceu!!!\n\n", retornaNomePokemon(pokemonInimigo));
    while(pokemonAtual != NULL)
    {
        while(retornaHpPokemon(pokemonAtual) > 0 && retornaHpPokemon(pokemonInimigo) > 0)
        {
            printf("%s - %.1f%% HP\n", retornaNomePokemon(pokemonInimigo), retornaPocentagemHp(pokemonInimigo));
            printf("%s - %.1f%% HP\n\n", retornaNomePokemon(pokemonAtual), retornaPocentagemHp(pokemonAtual));
            if(turnoJogador)
            {
                imprimeMenuOpcoes(jogador, pokemonAtual);
                do
                {
                    scanf("%d", &opcao);
                } while(opcao < 1 || opcao > 5);
                
                switch(opcao)
                {
                    case 1:
                        selecionaAtaque(retornaNumAtaque(pokemonAtual, 0), pokemonAtual, pokemonInimigo);
                        break;

                    case 2:
                        selecionaAtaque(retornaNumAtaque(pokemonAtual, 1), pokemonAtual, pokemonInimigo);
                        break;

                    case 3:
                        selecionaAtaque(retornaNumAtaque(pokemonAtual, 2), pokemonAtual, pokemonInimigo);
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
                switch(opcao)
                {
                    case 1:
                        selecionaAtaque(retornaNumAtaque(pokemonInimigo, 0), pokemonInimigo, pokemonAtual);
                        break;

                    case 2:
                        selecionaAtaque(retornaNumAtaque(pokemonInimigo, 1), pokemonInimigo, pokemonAtual);
                        break;

                    case 3:
                        selecionaAtaque(retornaNumAtaque(pokemonInimigo, 2), pokemonInimigo, pokemonAtual);
                        break;
                }
                turnoJogador = 1;
            }
        }
        if(retornaHpPokemon(pokemonAtual) <= 0)
        {
            setterQtdPokemon(jogador, -1);
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
            if(probabilidade(chanceMew/128.0))
            {
                pokemonInimigo = selecionaPokemon('M');
                chanceMew = 0;
            }
            else
                pokemonInimigo = selecionaPokemon(numeroAleatorio(5) + 48);
            setterQtdVitoria(jogador);
            setterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) + 10);
            chanceMew++;
        }
    }
    destroiPokemon(pokemonInimigo);
    printf("GAME OVER!!! Voce fez %d pontos\n", retornaVitorias(jogador));
}

void imprimeMenuOpcoes(Jogador *jogador, Pokemon *pokemon)
{
    printf("1- %s\n2- %s\n3- %s\n4- Pokebolas (%d disponiveis)\n5- Fugir\n", retornaNomeAtaque(retornaNumAtaque(pokemon, 0)), retornaNomeAtaque(retornaNumAtaque(pokemon, 1)), retornaNomeAtaque(retornaNumAtaque(pokemon, 2)), retornaQtdPokebolas(jogador));
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