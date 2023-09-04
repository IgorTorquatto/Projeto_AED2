#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"
#include <string.h>

// Função para ler e inserir todas as naves do arquivo
int inserirTodasNavesDoArquivo(FILE *arquivo, Heap *heap) {
    int navesInseridas = 0;
    char linha[256]; // Tamanho suficiente para armazenar uma linha

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int id, prioridade, idade, identificadorUnico;
        char nome[50], planetaOrigem[50];

        if (sscanf(linha, "%d,%d,%49[^,],%d,%49[^,],%d,", &id, &prioridade, nome, &idade, planetaOrigem, &identificadorUnico) == 6) {
            Passageiro passageiros[1];
            passageiros[0].idade = idade;
            strcpy(passageiros[0].nome, nome);
            strcpy(passageiros[0].planetaOrigem, planetaOrigem);
            passageiros[0].identificadorUnico = identificadorUnico;

            Recurso recursos[50];
            int numRecursos = 0;

            char recursoNome[50];
            int quantidade;

            // Agora, dividimos a linha em recursos separados por vírgulas
            char *token = strtok(linha, ",");
            while (token != NULL) {
                token = strtok(NULL, ",");
                if (token != NULL && sscanf(token, "%49[^,],%d", recursoNome, &quantidade) == 2) {
                    strcpy(recursos[numRecursos].nomeRecurso, recursoNome);
                    recursos[numRecursos].quantidade = quantidade;
                    numRecursos++;
                }
            }

            NaveEspacial nave = {id, prioridade, passageiros, 1, recursos, numRecursos, verificarDadosNave};
            inserir(heap, nave);
            navesInseridas++;
        } else {
            return 0; // Encerra o loop se não for possível ler mais naves
        }
    }

    return navesInseridas;
}



int main() {
    setlocale(LC_ALL, "Portuguese"); // Para corrigir os problemas de acentuação
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    Heap *heap = criarHeap(10);

    FILE *arquivo = fopen("naves.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int navesLidas=0;

    // Leitura e inserção das naves a partir do arquivo
    while (inserirTodasNavesDoArquivo(arquivo, heap)) {
        navesLidas++;
    }

  //  printf(" Naves lidas :%d",navesLidas); para verificar  o erro de ler só uma nave do txt

    fclose(arquivo);

    // Impressão
    if (navesLidas > 0) {
        imprimir(heap);

    // Construção da heap
    constroiHeap(heap);

    // Remoção
    while (heap->tamanho > 0) {
        NaveEspacial nave = heap->array[0];
        printf("Nave id %d saindo da fila com prioridade %d\n", nave.id, nave.prioridade);
        remover(heap);
    }
    } else {
    printf("Nenhuma nave foi lida do arquivo.\n");
    }

    // Liberação
    free(heap->array);
    free(heap);

    return 0;
}
