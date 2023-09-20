#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"
#include "hash.h"
#include <string.h>
#define NUM_RECURSOS 5


// Função para ler e inserir todas as naves do arquivo
int inserirTodasNavesDoArquivo(FILE *arquivo, Heap *heap) {
    int navesInseridas = 0;
    char* nomesRecursos[NUM_RECURSOS] = {"Agua", "Gasolina", "Comida","Remedios", "Itens"};
    char linha[256]; // Tamanho suficiente para armazenar uma linha

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int id, prioridade, idade, identificadorUnico,num_passageiros;
        char nome[50], planetaOrigem[50];

        if (sscanf(linha, "%d,%d,%49[^,],%d,%49[^,],%d,", &id, &prioridade, nome, &idade, planetaOrigem, &identificadorUnico) == 6) {
            Passageiro passageiros[1];
            passageiros[0].idade = idade;
            strcpy(passageiros[0].nome, nome);
            strcpy(passageiros[0].planetaOrigem, planetaOrigem);
            passageiros[0].identificadorUnico = identificadorUnico;

            //Qtd passageiros
            num_passageiros = rand();
            num_passageiros = num_passageiros %101;

            //Qtd Recursos
            Recurso recursos[1];
            int numRecursos = rand();
            numRecursos = numRecursos % 101;

            //Nome do Recurso
            int num_aleatorio = rand();
            num_aleatorio = num_aleatorio % 6;

            strcpy(recursos[0].nomeRecurso, nomesRecursos[num_aleatorio]);
            recursos[0].quantidade = numRecursos;

            NaveEspacial nave = {id, prioridade, passageiros, num_passageiros, recursos, numRecursos, verificarDadosNave};
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
    RecursoCombination novaComb;

    // Leitura e inserção das naves a partir do arquivo
    while (inserirTodasNavesDoArquivo(arquivo, heap)) {
        navesLidas++;

        /* Calcula a combinação dos recursos da nova nave e insere na tabela de dispersão
        int idRecursosNave[3]; // Suponha que você tem os IDs dos recursos da nova nave
        novaComb.recursos[0] = idRecursosNave[0];
        novaComb.recursos[1] = idRecursosNave[1];
        novaComb.recursos[2] = idRecursosNave[2];
        inserirCombinacaoUnica(&novaComb);

        // Verifica a expansão com base na nova combinação
        verificarExpansao(&novaComb);*/
    }

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
