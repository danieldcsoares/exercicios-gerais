#include <stdio.h>
#include "base_alunos.h"
#include "aluno.h"
#include <string.h>
#include <stdlib.h>

int main(){
    char caminho[100];
    scanf("%[^\n]\n", caminho);

    tBaseAlunos* base = CriarBaseAlunos();
    LerBaseAlunos(base, caminho);
    
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;

}