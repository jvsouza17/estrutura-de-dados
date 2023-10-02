/*
Exemplo de Uso de Fila: Sistema de Filas em um Banco
Um exemplo real de uso de uma fila é em um sistema de filas em um banco.
As pessoas entram na fila (fila de espera) e são atendidas na ordem
em que chegaram.
*/

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct Fila {
  int capacidade;
  int inicio;
  int fim;
  Objeto **elementos;
};

/*
Aqui, definimos a estrutura real da fila, que inclui uma capacidade, índices de
início e fim, bem como um array de ponteiros para objetos. Essa estrutura é
definida apenas no arquivo fila.c para ocultar os detalhes de implementação do
usuário do arquivo fila.h.
*/

Fila *criarFila(int capacidade) {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  if (fila == NULL) {
    return NULL;
  }
  fila->capacidade = capacidade;
  fila->inicio = 0;
  fila->fim = -1;
  fila->elementos = (Objeto **)malloc(capacidade * sizeof(Objeto *));
  if (fila->elementos == NULL) {
    free(fila);
    return NULL;
  }
  return fila;
}

void destruirFila(Fila *fila) {
  if (fila != NULL) {
    for (int i = 0; i < fila->capacidade; i++) {
      free(fila->elementos[i]);
    }
    free(fila->elementos);
    free(fila);
  }
}

int enfileirar(Fila *fila, Objeto *objeto) {
  if (fila == NULL || fila->fim - fila->inicio + 1 == fila->capacidade) {
    return 0; // Fila cheia ou inválida
  }
  fila->fim = (fila->fim + 1) % fila->capacidade;
  fila->elementos[fila->fim] = objeto;
  return 1;
}

int desenfileirar(Fila *fila, Objeto **objeto) {
  if (fila == NULL || fila->inicio > fila->fim) {
    *objeto = NULL;
    return 0; // Fila vazia ou inválida
  }
  *objeto = fila->elementos[fila->inicio];
  fila->inicio = (fila->inicio + 1) % fila->capacidade;
  return 1;
}

int tamanhoFila(Fila *fila) {
  if (fila == NULL) {
    return -1; // Fila inválida
  }
  if (fila->inicio <= fila->fim) {
    return fila->fim - fila->inicio + 1;
  } else {
    return fila->capacidade - fila->inicio + fila->fim + 1;
  }
}

/*
As implementações das funções (como criarFila, destruirFila, enfileirar,
desenfileirar, tamanhoFila, filaVazia, etc.) estariam no restante do arquivo
fila.c, mas não as incluí aqui para manter o código mais conciso.
*/

int filaVazia(Fila *fila) { return tamanhoFila(fila) == 0; }