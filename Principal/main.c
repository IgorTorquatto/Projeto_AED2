#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"

int main() {
	setlocale(LC_ALL,"Portuguese"); // Para corrigir os problemas de acentua��o
	 srand(time(NULL)); // Inicializa a semente do gerador de n�meros aleat�rios
    Heap *heap = criarHeap(10);
    int *a;

    // Exemplo de cria��o de uma nave espacial
    Passageiro passageiros[2] = {
        {"Passageiro1", 30, "Terra", 1},
        {"Passageiro2", 25, "Marte", 2}
    };

    Passageiro familia[4] = {
        {"Anais", 20, "Lua", 3},
        {"Luke",22,"Lua",4},
        {"Pedro", 54, "Lua", 5},
        {"Ana",55,"Lusa",6}
    };

    Passageiro grupo[3] = {
        {"Ana",26,"Marte",7},
        {"Pedro",22,"Terra",8},
        {"Julia",19,"Lua",9}
    };

    Recurso recursos[2] = {
        {"Comida", 100},
        {"�gua", 50}
    };

    Recurso itens[4] = {
        {"Comida", 100},
        {"�gua", 50},
        {"Cilindro de oxigenio",2},
        {"Tecido de algodao",30}
    };

    NaveEspacial nave = {1,15, passageiros, 2, recursos, 2, verificarDadosNave}; // fun��o de verifica��o inclu�da
    NaveEspacial espac = {2,7,familia,4,itens,4,verificarDadosNave};
    NaveEspacial nova = {3,9,familia,4,recursos,2,verificarDadosNave};
    NaveEspacial ult = {4,2,grupo,3,itens,4,verificarDadosNave};
    NaveEspacial uma = {5,7,grupo,3,recursos,4,verificarDadosNave};
    NaveEspacial ume = {6,-7,grupo,3,recursos,4,verificarDadosNave};

    inserirDesordenado(heap, nave);
    inserirDesordenado(heap, espac);
    inserirDesordenado(heap,ult);
    inserirDesordenado(heap, nova);
    inserirDesordenado(heap,uma);
    inserirDesordenado(heap,ume);

    // Exibir informa��es da nave espacial inserida
    /*printf("Nave na posi��o 1 - id: %d \n",heap->array[0].id);
    printf("Prioridade: %d\n", heap->array[0].prioridade);
    printf("N�mero de passageiros: %d\n", heap->array[0].numPassageiros);
    printf("N�mero de recursos: %d\n", heap->array[0].numRecursos);
    */

    imprimir(heap);

    constroiHeap(heap);

    imprimir(heap);

    free(heap->array);
    free(heap);

    return 0;
}
