#include <stdio.h>
#include <stdlib.h>
#include "naveEspacial.h"

int verificarDadosNave(NaveEspacial *nave) {
    // Exemplo de verificação: ajustar prioridade se for inválida
    if (nave->prioridade < 1 || nave->prioridade > 10) {
        printf("Prioridade da nave de id: %d invalida. Ajustando para 5.\n",nave->id);
        nave->prioridade = 5;
        return 1; // Indica que a prioridade foi ajustada
    }

    return 0; // Indica que a prioridade é válida
}

