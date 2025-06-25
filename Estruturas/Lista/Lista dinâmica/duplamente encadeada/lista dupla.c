#include <stdio.h>
#include <stdlib.h>

struct noD{

    int elem;
    struct noD *ant;
    struct noD *prox;

};

typedef struct noD Lista;

    void inicializar(Lista **l)
    {
        *l = NULL;
    }

    void inserirNoInicio (Lista **l, int elem)
    {

        Lista *novoNo = malloc (sizeof(Lista));


        novoNo->elem = elem;
        novoNo->ant = NULL;


        if (*l == NULL)
        {
            novoNo->prox = NULL;
            *l = novoNo;

        }

        else{

            novoNo->prox = *l;

            *l = novoNo;

        }

    }

    void imprimir(Lista *l)
    {
        while (l != NULL)
        {
            printf ("%d\n", l->elem);
            l = l->prox;
        }
        printf ("\nFIM DO PRINTF\n\n");
    }

    int quantidadeDeValores(Lista *l)
    {
        int contador = 0;
        while (l != NULL)
        {
        contador++;
        l = l->prox;

        }
    return contador;
    }

    int qntDeX(Lista *l, int x)
    {
        int contador = 0;

        while (l != NULL)
        {
            if (l->elem == x)
            {
                contador++;

            }


            l = l->prox;
        }

        return contador;


    }



int main ()
{
    Lista *l;

    inicializar(&l);

    inserirNoInicio(&l, 1);

    inserirNoInicio(&l, 2);

    imprimir(l);

    int qnt = qntDeX(l, 1);

    printf ("\nQUANTIDADE DE X: %d\n", qnt);




    return 0;
}
