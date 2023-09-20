
#ifndef NAVE_ESPACIAL_H
#define NAVE_ESPACIAL_H

// Defini��o da estrutura do passageiro
typedef struct {
    char nome[50];
    int idade;
    char planetaOrigem[50];
    int identificadorUnico;
} Passageiro;

// Defini��o da estrutura dos recursos transportados
typedef struct {
    char nomeRecurso[50];
    int quantidade;
} Recurso;

// Defini��o da estrutura da nave espacial
typedef struct NaveEspacial {
    int id;
    int prioridade;
    Passageiro *passageiros;
    int numPassageiros;
    Recurso *recursos;
    int numRecursos;
    int (*verificarDados)(struct NaveEspacial *nave);
} NaveEspacial;

int verificarDadosNave(NaveEspacial *nave);

#endif

