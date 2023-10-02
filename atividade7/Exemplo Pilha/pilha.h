#ifndef PILHA_H
#define PILHA_H

#define N 5

typedef struct PILHA {
    int dados[N];
    int topo;
} PILHA;

void inicializaPilha(PILHA *p);
void novaPagina(int dado, PILHA *p);
int removerHistorico(PILHA *p);
void historico(PILHA *p);

#endif /* PILHA_H */
