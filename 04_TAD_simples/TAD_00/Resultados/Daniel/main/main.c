#include <stdio.h>
#include "ponto.h"

int main(){
    float x1,y1,x2,y2;
    scanf("%f %f %f %f", &x1,&y1,&x2,&y2);

    Ponto p1, p2;
    p1 = pto_cria(x1,y1);
    p2 = pto_cria(x2,y2);

    printf("%g\n", pto_distancia(p1,p2));

    return 0;    

}