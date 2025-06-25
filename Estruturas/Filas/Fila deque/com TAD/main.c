#include <stdio.h>
#include "filas.h"
#include <stdbool.h>
#include <math.h>
#include <time.h>

void inicializar (fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

bool cheia(fila *f)
{
    noFila *novoNo = malloc (sizeof(noFila));

    if (novoNo == NULL){
        return true;
    }
    else {
        return false;
    }
}

bool vazia (fila *f)
{
    if (f->inicio == NULL){
        return true;
    }
    else {
        return false;
    }
}

void inserirNoInicio(fila *f)
{
    noFila *novoNo = malloc (sizeof(noFila));
    novoNo->elemento = rand () % 20;
    printf ("\nINICIO: %d", novoNo->elemento);

    novoNo->prox = NULL;
    novoNo->ant = NULL;


    if (vazia(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
    }
    else {
        novoNo->prox = f->inicio;
        f->inicio->ant = novoNo;
        f->inicio = novoNo;

    }
}

void imprimirFila(fila f)
{
    noFila *aux = f.inicio;

    printf ("\nFILA: ");

    while (aux != NULL)
    {
        printf ("%d  ", aux->elemento);
        aux = aux->prox;
    }

    free(aux);

}

void inserirNoFinal (fila *f)
{
    noFila *novoNo = malloc (sizeof(noFila));
    novoNo->elemento =  rand() % 20;
    printf ("\nFINAL: %d", novoNo->elemento);
    novoNo->prox = NULL;

    if (vazia(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
    }
    else {
        f->fim->prox = novoNo;
        novoNo->ant = f->fim;
        f->fim = novoNo;
    }


}

void removerDoInicio(fila *f)
{
   if (!vazia(f)){
    int elemento = f->inicio->elemento;
    f->inicio = f->inicio->prox;
    f->inicio->ant = NULL;
    printf ("\nElem removido do inicio: %d", elemento);


   }
}

void removerDoFinal (fila *f)
{
    if (!vazia(f)){
        int elemento = f->fim->elemento;
        f->fim = f->fim->ant;
        f->fim->prox = NULL;
    printf ("\nElem removido do final: %d", elemento);
    }


}

void consultarElemInicio (fila *f)
{
    if (!vazia(f)){
        printf ("\nElem do inicio: %d", f->inicio->elemento);
    }

}

void consultarElemFim (fila *f)
{
    if (!vazia(f)){
        printf ("\nElem do final: %d", f->fim->elemento);
    }



}



int main ()
{
    srand(time(NULL));

    fila f;

    inicializar(&f);

    inserirNoInicio(&f);
    inserirNoInicio(&f);
    inserirNoInicio(&f);

    inserirNoFinal(&f);

    inserirNoInicio(&f);

    imprimirFila(f);

    removerDoFinal(&f);

    imprimirFila(f);

    consultarElemInicio(&f);

    consultarElemFim(&f);


}
