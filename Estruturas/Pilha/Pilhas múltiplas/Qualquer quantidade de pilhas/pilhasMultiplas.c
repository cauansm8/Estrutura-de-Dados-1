#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define NPilhas 2

typedef struct pilha{

    int elementos[MAX];
    int base[NPilhas];
    int topo[NPilhas];
    int quantidadePorPilha[NPilhas];
    int NElemP;

} pilha;


void inicializar (pilha *p)
{
    p->NElemP = MAX / NPilhas;

    for (int i = 0; i < NPilhas; i++){

        p->base[i] = p->NElemP * i;
        p->topo[i] = p->base[i];

        p->quantidadePorPilha[i] = 0;
    }
}

bool pilhaCheia (pilha *p, int pilhaEscolhida)
{
    if (p->quantidadePorPilha[pilhaEscolhida] == p->NElemP){
        return true;
    }
    else {
        return false;
    }
}

void push (pilha *p, int pilhaEscolhida, int elemento)
{
    if (pilhaCheia(p, pilhaEscolhida) == false){

        p->elementos[p->topo[pilhaEscolhida]] = elemento;
        p->topo[pilhaEscolhida]++;
        p->quantidadePorPilha[pilhaEscolhida]++;
    }
    else {
        printf ("\nPilha cheia");
    }
}

void imprimirPilha (pilha *p, int pilhaEscolhida)
{
    int i = p->topo[pilhaEscolhida] - 1;

    printf ("\n(pilha %d)\n", pilhaEscolhida);

    while (i >= p->base[pilhaEscolhida])
    {
        printf ("\n%d", p->elementos[i]);
        i--;
    }

}
bool pilhaVazia (pilha *p, int pilhaEscolhida)
{
    if (p->quantidadePorPilha[pilhaEscolhida] == 0){
        return true;
    }
    else {
        return false;
    }
}


int pop (pilha *p, int pilhaEscolhida)
{
    if (pilhaVazia(p, pilhaEscolhida) == false){
        p->topo[pilhaEscolhida]--;
        int remover = p->elementos[p->topo[pilhaEscolhida]];
        p->elementos[p->topo[pilhaEscolhida]] = -1;

        return remover;
    }
    else {
        printf ("\nPilha vazia");
        return -1;
    }



}



int main ()
{
    pilha p;

    inicializar (&p);

    push(&p, 0, 2);

    push(&p, 0, 3);

    push(&p, 1, 8);

    push(&p, 1, 9);

    imprimirPilha (&p, 0);
    imprimirPilha (&p, 1);

    int remover;

    remover = pop(&p, 1);

    printf ("\nElemento removido: %d", remover);

    imprimirPilha (&p, 0);
    imprimirPilha (&p, 1);

}

