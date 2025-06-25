#include <stdio.h>

struct NoFila{
    int elemento;

    struct NoFila *prox;
    struct NoFila *ant;

};

typedef struct NoFila noFila;

typedef struct {
    noFila *inicio;
    noFila *fim;
}fila;
