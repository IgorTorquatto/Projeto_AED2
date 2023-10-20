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
enum RecursoID {
    AGUA = 0,
    GASOLINA = 1,
    COMIDA = 2,
    REMEDIOS = 3,
    ARMAS = 4,
    ROUPA = 5
};

typedef struct {
    int recursoID;
    char nomeRecurso[50];
    int quantidade;
} Recurso;

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
