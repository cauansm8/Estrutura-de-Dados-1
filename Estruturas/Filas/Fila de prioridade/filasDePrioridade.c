#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int elemento; // representa o "cliente"
    int prioridade; // prioridade do "cliente"
    struct no *prox;

} no;



typedef struct fila {

    struct no *inicio;
    struct no *fim;
    int quantidade;

} fila;


void inicializar (fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;

    f->quantidade = 0;

}

void inserir (fila *f, int elemento, int prioridade)
{
    no *novoNo = malloc (sizeof(no));

    if (novoNo == NULL){
        printf ("\nFila cheia");
    }

    novoNo->elemento = elemento;
    novoNo->prioridade = prioridade;
    novoNo->prox = NULL;

    if (f->inicio == NULL){ // insercao para fila vazia
        f->inicio = novoNo;
        f->fim = novoNo;
    }

    else if (novoNo->prioridade < f->inicio->prioridade){
        novoNo->prox = f->inicio;
        f->inicio = novoNo;
    }

    else {

        no *anterior;
        no *posterior = f->inicio;

        while (posterior != NULL && novoNo->prioridade >= posterior->prioridade) // anda ate posterior ser nulo ou a prioridade ser menor
        {
            anterior = posterior;

            posterior = posterior->prox;
        }

        anterior->prox = novoNo;
        novoNo->prox = posterior;


        if (posterior == NULL){     // se o posterior for nulo -> fim da fila -> o prox do ant é igual ao novo "cliente"
            f->fim = novoNo;
        }



    }



    f->quantidade++;
}

void imprimirFila (fila *f)
{
    no *aux = f->inicio;

    printf ("\n(fila)\n");

    while (aux != NULL)
    {
        printf ("%d    ", aux->elemento);
        aux = aux->prox;
    }
}

int remover (fila *f)
{
    if (f->quantidade == 0){
        printf ("\nFila vazia");

        return -1;
    }
    else {
        no *remover = f->inicio;

        int removido = remover->elemento;

        f->inicio = f->inicio->prox;

        free (remover);

        f->quantidade--;

        return removido;
    }

}

int main ()
{
    fila f;
    inicializar(&f);

    inserir(&f, 1, 1);
    inserir(&f, 9, 1);

    inserir(&f, 3, 0);

    inserir(&f, 2, 2);

    inserir(&f, 8, 4);

    inserir(&f, 7, 3);

    imprimirFila(&f);

    int removido = remover (&f);

    printf ("\nRemovido: %d", removido);

    imprimirFila(&f);

    return 0;
}
