#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void lista_inserir_no_i(No** L, int i, char valor) {
    if (i < 0) {
        printf("Índice inválido. Insira um índice não negativo.\n");
        return;
    }

    if (i == 0) {
        No* novo_no = no(valor, *L);
        *L = novo_no;
        return;
    }

    int indice_atual = 0;
    No* no_atual = *L;
    while (no_atual != NULL && indice_atual < i - 1) {
        no_atual = no_atual->proximo_no;
        indice_atual++;
    }

    if (no_atual == NULL) {
        printf("O índice %d excede o tamanho da lista. O nó não foi inserido.\n", i);
        return;
    }

    No* novo_no = no(valor, no_atual->proximo_no);
    no_atual->proximo_no = novo_no;
}

void lista_remover_no_i(No** L, int i) {
    if (i < 0) {
        printf("Índice inválido. Insira um índice não negativo.\n");
        return;
    }

    if (i == 0) {
        No* no_a_remover = *L;
        if (no_a_remover != NULL) {
            *L = (*L)->proximo_no;
            free(no_a_remover);
        }
        return;
    }

    int indice_atual = 0;
    No* no_anterior = NULL;
    No* no_atual = *L;
    while (no_atual != NULL && indice_atual < i) {
        no_anterior = no_atual;
        no_atual = no_atual->proximo_no;
        indice_atual++;
    }

    if (no_atual == NULL) {
        printf("O índice %d excede o tamanho da lista. Nenhum nó foi removido.\n", i);
        return;
    }

    no_anterior->proximo_no = no_atual->proximo_no;
    free(no_atual);
}

void lista_remover_no(No** L, char valor_busca) {
    No* no_anterior = NULL;
    No* no_atual = *L;

    while (no_atual != NULL) {
        if (no_atual->valor == valor_busca) {
            if (no_anterior == NULL) {
                // Se o nó a ser removido for o primeiro da lista
                *L = no_atual->proximo_no;
            } else {
                no_anterior->proximo_no = no_atual->proximo_no;
            }
            free(no_atual);
            no_atual = no_anterior->proximo_no;
        } else {
            no_anterior = no_atual;
            no_atual = no_atual->proximo_no;
        }
    }
}