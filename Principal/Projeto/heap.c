#include "heap.h"
#include "naveEspacial.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM_RECURSOS 6

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
        printf("A heap esta cheia\n");
        return;
    }

    int ajuste = nave.verificarDados(&nave); //Verifica os dados da nave para saber se precisa reajustar a prioridade

    // Probabilidade de 10% para atribuir uma nova prioridade aleatória para qualquer nave
    if (rand() % 100 < 10) {
        nave.prioridade = rand() % 10 + 1; // Gera um número aleatório entre 1 e 10
        printf("Nova prioridade atribuida! Nave de id %d mudou prioridade para : %d \n",nave.id, nave.prioridade);
        printf("\n");
    }

    heap->array[heap->tamanho] = nave;
    heap->tamanho++;
    ajustarParaCima(heap, heap->tamanho - 1); //para satisfazer as propriedades do heap

    //Caso a prioridade precisou ser ajustada , no caso de ser menor do que 1 por exemplo, mostramos qual posição a prioridade foi ajustada
    if (ajuste) {
        printf("Nave ajustada na posiçao %d com prioridade %d.\n", heap->tamanho, nave.prioridade);
        printf("\n");
    }
}


void imprimir(Heap *heap) {

    int i=0;

    printf("-------------------------------------\n");
    printf("A heap tem no total (%d) naves\n",heap->tamanho);
    printf("-------------------------------------\n");

    sleep(5);

    printf("\nDados das naves:\n\n");
    sleep(5);

    while (i < heap->tamanho) {
        printf("Nave na posicao %d(id:%d)\n", i + 1, heap->array[i].id);
        printf("Prioridade: %d\n", heap->array[i].prioridade);
        printf("Numero de passageiros: %d\n", heap->array[i].numPassageiros);
        printf("Numero de recursos: %d\n", heap->array[i].numRecursos);
        printf("-------------------------------------\n");
        i++;
    }

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
        printf("A heap esta vazia\n");
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

//Parte 2
bool next_permutation(int *arr, int n) {
    int i = n - 2;

    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    int j = n - 1;

    while (arr[j] <= arr[i]) {
        j--;
    }

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    j = n - 1;
    i++;

    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    return true;
}

void analisarRecursosIguais(NaveEspacial *naves, int numNaves) {
    int combinacoesIguais = 0;

    for (int i = 0; i < numNaves - 2; i++) {
        for (int j = i + 1; j < numNaves - 1; j++) {
            for (int k = j + 1; k < numNaves; k++) {
                bool compartimentosIguais = true;

                for (int compartimento = 0; compartimento < 4; compartimento++) {
                    int compartimento1 = compartimento;
                    int compartimento2 = compartimento;
                    int compartimento3 = compartimento;
                    int compartimento4 = compartimento;

                    if (naves[i].recursos[compartimento1].recursoID != naves[j].recursos[compartimento2].recursoID ||
                        naves[i].recursos[compartimento1].recursoID != naves[k].recursos[compartimento3].recursoID ||
                        naves[j].recursos[compartimento2].recursoID != naves[k].recursos[compartimento4].recursoID) {
                        compartimentosIguais = false;
                        break;
                    }
                }

                if (compartimentosIguais) {
                    combinacoesIguais++;
                    break;  // Se encontrou uma combinação igual, não precisa continuar verificando as permutações
                }
            }
        }
    }

    if (combinacoesIguais > 0) {
        printf("Vai haver expansao!\n");
    } else {
        printf("Não há expansao iminente.\n");
    }
}



//

int inserirTodasNavesDoArquivo(FILE *arquivo, Heap *heap) {
    int navesInseridas = 0;
    const char* nomesRecursos[] = {"Agua","Gasolina","Comida","Remedios","Armas","Roupa"};
    char linha[256];

    //Parte 2
    NaveEspacial naves[100];
    int numNaves = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int id, prioridade, idade, identificadorUnico, num_passageiros;
        char nome[50], planetaOrigem[50];

        if (sscanf(linha, "%d,%d,%49[^,],%d,%49[^,],%d", &id, &prioridade, nome, &idade, planetaOrigem, &identificadorUnico) == 6) {
            Passageiro piloto[1];
            piloto[0].idade = idade;
            strcpy(piloto[0].nome, nome);
            strcpy(piloto[0].planetaOrigem, planetaOrigem);
            piloto[0].identificadorUnico = identificadorUnico;

            num_passageiros = rand() % 101;

            int numRecursos = rand() % 101;
            Recurso recursos[numRecursos];

            int maxQuantidade = 0; // Variável para rastrear a maior quantidade de recurso
            int recursoMaisQuantidade = -1; // Variável para rastrear o recurso com a maior quantidade

            for (int i = 0; i < numRecursos; i++) {
                int num_aleatorio = rand() % NUM_RECURSOS; // Gera um identificador numérico aleatório
                recursos[i].recursoID = num_aleatorio;
                recursos[i].quantidade = 1;

                // Verificar se a quantidade atual é maior que a quantidade máxima
                if (recursos[i].quantidade > maxQuantidade) {
                    maxQuantidade = recursos[i].quantidade;
                    recursoMaisQuantidade = num_aleatorio;
                }
            }

            int quantidadeTotalRecursos = 0;
            for (int i = 0; i < numRecursos; i++) {
                quantidadeTotalRecursos += recursos[i].quantidade;
            }

            NaveEspacial nave = {id, prioridade, piloto, num_passageiros, recursos, numRecursos, verificarDadosNave};

            // Calcular a quantidade média por compartimento
            int quantidadeMediaPorCompartimento = quantidadeTotalRecursos / 4;

            printf("Nave de id (%d) transportando:\n", id);
            for (int i = 0; i < numRecursos; i++) {
                // Distribuir a quantidade média nos compartimentos
                int quantidadePorCompartimento = quantidadeMediaPorCompartimento;
                if (i < numRecursos % 4) {
                    quantidadePorCompartimento++;
                }

                printf("(Recurso %d)", recursos[i].recursoID);
            }
            sleep(2);

            printf("\n");

            for(int i = 0; i < 4; i++){
               printf("\nCompartimento %d transportando aproximadamente %d itens \n", i+1, quantidadeMediaPorCompartimento);
            }

            sleep(2);
            printf("\nQuantidade total de recursos: %d\n", quantidadeTotalRecursos);
            printf("Identificador do recurso com a maior quantidade: %d\n", recursoMaisQuantidade);
            printf("Nome do recurso com a maior quantidade: %s\n", nomesRecursos[recursoMaisQuantidade]);
            printf("Piloto da nave de id (%d): %s do planeta %s\n\n", id, nave.passageiros->nome, nave.passageiros->planetaOrigem);

            inserir(heap, nave);
            // Armazene a nave no array
            naves[numNaves] = nave;
            numNaves++;

            navesInseridas++;
            sleep(2);
        }
    }
    // Verificar se recursos são iguais em combinações de 3 naves
    analisarRecursosIguais(naves, numNaves);
    return navesInseridas;
}
