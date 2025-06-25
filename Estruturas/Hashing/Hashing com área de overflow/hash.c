#include <stdio.h>
#define TAM 7
#define TAMMAX 11

typedef struct reg
{
    int elemento;
    int prox;

}reg;

typedef struct tabela
{
    reg Regs[TAMMAX];
    int primeiraColisao;

} tabela;

void inicializar (tabela *t)
{
    for (int i = 0; i < TAMMAX; i++)
    {
        t->Regs[i].elemento = -1;
        t->Regs[i].prox = -1;
    }



}

int hash (int chave)
{
    return chave % TAM;

}

void imprimir (tabela *t)
{
    printf ("\n(tabela)\n");

    for (int i = 0; i < TAMMAX; i++)
    {
        printf ("\nI: %d // Numero: %d // Prox: %d",i , t->Regs[i].elemento, t->Regs[i].prox);

    }
    printf ("\n");

}

void inserir (tabela *t, int elemento)
{
    int indice = hash(elemento);

    printf ("\nNumero: %d // Indice que tentara inserir: %d", elemento, indice);

    if (t->Regs[indice].elemento == -1){
        t->Regs[indice].elemento = elemento;
    }

    else { // tratamento da colisao

        if (t->primeiraColisao < TAMMAX){

            int posicaoAnterior = indice;

            reg Aux = t->Regs[indice];

            while (Aux.prox != -1)
            {
                posicaoAnterior = Aux.prox;

                Aux = t->Regs[Aux.prox];
            }

            t->Regs[posicaoAnterior].prox = t->primeiraColisao;

            t->Regs[t->primeiraColisao].elemento = elemento;
            t->Regs[t->primeiraColisao].prox = -1;

            t->primeiraColisao++;
            }
        else {
            printf ("\nArea de overflow cheia -> conteudo perdido");
        }

        }



}






int main ()
{
    tabela t;

    t.primeiraColisao = 7;

    inicializar(&t);

    imprimir (&t);

    inserir (&t, 501);

    imprimir (&t);

    inserir (&t, 1);

    imprimir (&t);

    inserir (&t, 11);

    imprimir (&t);

    inserir (&t, 54);

    imprimir (&t);

    inserir (&t, 23);

    imprimir (&t);

    inserir (&t, 109);

    imprimir (&t);






    return 0;
}
