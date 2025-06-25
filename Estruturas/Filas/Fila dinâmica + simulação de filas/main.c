#include <stdio.h>
#include <time.h>
#include "filas.h"
#include <stdlib.h>
#include <stdbool.h>

// tempo para chegar cliente (0 - 4 ) = % 5
   // rand para o caixa
// tempo para sair o cliente (0 - 5) + tempChegada

/*
Em uma agência bancária dos anos 80 existem 4 caixas e uma fila para cada caixa. Implementar um programa para simulação das filas na agência.
Considerar que o tamanho das filas é indeterminado. Nessa agência está sendo realizada uma pesquisa e todos as pessoas ao serem atendidas na
entrada da fila eles preenchem uma ficha fornecendo as seguintes informações: nome e  a operação a ser realizada (depósito ou saque) e informação se é cliente do
banco ou não.
Para o programa use um vetor de 4 posições para representar as Filas, e em cada posição do vetor use uma Fila para representar as pessoas pertencentes a elas.
Para simular a chegada de pessoas nessa fila use o random, que escolhe de forma aleatória as operações que serão realizadas, se chega alguém no banco e em
qual fila ele irá entrar, ou se alguém já foi atendido em algum dos caixas.


*/


/// IMPLEMENTAR:
/// remoção que não seja de forma aleatória -> colocar aquela antiga implementacao de
// if (tempoAtual == tempoSaida) removerCliente

int tempoSimulacao = 500;
int tempoAtual = 0;

void caixas(Fila *f, Fila *f1, Fila *f2, Fila *f3)
{

    while (tempoAtual < tempoSimulacao)
    {
        verifica_chegada(f, f1, f2, f3);

        verifica_saida(f, f1, f2, f3);

        printf ("\nTEMPO: %d", tempoAtual);

        printf ("\nCAIXA 1: ");
        imprimirFila(f);

        printf ("\n");

        printf ("CAIXA 2: ");
        imprimirFila(f1);

        printf ("\n");

        printf ("CAIXA 3: ");
        imprimirFila(f2);

        printf ("\n");

        printf ("CAIXA 4: ");
        imprimirFila(f3);

        printf ("\n\n");



        tempoAtual++;
    }

    printf ("\n\nFIM DA SIMULACAO\n\nQUANTIDADE TOTAL DE CLIENTES ATENDIDOS P/ CAIXA:");
    printf ("\nCAIXA 1: %d", f->qntClientesAtendidos);
    printf ("\nCAIXA 2: %d", f1->qntClientesAtendidos);
    printf ("\nCAIXA 3: %d", f2->qntClientesAtendidos);
    printf ("\nCAIXA 4: %d", f3->qntClientesAtendidos);

    printf ("\n\nTEMPO DE ATENDIMENTO POR CAIXA:");
    printf ("\nCAIXA 1: %d", f->tempo);
    printf ("\nCAIXA 2: %d", f1->tempo);
    printf ("\nCAIXA 3: %d", f2->tempo);
    printf ("\nCAIXA 4: %d", f3->tempo);

    printf ("\n\nTEMPO DE ATENDIMENTO POR CLIENTE");
    printf ("\nCAIXA 1: %.2f", f->tempo / (float) f->qntClientesAtendidos );
    printf ("\nCAIXA 2: %.2f", f1->tempo / (float) f->qntClientesAtendidos);
    printf ("\nCAIXA 3: %.2f", f2->tempo / (float) f->qntClientesAtendidos);
    printf ("\nCAIXA 4: %.2f", f3->tempo / (float) f->qntClientesAtendidos);

    printf ("\n\nTEMPO MEDIO DE ATENDIMENTO:");
    printf (": %.2f", (f->tempo / (float) f->qntClientesAtendidos +
                        f1->tempo / (float) f->qntClientesAtendidos +
                        f2->tempo / (float) f->qntClientesAtendidos +
                            f3->tempo / (float) f->qntClientesAtendidos) / 4.0);

    printf ("\n\nQUANTIDADE TOTAL DE CLIENTES ATENDIDOS");
    printf (": %d", (f->qntClientesAtendidos + f1->qntClientesAtendidos + f2->qntClientesAtendidos
                              + f3->qntClientesAtendidos));

    printf ("\n\nTEMPO DA SIMULACAO: %d\n", tempoAtual);

}

