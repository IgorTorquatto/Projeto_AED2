#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"

int main() {
	setlocale(LC_ALL,"Portuguese"); // Para corrigir os problemas de acentua??o 
	 srand(time(NULL)); // Inicializa a semente do gerador de n?meros aleat?rios
    Heap *heap = criarHeap(10);

    // Exemplo de cria??o de uma nave espacial
    Passageiro passageiros[2] = {
        {"Passageiro1", 30, "Terra", 1},
        {"Passageiro2", 25, "Marte", 2}
    };

    Recurso recursos[2] = {
        {"Comida", 100},
        {"?gua", 50}
    };

    NaveEspacial nave = {15, passageiros, 2, recursos, 2, verificarDadosNave}; // fun??o de verifica??o inclu?da

    inserir(heap, nave);

    // Exibir informa??es da nave espacial inserida
    printf("Prioridade: %d\n", heap->array[0].prioridade);
    printf("N?mero de passageiros: %d\n", heap->array[0].numPassageiros);
    printf("N?mero de recursos: %d\n", heap->array[0].numRecursos);

    free(heap->array);
    free(heap);

    return 0;
}
