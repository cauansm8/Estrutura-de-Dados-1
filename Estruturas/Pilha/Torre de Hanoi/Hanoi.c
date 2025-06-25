#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Hanoi.h"

void inicializar(pinos *p1, pinos *p2, pinos *p3,
                 disco *d1, disco *d2, disco *d3){

    d1->numero = 1;
    d2->numero = 2;
    d3->numero = 3;
    // na inicializacao do programa todos os discos estao no pino1
    p1->topo = d1;
    d1->baixo = d2;
    d2->baixo = d3;
    d3->baixo = NULL;

    p2->topo = NULL;

    p3->topo = NULL;
}


bool vazia(pinos *p)
{
    if (p->topo == NULL){
        return true;
    }
    else {
        return false;
    }
}


void comecarJogo(pinos *p1, pinos *p2, pinos *p3)
{
    int jogoTerminado = 0;

    while (jogoTerminado != 1)
    {
    int remover;
    printf ("\nDe qual pino vc deseja remover (1, 2 ou 3): ");
    scanf ("%d", &remover);

    int discoEncontrado = 0;
    disco *discoAux;

    switch(remover)
    {
        case 1:
            if (vazia(p1) == false){
                discoAux = p1->topo;
                p1->topo = p1->topo->baixo;
                discoEncontrado = 1;
            }
            else {
                printf ("\nPino vazio, escolha novamente");
            }
        break;

        case 2:
            if (vazia(p2) == false){
                discoAux = p2->topo;
                p2->topo = p2->topo->baixo;
                discoEncontrado = 1;
            }
            else {
                printf ("\nPino vazio, escolha novamente");
            }
        break;

        case 3:
            if (vazia(p3) == false){
                discoAux = p3->topo;
                p3->topo = p3->topo->baixo;
                discoEncontrado = 1;
            }
            else {
                printf ("\nPino vazio, escolha novamente");
            }
        break;

        default:
            printf ("\nNao existe este pino, logo, rodada perdida");
        break;

    }

    if (discoEncontrado == 1){

    discoAux->baixo = NULL; // garante que nao ha discos "grudados"

    int inserir;
    printf ("\nDeseja inserir em qual pino (1, 2 ou 3): ");
    scanf ("%d", &inserir);

    int discoInserido = 0;

    switch (inserir)
    {
        case 1:
            if (vazia(p1) == true){
                p1->topo = discoAux;
                discoInserido = 1;
            }
            else if (discoAux->numero < p1->topo->numero){
                discoAux->baixo = p1->topo;
                p1->topo = discoAux;
                discoInserido = 1;
            }
            else {
                printf ("\nVc esta tentando colocar disco maior acima de algum disco menor - ERRO");
            }
        break;

        case 2:
            if (vazia(p2) == true){
                p2->topo = discoAux;
                discoInserido = 1;
            }
            else if (discoAux->numero < p2->topo->numero){
                discoAux->baixo = p2->topo;
                p2->topo = discoAux;
                discoInserido = 1;
            }
            else {
                printf ("\nVc esta tentando colocar disco maior acima de algum disco menor - ERRO");
            }
        break;

        case 3:
            if (vazia(p3) == true){
                p3->topo = discoAux;
                discoInserido = 1;
            }
            else if (discoAux->numero < p3->topo->numero){
                discoAux->baixo = p3->topo;
                p3->topo = discoAux;
                discoInserido = 1;
            }
            else{
                printf ("\nVc esta tentando colocar disco maior acima de algum disco menor - ERRO");
            }
        break;

        default:
            printf ("\nNao existe esse pino, logo, rodada perdida");
        break;

    }
    // impressao do programa
    disco *discoImpressao;

    printf ("\n\nPino 1:\n");
    discoImpressao = p1->topo;
    int contadorPino1 = 0;

    while (discoImpressao != NULL){
        printf ("disco: %d\n", discoImpressao->numero);
        discoImpressao = discoImpressao->baixo;
        contadorPino1++;
    }

    printf ("\n\nPino 2:\n");
    discoImpressao = p2->topo;
    int contadorPino2 = 0;

    while (discoImpressao != NULL){
        printf ("disco: %d\n", discoImpressao->numero);
        discoImpressao = discoImpressao->baixo;
        contadorPino2++;
    }

    printf ("\n\nPino 3:\n");
    discoImpressao = p3->topo;
    int contadorPino3 = 0;

    while (discoImpressao != NULL){
        printf ("disco: %d\n", discoImpressao->numero);
        discoImpressao = discoImpressao->baixo;
        contadorPino3++;
    }

    if (contadorPino1 == 3 || contadorPino2 == 3 || contadorPino3 == 3){
        printf ("\n\nFIM DO JOGO!!!\n\n");
        jogoTerminado = 1;
    }





    }



    }




}

int main ()
{
    pinos p1;
    pinos p2;
    pinos p3;

    disco d1;
    disco d2;
    disco d3;

    inicializar(&p1, &p2, &p3, &d1, &d2, &d3);

    //imprimir(&p1, &p2, &p3);

    comecarJogo(&p1, &p2, &p3);
}
