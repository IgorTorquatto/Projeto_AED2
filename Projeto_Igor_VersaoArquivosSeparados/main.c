#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Heap *heap = criarHeap(10);

    // Leitura de dados de um arquivo
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Parse dos dados da linha e criação das naves espaciais
        NaveEspacial nave;

        // Use sscanf para analisar a linha do arquivo
        sscanf(linha, "%d %d %s", &nave.id, &nave.prioridade, nave.nome);

        inserirDesordenado(heap, nave);
    }

    fclose(arquivo);

    int opcao;
    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Inserir nova nave espacial\n");
        printf("2. Remover nave espacial de maior prioridade\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        // Solicitar dados da nova nave espacial ao usuário e inserir
        NaveEspacial novaNave;

        switch (opcao) {
            case 1:
                // Leitura dos dados da nova nave espacial e inserção
                printf("ID: ");
                scanf("%d", &novaNave.id);
                printf("Prioridade: ");
                scanf("%d", &novaNave.prioridade);
                
                // Usando fgets para ler o nome da nave
                printf("Nome: ");
                fgets(novaNave.nome, sizeof(novaNave.nome), stdin);
                novaNave.nome[strcspn(novaNave.nome, "\n")] = '\0'; // Remover a quebra de linha
                
                inserir(heap, novaNave);
                break;
            case 2:
                // Remover nave espacial de maior prioridade
                if (heap->tamanho > 0) {
                    printf("Nave espacial de maior prioridade removida.\n");
                    remover(heap);
                } else {
                    printf("A fila de prioridades está vazia.\n");
                }
                fflush(stdout);
                break;
            case 3:
                // Sair do programa
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 3);

    // Liberar memória
    free(heap->array);
    free(heap);

    return 0;
}

