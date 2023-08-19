#include "naveEspacial.h"

int verificarDadosNave(NaveEspacial *nave) {
    // Exemplo de verificação: ajustar prioridade se for inválida
    if (nave->prioridade < 1 || nave->prioridade > 10) {
        printf("Prioridade inválida. Ajustando para 5.\n");
        nave->prioridade = 5;
        return 1; // Indica que a prioridade foi ajustada
    }
    
    return 0; // Prioridade válida
}

