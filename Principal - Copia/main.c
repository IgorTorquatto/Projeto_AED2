#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"

int main() {
	setlocale(LC_ALL,"Portuguese"); // Para corrigir os problemas de acentuação
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    Heap *heap = criarHeap(10);
    int *a;

    // Exemplo de criação de uma nave espacial
    
    Passageiro passageiros[2] = { //Quantidade de passageiros a ser criados
        {"Passageiro1", 30, "Terra", 1}, //Preenchendo todos os atributos do scruct
        {"Passageiro2", 25, "Marte", 2}
    };


    Recurso recursos[2] = {
        {"Comida", 100},
        {"Água", 50}
    };

	//Criação das naves
    NaveEspacial nave = {1,15, passageiros, 2, recursos, 2, verificarDadosNave}; // id,prioridade,passageiros,num_passageiro,recursos,num_recursos,função de verificação
   
	//Inserção das naves no heap
    inserir(heap, nave);

    //Impressão
    imprimir(heap);

    //Construção da heap
    constroiHeap(heap);

	//Remoção
	while (heap->tamanho > 0) {
    NaveEspacial nave = heap->array[0];
    printf("Nave id %d saindo da fila com prioridade %d\n", nave.id, nave.prioridade);
    remover(heap);
	}


	//Liberação
    free(heap->array);
    free(heap);

    return 0;
}
