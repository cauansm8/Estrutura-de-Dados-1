#include <stdio.h>
#include "palindromo.h"
#include <string.h>
#include <stdlib.h>

    void inicializar(pilha *p)
    {
        p->topo = NULL;
    }

    void pilhaCheia (pilha *p)
    {

        noP *novoNo = malloc (sizeof(noP));

        if (novoNo == NULL) printf ("Pilha cheia");

        else printf ("Pilha NAO cheia");

    }

    void push (pilha *p, ST *st1)
    {

        while (st1 != NULL)
        {

         if (st1->c != NULL)
         {

         noP *novoTermoNaPilha = malloc (sizeof(noP));

         novoTermoNaPilha->c = st1->c;

         novoTermoNaPilha->prox = p->topo;

         p->topo = novoTermoNaPilha;

         }

         st1 = st1->prox;

        }
    }

    void pop (pilha *p, char *c)
    {
        *c = p->topo->c;

        p->topo = p->topo->prox;


    }

    void imprimirPilha (pilha *p)
    {
        noP *aux = p->topo;

        while (aux != NULL)
        {
            printf ("%c\n", aux->c);
            aux = aux->prox;
        }



    }


    ST* inicializarSt ()
    {
        ST *st = malloc (sizeof(ST));
        st->prox = NULL;
        return st;
    }

    void inserirCaracteres(ST **st, char palavra[])
    {

        ST *aux = *st;

        int i = 0;

        if (strlen(palavra) > 0)
        {
            aux->c = palavra[0];
            i++;
        }

        while (i < strlen(palavra))
        {
            ST *novaLetra = malloc (sizeof(ST));
            novaLetra->c = palavra[i];
            novaLetra->prox = NULL;

            aux->prox = novaLetra;
            aux = aux->prox;
            i++;

        }


    }

    void imprimirPalavra (ST *st)
    {
        while (st != NULL)
        {
         printf ("%c\n", st->c);
         st = st->prox;
        }


    }

    void palindromo (pilha *p, char palavra[])
    {
        noP *aux = p->topo;

        int contador = 0;
        int tamanho = strlen(palavra);

        while (contador < tamanho / 2)
        {
                if (aux->c != palavra[contador]){
                    printf ("NAO EH PALINDROMO");
                    return 0;
                }
                else{
                    aux = aux->prox;
                    contador++;
                }


        }

        printf ("Eh palindromo");



    }



int main ()
{
    ST *st1 = malloc (sizeof(ST));

    pilha *p;

    st1 = inicializarSt();

    char palavra[10];

    strcpy (palavra, "osso");

    palavra[strlen(palavra)] = '\0';

    inserirCaracteres(&st1, palavra);

    push (&p, st1);

    imprimirPilha(&p);

    palindromo(&p, palavra);

    return 0;
}
