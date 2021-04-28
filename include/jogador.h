#ifndef Jogador_h
#define Jogador_h

typedef struct jogador Jogador;

Jogador *criaJogador(char *nome);

int verificaNome(char *nome);

void destroiJogador(Jogador *jogador);

char *retornaNome(Jogador *jogador);

#endif