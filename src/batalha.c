#include "batalha.h"

void menuBatalha(Jogador *jogador)
{
    inicializaTabelaAtaques();
    int turnoJogador = 1;

    int chanceMew = 0, chancePokebola = 0;

    Pokemon *pokemonInimigo = selecionaPokemon(numeroAleatorio(5) + 48);
    Pokemon *pokemonAtual = retornaListaJogador(jogador);

    printf("Um %s selvagem apareceu!!!\n\n", retornaNomePokemon(pokemonInimigo));
    while(pokemonAtual != NULL)
    {
        while(retornaHpPokemon(pokemonAtual) > 0 && retornaHpPokemon(pokemonInimigo) > 0)
        {
            printf("%s - %.1f%% HP", retornaNomePokemon(pokemonInimigo), retornaPocentagemHp(pokemonInimigo));
            imprimeEfeitosPokemon(pokemonInimigo);
            printf("%s - %.1f%% HP", retornaNomePokemon(pokemonAtual), retornaPocentagemHp(pokemonAtual));
            imprimeEfeitosPokemon(pokemonAtual);
            printf("\n");
            if(turnoJogador)
            {
                if(retornaCavar(pokemonAtual) == 1)
                {
                    selecionaAtaque(retornaNumAtaque(pokemonAtual, 2), pokemonAtual, pokemonInimigo);
                }
                else
                {
                    if(verificaEfeitos(pokemonAtual))
                    {
                        imprimeMenuOpcoes(jogador, pokemonAtual);
                        turnoAtual(jogador, pokemonAtual, pokemonInimigo);
                    }
                }
                if(retornaQueimar(pokemonAtual))
                    setterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) - (retornaHpMaxPokemon(pokemonAtual)/16));
                retiraEfeitosPokemon(pokemonAtual);

                turnoJogador = 0;
            }
            else
            {
                if(retornaCavar(pokemonInimigo) == 1)
                {
                    selecionaAtaque(retornaNumAtaque(pokemonInimigo, 11), pokemonInimigo, pokemonAtual);
                }
                else
                {
                    if(verificaEfeitos(pokemonInimigo))
                    {
                        turnoInimigo(jogador, pokemonInimigo, pokemonAtual);
                    }   
                }
                if(retornaQueimar(pokemonAtual))
                    setterPokemonHp(pokemonAtual, retornaHpPokemon(pokemonAtual) - (retornaHpMaxPokemon(pokemonAtual)/16));
                retiraEfeitosPokemon(pokemonInimigo);

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

void turnoAtual(Jogador *jogador, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int opcao;
    do
    {
        scanf("%d", &opcao);
    } while(opcao < 1 || opcao > 5);
    
    switch(opcao)
    {
        case 1:
            selecionaAtaque(retornaNumAtaque(pokemonAtacante, 0), pokemonAtacante, pokemonDefensor);
            break;

        case 2:
            selecionaAtaque(retornaNumAtaque(pokemonAtacante, 1), pokemonAtacante, pokemonDefensor);
            break;

        case 3:
            selecionaAtaque(retornaNumAtaque(pokemonAtacante, 2), pokemonAtacante, pokemonDefensor);
            break;

        case 4:
            break;

        case 5:
            break;
    }
}

void turnoInimigo(Jogador *jogador, Pokemon *pokemonAtacante, Pokemon *pokemonDefensor)
{
    int opcao;
    opcao = numeroAleatorio(3);
    switch(opcao)
    {
        case 1:
            selecionaAtaque(retornaNumAtaque(pokemonAtacante, 0), pokemonAtacante, pokemonDefensor);
            break;

        case 2:
            selecionaAtaque(retornaNumAtaque(pokemonAtacante, 1), pokemonAtacante, pokemonDefensor);
            break;

        case 3:
            selecionaAtaque(retornaNumAtaque(pokemonAtacante, 2), pokemonAtacante, pokemonDefensor);
            break;
    }
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