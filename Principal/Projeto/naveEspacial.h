#ifndef NAVE_ESPACIAL_H
#define NAVE_ESPACIAL_H
#define MAX_RECURSOS 6
#define MAX_NAVES 100

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

//Começo - Parte II
//Estrutura de dados para rastrear as naves que transportam os mesmos recursos:
typedef struct {
    char* recursosComuns[MAX_RECURSOS];
    char* nomesRecursosComuns[MAX_NAVES];
    int numRecursosComuns;
    int navesComRecursosIguais[MAX_NAVES];
    int numNavesComRecursosIguais;
} RecursosIguais;
// Fim - Parte II

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

int verificarDadosNave(NaveEspacial *nave);

#endif
