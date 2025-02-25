#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    printf("tad_gen_01\n");
    int tamanho;
    Type tipo;
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d", &tipo, &tamanho);
    
    tGeneric* generico = CriaGenerico(tipo,tamanho);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);

    return 0;

}