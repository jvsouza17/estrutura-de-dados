#include "pilha.h"
#include <stdio.h>

void inicializaPilha(PILHA *p) {
    int i;
    for (i = 0; i < N; i++) {
        p->dados[i] = 0;
    }
    p->topo = 0;
}

void novaPagina(int dado, PILHA *p) {
    if (p->topo == N) {
        printf("MAX\n");
        return;
    } else {
        p->dados[p->topo] = dado;
        p->topo++;
        return;
    }
}

int removerHistorico(PILHA *p) {
    if (p->topo == 0) {
        printf("Historico Limpo\n");
        return 1;
    } else {
        p->topo--;
        return p->dados[p->topo];
    }
}

void historico(PILHA *p) {
    int i;
    printf("Historico de navegacao: \n");
    for (i = 0; i < p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
}
