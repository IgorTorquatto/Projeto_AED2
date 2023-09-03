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
    
    Passageiro passageiros[2] = { //Quantidade de passageiros a ser criados
        {"Passageiro1", 30, "Terra", 1}, //Preenchendo todos os atributos do scruct
        {"Passageiro2", 25, "Marte", 2}
    };


    Recurso recursos[2] = {
        {"Comida", 100},
        {"�gua", 50}
    };

	//Cria��o das naves
    NaveEspacial nave = {1,15, passageiros, 2, recursos, 2, verificarDadosNave}; // id,prioridade,passageiros,num_passageiro,recursos,num_recursos,fun��o de verifica��o
   
	//Inser��o das naves no heap
    inserir(heap, nave);

    //Impress�o
    imprimir(heap);

    //Constru��o da heap
    constroiHeap(heap);

	//Remo��o
	while (heap->tamanho > 0) {
    NaveEspacial nave = heap->array[0];
    printf("Nave id %d saindo da fila com prioridade %d\n", nave.id, nave.prioridade);
    remover(heap);
	}


	//Libera��o
    free(heap->array);
    free(heap);

    return 0;
}
