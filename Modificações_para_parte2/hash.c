#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define TAMANHO_TABELA_HASH 1000

RecursoCombination* tabelaHash[TAMANHO_TABELA_HASH];

int calcularHash(RecursoCombination* combinacao) {
    int hash = 0;
    for (int i = 0; i < 3; i++) {
        hash += combinacao->recursos[i];
    }
    return hash;
}

int compararCombinacoes(RecursoCombination* comb1, RecursoCombination* comb2) {
    for (int i = 0; i < 3; i++) {
        if (comb1->recursos[i] < comb2->recursos[i]) return 1;
        if (comb1->recursos[i] > comb2->recursos[i]) return 0;
    }
    return 0;
}

void inserirCombinacaoUnica(RecursoCombination* combinacao) {
    int indice = calcularHash(combinacao) % TAMANHO_TABELA_HASH;
    tabelaHash[indice] = combinacao;
    combinacao->ultimoMomentoVisto = momentoAtual(); // Obtenha o momento atual
}

void verificarExpansao(RecursoCombination* novaComb) {
    // Recupere a última combinação vista
    RecursoCombination* ultimaComb = tabelaHash[calcularHash(NULL) % TAMANHO_TABELA_HASH];

    // Verifique se a nova combinação está imediatamente após a última
    // Se sim, a próxima expansão está prestes a acontecer
    if (compararCombinacoes(ultimaComb, novaComb)) {
        // Sinalize para os organizadores que a expansão está prestes a acontecer
        informarExpansaoProxima();
    }
}

int momentoAtual() {
    return 0;
}

void informarExpansaoProxima() {
    printf("A expansão está prestes a acontecer.\n");
}
