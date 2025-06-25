#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


void inicializar (Matriz *m)
{
    for (int i = 0; i < M; i++){
        m->vLin[i] = NULL;
    }

    for (int i = 0; i < N; i++){
        m->vCol[i] = NULL;
    }

}


void inserirNaMatriz (Matriz *m, int numero, int linha, int coluna)
{

    No *novoElemento = malloc (sizeof(No));

    novoElemento->numero = numero;
    novoElemento->linha = linha;
    novoElemento->coluna = coluna;
    novoElemento->baixo = NULL;
    novoElemento->direita = NULL;

    No *ponteiroColuna, *ponteiroLinha; // ponteiro que aponta para o primeiro termo
                                        // da linha ou da coluna
    ponteiroColuna = m->vCol[coluna];
    ponteiroLinha = m->vLin[linha];

    /// INSERCAO EM LINHA

    if (ponteiroLinha == NULL){         // linha vazia
        m->vLin[linha] = novoElemento;
    }

    else { // insercao na linha (inicio, meio ou fim) -> linha nao vazia

        No *ant = NULL;

        while (ponteiroLinha != NULL && (ponteiroLinha->coluna < coluna))
            // while para encontrar alguma coluna vazia ou ate chegar na coluna que deve ser inserida
            // o novo Nó

        {
            ant = ponteiroLinha;    // guarda o anterior (para insercao no meio!)

            ponteiroLinha = ponteiroLinha->direita; // continua o loop andando pela direita
                                                    // insercao ordenada pela linha

        }

        // se o anterior continua sendo NULL -> significa que sera colocado o elemento antes do primeiro elemento
        // da linha -> ou seja, insercao no inicio


        // anterior != NULL -> insercao no meio ou no fim

            if (ponteiroLinha != NULL)
            {
                if (ponteiroLinha->coluna == coluna){
                    // o while eh quebrado por causa que a coluna do primeiro elemento da linha eh igual a coluna
                    // do novo elemento

                    printf ("\nEspaco ja preenchido na matriz\n");

                }

                /// insercao no anterior ao primeiro elemento da linha -> anterior = NULL
                else if (ant == NULL){ // anterior igual a nulo -> insercao na posicao anterior ao primeiro elemento da linha
                    // como o anterior eh nulo, a insercao sera na posicao anterior ao primeiro elemento da linha
                        // logo a direita do elemento tem que ser colocada o vetorLinha[linha] E o
                            // vetorLinha[linha] igual ao novo elemento

                    novoElemento->direita = m->vLin[linha];
                    m->vLin[linha] = novoElemento;

                }

                /// insercao no meio -> ant != NULL e ant->direita != NULL
                else if (ant != NULL){ // se o ant != NULL -> ha elementos na posicao anterior e posterior ao novo elemento

                    novoElemento->direita = ant->direita;   // acho q da na mesma que novoElemento->direita = ponteiroLinha ****
                                                            // SE DER ERRO, MUDAR ISSO AQUI
                    ant->direita = novoElemento;
                }

            }
                /// insercao no final -> ant != NULL e ponteiroLinha = NULL (andou para a total direita)
            else if (ponteiroLinha == NULL){
                    ant->direita = novoElemento;
            }


    }

    /// INSERCAO EM COLUNA

    if (ponteiroColuna == NULL){       //  ponteiro esta vazio, logo ele aponta
        m->vCol[coluna] = novoElemento; // para o novoElemento
    }

    else {

        No *ant = NULL;

        while (ponteiroColuna != NULL && (ponteiroColuna->linha < linha))   // loop para pegar o anterior da linha de insercao
        {
            ant = ponteiroColuna;
            ponteiroColuna = ponteiroColuna->baixo;
        }

        if (ponteiroColuna != NULL)
        {
            if (ponteiroColuna->linha == linha){    // se o ponteiroColuna parou na posicao da linha do novo elemento -> espaco ocupado
                printf ("\nEspaco ja preenchido na matriz\n");

            }

            else if (ant == NULL){  // se o anterior eh nulo -> insercao no inicio
                novoElemento->baixo = m->vCol[coluna];
                m->vCol[coluna] = novoElemento;
            }

            else if (ant != NULL){  // anterior != NULL -> insercao no meio
                novoElemento->baixo = ant->baixo;
                ant->baixo = novoElemento;
            }

        }

        else if (ponteiroColuna == NULL){   // se o ponteiroColuna chegou no fim da coluna -> insercao no final
            ant->baixo = novoElemento;
        }


    }


}

