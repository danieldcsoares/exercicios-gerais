#include <stdio.h>
#include <stdlib.h>
#include "data.h"

tData* LeData(){
    tData* data = (tData*) malloc(sizeof(tData));;
    scanf("%d/%d/%d\n", &data->dia,&data->mes,&data->ano);
    return data;
}

tData* CriaData(int dia, int mes, int ano){
    tData* data = (tData*) malloc(sizeof(tData));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

void LiberaData(tData* d){
    if(d != NULL){
        free(d);
    }
}

int CalculaIdadeData(tData* nascimento, tData* diacalc){
    int diff = diacalc->ano - nascimento->ano;

    if(diacalc->mes < nascimento->mes || (diacalc->mes == nascimento->mes && diacalc->dia < nascimento->dia)){
        diff-=1;
    }

    return diff;
}

void ImprimeData(tData* d){
    printf("%d/%d/%d\n", d->dia,d->mes,d->ano);
}