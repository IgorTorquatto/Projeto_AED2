#include <stdio.h>
#include <stdlib.h>
#include "naveEspacial.h"
#include "heap.h"

int main() {
    Heap *heap = criarHeap(10);

    // Exemplo de cria��o de uma nave espacial
    Passageiro passageiros[2] = {
        {"Passageiro1", 30, "Terra", 1},
        {"Passageiro2", 25, "Marte", 2}
    };

    Recurso recursos[2] = {
        {"Comida", 100},
        {"�gua", 50}
    };

    NaveEspacial nave = {5, passageiros, 2, recursos, 2};

    inserir(heap, nave);

    // Exibir informa��es da nave espacial inserida
    printf("Prioridade: %d\n", heap->array[0].prioridade);
    printf("N�mero de passageiros: %d\n", heap->array[0].numPassageiros);
    printf("N�mero de recursos: %d\n", heap->array[0].numRecursos);

    free(heap->array);
    free(heap);

    return 0;
}

