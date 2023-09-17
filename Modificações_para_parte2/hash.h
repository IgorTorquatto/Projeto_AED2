#ifndef HASH_H
#define HASH_H

typedef struct RecursoCombination {
    int recursos[3]; // IDs dos recursos em ordem lexicográfica
    int ultimoMomentoVisto; // Momento em que foi vista pela última vez
} RecursoCombination;

int calcularHash(RecursoCombination* combinacao);
int compararCombinacoes(RecursoCombination* comb1, RecursoCombination* comb2);
void inserirCombinacaoUnica(RecursoCombination* combinacao);
void verificarExpansao(RecursoCombination* novaComb);
int momentoAtual();
void informarExpansaoProxima();

#endif