void imprimirLinha (Matriz *m)
{
    for (int i = 0; i < M; i++) // percorre todas as linhas
    {
        No *aux = m->vLin[i];

        printf ("\nLinha %d: ", i);

        while (aux != NULL)
        {
        printf ("%d    ", aux->numero);
        aux = aux->direita;
        }
    }

            printf("\n\n");
}

void imprimirColuna (Matriz *m)
{
    for (int i = 0; i < M; i++) // percorre todas as colunas
    {
        No *aux = m->vCol[i];

        printf ("\nColuna %d: ", i);

        while (aux != NULL)
        {
        printf ("%d    ", aux->numero);
        aux = aux->baixo;
        }
    }

    printf("\n\n");
}


void remover(Matriz *m, int linha, int coluna)
{
    No *ponteiroLinha = m->vLin[linha];
    No *ponteiroColuna = m->vCol[coluna];

    /// remocao do elemento (linha)

    if (ponteiroLinha == NULL){ // nao ha o que remover se a linha esta vazia
        printf ("\nLinha vazia\n");
    }

    else {
        No *ant = NULL;

        while (ponteiroLinha != NULL && ponteiroLinha->coluna < coluna) // anda na linha ate chegar na coluna
        {
            ant = ponteiroLinha;

            ponteiroLinha = ponteiroLinha->direita;
        }

        No *remover = NULL;

        if (ponteiroLinha != NULL)
        {
            if (ant == NULL)    // remocao do inicio
            {
                remover = m->vLin[linha];
                m->vLin[linha] = m->vLin[linha]->direita;
            }

            else if (ant != NULL)    // remocao do meio
            {
                remover = ant->direita;
                ant->direita = ant->direita->direita;
            }



        }

        else if (ponteiroLinha != NULL && ant->coluna + 1 == coluna) // remocao do final
        {
            remover = ant->direita;
            ant->direita = NULL;
        }

        else if (ponteiroLinha == NULL && ant->coluna + 1 <= coluna)
        {
            printf ("\nNao ha elemento para ser removido\n");

        }



    }


    /// remocao do elemento (coluna)

    if (ponteiroColuna == NULL){
        printf ("\nNao ha elementos na coluna\n");
    }

    else {

        No *ant = NULL;

        while (ponteiroColuna != NULL && ponteiroColuna->linha < linha)
        {
            ant = ponteiroColuna;

            ponteiroColuna = ponteiroColuna->baixo;

        }

        if (ponteiroColuna != NULL)
        {
            if (ant == NULL)        // remocao do inicio
            {
                m->vCol[coluna] = m->vCol[coluna]->baixo;
            }

            if (ant != NULL)        // remocao do meio
            {
                ant->baixo = ant->baixo->baixo;

            }
        }

        else if (ponteiroColuna == NULL && ant->linha + 1 == linha) // remocao do final
        {
            ant->baixo = NULL;
        }

        else if (ponteiroColuna == NULL && ant->linha + 1 <= linha)
        {
            printf ("\nNao ha elemento para ser removido\n");
        }

    }



}


void somarConstanteNaLinha (Matriz *m, int linha, int constante)
{
    No *aux = m->vLin[linha];

    int colunasSomadas[N] = {0};  // verificador de colunas somadas com a constante

    while (aux != NULL){

        aux->numero += constante;

        colunasSomadas[aux->coluna] = 1;    // se somou na coluna, verificador = 1

        aux = aux->direita;

    }

    for (int i = 0; i < N; i++)
    {
        if (colunasSomadas[i] != 1){        // se nao somou -> coluna sem numero -> insere a constante na posicao
            inserirNaMatriz(m, constante, linha, i);
        }


    }


}



int main ()
{
    Matriz m;
    inicializar(&m);


    // matriz, numero, linha, coluna
    inserirNaMatriz(&m, 10, 0, 1);
    inserirNaMatriz(&m, 8, 0, 2);
    inserirNaMatriz(&m, -5, 0, 3);


    inserirNaMatriz(&m, 5, 1, 3);
    inserirNaMatriz(&m, 6, 1, 2);
    inserirNaMatriz(&m, 8, 1, 0);
    inserirNaMatriz(&m, 7, 1, 1);


    imprimirLinha(&m);

    somarConstanteNaLinha(&m, 0, 5);

    imprimirLinha(&m);

    remover(&m, 0, 2);

    imprimirLinha(&m);



return 0;
}
