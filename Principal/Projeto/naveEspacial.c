#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int sao_permutacoes_iguais(Permutacao p1, Permutacao p2) {
    int i,j;
    for (i = 0; i < 6; i++) {
        int igual = 0;
        for (j = 0; j < 6; j++) {
            if (strcmp(p1.permutacao[i], p2.permutacao[j]) == 0) {
                igual = 1;
                break;
            }
        }
        if (!igual) {
            return 0;
        }
    }
    return 1;
}
