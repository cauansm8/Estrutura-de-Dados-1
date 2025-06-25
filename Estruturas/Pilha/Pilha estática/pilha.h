#include <stdio.h>

#define MAX 3

typedef struct {

    int vPilha[MAX];
    int topo;

} pilha;


void inicializar(pilha *p);

void imprimirPilha (pilha p);

int pop (pilha *p);
