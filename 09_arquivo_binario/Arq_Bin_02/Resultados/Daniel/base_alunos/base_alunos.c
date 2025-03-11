#include <stdio.h>
#include "base_alunos.h"
#include "aluno.h"
#include <string.h>
#include <stdlib.h>

struct BaseAlunos{
    int numAlunos;
    tAluno** alunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos* base = (tBaseAlunos*) malloc(sizeof(tBaseAlunos));

    base->numAlunos = 0;

    return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    if(baseAlunos != NULL){
        for(int i = 0; i < baseAlunos->numAlunos; i++){
            DestruirAluno(baseAlunos->alunos[i]);
        }
        free(baseAlunos->alunos);
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE* fp = fopen(nomeArquivo, "rb");

    fread(&baseAlunos->numAlunos, sizeof(int), 1, fp);
    baseAlunos->alunos = (tAluno**) malloc(baseAlunos->numAlunos * sizeof(tAluno*));

    for(int i = 0; i < baseAlunos->numAlunos; i++){
        baseAlunos->alunos[i] = LeAluno(fp);
    }

    fclose(fp);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float soma = 0;
    for(int i = 0; i < baseAlunos->numAlunos; i++){
        soma = soma + GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return soma / baseAlunos->numAlunos;
}