#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <time.h>



void inicializar (arvoreB *arb, int elemento)
{
    no *novoNo = malloc (sizeof(no));
    novoNo->elemento = elemento;
    novoNo->dir = NULL;
    novoNo->esq = NULL;

    arb->raiz = novoNo;
}

void inserir (no *raiz, int elemento)
{
    no *novoNo = malloc (sizeof(no));
    novoNo->elemento = elemento;
    novoNo->dir = NULL;
    novoNo->esq = NULL;

    if (novoNo == NULL){
        printf ("\nMemória cheia");
    }

    else {

        if (elemento < raiz->elemento){

            if (raiz->esq != NULL){
                return inserir (raiz->esq, elemento);
            }
            else {
                raiz->esq = novoNo;
            }

        }
        else if (elemento > raiz->elemento){

            if (raiz->dir != NULL){
                return inserir (raiz->dir, elemento);
            }

            else {
                raiz->dir = novoNo;
            }

        }
        else if (elemento == raiz->elemento){
            printf("\n\nElemento ja inserido");
        }
    }
}

void pre_ordem(no *No)
{
    if (No != NULL)
    {
        printf ("\n%d", No->elemento);
        pre_ordem(No->esq);
        pre_ordem(No->dir);
    }
}

void em_ordem (no *No)
{
    if (No != NULL)
    {
        em_ordem (No->esq);
        printf ("\n%d", No->elemento);
        printf ("  fb: %d", fatorDeBalanceamento(No));
        em_ordem (No->dir);
    }
}

void pos_ordem (no *No)
{
    if (No != NULL)
    {
        pos_ordem (No->esq);
        pos_ordem (No->dir);
        printf ("\n%d", No->elemento);
    }
}

no* removerNo(no *raiz, int elemento)
{

    // verifica se o nó não é nulo
    if (raiz == NULL){
        return NULL;
    }

    // procurando pelo nó
    else if (elemento < raiz->elemento){
        raiz->esq = removerNo(raiz->esq, elemento);
    }
    
    // procurando pelo nó
    else if (elemento > raiz->elemento){
        raiz->dir = removerNo(raiz->dir, elemento);
    }


    // ENCONTRAMOS O NÓ A SER REMOVIDO!
    else {

        // 1° CASO: nó com um único filho OU sem filhos
        if (raiz->esq == NULL){

            no *temp = raiz->dir;

            free (raiz);

            return temp;
        }

        if (raiz->dir == NULL){
            
            no *temp = raiz->esq;

            free (raiz);

            return temp;

        }

        // 2° CASO: nó com dois filhos
        else {

            no *sucessor = raiz->dir;

            // anda até encontrar o menor entre os maiores que o elemento
            while (sucessor->esq != NULL){
                sucessor = sucessor->esq;
            }

            // copia o valor
            raiz->elemento = sucessor->elemento;

            // remove o nó que está duplicado -> o comando acima somente faz a cópia do valor!
            raiz->dir = removerNo(raiz->dir, sucessor->elemento);

            
        }
    }  

    // retornando nó removido
    return raiz;
}

no* busca(no *raiz, int elemento)
{
    if (raiz != NULL){
        if (raiz->elemento == elemento){
            printf ("\n\nNo encontrado!");
            return raiz;
        }

        else {

            if (elemento < raiz->elemento){
                return busca (raiz->esq, elemento);
            }
            else {
                return busca (raiz->dir, elemento);
            }

        }
    }

    else {
        printf ("\n\nElemento inexistente");
        return NULL;
    }
}

    // 1 -> eh binaria de busca
    // 0 -> nao eh binaria de busca
int verificando_se_a_arvore_eh_binaria_de_busca (no *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }

    if (raiz->esq != NULL && raiz->elemento < raiz->esq->elemento)
    {
        return 0;
    }

    if (raiz->dir != NULL && raiz->elemento > raiz->dir->elemento)
    {
        return 0;
    }

    return verificando_esquerda (raiz->esq, raiz->elemento) && verificando_direita (raiz->dir, raiz->elemento);
}


