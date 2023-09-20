
#include <stdio.h>
#include <stdlib.h>
#include "naveEspacial.h"

int verificarDadosNave(NaveEspacial *nave) {
    // Exemplo de verifica��o: ajustar prioridade se for inv�lida
    if (nave->prioridade < 1 || nave->prioridade > 10) {
        printf("Prioridade da nave de id: %d inv�lida. Ajustando para 5.\n",nave->id);
        nave->prioridade = 5;
        return 1; // Indica que a prioridade foi ajustada
    }

    return 0; // Indica que a prioridade � v�lida
}

