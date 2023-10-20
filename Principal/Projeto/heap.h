#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
bool next_permutation(int *arr, int n);
void analisarRecursosIguais(NaveEspacial *naves, int numNaves);
int inserirTodasNavesDoArquivo(FILE *arquivo, Heap *heap);

#endif
