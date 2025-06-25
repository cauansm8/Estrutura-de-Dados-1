#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int tipo; // 0 - arquivo | 1 - diretorio
    char nome[50];
    int tamanho;

    union {
        struct Node *sublista; // ponteiro para o diretorio
    };

    struct Node *prox; // encadeamento dos arquivos

} Node;

typedef struct listaG{

    struct Node *inicio;
    struct Node *fim;

} lista;

void inicializar (lista *l)
{
    l->inicio = NULL;

}

void inserir(lista *l, Node *novoNo) {
    novoNo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novoNo;
        return;
    }

    Node *aux = l->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    if (aux->tipo == 0){
        aux->prox = novoNo;
    }

    else {

        if (aux->sublista == NULL){
            aux->sublista = novoNo;
        }

        else {
            Node *aux2 = aux->sublista;

            while (aux2 -> prox != NULL){
                aux2 = aux2->prox;
            }

            aux2->prox = novoNo;
        }

    }
}
void imprimir (Node *l)
{
    Node *aux = l;


    while (aux != NULL){

        printf ("Nome: %s  T: %d // ", aux->nome, aux->tamanho);

        if (aux->tipo == 0){
            aux = aux->prox;
        }
        else {
            printf ("[ ");
            imprimir(aux->sublista);
            printf (" ]");

            aux = aux->prox;
        }


    }
}

void buscaDoArquivo (Node *l, int tamanho, char nome[])
{
    Node *aux = l;

    while (aux != NULL){

        if (aux->tipo == 1){
            buscaDoArquivo(aux->sublista, tamanho, nome);

            aux = aux->prox;
        }
        else {

            if (strcmp(aux->nome, nome) == 0 && aux->tamanho >= tamanho){
                printf ("\n\nArquivo encontrado!\n\n");
                break;
            }

            aux = aux->prox;

        }
    }
}

int main ()
{
    lista listaPrincipal;

    inicializar(&listaPrincipal);

    Node *novoArquivo = malloc (sizeof(Node));
    Node *novoArquivo2 = malloc (sizeof(Node));
    Node *novoArquivo3 = malloc (sizeof(Node));
    Node *novoDiretorio = malloc (sizeof(Node));
    Node *novoArquivo4 = malloc (sizeof(Node));


    strcpy (novoArquivo->nome,"arquivo1");
    novoArquivo->tamanho = 10;
    novoArquivo->tipo = 0;
    novoArquivo->sublista = NULL;
    novoArquivo->prox = NULL;

    inserir(&listaPrincipal, novoArquivo);

    strcpy (novoArquivo2->nome,"arquivo2");
    novoArquivo2->tamanho = 12;
    novoArquivo2->tipo = 0;
    novoArquivo2->sublista = NULL;


    inserir(&listaPrincipal, novoArquivo2);

    strcpy (novoDiretorio->nome,"diretorio1");
    novoDiretorio->tamanho = 5;
    novoDiretorio->tipo = 1;
    novoDiretorio->sublista = NULL;
    novoDiretorio->prox = NULL;

    inserir (&listaPrincipal, novoDiretorio);

    strcpy (novoArquivo3->nome,"arquivoDoDiretorio");
    novoArquivo3->tamanho = 2;
    novoArquivo3->tipo = 0;
    novoArquivo3->sublista = NULL;

    inserir (&novoDiretorio, novoArquivo3);

    strcpy (novoArquivo4->nome,"arquivo4");
    novoArquivo4->tamanho = 5;
    novoArquivo4->tipo = 0;
    novoArquivo4->sublista = NULL;
    novoArquivo4->prox = NULL;

    inserir(&novoDiretorio, novoArquivo4);

    imprimir(listaPrincipal.inicio);

    char nome[50];
    strcpy (nome, "arquivo4");

    buscaDoArquivo (listaPrincipal.inicio, 1, nome);

    return 0;
}
