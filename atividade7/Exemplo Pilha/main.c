#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    PILHA p1;

    inicializaPilha(&p1);

    novaPagina(1, &p1);
    novaPagina(2, &p1);
    novaPagina(3, &p1);
    novaPagina(4, &p1);
    novaPagina(5, &p1);

    historico(&p1);

    printf("\n");
    system("pause");
    system("cls");

    printf("Apagar Historico: \n");

    printf("Removendo do Historico: %d\n", removerHistorico(&p1));
    printf("Removendo do Historico: %d\n", removerHistorico(&p1));
    printf("Removendo do Historico: %d\n", removerHistorico(&p1));
    printf("Removendo do Historico: %d\n", removerHistorico(&p1));
    printf("Removendo do Historico: %d\n", removerHistorico(&p1));
    printf("\n");

    removerHistorico(&p1);

    return 0;
}
