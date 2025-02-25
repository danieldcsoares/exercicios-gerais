#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct data{
    int dia,mes,ano;
};

/**
 * @brief Lê uma data da entrada padrão.
 * @return Um ponteiro para a data lida.
 */
tData* LeData(){
    tData* data = (tData *) malloc(sizeof(tData));
    scanf("%d/%d/%d\n", &data->dia,&data->mes,&data->ano);
    return data;
}

/**
 * @brief Cria uma data com o dia, mês e ano fornecidos. Se a alocação falhar, o programa é encerrado.
 * @param dia O dia da data.
 * @param mes O mês da data.
 * @param ano O ano da data.
 * @return Um ponteiro para a data criada.
 */
tData* CriaData(int dia, int mes, int ano){
    tData* data = (tData *) malloc(sizeof(tData));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

/**
 * @brief Libera a memória alocada para uma data.
 * @param d Um ponteiro para a data a ser liberada.
 */
void LiberaData(tData* d){
    if(d != NULL){
        free(d);
    }
}

/**
 * @brief Calcula a idade de uma pessoa com base na data de nascimento e em uma data para calcular a idade.
 * @param nascimento Um ponteiro para a data de nascimento da pessoa.
 * @param diacalc Um ponteiro para a data para calcular a idade.
 * @return A idade da pessoa.
 */
int CalculaIdadeData(tData* nascimento, tData* diacalc){
    int diff = diacalc->ano - nascimento->ano;

    if(diacalc->mes < nascimento->mes || (diacalc->mes == nascimento->mes && diacalc->dia < nascimento->dia)){
        diff-=1;
    }

    return diff;
}

/**
 * @brief Imprime uma data na saída padrão.
 * @param d Um ponteiro para a data a ser impressa.
 */
void ImprimeData(tData* d){
    printf("%d/%d/%d\n", d->dia,d->mes,d->ano);
}