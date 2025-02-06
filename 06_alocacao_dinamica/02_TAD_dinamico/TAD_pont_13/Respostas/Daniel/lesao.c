#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

/**
 * @brief Cria uma estrutura do tipo lesão
 * 
 * @return ponteiro para estrutura do tipo lesão
 */ 
tLesao* CriaLesao(){
    tLesao* lesao = (tLesao*) malloc(sizeof(tLesao));
    lesao->id = (char*) malloc(TAM_ID * sizeof(char));
    lesao->diagnostico = (char*) malloc(TAM_DIAG * sizeof(char));
    lesao->regiao_corpo = (char*) malloc(TAM_REG * sizeof(char));
    return lesao;
}

/**
 * @brief Lê informações sobre uma lesão da entrada padrão.
 * 
 * @param l ponteiro para lesão que terá seus dados preenchidos
 */
void LeLesao(tLesao* l){
    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diagnostico);
    scanf("%[^\n]\n", l->regiao_corpo);
    scanf("%d\n", &l->chance_malignidade);
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tLesao.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao a ser liberada.
 */
void LiberaLesao(tLesao* l){
    if(l != NULL){
        free(l->id);
        free(l->diagnostico);
        free(l->regiao_corpo);
        free(l);
    }
}

/**
 * @brief Retorna o identificador da lesão.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna uma string contendo o identificador da lesão.
 */
char* GetIdLesao(tLesao* l){
    return l->id;
}

/**
 * @brief Verifica se a lesão precisa de cirurgia.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna 1 se a lesão precisa de cirurgia e 0 caso contrário.
 */
int PrecisaCirurgiaLesao(tLesao* l){
    return (l->chance_malignidade > 50);
}