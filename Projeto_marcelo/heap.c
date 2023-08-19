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
        printf("Nova prioridade atribu�da: %d \n", nave.prioridade);
        printf("\n");
    }

    heap->array[heap->tamanho] = nave;
    heap->tamanho++;
    ajustarParaCima(heap, heap->tamanho - 1);

    if (ajuste) {
        printf("Nave ajustada na posi��o %d com prioridade %d.\n", heap->tamanho, nave.prioridade);
        printf("\n");
    }
}


void imprimir(Heap *heap){
    int i;
    for(i = 0; i<heap->tamanho; i++){
    printf("Nave na posi��o %d - id:                                      %d \n",i+1,heap->array[i].id);
    printf("Prioridade:                        %d\n", heap->array[i].prioridade);
    printf("N�mero de passageiros: %d\n", heap->array[i].numPassageiros);
    printf("N�mero de recursos: %d\n", heap->array[i].numRecursos);
    printf("\n");
    }
    printf("A heap tem %d naves \n", heap->tamanho);
    printf("------------------------------------- \n");
}

void descer(Heap *heap,int indice){
    int filho = 2 * indice + 1;
    if(filho <= heap->tamanho){
        if(filho < heap->tamanho){
            if(heap->array[filho + 1].prioridade  >  heap->array[filho].prioridade){
                filho = filho + 1;
            }
        }
        if(heap->array[filho].prioridade > heap->array[indice].prioridade){
            trocar(&heap->array[filho],&heap->array[indice]);
            descer(heap, filho);
        }
    }
}

void remover(Heap *heap){
    if (heap->tamanho == 0) {
        printf("A heap est� vazia\n");
        return;
    }
    heap->array[0] = heap->array[heap->tamanho - 1];
    descer(heap,0);
    //desalocar memoria;
    heap->tamanho--;
}

void inserirDesordenado(Heap *heap,NaveEspacial nave){
    if (heap->tamanho == heap->capacidade) {
        printf("A heap est� cheia\n");
        return;
    }
    int ajuste = nave.verificarDados(&nave);

    heap->array[heap->tamanho] = nave;
    heap->tamanho++;

    if (ajuste) {
        printf("Nave ajustada na posi��o %d com prioridade %d.\n", heap->tamanho, nave.prioridade);
        printf("\n");
    }
}

void constroiHeap(Heap *heap){
    int i;
    for(i = heap->tamanho/2; i >= 0; i--){
        descer(heap,i);
    }
}

