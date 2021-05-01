#include <stdio.h>
#include <stdlib.h>



typedef struct Lista {
    int numero;
    struct Lista *next;
}Lista;

void criaCelula(struct Lista *celula);
void circulaLista(struct Lista *lista);
void liberaLista(struct Lista *lista);

int main(void)
{
    struct Lista *lista;
    struct Lista *celula_atual;
    int i;

    lista = (struct Lista*) calloc(1, sizeof(struct Lista));

    // primeira posição
    celula_atual = lista;
    celula_atual->numero = 0;
    celula_atual->next = NULL;

    // segunda posição
    criaCelula(celula_atual);
    celula_atual = celula_atual->next;
    celula_atual->numero = 1;
    celula_atual->next = NULL;

    for (i = 2; i < 10; i++)
    {
        criaCelula(celula_atual);
        celula_atual = celula_atual->next;
        celula_atual->numero = i;
        celula_atual->next = NULL;
    }

    circulaLista(lista);

    liberaLista(lista);
    
    circulaLista(lista);

    return 0;
}

void criaCelula(struct Lista *celula)
{
    celula->next = (struct Lista*) calloc(1, sizeof(struct Lista));
}

void circulaLista(struct Lista *lista)
{
    struct Lista *celula_atual;

    celula_atual = lista;
    printf("%d\n", celula_atual->numero); 

    while(celula_atual->next != NULL)
    {
        celula_atual = celula_atual->next;
        printf("%d\n", celula_atual->numero);
    };
}

void liberaLista(struct Lista *lista)
{
    struct Lista *proxima_celula;
    struct Lista *celula_atual;

    celula_atual = lista;

    do
    {
        proxima_celula = celula_atual->next;
        free(celula_atual);
        celula_atual = proxima_celula;
    }while(celula_atual != NULL);

}

