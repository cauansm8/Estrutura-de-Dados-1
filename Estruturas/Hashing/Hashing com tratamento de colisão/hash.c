#include <stdio.h>
#include <stdlib.h>
#define TAM 11

int hash (int chave)
{
    return (chave % TAM);
}
typedef struct listaColisao{

    int elemento;
    struct listaColisao *prox;
    struct listaColisao *ant;

} listaColisao;


typedef struct listaH{

    listaColisao *elementos[TAM];

} listaH;

void inicializar (listaH *l)
{
    for (int i = 0; i < TAM; i++)
    {
        l->elementos[i] = NULL;
    }


}

void inserir (listaH *l, int chave)
{
    int indice = hash (chave);

    listaColisao *novoNo = malloc(sizeof(listaColisao));
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    novoNo->elemento = chave;

    if (l->elementos[indice] == NULL){
        l->elementos[indice] = novoNo;
    }
    else {

        if (chave < l->elementos[indice]->elemento){

            novoNo->prox = l->elementos[indice];
            l->elementos[indice]->ant = novoNo;

            l->elementos[indice] = novoNo;
        }
        else {

            listaColisao *anterior;
            listaColisao *posterior = l->elementos[indice]; // primeiro

            while (posterior != NULL && chave >= posterior->elemento)
            {
                anterior = posterior;

                posterior = posterior->prox;
            }

                anterior->prox = novoNo;
                novoNo->ant = anterior;

                if (posterior != NULL){

                    novoNo->prox = posterior;
                    posterior->ant = novoNo;
                }


                else {
                    novoNo->prox = NULL;
                }
        }
    }
}

void imprimir (listaH *l)
{
    for (int i = 0; i < TAM; i++)
    {
        if (l->elementos[i] != NULL){

            printf ("\n(posicao %d)\n", i);

            listaColisao *aux = l->elementos[i];

            while (aux != NULL)
            {
                printf ("%d   ", aux->elemento);

                aux = aux->prox;
            }
        }
    }
}


void buscarDeElemento (listaH *l, int chave)
{
    int indice = hash (chave);

    if (l->elementos[indice]->elemento == chave){
        printf ("\nNumero encontrado!");
    }
    else {

        if (l->elementos[indice] != NULL){

            listaColisao *aux = l->elementos[indice];
            int encontrado = 0;

            while (aux != NULL)
            {
                if (aux->elemento == chave){
                    printf ("\nNumero encontrado");
                    encontrado = 1;
                    break;
                }
                else {
                    aux = aux->prox;
                }
            }

            if (encontrado == 0){
                printf ("\nNumero nao encontrado");
            }
        }
        else {
            printf ("\nNumero nao encontrado");
        }
    }
}

void remover (listaH *l, int chave)
{
    listaColisao *remover = NULL;

    int indice = hash(chave);

    if (l->elementos[indice]->elemento == chave){
        remover = l->elementos[indice];
        l->elementos[indice] = remover->prox;
        l->elementos[indice]->ant = NULL;

        free (remover);

        printf ("\nNumero removido");
    }
    else {

        if (l->elementos[indice] != NULL){

            listaColisao *anterior;
            listaColisao *posterior = l->elementos[indice];

            while (posterior != NULL && posterior->elemento != chave)
            {
                anterior = posterior;

                posterior = posterior->prox;

            }

            if (posterior->prox != NULL && posterior->elemento == chave){
                remover = posterior;

                posterior = posterior->prox;

                anterior->prox = posterior;
                posterior->ant = anterior;

                free (remover);

                printf ("\nNumero removido");
            }

            else if (posterior->prox == NULL && posterior->elemento == chave){
                remover = posterior;

                anterior->prox = NULL;

                free (remover);
            }


            else {
                printf ("\nNumero nao encontrado");
            }


        }
        else {
            printf ("\nNumero nao encontrado");
        }





    }

}




int main ()
{
    listaH l;

    inicializar(&l);

    inserir (&l, 0);

    inserir (&l, 1);

    inserir (&l, 2);

    inserir (&l, 3);

    inserir (&l, 4);

    inserir (&l, 5);

    inserir (&l, 17);

    inserir (&l, 6);

    inserir (&l, 7);

    inserir (&l, 8);

    inserir (&l, 9);

    inserir (&l, 10);

    inserir (&l, 11);

    inserir (&l, 12);

    inserir (&l, 11);

    inserir (&l, 28);

    imprimir (&l);

    remover(&l, 17);

    imprimir (&l);


    return 0;
}
