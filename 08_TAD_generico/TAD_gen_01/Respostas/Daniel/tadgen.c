#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic{
    void* array;
    int tam;
    Type tipo;
};


/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* t = (tGeneric*) malloc(sizeof(tGeneric));
    t->tam = numElem;
    t->tipo = type;

    switch(t->tipo){
        case FLOAT:
            t->array = malloc(t->tam * sizeof(float));
            break;
        
        case INT:
            t->array = malloc(t->tam * sizeof(int));
            break;
    }

    return t;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    if(gen != NULL){
        free(gen->array);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    switch(gen->tipo){
        case INT:
            for(int i = 0; i < gen->tam; i++){
                scanf("%d", (int*)gen->array + i);
            }
            break;

        case FLOAT:
            for(int i = 0; i < gen->tam; i++){
                scanf("%f", (float*)gen->array + i);
            }
            break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    switch(gen->tipo){
        case INT:
            for(int i = 0; i < gen->tam; i++){
                printf("%d ", ((int*)gen->array)[i]);
            }
            break;

        case FLOAT:
            for(int i = 0; i < gen->tam; i++){
                printf("%.2f ", ((float*)gen->array)[i]);
            }
            break;
    }
    printf("\n");
}