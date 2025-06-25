#include <stdio.h>
#include <stdlib.h>


// estrutura utilizada: pilha

typedef struct Disco {  /// struct para o numero e o encadeamento do proximo numero

    int numero;     // numero se refere ao tamanho do disco
                    // o disco 3 é o maior disco!
    struct Disco *baixo;

} disco;

typedef struct Pinos{  /// struct para apontar ao topo do pino

    disco *topo;

} pinos;
