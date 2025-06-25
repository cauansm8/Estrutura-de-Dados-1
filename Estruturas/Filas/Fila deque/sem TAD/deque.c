#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int elemento;
    struct no *prox;

} no;

typedef struct fila{

    struct no *inicio;
    struct no *fim;

} fila;

void inicializarFila (fila *f)
{
    f->inicio = NULL;

    f->fim = NULL;

}


void inserirNoInicio (fila *f, int elemento)
{
    no *novoNo = malloc (sizeof(no));
    novoNo->elemento = elemento;
    novoNo->prox = NULL;

    printf ("\nInserindo no inicio");

    if (f->inicio == NULL){
        f->inicio = novoNo;
        f->fim = novoNo;
    }
    else {
        novoNo->prox = f->inicio;
        f->inicio = novoNo;
    }
}

void inserirNoFinal(fila *f, int elemento)
{
    no *novoNo = malloc (sizeof(no));
    novoNo->elemento = elemento;
    novoNo->prox = NULL;

    printf ("\nInserindo no final");

    if (f->inicio == NULL){
        f->inicio = novoNo;
        f->fim = novoNo;
    }
    else {
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
}

void imprimir (fila *f)
{
    no *aux = f->inicio;

    printf ("\n(fila)\n");

    while (aux != NULL){
        printf ("%d   ", aux->elemento);

        aux = aux->prox;
    }

}

int removerDoInicio (fila *f)
{
   if (f->inicio != NULL){
        no *remover = f->inicio;


        if (f->inicio == f->fim){
            f->inicio = NULL;
            f->fim = NULL;
        }

        else {
            f->inicio = f->inicio->prox;
        }
        int removido = remover->elemento;

        free (remover);

        printf ("\nRemovido do inicio");

        return removido;

   }
}

int removerDoFinal (fila *f)
{
   if (f->fim != NULL){
        no *remover = f->fim;

        if (f->inicio == f->fim){
            f->inicio = NULL;
            f->fim = NULL;
        }

        else {
            no *aux = f->inicio;

            while (aux->prox != f->fim)
            {
                aux = aux->prox;
            }

            aux->prox = NULL;

            f->fim = aux;

        }

        int removido = remover->elemento;

        free (remover);

        printf ("\nRemovido do final");

        return removido;
   }
}

void consultar (fila *f)
{
    if (f->inicio != NULL){
        printf ("\nInicio: %d", f->inicio->elemento);
    }

    if (f->fim != NULL){
        printf ("\nFim: %d", f->fim->elemento);
    }
}

void filaVazia (fila *f)
{
    if (f->inicio == NULL){
        printf ("\nFila vazia");
    }

    else {
        printf ("\nFila nao vazia");
    }
}

void filaCheia (fila *f)
{
    no *novoNo = malloc (sizeof(no));

    if (novoNo == NULL){
        printf ("\nFila cheia");
    }

    else {
        printf ("\nFila nao cheia");
    }
}



int main ()
{
    fila f;

    inicializarFila (&f);

    inserirNoInicio(&f, 1);

    inserirNoInicio(&f, 2);

    inserirNoInicio(&f, 3);

    inserirNoFinal (&f, 5);

    imprimir (&f);

    int remover;

    remover = removerDoInicio(&f);

    imprimir (&f);

    remover = removerDoFinal(&f);

    imprimir(&f);

    consultar(&f);

    filaVazia (&f);

    filaCheia (&f);

    return 0;
}
