#include <stdio.h>
#include <stdbool.h>
#define MAX 6

typedef struct
{
    int elem[MAX];
    int inicio;
    int fim;
}Fila;

void inicializar (Fila *f);

bool vazia (Fila *f);

bool cheia (Fila *f);

void inserir (Fila *f, int elemento);

void remover (Fila *f, int *ele);
