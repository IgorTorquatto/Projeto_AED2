#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"
#include <unistd.h>

void carregarDadosDeArquivo(const char *nomeArquivo, Heap *heap) {
    // Abrir o arquivo para leitura
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    NaveEspacial nave;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verificar se é uma linha com ID e prioridade
        if (sscanf(linha, "%d %d %s", &nave.id, &nave.prioridade, nave.nome) == 3) {
            // Inicializar os campos de passageiros e recursos
            nave.passageiros = NULL;
            nave.numPassageiros = 0;
            nave.recursos = NULL;
            nave.numRecursos = 0;

            // Adicionar a nave à heap
            inserirDesordenado(heap, nave);
        }
        // Verificar se é uma linha de passageiro
        else if (strstr(linha, "Passageiros:") != NULL) {
            while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                // Verificar se é o fim da seção de passageiros
                if (strstr(linha, "Recursos:") != NULL) {
                    break;
                }

                // Processar a linha de passageiro e adicionar aos passageiros da nave
                Passageiro passageiro;
                sscanf(linha, "%s %d %s %d", passageiro.nome, &passageiro.idade, passageiro.planetaOrigem, &passageiro.identificadorUnico);

                // Expandir a lista de passageiros da nave
                nave.numPassageiros++;
                nave.passageiros = realloc(nave.passageiros, nave.numPassageiros * sizeof(Passageiro));
                nave.passageiros[nave.numPassageiros - 1] = passageiro;
            }
        }
        // Verificar se é uma linha de recurso
        else if (strstr(linha, "Recursos:") != NULL) {
            while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                // Processar a linha de recurso e adicionar aos recursos da nave
                Recurso recurso;
                sscanf(linha, "%s %d", recurso.nomeRecurso, &recurso.quantidade);

                // Expandir a lista de recursos da nave
                nave.numRecursos++;
                nave.recursos = realloc(nave.recursos, nave.numRecursos * sizeof(Recurso));
                nave.recursos[nave.numRecursos - 1] = recurso;
            }
        }
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void imprimirNave(NaveEspacial *nave) {
    printf("Nave %d, entrando na fila com prioridade %d com %d passageiros e %d recursos.\n", nave->id, nave->prioridade, nave->numPassageiros, nave->numRecursos);
}

int main() {
    // Inicializar a heap
    Heap *heap = criarHeap(10);
    int i;

    // Carregar dados do arquivo
    carregarDadosDeArquivo("dados.txt", heap);

    // Imprimir as naves espaciais carregadas
    //imprimir(heap);
    
    // Imprimir as naves espaciais carregadas com atraso de 2 segundos entre cada nave
	for (i = 0; i < heap->tamanho; i++) {
    imprimirNave(&heap->array[i]);
	}


    // Liberar memória
    for (i = 0; i < heap->tamanho; i++) {
        free(heap->array[i].passageiros);
        free(heap->array[i].recursos);
    }
    free(heap->array);
    free(heap);

    return 0;
}







