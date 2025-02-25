#include <stdio.h>
#include "evento.h"
#include <string.h>

void cadastrarEvento(Evento* eventos, int* numEventos){
    scanf("%s", eventos[*numEventos].nome);
    scanf("%d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    (*numEventos)++;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    printf("Eventos cadastrados:\n");
    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int indice;
    scanf("%d", &indice);
    if(indice >= *numEventos){
        printf("Indice invalido!\n");
        return;
    }
    scanf("%d %d %d", &eventos[indice].dia, &eventos[indice].mes, &eventos[indice].ano);
    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA >= *numEventos || *indiceB >= *numEventos){
        printf("Indices invalidos!\n");
        return;
    }
    
    Evento aux;
    strcpy(aux.nome, eventos[*indiceA].nome);
    aux.dia = eventos[*indiceA].dia;
    aux.mes = eventos[*indiceA].mes;
    aux.ano = eventos[*indiceA].ano;

    strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);
    eventos[*indiceA].dia = eventos[*indiceB].dia;
    eventos[*indiceA].mes = eventos[*indiceB].mes;
    eventos[*indiceA].ano = eventos[*indiceB].ano;

    strcpy(eventos[*indiceB].nome, aux.nome);
    eventos[*indiceB].dia = aux.dia;
    eventos[*indiceB].mes = aux.mes;
    eventos[*indiceB].ano = aux.ano;

    printf("Eventos trocados com sucesso!\n");
}