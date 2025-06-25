#include <stdio.h>
#include "listaG.h"
#include <stdbool.h>
#include <math.h>
#include <time.h>

void inicilizar(L *l)
{
    l->prox = NULL;
}

bool vazia(L *l)
{
    if (l == NULL){
        return true;
    }
    else {
        return false;
    }

}

void inserirNaLista(L *l, L *l2)
{
    L *aux = l;


    while (aux->prox != NULL){
    aux = aux->prox;
    }


    if (aux->tipo == 0){
        aux->prox = l2;
    }

    else if (aux->tipo == 1){
        if(aux->Union.sub == NULL){
            aux->Union.sub = l2;
        }

        else {
            L *subaux = aux->Union.sub;

            while (subaux->prox != NULL){
                subaux = subaux->prox;
            }

            subaux->prox = l2;

        }
    }


}

L* criarBloco (int tipo)
{
    L *bloco = malloc (sizeof(L));

    if (tipo == 0){
        bloco->tipo = 0;
        bloco->Union.elemento = rand() % 10;
    }

    else if (tipo == 1){
        bloco->tipo = 1;
        bloco->Union.sub = NULL;
    }

    bloco->prox = NULL;

    return bloco;

}

void imprimirListas(L *l)
{
    if (l != NULL)
    {
        if (l->tipo == 0){
            printf ("\n%d", l->Union.elemento);
        }
        else {
            imprimirListas(l->Union.sub);
        }

        imprimirListas(l->prox);



    }




}




int main ()
{

    srand(time(NULL));

    L *head = criarBloco(0);

    L *bloco1 = criarBloco(1);

    L *bloco2 = criarBloco(0);

    L *subBloco = criarBloco (0);

    L *subBloco2 = criarBloco(0);

    printf ("\nHEAD: "); imprimirListas(head);

    printf ("\nBLOCO1: "); imprimirListas(bloco1); // vazio pois eh do tipo union.sub

    printf ("\nBLOCO2: "); imprimirListas(bloco2);

    printf ("\nSUBBLOCO: "); imprimirListas(subBloco);

    printf ("\nSUBBLOCO2: "); imprimirListas(subBloco2);


    inserirNaLista(head, bloco1);

    inserirNaLista (bloco1, subBloco);

    inserirNaLista (bloco1, subBloco2);

    inserirNaLista(head, bloco2);

    printf("\nHEAD FINAL: "); imprimirListas(head);








}
