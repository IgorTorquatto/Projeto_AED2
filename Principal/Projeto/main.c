#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "naveEspacial.h"
#include "heap.h"
#include <string.h>
#define NUM_RECURSOS 6


int inserirTodasNavesDoArquivo(FILE *arquivo, Heap *heap) {
    int navesInseridas = 0;
    char* nomesRecursos[NUM_RECURSOS] = {"Agua", "Gasolina", "Comida","Remedios", "Armas","Roupa"};  //6 itens conforme a descrição do trabalho
    char linha[256]; // Tamanho suficiente para armazenar uma linha

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int id, prioridade, idade, identificadorUnico, num_passageiros;
        char nome[50], planetaOrigem[50];

        if (sscanf(linha, "%d,%d,%49[^,],%d,%49[^,],%d,", &id, &prioridade, nome, &idade, planetaOrigem, &identificadorUnico) == 6) {
            Passageiro piloto[1];
            piloto[0].idade = idade;
            strcpy(piloto[0].nome, nome);
            strcpy(piloto[0].planetaOrigem, planetaOrigem);
            piloto[0].identificadorUnico = identificadorUnico;

            // Qtd passageiros
            num_passageiros = rand() % 101;

            // Qtd Recursos
            Recurso recursos[1];
            int numRecursos = rand() % 101;
            recursos[0].quantidade = numRecursos;

            // Nome do Recurso
            int num_aleatorio = rand() % 6;
            strcpy(recursos[0].nomeRecurso, nomesRecursos[num_aleatorio]);

            NaveEspacial nave = {id, prioridade, piloto, num_passageiros, recursos, numRecursos, verificarDadosNave};
            printf("Nave de id (%d) transportando: %s \n",id,nave.recursos->nomeRecurso);
            printf("Piloto da nave de id (%d): %s do planeta %s \n\n",id,nave.passageiros->nome,nave.passageiros->planetaOrigem);

            inserir(heap, nave);
            navesInseridas++;
        } else {
            return 0; // Encerra o loop se não for possível ler mais naves
        }
    }

    return navesInseridas;
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    Heap *heap = criarHeap(10);

    FILE *arquivo = fopen("naves.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int navesLidas=0;

    // Leitura e inserção das naves a partir do arquivo na heap criada
    while (inserirTodasNavesDoArquivo(arquivo, heap)) {
        navesLidas++;
    }
    fclose(arquivo);

    //Construção da heap de acordo com suas condições
    constroiHeap(heap);

    // Impressão
    if (navesLidas > 0) {
    imprimir(heap);} else {
    printf("Nenhuma nave foi lida do arquivo.\n");
    }

    //Remoção
    while (heap->tamanho > 0) {
        NaveEspacial nave = heap->array[0];
        printf("\nNave id %d saindo da fila com prioridade %d\n", nave.id, nave.prioridade);
        printf("%s",heap->array);
        sleep(3);
        remover(heap); //diminui o tamanho do heap
    }

    // Liberação de memória
    free(heap->array);
    free(heap);

    return 0;
}
