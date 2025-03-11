#include <stdio.h>
#include "aluno.h"
#include <string.h>
#include <stdlib.h>

#define MAX_TAM_NOME 100
#define MAX_TAM_DATA 11
#define MAX_TAM_CURSO 50


struct Aluno{
    char* nome;
    char* dataNascimento;
    char* curso;
    int periodo;
    float coeficienteRendimento;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno* aluno = (tAluno*) malloc(sizeof(tAluno));
    aluno->nome = (char*) malloc(sizeof(char) * MAX_TAM_NOME);
    aluno->dataNascimento = (char*) malloc(sizeof(char) * MAX_TAM_DATA);
    aluno->curso = (char*) malloc(sizeof(char) * MAX_TAM_CURSO);

    strcpy(aluno->nome,nome);
    strcpy(aluno->dataNascimento,dataNascimento);
    strcpy(aluno->curso,curso);
    aluno->periodo = periodo;
    aluno->coeficienteRendimento = coeficienteRendimento;

    return aluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    if(aluno != NULL){
        free(aluno->nome);
        free(aluno->dataNascimento);
        free(aluno->curso);
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
    /*char caminho[100];
    scanf("%[^\n]\n", caminho);

    arquivo_binario = fopen(caminho, "rb");

    int nAlunos;
    fread(&nAlunos, sizeof(int), 1, arquivo_binario);

    for(int i = 0; i < nAlunos, i++){

    }

    fclose(arquivo_binario);*/

    tAluno* aluno = CriarAluno("vazio", "vazio", "vazio", 0, 0);
    fread(aluno->nome, sizeof(char), MAX_TAM_NOME, arquivo_binario);
    fread(aluno->dataNascimento, sizeof(char), MAX_TAM_DATA, arquivo_binario);
    fread(aluno->curso, sizeof(char), MAX_TAM_CURSO, arquivo_binario);
    fread(&aluno->periodo, sizeof(int), 1, arquivo_binario);
    fread(&aluno->coeficienteRendimento, sizeof(float), 1, arquivo_binario);

    return aluno;

}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->coeficienteRendimento;
}