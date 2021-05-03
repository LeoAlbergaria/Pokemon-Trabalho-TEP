#include "batalha.h"

void menuBatalha(Jogador *jogador)
{
    int turnoJogador = 1, opcao;
    Pokemon *pokemonInimigo = selecionaPokemon('C');
    Pokemon *pokemonAtual = retornaListaJogador(jogador);
    system("clear");
    printf("Um %s selvagem apareceu!!!\n", retornaNomePokemon(pokemonInimigo));
    while(pokemonAtual != NULL)
    {
        while(retornaHpPokemon(pokemonAtual) > 0 && retornaHpPokemon(pokemonInimigo) > 0)
        {
            printf("%s - %d\n", retornaNomePokemon(pokemonInimigo), retornaHpPokemon(pokemonInimigo));
            printf("%s - %d\n", retornaNomePokemon(pokemonAtual), retornaHpPokemon(pokemonAtual));
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
                        break;

                    case 2:
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
                SetterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) - 100);
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
            pokemonInimigo = selecionaPokemon('P');
            SetterQtdVitoria(jogador);
            SetterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) + 10);
        }
    }
    destroiPokemon(pokemonInimigo);
    printf("GAME OVER!!! Voce fez %d pontos\n", retornaVitorias(jogador));
}

void imprimeMenuOpcoes(Jogador *jogador)
{
    printf("1- Ataque 1\n2- Ataque 1\n3- Ataque3\n4- Pokebolas (%d disponiveis)\n5- Fugir\n", retornaPokebolas(jogador));
}