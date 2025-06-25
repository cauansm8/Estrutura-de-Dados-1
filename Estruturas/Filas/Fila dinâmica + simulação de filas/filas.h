#include <stdio.h>

#define MAX 100

struct noFila{
    int elem;
    struct noFila *prox;
};

typedef struct noFila NoFila;


struct fila{
    int tempoChegada;
    int tempoSaida;
    int tempo;
    int contador;
    int qntClientesAtendidos;
    int tempoClientesSaida[MAX];
    NoFila *inicio;
    NoFila *fim;
};

typedef struct fila Fila;
