#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

    ST* inicializar (){

    ST *st = malloc (sizeof(ST));

    st->prox = NULL;

    return st;


    }


    void imprimir(ST *st){

    while (st != NULL){
        printf ("%c", st->c);
        st = st->prox;
    }
        printf ("\n");

    }

    int contarStringD(ST *st){
    int i = 0;
    while (st != NULL){
        i++;
        st = st->prox;
    }
    return i;

    }

    void inserirCaracter (ST **st, char palavra[]){     /// funcao inserirCaracter
        int tamanho = strlen (palavra);
        int i = 0;

        ST *aux = *st;

        if (tamanho > 0)                                /// o problema que estava dando eh que o primeiro caracter era igual a NULL (em inicializar)
        {                                               /// logo aqui se atribui diretamente o primeiro caracter da palavra
            aux->c = palavra[0];
            i++;
        }



        while (i < tamanho)
        {

            ST * novoC = malloc(sizeof(ST));
            novoC->c = palavra[i];
            novoC->prox = NULL;

            aux->prox = novoC;

            aux = aux->prox;



            i++;
        }
    }



    void copiarPalavra(ST *st1, char palavra[])     /// funcao de copia de palavra
    {

        int i = 0;



        while (st1!= NULL)
        {

            palavra[i] = st1->c;

            st1 = st1->prox;
            i++;

        }




    }

    void concatenar (ST *st1, ST *st2, ST **st3)    /// para concactenar, eu chamei as funcoes de copia de lista duas vezes (as duas primeiras listas)
    {                                               /// concatenei a palavra e passei para a funcao inserirCaracter junto com a lista 3
        char palavra1[20];
        copiarPalavra(st1, palavra1);

        char palavra2[20];
        copiarPalavra(st2, palavra2);


        char palavra3[40];
        strcpy (palavra3, palavra1);
        strcat (palavra3, palavra2);
        palavra3[strlen(palavra3)] = '\0';


        inserirCaracter(st3, palavra3);

    }

    void removerCaracter(ST **st, int qnt, int start)   /// CASO qnt+start > palavra -> nao ha mudanca na lista
    {
        char palavra[20];
        copiarPalavra(*st, palavra);

            /// nao eh nem a primeira nem a ultima letra que serao removidas (letras do "meio")
            if (start >0 && start != strlen(palavra) - 1 && start + qnt <= strlen(palavra))
            {

            int i = 0;
            ST *aux1 = *st;


            /// loop para chegar na posicao
            while (i < start - 1)      /// -1 -> tem que chegar na casa anterior da letra a ser removida!!!
            {
                i++;
                aux1 = aux1->prox;


            }
            int j = 0;
            ST *aux2 = aux1;

            /// loop para pular x(qnt) -> encontra o nó especifico apos as letras que serao removidas
            while (j < qnt + 1)     /// +1 -> por causa do -1 anterior (sem o +1 a ultima letra a ser removida continua)
            {
                aux2 = aux2->prox;
                j++;
            }

            aux1->prox = aux2;      /// atribui a primeira parte da lista->prox = segunda parte da lista
                                    /// apos pular as qnt de letras
            }




                /// remove da primeira letra e as proximas
                else if(start == 0 && qnt >= 1 && qnt <= strlen(palavra) - 1)
                {
                /// quantidade de letras removidas (1 a tamanho-1)

                int j = 0;
                ST *aux2 = *st;


                while (j < qnt)     /// nao precisa do +1 pq a primeira posicao vai ser excluida
                {
                    aux2 = aux2->prox;
                    j++;
                }
                    *st = aux2;     /// apenas atribui para a lista original o encadeamento apos as letras pular as letras
                }





                    /// remove a ultima letra
                    else if(start == strlen(palavra) - 1 && qnt == 1)
                            /// quantidade = 1 (obrigatorio)
                    {

                    int i = 0;
                    ST *aux1 = *st;


                    while (i < start - 1) /// -1 -> tem que chegar na casa anterior da letra a ser removida!!!
                    {
                            i++;
                            aux1 = aux1->prox;
                    }
                    aux1->prox = NULL;    /// atribui NULL para o prox
                    }

    }

    void menorOuMaior(ST *st1, ST *st2)
    {
        int verif = 1;

        while (st1 != NULL && st2 != NULL)
        {

            if (st1->c <= st2->c)
            {
                st1 = st1->prox;

                st2 = st2->prox;
            }

            else{
                verif = 0;
                break;
            }

        }

        if (verif == 1)
        {
            printf ("\nA string1 eh menor que a string2\n");

        }

        if (verif == 0)
        {
            printf ("\nA string1 NAO eh menor que a string2\n");

        }

    }

    void strIguais (ST *st1, ST *st2)
    {
        int verif = 1;

        while (st1 != NULL && st2 != NULL)
        {
            if (st1->c == st2->c){
                verif = 1;

                st1 = st1->prox;
                st2 = st2->prox;

            }


            else {
                verif = 0;
                break;
            }
        }

        if (verif == 1)
        {
            printf ("\nAs strings sao IGUAIS\n");

        }

        if (verif == 0)
        {
            printf ("\nAs strings NAO sao IGUAIS\n");

        }
    }

    void inserirSubString (ST **st1, ST *st2, int pos)
    {
        char palavra[20];
        copiarPalavra(*st1, &palavra);


        /// inserir no inicio
        if (pos == 0)
        {
            ST *aux = st2;


            while (aux -> prox != NULL){    /// andando ate o final da string2
                aux = aux->prox;
            }
            aux -> prox = *st1;             /// alocando o prox da string2 = string1

            *st1 = st2;                     /// passando toda a lista2 para a lista1

        }

        /// inserir no meio
        else if (pos < strlen(palavra))
        {
            int contador = 0;

            ST *aux = *st1;
            ST *aux2 = st2;


            while (contador < pos - 1)  /// andando ate a posicao anterior aquela de entrada da string1
            {
                aux = aux->prox;
                contador++;

            }
            while (aux2 ->prox != NULL) /// andando ate o final da string2
            {
                aux2 = aux2->prox;

            }


            aux2 -> prox = aux -> prox; /// alocando string2->prox = string1->prox

            aux->prox = st2;            /// inserindo a string2 na posicao

        }

        /// inserir no final
        else if (pos == strlen(palavra))
        {
            ST *aux = *st1;

            while (aux->prox != NULL)
            {
                aux = aux->prox;


            }

            aux->prox = st2;

        }
    }


    void buscarSubString(ST *st1, ST *st2, int pos)
    {

    ST *aux = st1;

    while (aux != NULL)
    {

        if (aux->c == st2->c)
        {

        ST *aux3 = st2;

        int verif = 1;

        while (aux3 != NULL && verif != 0 && aux != NULL)
        {
                if (aux->c == aux3->c)
                {
                   aux = aux->prox;
                   aux3 = aux3->prox;
                   verif = 1;

                }
                else{
                    verif = 0;
                }

        }

        if (verif == 1)
        {
            printf ("A str2 esta na str1");
            printf ("\nPosicao: %d\n", pos);
            return;
        }

        }


        else{

            aux = aux->prox;

        }

    pos++;
    }
        free (aux);

        printf ("A str2 nao esta na str1");


    }



int main (){

    ST *head1, *head2, *head3;

    head1 = inicializar();

    char palavra[20];

    strcpy (palavra, "cauan");

    inserirCaracter(&head1, palavra);

    head2 = inicializar();

    char palavra2[20];

    strcpy (palavra2, "aua");

    inserirCaracter(&head2, palavra2);

    buscarSubString(head1, head2, 0);



return 0;
}
