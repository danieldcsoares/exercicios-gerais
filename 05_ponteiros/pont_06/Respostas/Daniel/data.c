#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    if(mes > 12){
        mes = 12;
    }
    
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    if(data->dia > InformaQtdDiasNoMes(data)){
        data->dia = InformaQtdDiasNoMes(data);
    }
}

void LeData( tData *data ){
    int dia,mes,ano;
    scanf("%d %d %d\n", &dia, &mes, &ano);
    InicializaDataParam(dia,mes,ano,data);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if(data->ano % 100 == 0){
        if(data->ano % 400 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(data->ano % 4 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12){
        return 31;
    }
    if(data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11){
        return 30;
    }
    if(data->mes == 2){
        if(EhBissexto(data)){
            return 29;
        }
        else{
            return 28;
        }
    }
}

void AvancaParaDiaSeguinte( tData *data ){
    if(data->dia < InformaQtdDiasNoMes(data)){
        data->dia++;
    }
    else{
        if(data->mes < 12){
            data->mes++;
            data->dia = 01;
        }
        else{
            data->ano++;
            data->dia = 01;
            data->mes = 01;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){
    return (data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano);
}