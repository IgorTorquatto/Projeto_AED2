#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"
#include <string.h>

// Fun��o para ler e inserir uma nave do arquivo
int inserirNaveDoArquivo(FILE *arquivo, Heap *heap) {
    int id, prioridade, idade, identificadorUnico;
    char nome[50], planetaOrigem[50];

    if (fscanf(arquivo, "%d,%d,%49[^,],%d,%49[^,],%d,", &id, &prioridade, nome, &idade, planetaOrigem, &identificadorUnico) == 6) {
        Passageiro passageiros[1];
        passageiros[0].idade = idade;
        strcpy(passageiros[0].nome, nome);
        strcpy(passageiros[0].planetaOrigem, planetaOrigem);
        passageiros[0].identificadorUnico = identificadorUnico;

        Recurso recursos[50];
        int numRecursos = 0;

        char recursoNome[50];
        int quantidade;

        // Leitura dos recursos separados por v�rgulas
        while (fscanf(arquivo, "%49[^,],%d,", recursoNome, &quantidade) == 2) {
            strcpy(recursos[numRecursos].nomeRecurso, recursoNome);
            recursos[numRecursos].quantidade = quantidade;
            numRecursos++;
        }

        NaveEspacial nave = {id, prioridade, passageiros, 1, recursos, numRecursos, verificarDadosNave};
        inserir(heap, nave);
        return 1; // Indica que uma nave foi inserida
    }
    return 0; // Indica que n�o foi poss�vel ler mais naves
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Para corrigir os problemas de acentua��o
    srand(time(NULL)); // Inicializa a semente do gerador de n�meros aleat�rios
    Heap *heap = criarHeap(10);

    FILE *arquivo = fopen("naves.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int navesLidas = 0;

    // Leitura e inser��o das naves a partir do arquivo
    while (inserirNaveDoArquivo(arquivo, heap)) {
        navesLidas++;
    }

    fclose(arquivo);

    // Impress�o
    if (navesLidas > 0) {
        imprimir(heap);

    // Constru��o da heap
    constroiHeap(heap);

    // Remo��o
    while (heap->tamanho > 0) {
        NaveEspacial nave = heap->array[0];
        printf("Nave id %d saindo da fila com prioridade %d\n", nave.id, nave.prioridade);
        remover(heap);
    }
    } else {
    printf("Nenhuma nave foi lida do arquivo.\n");
    }

    // Libera��o
    free(heap->array);
    free(heap);

    return 0;
}
