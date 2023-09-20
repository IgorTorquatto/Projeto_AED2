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
    // Recupere a �ltima combina��o vista
    RecursoCombination* ultimaComb = tabelaHash[calcularHash(NULL) % TAMANHO_TABELA_HASH];

    // Verifique se a nova combina��o est� imediatamente ap�s a �ltima
    // Se sim, a pr�xima expans�o est� prestes a acontecer
    if (compararCombinacoes(ultimaComb, novaComb)) {
        // Sinalize para os organizadores que a expans�o est� prestes a acontecer
        informarExpansaoProxima();
    }
}

int momentoAtual() {
    return 0;
}

void informarExpansaoProxima() {
    printf("A expans�o est� prestes a acontecer.\n");
}

