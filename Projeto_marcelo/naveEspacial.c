#include <stdio.h>
#include "naveEspacial.h"

int verificarDadosNave(NaveEspacial *nave) {
    // Exemplo de verifica��o: ajustar prioridade se for inv�lida
    if (nave->prioridade < 1 || nave->prioridade > 10) {
        printf("Prioridade da nave %d inv�lida. Ajustando para 5.\n",nave->id);
        nave->prioridade = 5;
        return 1; // Indica que a prioridade foi ajustada
    }

    return 0; // Prioridade v�lida
}

