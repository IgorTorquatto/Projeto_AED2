#include "heap.h"
#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Função para criar uma nova heap
Heap* criarHeap(int capacidade) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->capacidade = capacidade; //queremos passar a capacidade da heap ao chamar a função
    heap->tamanho = 0; // inicialmente o tamanho deve ser 0
    heap->array = (NaveEspacial*)malloc(capacidade * sizeof(NaveEspacial)); //alocando espaço para as naves
    return heap;
}

// Função para trocar duas naves espaciais
void trocar(NaveEspacial *a, NaveEspacial *b) {
    NaveEspacial temp = *a;
    *a = *b;
    *b = temp;
}


// Funçã para manter a propriedade da heap após a inserção de uma nova nave espacial
void ajustarParaCima(Heap *heap, int indice) {
    int pai = (indice - 1) / 2; //lembrando que o índice começa em 0 por isso o -1
    while (indice > 0 && heap->array[pai].prioridade < heap->array[indice].prioridade) {
        trocar(&heap->array[pai], &heap->array[indice]);
        indice = pai;
        pai = (indice - 1) / 2;
    }
}


// Função para inserir uma nave espacial na heap
void inserir(Heap *heap, NaveEspacial nave) {
    if (heap->tamanho == heap->capacidade) {
        printf("A heap está cheia\n");
        return;
    }

    int ajuste = nave.verificarDados(&nave); //Verifica os dados da nave para saber se precisa reajustar a prioridade

    // Probabilidade de 10% para atribuir uma nova prioridade aleatória para qualquer nave
    if (rand() % 100 < 10) {
        nave.prioridade = rand() % 10 + 1; // Gera um número aleatório entre 1 e 10
        printf("Nova prioridade atribuída!, nave de id %d mudou prioridade para : %d \n",nave.id, nave.prioridade);
        printf("\n");
    }

    heap->array[heap->tamanho] = nave;
    heap->tamanho++;
    ajustarParaCima(heap, heap->tamanho - 1); //para satisfazer as propriedades do heap

    //Caso a prioridade precisou ser ajustada , no caso de ser menor do que 1 por exemplo, mostramos qual posição a prioridade foi ajustada
    if (ajuste) {
        printf("Nave ajustada na posição %d com prioridade %d.\n", heap->tamanho, nave.prioridade);
        printf("\n");
    }
}


void imprimir(Heap *heap) {

    setlocale(LC_ALL, "Portuguese");
    int i= 0;

    printf("Dados das naves:\n\n");
    while (i < heap->tamanho) {
        printf("Nave na posição %d(id:%d)\n", i + 1, heap->array[i].id);
        printf("Prioridade: %d\n", heap->array[i].prioridade);
        printf("Número de passageiros: %d\n", heap->array[i].numPassageiros);
        printf("Número de recursos: %d\n", heap->array[i].numRecursos);
        printf("-------------------------------------\n");
        i++;
    }
    printf("-------------------------------------\n");
    printf("A heap tem no total (%d) naves\n",heap->tamanho);
    printf("-------------------------------------\n");
}


void descer(Heap *heap, int indice) {
    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;
    int maior = indice;

    if (filhoEsquerdo < heap->tamanho && heap->array[filhoEsquerdo].prioridade > heap->array[maior].prioridade) {
        maior = filhoEsquerdo;
    }

    if (filhoDireito < heap->tamanho && heap->array[filhoDireito].prioridade > heap->array[maior].prioridade) {
        maior = filhoDireito;
    }

    if (maior != indice) {
        trocar(&heap->array[indice], &heap->array[maior]);
        descer(heap, maior);
    }
}


void remover(Heap *heap){
    if (heap->tamanho == 0) {
        printf("A heap está vazia\n");
        return;
    }
    //Copiamos o último elemento para primeira posição e aplicamos o descer
    heap->array[0] = heap->array[heap->tamanho - 1];
    descer(heap,0);
    heap->tamanho--;
}

//Função que constrói o heap, igual vimos em sala
void constroiHeap(Heap *heap) {
	int i;
    for (i = (heap->tamanho / 2) - 1; i >= 0; i--) {
        descer(heap, i);
    }
}
