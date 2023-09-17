#ifndef HEAP_H
#define HEAP_H
#include "naveEspacial.h"

// Definição da estrutura da heap
typedef struct {
    NaveEspacial *array;
    int capacidade;
    int tamanho;
} Heap;

Heap* criarHeap(int capacidade);
void inserir(Heap *heap, NaveEspacial nave);
void trocar(NaveEspacial *a, NaveEspacial *b);
void ajustarParaCima(Heap *heap, int indice);
void imprimir(Heap *heap);
void descer(Heap *heap,int indice);
void inserirDesordenado(Heap *heap,NaveEspacial nave);
void constroiHeap(Heap *heap);

#endif

