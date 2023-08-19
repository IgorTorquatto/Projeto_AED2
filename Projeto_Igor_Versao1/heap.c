#include "heap.h"

// Fun��o para criar uma nova heap
Heap* criarHeap(int capacidade) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->capacidade = capacidade;
    heap->tamanho = 0;
    heap->array = (NaveEspacial*)malloc(capacidade * sizeof(NaveEspacial));
    return heap;
}

// Fun��o para trocar duas naves espaciais
void trocar(NaveEspacial *a, NaveEspacial *b) {
    NaveEspacial temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o para manter a propriedade da heap ap�s a inser��o de uma nova nave espacial
void ajustarParaCima(Heap *heap, int indice) {
    int pai = (indice - 1) / 2;
    while (indice > 0 && heap->array[pai].prioridade < heap->array[indice].prioridade) {
        trocar(&heap->array[pai], &heap->array[indice]);
        indice = pai;
        pai = (indice - 1) / 2;
    }
}

// Fun��o para inserir uma nave espacial na heap
void inserir(Heap *heap, NaveEspacial nave) {
    if (heap->tamanho == heap->capacidade) {
        printf("A heap est� cheia\n");
        return;
    }

    int ajuste = nave.verificarDados(&nave); //Verifica os dados da nave

    // Probabilidade de 10% para atribuir uma nova prioridade aleat�ria
    if (rand() % 100 < 10) {
        nave.prioridade = rand() % 10 + 1; // Gera um n�mero aleat�rio entre 1 e 10
        printf("Nova prioridade atribu�da: %d\n", nave.prioridade);
    }

    heap->array[heap->tamanho] = nave;
    heap->tamanho++;
    ajustarParaCima(heap, heap->tamanho - 1);

    if (ajuste) {
        printf("Nave ajustada na posi��o %d com prioridade %d.\n", heap->tamanho, nave.prioridade);
    }
}

