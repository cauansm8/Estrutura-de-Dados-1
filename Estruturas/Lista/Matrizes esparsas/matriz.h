#include <stdio.h>

#define M 5     // linha
#define N 5     // coluna

struct no{

    int numero;
    int linha;
    int coluna;

    struct no *direita;
    struct no *baixo;
};

typedef struct no No;


struct matriz{
    struct no *vLin[M];
    struct no *vCol[N];
};

typedef struct matriz Matriz;
