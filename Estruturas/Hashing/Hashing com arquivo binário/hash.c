#include <stdio.h>
#include <string.h>
#define TAM 7

int primeiraColisao = 7;

typedef struct reg{
    char chave[20];
    int ocupado; // 0 -> conteudo vazio E 1 -> contem conteudo
    int prox;
} reg;



int funcaoHash (char chave[])
{
    int soma = 0;

    for (int i = 0; i < strlen(chave); i++)
    {
        soma += chave[i] * i;
    }

    printf ("\n\nSoma: %d || Indice: %d", soma, soma%TAM);

    return soma % TAM;

}

void inserirNoArquivo(char nome[])
{
    FILE *file = fopen (nome, "wb+");

    if (file == NULL){
        printf ("\nErro");
    }


    reg Aux;            // joga todas as regs vazias
    strcpy (Aux.chave, "");
    Aux.ocupado = 0;
    Aux.prox = -1;

    for (int i = 0; i < 11; i++)
    {
        fwrite (&Aux, sizeof(reg), 1, file);
    }

    rewind (file);


    char chave[20];

    do
    {

        printf ("\n\nInforme a chave: ");
        scanf ("%s", chave);

        int indice = funcaoHash (chave);

        fseek (file, indice * sizeof(reg), SEEK_SET);
        fread (&Aux, sizeof(reg), 1, file);

        reg novoRegistro;
        strcpy (novoRegistro.chave, chave);
        novoRegistro.ocupado = 1;
        novoRegistro.prox = -1;


        if (Aux.ocupado == 0){
            strcpy (novoRegistro.chave, chave);
            novoRegistro.ocupado = 1;

            fseek (file, indice * sizeof(reg), SEEK_SET);
            fwrite (&novoRegistro, sizeof(reg), 1, file);
        }

        else if (primeiraColisao < 11){

            int posicao = indice;

            while (Aux.prox != -1)
            {
                posicao = Aux.prox;
                fseek (file, Aux.prox * sizeof (reg), SEEK_SET);
                fread (&Aux, sizeof(reg), 1, file);
            }

            reg atualizarRegistro;

            fseek (file, posicao * sizeof(reg), SEEK_SET);
            fread (&atualizarRegistro, sizeof(reg), 1, file);

            atualizarRegistro.prox = primeiraColisao;

            fseek (file, posicao * sizeof(reg), SEEK_SET);
            fwrite (&atualizarRegistro, sizeof(reg), 1, file);

            reg novoRegistro;
            strcpy (novoRegistro.chave, chave);
            novoRegistro.ocupado = 1;
            novoRegistro.prox = -1;

            fseek (file, primeiraColisao * sizeof(reg), SEEK_SET);
            fwrite (&novoRegistro, sizeof(reg), 1, file);

            primeiraColisao++;

        }

        else {
            printf ("\nArea de overflow cheia -> conteudo perdido!");
        }

        for (int i = 0; i < 11 ; i++)
        {
            reg Aux;
            fseek (file, i * sizeof(reg), SEEK_SET);
            fread (&Aux, sizeof(reg), 1, file);

            printf ("\nI: %d || Chave: %s    || prox: %d     ", i, Aux.chave, Aux.prox);


        }


    }while (chave[0] != '.');



    printf ("\n\nFIM DO PROGRAMA\n\n");

    fclose(file);
}


int main ()
{

    char nomeDoArquivo[20];
    printf ("\nInforme o nome do arquivo: ");
    scanf ("%s", nomeDoArquivo);

    printf ("\nArea de overflow: 7 - 10");
    printf ("\nFim da insercao -> coloque '.' na chave");

    inserirNoArquivo(nomeDoArquivo);

return 0;
}
