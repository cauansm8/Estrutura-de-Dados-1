#include <stdio.h>
#include "pilha.h"
#include <math.h>
#include <time.h>

void inicializar (pilha *p)
{
    p->topo = -1;

}

void push (pilha *p)
{
    if (p->topo < MAX - 1){

    (p->topo)++;

    p->vPilha[p->topo] = rand () % 20;

    }

    else {
        printf ("\nPILHA CHEIA");
    }

}

int pop (pilha *p)
{
   if (p->topo != -1){
        int elemento = p->vPilha[p->topo];
        (p->topo)--;
        return elemento;
   }

   else {
    printf ("\nPILHA VAZIA");
    return;
   }


}

void imprimirPilha (pilha p)
{
    int i = p.topo;

    printf ("\nPILHA: ");

    while (i != -1){
        printf ("%d   ", p.vPilha[i]);
        i--;
    }

    printf ("\n");

}



int main ()
{
    srand(time(NULL));

    pilha p;

    inicializar(&p);

    push(&p);

    push(&p);

    push(&p);

    imprimirPilha(p);






}
