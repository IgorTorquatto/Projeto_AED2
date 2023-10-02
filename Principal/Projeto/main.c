#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "naveEspacial.h"
#include "heap.h"
#define MAX_PERMUTACOES (216)

int main() {

    //permutacoes:
    Permutacao permutacoes[MAX_PERMUTACOES];
    int contador_permutacoes = 0;

    //Heap:
    Heap *heap = criarHeap(10);

    FILE *arquivo = fopen("naves.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Leitura e inserção das naves a partir do arquivo na heap criada
    int navesInseridas = inserirTodasNavesDoArquivo(arquivo, heap, permutacoes, &contador_permutacoes);
    fclose(arquivo);

    printf("Carregando informacoes das naves ...\n");
    sleep(5);

    //Construção da heap de acordo com suas condições
    constroiHeap(heap);

    // Impressão
    if(navesInseridas > 0){
        imprimir(heap);
    } else{
        printf("Nenhuma nave foi inserida. \n");
    }

    if (navesInseridas >= 10) {
    // Expandir a abertura
    printf("Expansao da abertura!\n");
    navesInseridas = 0;
    contador_permutacoes = 0; // Limpar permutações
    }

    sleep(5);
    printf("Organizando naves em fila de saida: \n");
    sleep(5);

    //Remoção
    while (heap->tamanho > 0) {
        NaveEspacial nave = heap->array[0];
        printf("\nNave id %d saindo da fila com prioridade %d\n", nave.id, nave.prioridade);
        sleep(3);
        remover(heap); //diminui o tamanho do heap
    }

    // Liberação de memória
    free(heap->array);
    free(heap);

    return 0;
}
