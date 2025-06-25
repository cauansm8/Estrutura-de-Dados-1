#include <stdio.h>
#include <stdlib.h>

#define max 100

struct noPilha{             // nó da pilha
    int c;
    struct noPilha *prox;
};
typedef struct noPilha noPi;


typedef struct {            // descritor da pilha (aponta para o topo)
    struct noPilha *topo;
}Pilha;

    void inicializar (Pilha *pilha)
    {
        pilha -> topo = NULL;
    }

    void pilhaVazia (Pilha *pilha)
    {
        if (pilha->topo == NULL) printf ("\nVazia");

        else printf ("\nNao vazia");

    }

    void pilhaCheia (Pilha *pilha)
    {
        noPi *novoNo = malloc (sizeof(noPi));

        if (novoNo == NULL) printf ("\nPilha cheia");

        else printf ("\nPilha nao cheia");


    }

    void push (Pilha *pilha, int e)
    {
        noPi *novoNo = malloc (sizeof(noPi));

        if (novoNo == NULL){
         printf ("Pilha cheia");
         return;
        }

        novoNo->c = e;              // cria novoNo
        novoNo->prox = pilha->topo; // insere no inicio da lista
        pilha->topo = novoNo;       // declara como topo

        printf ("\nPUSH\n");
    }

    void pop (Pilha *pilha, int *ele)
    {
        if (pilha->topo == NULL)
        {
            printf("Pilha vazia\n");
            return;
        }


        *ele = pilha->topo->c;          // arquivando valores
        pilha->topo = pilha->topo->prox;// retornando uma casa do topo


        printf ("\nPOP\n");
    }

    void imprimir(Pilha *pilha)
    {
        noPi *aux = pilha->topo;

        while (aux != NULL)
        {
            printf ("\n%d\n", aux->c);
            aux = aux -> prox;

        }

    }

    void binNaPilha(Pilha *p, int x, int *ops)
    {

    while (x >= 1)
    {
        int y = x % 2;

        push (p, y);

        x = x / 2;

        (*ops)++;

        if (x == 2)
        {
            push (p, 2%2); // manda o resto para a pilha
            push (p, 2/2); // manda o resultado da divisao (nesse caso sempre eh 1)
            (*ops)++;
            break;
        }

        if (x == 1)
        {
            push (p, 1);
            break;
        }
    }
    }

    void arquivarBin(Pilha *pilha, int *leitor)
    {
        int i = 0;


        while (pilha->topo != NULL)
        {
            pop (pilha, &leitor[i]);

            i++;

        }




    }


/// REFAZER -> para alguns valores esta dando erro



int main ()
{
    int x = 10;

    Pilha p;

    inicializar(&p);

    int ops = 0; // conta quantas operacoes foram feitas (eh necessario para definir o loop de printf)

    binNaPilha (&p, x, &ops);

    int bin[max];

    arquivarBin(&p, bin);

    for(int i = 0; i <= ops; i++)
    {
        printf ("%d\n", bin[i]);
    }



    return 0;
}
