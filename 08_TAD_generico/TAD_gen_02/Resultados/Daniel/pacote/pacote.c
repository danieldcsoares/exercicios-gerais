#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote{
    void *mensagem;
    int somaDeVerificacao;
    Type tipo;
    int tamanho;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote* pacote = (tPacote*) malloc(sizeof(tPacote));
    pacote->tipo = type;
    pacote->tamanho = numElem;

    switch(pacote->tipo){
        case INT:
            pacote->mensagem = malloc(pacote->tamanho * sizeof(int));
            break;
        
        case CHAR:
            pacote->mensagem = malloc(pacote->tamanho * sizeof(char));
            break;
    }

    return pacote;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    if(pac != NULL){
        free(pac->mensagem);
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    switch(pac->tipo){
        case INT:
            for(int i = 0; i < pac->tamanho; i++){
                scanf("%d", (int*)pac->mensagem + i);
            }
            break;

        case CHAR:
            getchar();
            for(int i = 0; i < pac->tamanho; i++){
                scanf("%c", (char*)pac->mensagem + i);
            }
            break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->somaDeVerificacao);
    switch(pac->tipo){
        case INT:
            for(int i = 0; i < pac->tamanho; i++){
                printf("%d ", ((int*)pac->mensagem)[i]);
            }
            break;

        case CHAR:
            printf("%s", (char*)pac->mensagem);
            break;
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    int soma = 0;
    for(int i = 0; i < pac->tamanho; i++){
        if(pac->tipo == INT){
            soma = soma + ((int*)pac->mensagem)[i];
        }
        else{
            soma = soma + ((char*)pac->mensagem)[i];
        }
    }
    pac->somaDeVerificacao = soma;
}