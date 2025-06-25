#include <stdio.h>
#include "pilhaMul.h"
#include <time.h>
#include <math.h>

void inicializarPilhaMul(pilhaM *p)
{
    p->base[0] = 0;
    p->topo[0] = -1;

    p->base[1] = 9;
    p->topo[1] = 10;
}

void inserirNaPilhaMul(pilhaM *p, int pilhaEspecifica)
{
    if (pilhaEspecifica == 0 && (p->topo[0]  != TAM/2 - 1)){
        p->topo[0]++;
        int elemento = rand () % 20;
        p->vetPilha[p->topo[0]] = elemento;
        printf ("\nElem inserido na pilha %d: %d", pilhaEspecifica+1, elemento);

    }
    else if (pilhaEspecifica == 0){
        printf ("\nPILHA CHEIA");
    }


    if (pilhaEspecifica == 1 && (p->topo[1]  != TAM/2)){
        p->topo[1]--;
        int elemento = rand () % 20;
        p->vetPilha[p->topo[1]] = elemento;
        printf ("\nElem inserido na pilha %d: %d", pilhaEspecifica+1, elemento);
    }
    else if (pilhaEspecifica == 1){
        printf ("\nPILHA CHEIA");
    }

}

void imprimirPilhaMulti(pilhaM *p)
{
    printf ("\n\nPilha1: ");

    for (int i = p->topo[0]; i > p->base[0] - 1; i--){
        printf ("%d    ", p->vetPilha[i]);
    }

    printf ("\n\nPilha2: ");

    for (int i = p->topo[1]; i < p->base[1] + 1; i++){
        printf ("%d    ", p->vetPilha[i]);
    }

}

void removerDaPilhaMul(pilhaM *p, int pilhaEspecifica)
{
    if (pilhaEspecifica == 0 && p->topo[0] != p->base[0] - 1){
        printf ("\nRemovendo elem da pilha %d: %d", pilhaEspecifica+1, p->vetPilha[p->topo[0]]);
        p->topo[0]--;
    }

    else if (pilhaEspecifica == 0){
        printf ("\nPILHA VAZIA(IMPOSSIVEL REMOVER DA LISTA 1)");
    }

    if (pilhaEspecifica == 1 && p->topo[1] != p->base[1] + 1){
        printf ("\nRemovendo elem da pilha %d: %d", pilhaEspecifica+1, p->vetPilha[p->topo[1]]);
        p->topo[1]++;
    }

    else if (pilhaEspecifica == 1){
        printf ("\nPILHA VAZIA(IMPOSSIVEL REMOVER DA LISTA 2)");
    }
}


void pilhaVazia(pilhaM *p)
{
    if (p->topo[0] == p->base[0] - 1){
        printf ("\nPILHA 1 VAZIA");
    }
    else {
        printf ("\nPILHA 1 NAO VAZIA");
    }


    if (p->topo[1] == p->base[1] + 1){
        printf ("\nPILHA 2 VAZIA");
    }

    else {
        printf ("\nPILHA 2 NAO VAZIA");
    }


}

void pilhaCheia(pilhaM *p)
{
    if (p->topo[0] == TAM/2 - 1){
        printf ("\nPILHA 1 CHEIA");
    }
    else {
        printf ("\nPILHA 1 NAO CHEIA");
    }

    if (p->topo[1] == TAM / 2){
        printf ("\nPILHA 2 CHEIA");
    }
    else {
        printf ("\nPILHA 2 NAO CHEIA");
    }



}


int main ()
{
    srand(time(NULL));

    pilhaM p;

    inicializarPilhaMul(&p);

    inserirNaPilhaMul(&p, 0);
    inserirNaPilhaMul(&p, 0);
    inserirNaPilhaMul(&p, 0);
    inserirNaPilhaMul(&p, 0);
    inserirNaPilhaMul(&p, 0);


    inserirNaPilhaMul(&p, 1);
    inserirNaPilhaMul(&p, 1);
    inserirNaPilhaMul(&p, 1);
    inserirNaPilhaMul(&p, 1);
    inserirNaPilhaMul(&p, 1);

    imprimirPilhaMulti(&p);
    pilhaCheia(&p);
    pilhaVazia(&p);

    removerDaPilhaMul(&p, 0);
    removerDaPilhaMul(&p, 0);
    removerDaPilhaMul(&p, 0);
    removerDaPilhaMul(&p, 0);
    removerDaPilhaMul(&p, 0);

    removerDaPilhaMul(&p, 1);
    removerDaPilhaMul(&p, 1);
    removerDaPilhaMul(&p, 1);
    removerDaPilhaMul(&p, 1);
    removerDaPilhaMul(&p, 1);

    pilhaCheia(&p);
    pilhaVazia(&p);

    imprimirPilhaMulti(&p);

    return 0;
}
