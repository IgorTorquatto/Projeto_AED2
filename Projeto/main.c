#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do passageiro
typedef struct {
    char nome[50];
    int idade;
    char planetaOrigem[50];
    int identificadorUnico;
} Passageiro;

// Defini��o da estrutura dos recursos transportados
typedef struct {
    char nomeRecurso[50];
    int quantidade;
} Recurso;

// Defini��o da estrutura da nave espacial
typedef struct {
    int prioridade;
    Passageiro *passageiros;
    int numPassageiros;
    Recurso *recursos;
    int numRecursos;
} NaveEspacial;

// Defini��o da estrutura da heap
typedef struct {
    NaveEspacial *array;
    int capacidade;
    int tamanho;
} Heap;

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

    heap->array[heap->tamanho] = nave;
    heap->tamanho++;
    ajustarParaCima(heap, heap->tamanho - 1);
}

// Fun��o principal
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

