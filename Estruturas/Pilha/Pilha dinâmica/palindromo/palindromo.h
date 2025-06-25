#include <stdio.h>

struct noPilha{
    int c;
    struct noPilha *prox;
};

typedef struct noPilha noP;

struct Pilha{
    struct noPilha *topo;
};

typedef struct Pilha pilha;

typedef struct strdim{
    char c;
    struct strdim *prox;
}ST;
