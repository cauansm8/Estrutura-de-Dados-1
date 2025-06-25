#include <stdio.h>



struct lista{
    int tipo;

    union {
        int elemento;
        struct lista *sub;
    } Union;

    struct lista *prox;
};


typedef struct lista L;