void verifica_chegada(Fila *f, Fila *f1, Fila *f2, Fila *f3)
{
    if (tempoAtual % (rand() % 3 + 1) == 0){     // chega cliente a cada 1 - 3 min

        int caixa = rand() % 4;            // escolha do caixa

        switch (caixa)
        {
            case 0:
            verifica_atendimento(f);
            break;

            case 1:
            verifica_atendimento(f1);
            break;

            case 2:
            verifica_atendimento(f2);
            break;

            case 3:
            verifica_atendimento(f3);
            break;

            default:
            printf ("CAIXA INVALIDO");
            break;

        }
    }



}

void verifica_atendimento(Fila *fila)
{
     int cliente = rand () % 100; // somente representacao do cliente

     inserirNaFila(fila, cliente);

     int tempoSaida = rand() % 8 + 1;

     printf ("\nTEMPO: %d", tempoAtual);
     printf ("\nCLIENTE: %d", cliente);
     printf ("\nVALOR RAND: %d", tempoSaida);

     fila->tempo += tempoSaida;

     fila->tempoClientesSaida[fila->qntClientesAtendidos] = tempoSaida + tempoAtual;

     printf ("\nTEMPO DE SAIDA DA FILA: %d\n", fila->tempoClientesSaida[fila->qntClientesAtendidos]);

     fila->qntClientesAtendidos++;


}

void verifica_saida(Fila *f, Fila *f1, Fila *f2, Fila *f3)
{
    int cliente; // apenas para satisfazer a funcao

    for (int i = 0; i < f->qntClientesAtendidos; i++){

        if (tempoAtual == f->tempoClientesSaida[i])
        {
        removerDaFila(f, &cliente);
        f->contador++;
        }

    }


    for (int i = 0; i < f1->qntClientesAtendidos; i++){

        if (tempoAtual == f1->tempoClientesSaida[i])
        {
        removerDaFila(f1, &cliente);
        f1->contador++;
        }

    }

    for (int i = 0; i < f2->qntClientesAtendidos; i++){

        if (tempoAtual == f2->tempoClientesSaida[i])
        {
        removerDaFila(f2, &cliente);
        f2->contador++;
        }

    }

    for (int i = 0; i < f3->qntClientesAtendidos; i++){

        if (tempoAtual == f3->tempoClientesSaida[i])
        {
        removerDaFila(f3, &cliente);
        f3->contador++;
        }

    }


}


void inicializar (Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->tempo = 0;
    f->tempoChegada = 0;
    f->tempoSaida = 0;
    f->qntClientesAtendidos = 0;
    f->contador = 0;
}

bool vazia(Fila *f)
{
    if (f->inicio == NULL)
    {
        return true;
    }
    else {
        return false;
    }
}




void inserirNaFila (Fila *f, int ele)
{
    NoFila *novoNo = malloc (sizeof(NoFila));
    novoNo->prox = NULL;
    novoNo->elem = ele;

    if (novoNo == NULL){
        printf ("\nFila cheia");
    }

    else
    {
        if (vazia(f)){
            f->inicio = novoNo;
            f->tempoChegada = tempoAtual;
        }
        else {
            f->fim->prox = novoNo;
        }

        f->fim = novoNo;
    }


}

void removerDaFila (Fila *f, int *ele)
{
    if (vazia(f)){}

    else {
        *ele = f->inicio->elem;

        NoFila *tmp = f->inicio;
        f->inicio = f->inicio->prox;

        free(tmp);

        int tempo = tempoAtual - f->tempoChegada;
        f->tempo += tempo;

        if (!vazia(f)){
            f->tempoChegada = tempoAtual;
        }

    }

}

void imprimirFila (Fila *f)
{
    NoFila *aux = f->inicio;

    while (aux != NULL)
    {
        printf ("%d  ", aux->elem);
        aux = aux->prox;
    }

}


int main ()
{
    Fila f[4];

    inicializar(&f[0]);
    inicializar(&f[1]);
    inicializar(&f[2]);
    inicializar(&f[3]);

    srand(time(NULL));
    caixas(&f[0], &f[1], &f[2], &f[3]);




    return 0;
}
