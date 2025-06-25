#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int tempoAtual = 0;

int identificacaoAviao = 1;

int tempoSimulacao = 100;

typedef struct no {

    int id;
    struct no *prox;
    int chegada;
    int saida;

}no;

typedef struct fila {

    struct no *inicio;
    struct no *fim;

} fila;

void inicializar (fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir (fila *f, int chegada, int saida)
{
    no *novoAviao = malloc (sizeof(no));
    novoAviao->id = identificacaoAviao;
    identificacaoAviao++;
    novoAviao->prox = NULL;
    novoAviao->chegada = chegada;
    novoAviao->saida = saida + tempoAtual;

    if (f->inicio == NULL){
        f->inicio = novoAviao;
        f->fim = novoAviao;
    }

    else {
        f->fim->prox = novoAviao;
        f->fim = novoAviao;
    }
}

void remover (fila *f, int tempo)
{
    if (f->inicio == NULL){
        printf ("\nFila vazia");
    }
    else {
        no *remover = f->inicio;

        f->inicio = f->inicio->prox;

        free(remover);

        if (f->inicio != NULL)
        {
            f->inicio->saida = tempoAtual + tempo;
        }

        else {
            f->fim = NULL;
        }
    }
}

void verificar_chegada (fila *decolagem, fila *pouso)
{
    int escolha = rand () % 2;

    if (escolha == 0){ // entra na fila de decolagem

        inserir(decolagem, tempoAtual, 5);

    }
    else {  // entra na fila de pouso

        inserir(pouso, tempoAtual, 10);

    }



}
void imprimirFilas (fila *decolagem, fila *pouso)
{
    printf ("\npouso: ");

    no *aux = pouso->inicio;

    while (aux != NULL){
        printf ("%d   ", aux->id);
        aux = aux->prox;
    }

    aux = decolagem->inicio;

    printf ("\ndecolagem: ");

    while (aux != NULL){
        printf ("%d   ", aux->id);
        aux = aux->prox;
    }

    printf ("\n");

}


void simulacao (fila *decolagem, fila *pouso)
{
    int aparecimentoAviao = rand() % 5 + 1;
    aparecimentoAviao += tempoAtual;


    while (tempoAtual < tempoSimulacao)
    {

      if (tempoAtual == aparecimentoAviao){

        verificar_chegada (decolagem, pouso);

        aparecimentoAviao = rand() % 5 + 1;
        aparecimentoAviao += tempoAtual;
      }


      // verificar pouso
      if (pouso->inicio != NULL && tempoAtual >= pouso->inicio->saida)
      {
          printf ("\nAviao: %d | chegada: %d  | saida: %d | espera: %d", pouso->inicio->id, pouso->inicio->chegada,
                                                pouso->inicio->saida, pouso->inicio->saida - pouso->inicio->chegada);



          remover (pouso, 10);
      }

      // verificar decolagem
      if (decolagem->inicio != NULL && tempoAtual >= decolagem->inicio->saida){

            if (pouso->inicio == NULL){
                printf ("\nAviao: %d | chegada: %d  | saida: %d | espera: %d", decolagem->inicio->id, decolagem->inicio->chegada,
                                                decolagem->inicio->saida, decolagem->inicio->saida - decolagem->inicio->chegada);

                remover (decolagem, 5);
            }

      }

       printf ("\nTempo atual: %d", tempoAtual);
       imprimirFilas(decolagem, pouso);



        tempoAtual++;
    }
}


int main ()
{
    srand (time(NULL));

    fila decolagem;
    fila pouso;

    inicializar(&decolagem);
    inicializar(&pouso);

    simulacao(&decolagem, &pouso);


return 0;
}
