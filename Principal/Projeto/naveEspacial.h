#ifndef NAVE_ESPACIAL_H
#define NAVE_ESPACIAL_H

// Definição da estrutura do passageiro
typedef struct {
    char nome[50];
    int idade;
    char planetaOrigem[50];
    int identificadorUnico;
} Passageiro;

//Definição da estrutura dos recursos transportados
typedef struct {
    char nomeRecurso[50];
    int quantidade;
} Recurso;

// Definição da estrutura da nave espacial
typedef struct NaveEspacial {
    int id;
    int prioridade;
    Passageiro *passageiros;
    int numPassageiros;
    Recurso *recursos;
    int numRecursos;
    int (*verificarDados)(struct NaveEspacial *nave);
} NaveEspacial;

typedef struct {
    char permutacao[6][50];
} Permutacao;


int verificarDadosNave(NaveEspacial *nave);
int sao_permutacoes_iguais(Permutacao p1, Permutacao p2);

#endif
