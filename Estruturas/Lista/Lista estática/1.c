#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct{
    int elem;
    int prox;
} reg;

typedef struct{
    reg Regs[max];
    int disp;
    int prim;
} lista;

    void listaVazia (lista *l){

        int i = 0;
        l->disp = 0;
        l->prim = -1;

        for (i = 0; i < max - 1; i++){
            l->Regs[i].prox = i + 1;// apontando para os proxs
            l->Regs[i].elem = 0;    // lista vazia
        }
        l->Regs[i].prox = -1;       // o ultimo elemento nn tem sucessor
        l->Regs[i].elem = 0;
    }

    void testarListaVazia(lista *l){
        int i = 0;
        int verificador = 1;
        while (i < max){
            if (l->Regs[i].elem != 0){
                verificador = 0;

            }
            i++;
        }
        if (verificador == 0){
            printf ("\nLISTA NAO VAZIA");
        }
        else{
            printf ("\nLISTA VAZIA");
        }
    }

    void imprimir (lista *l){
        for (int i = 0; i < max; i++){
            printf ("%d  ", l->Regs[i].elem);
        }
        printf ("\n");
    }

    void imprimir2 (lista *l){
        for (int i = 0; i < max; i++){
            printf ("%d  ", l->Regs[i].prox);
        }
        printf ("\n");
    }


    void inserir (lista *l, int eleme){ /// nao ordenado
        int i = 0;
        while (l->Regs[i].elem != 0)
        {
            i++;
        }
        l->Regs[i].elem = eleme;
    }

    void remover (lista *l, int pos){
        int i = 0;
        while (i != pos)
        {
            i++;
        }
        l->Regs[i].elem = 0;
    }



int main (){

    lista l;

    listaVazia(&l);

    inserir (&l, 2);

    inserir (&l, 3);

    inserir (&l, 4);

    inserir (&l, 5);
    inserir (&l, 5);
    inserir (&l, 5);
    inserir (&l, 5);
    inserir (&l, 5);
    inserir (&l, 5);
    inserir (&l, 5);
    inserir (&l, 5);

    inserir (&l, 5);
    imprimir (&l);




    testarListaVazia (&l);

    return 0;
}
