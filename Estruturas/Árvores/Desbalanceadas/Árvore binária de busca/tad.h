#include <stdio.h>


typedef struct no {

    int elemento;
    struct no *dir;
    struct no *esq;

}no;

typedef struct arvoreB {

    struct no *raiz;

}arvoreB;

void inicializar (arvoreB *arb, int elemento);

void pre_ordem(no *No);

void em_ordem (no *No);

void pos_ordem (no *No);

void inserir (no *No, int elemento);

no* busca (no *No, int elemento);

no* removerNo(no *No, int elemento);