int verificando_esquerda(no *raiz, int elemento)
{
    if (raiz == NULL)
    {
        return 1;
    }


    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        return 1;
    }

    if (raiz->esq != NULL)
    {
        if (elemento < raiz->esq->elemento)
        {
            return 0;
        }
    }

    if (raiz->dir != NULL)
    {
        if (elemento < raiz->dir->elemento)
        {
            return 0;
        }
    }

    return verificando_esquerda (raiz->esq, elemento) && verificando_esquerda (raiz->dir, elemento);
}

int verificando_direita(no *raiz, int elemento)
{
    if (raiz == NULL)
    {
        return 1;
    }


    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        return 1;
    }

    if (raiz->esq != NULL)
    {
        if (elemento > raiz->esq->elemento)
        {
            return 0;
        }
    }

    if (raiz->dir != NULL)
    {
        if (elemento > raiz->dir->elemento)
        {
            return 0;
        }
    }

    return verificando_direita (raiz->esq, elemento) && verificando_direita (raiz->dir, elemento);
}

void arvore_nao_binaria (no *raiz, int elemento)    /// somente gerando uma árvore não binária para testar a função de verificação de árvore binária
{
    int escolha = rand () % 2;

    if (escolha == 0) // esquerda
    {
        if (raiz->esq != NULL)
        {
            arvore_nao_binaria(raiz->esq, elemento);
        }
        else
        {
            no *novoNo = malloc (sizeof(no));
            novoNo->elemento = elemento;
            novoNo->dir = NULL;
            novoNo->esq = NULL;

            raiz->esq = novoNo;
        }

    }
    
    else            // direita
    {
        if (raiz->dir != NULL)
        {
            arvore_nao_binaria(raiz->dir, elemento);
        }
        else
        {
            no *novoNo = malloc (sizeof(no));
            novoNo->elemento = elemento;
            novoNo->dir = NULL;
            novoNo->esq = NULL;

            raiz->dir = novoNo;
        }
    }
}

int calcularAltura (no *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int calcularAlturaDireita = calcularAltura (raiz->dir);
    int calcularAlturaEsquerda = calcularAltura (raiz->esq);

    if (calcularAlturaDireita > calcularAlturaEsquerda)
    {
        return calcularAlturaDireita + 1;
    }

    else {
        return calcularAlturaEsquerda + 1;
    }
}

int fatorDeBalanceamento (no *raiz)
{
    return calcularAltura(raiz->dir) - calcularAltura (raiz->esq);
}



int verificar_se_eh_avl (no *raiz)
{
    if (raiz != NULL)
    {
        int fb = fatorDeBalanceamento (raiz);
        
        if (fb < 2 && fb > -2)
        {
            return verificar_se_eh_avl(raiz->esq) && verificar_se_eh_avl(raiz->dir);
        }
        else
        {
            return 0;
        }
    }
    else 
    {
        return 1;
    }
}

int verificar_se_eh_estritamente_binaria (no *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }

    if (raiz->esq == NULL & raiz->dir == NULL) // no folha
    {
        return verificar_se_eh_estritamente_binaria(raiz->esq) && verificar_se_eh_estritamente_binaria (raiz->dir);
    }

    else if (raiz->esq != NULL && raiz->dir != NULL) // no com dois filhos 
    {
        return verificar_se_eh_estritamente_binaria(raiz->esq) && verificar_se_eh_estritamente_binaria (raiz->dir);
    }

    else {
        return 0;
    }

}


int main ()
{

    srand(time(NULL));

    arvoreB arb;

    inicializar(&arb, 3);
    
    arvore_nao_binaria (arb.raiz, 5);

    arvore_nao_binaria (arb.raiz, 0);


    int verif = verificando_se_a_arvore_eh_binaria_de_busca (arb.raiz);

    printf ("\n\n");

    em_ordem(arb.raiz);

    printf ("\n\nVerificacao: %d", verif);

    return 0;

}
