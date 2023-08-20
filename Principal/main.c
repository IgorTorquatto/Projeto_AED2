#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "naveEspacial.h"
#include "heap.h"

int main() {
	setlocale(LC_ALL,"Portuguese"); // Para corrigir os problemas de acentuação
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    Heap *heap = criarHeap(10);
    int *a;

    // Exemplo de criação de uma nave espacial
    
    Passageiro passageiros[2] = { //Quantidade de passageiros a ser criados
        {"Passageiro1", 30, "Terra", 1}, //Preenchendo todos os atributos do scruct
        {"Passageiro2", 25, "Marte", 2}
    };

    Passageiro familia[4] = {
        {"Anais", 20, "Lua", 3},
        {"Luke",22,"Lua",4},
        {"Pedro", 54, "Lua", 5},
        {"Ana",55,"Lusa",6}
    };

    Passageiro grupo[3] = {
        {"Ana",26,"Marte",7},
        {"Pedro",22,"Terra",8},
        {"Julia",19,"Lua",9}
    };

    Recurso recursos[2] = {
        {"Comida", 100},
        {"Água", 50}
    };

    Recurso itens[4] = {
        {"Comida", 100},
        {"Água", 50},
        {"Cilindro de oxigenio",2},
        {"Tecido de algodao",30}
    };

	//Criação das naves
    NaveEspacial nave = {1,15, passageiros, 2, recursos, 2, verificarDadosNave}; // id,prioridade,passageiros,num_passageiro,recursos,num_recursos,função de verificação
    NaveEspacial espac = {2,7,familia,4,itens,4,verificarDadosNave};
    NaveEspacial nova = {3,9,familia,4,recursos,2,verificarDadosNave};
    NaveEspacial ult = {4,2,grupo,3,itens,4,verificarDadosNave};
    NaveEspacial uma = {5,7,grupo,3,recursos,4,verificarDadosNave};
    NaveEspacial ume = {6,-7,grupo,3,recursos,4,verificarDadosNave};
    
    
	//Inserção das naves no heap
    inserirDesordenado(heap, nave);
    inserirDesordenado(heap, espac);
    inserirDesordenado(heap,ult);
    inserirDesordenado(heap, nova);
    inserirDesordenado(heap,uma);
    inserirDesordenado(heap,ume);

    //Impressão
    imprimir(heap);

    //Construção da heap
    constroiHeap(heap);

    imprimir(heap);

	//Liberação
    free(heap->array);
    free(heap);

    return 0;
}
