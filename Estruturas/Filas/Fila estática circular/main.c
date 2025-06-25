#include <stdio.h>
#include "filas.h"
#include <stdbool.h>

void inicializar (Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
}

bool vazia (Fila *f)
{
    if (f->inicio == f->fim)
    {
        return true;
    }
    else {
        return false;
    }
}

bool cheia (Fila *f)
{
    if ((f->fim + 1) % MAX == f->inicio){
        return true;
    }

    else{
        return false;
    }

}

void inserir(Fila *f, int ele)
{
    if(cheia(f)){
        printf ("\nFILA CHEIA\n");
    }

    else {
        f->elem[f->fim] = ele;
        f->fim = (f->fim + 1) % MAX;
    }
}

void remover(Fila *f, int *ele)
{
    if (vazia (f))
    {
        printf ("\nFILA VAZIA\n");
    }
    else {
        *ele = f->elem[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;

    }
}

void imprimirFila(Fila *f)
{
    int contador = f->inicio;

    if (vazia(f)){
        printf ("\nFILA VAZIA");
    }

    else {
        int i = f->inicio;
        while (i != f->fim)
        {
            printf ("\nPOSICAO %d: %d", contador, f->elem[contador]);
            contador++;
            i = (i + 1) % MAX;
        }
    }


}



int main ()
{
    Fila f;

    inicializar(&f);
    inserir(&f, 1);
    inserir(&f, 2);
    inserir(&f, 3);
    inserir(&f, 4);
    inserir(&f, 5);

    int r;
    remover(&f, &r);
    inserir(&f, 6);



    imprimirFila(&f);


    return 0;
}
