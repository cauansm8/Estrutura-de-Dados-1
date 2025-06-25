#include <stdio.h>
#include "Struct.h"

int main (){

    testando teste;

    teste.conteudo = 10;

    printf ("Conteudo da struct de outro arquivo: %d\n", teste.conteudo);

    HelloWorld();

return 0;
}
