#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int elemento;
    struct no *esq;
    struct no *dir;
}no;

typedef struct avl {
    struct no *raiz;
} avl;


void inicializar (avl *arv, int elemento)
{
    no *novoNo = malloc (sizeof(no));
    novoNo->elemento = elemento;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    arv->raiz = novoNo;
}

no* rotacionarParaEsquerda(no *raiz)
{
    printf("\nRotacao para esquerda em %d", raiz->elemento);

    no *aux = raiz->dir;    

    raiz->dir = aux->esq;

    aux->esq = raiz;

    return aux;
}

no* rotacionarParaDireita (no *raiz)
{
    printf("\nRotacao para direita em %d", raiz->elemento);

    no *aux = raiz->esq;

    raiz->esq = aux->dir;

    aux->dir = raiz;

    return aux;
}


no* inserir (no *raiz, int elemento)
{
    if (elemento < raiz->elemento)
    {
        if (raiz->esq == NULL){
            no *novoNo = malloc(sizeof(no));
            novoNo->elemento = elemento;
            novoNo->esq = NULL;
            novoNo->dir = NULL;

            raiz->esq = novoNo;
        }
        else {
            raiz->esq = inserir (raiz->esq, elemento);
        }
    }
    
    else if (elemento > raiz->elemento)
    {
        if (raiz->dir == NULL){
            no *novoNo = malloc(sizeof(no));
            novoNo->elemento = elemento;
            novoNo->esq = NULL;
            novoNo->dir = NULL;

            raiz->dir = novoNo;
        }
        else {
            raiz->dir = inserir (raiz->dir, elemento);
        }


    }

    int fatorB = fatorDeBalanceamento (raiz);

    if (fatorB <= -2){
        if (fatorDeBalanceamento(raiz->esq) < 0){ // balanceamanto do pai e filho com mesmo sinal
            raiz = rotacionarParaDireita(raiz);
        }
        else {
            raiz->esq = rotacionarParaEsquerda(raiz->esq);
            raiz = rotacionarParaDireita (raiz);
        }
    }

    if (fatorB >= 2){
        if (fatorDeBalanceamento(raiz->dir) > 0){ // balanceamento do pai e filho com mesmo sinal
            raiz = rotacionarParaEsquerda (raiz);
        }
        else {
            raiz->dir = rotacionarParaDireita (raiz->dir);
            raiz = rotacionarParaEsquerda (raiz);
        }
    }

    return raiz;
}

void em_ordem (no *raiz)
{
    if (raiz != NULL){
        
        em_ordem (raiz->esq);
        printf ("\n%d", raiz->elemento);
        em_ordem (raiz->dir);
    }
}


int calcularAltura (no *raiz)
{
    if (raiz == NULL){
        return -1;
    }

    int alturaDaEsquerda = calcularAltura (raiz->esq);
    int alturaDaDireita = calcularAltura (raiz->dir);

        if (alturaDaEsquerda > alturaDaDireita){
            return alturaDaEsquerda+1;
        }

        return alturaDaDireita + 1;
}   

int fatorDeBalanceamento (no *raiz)
{
    return calcularAltura(raiz->dir) - calcularAltura(raiz->esq);
}

no* remover (no *raiz, int elemento)
{
    if (raiz == NULL){
        return NULL;
    }

    if (elemento < raiz->elemento)
    {
        raiz->esq = remover (raiz->esq, elemento);
    }

    else if (elemento > raiz->elemento)
    {
        raiz->dir = remover (raiz->dir, elemento);
    }

    else    // numero encontrado! 
    {
        // 1° caso: no é folha

        if (raiz->esq == NULL){

            no* temp = raiz->dir;

            free (raiz);
            
            return temp;
        }

        if (raiz->dir == NULL)
        {
            no* temp = raiz->esq;

            free (raiz);

            return temp;
        }

        else
        {
            // 2° caso: nó não é folha

            no *sucessor = raiz->dir;

            while (sucessor->esq != NULL)
            {
                sucessor = sucessor->esq;
            }

            raiz->elemento = sucessor->elemento;

            raiz->dir = remover (raiz->dir, sucessor->elemento);

        }

    }

    int fb = fatorDeBalanceamento (raiz);

    if (fb <= -2)
    {
        if (fatorDeBalanceamento(raiz->esq) > 0){
            raiz->esq = rotacionarParaEsquerda (raiz->esq);
        }

        raiz = rotacionarParaDireita(raiz);
    }

    if (fb >= 2)
    {
        if (fatorDeBalanceamento(raiz->dir) < 0)
        {
            raiz->dir = rotacionarParaDireita(raiz->dir);
        }
        
        raiz = rotacionarParaEsquerda (raiz);
    }


    return raiz;
}



int main ()
{
    avl arvore;

    inicializar(&arvore, 7);

    arvore.raiz = inserir (arvore.raiz, 5);

    arvore.raiz = inserir (arvore.raiz, 10);

    arvore.raiz = inserir (arvore.raiz, 4);

    arvore.raiz = inserir (arvore.raiz, 6);

    arvore.raiz = inserir (arvore.raiz, 11);

    arvore.raiz = inserir (arvore.raiz, 3);

    em_ordem (arvore.raiz);
    printf ("\n\n\n");

    arvore.raiz = remover (arvore.raiz, 5);

    em_ordem (arvore.raiz);

    return 0;
}


