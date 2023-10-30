#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
} 

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int count = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            count++;
        }
        atual = atual->proximo;
    }
    return count;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo == NULL) {
        return; 
    }
    No* atual = L->proximo;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    while (atual != L) {
        printf("%c ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

void lista_inserir_no_i(No* L, int i, char valor) {
    int pos = 0;
    No* atual = L;
    while (pos < i && atual->proximo != NULL) {
        atual = atual->proximo;
        pos++;
    }
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

void lista_remover_no_i(No* L, int i) {
    int pos = 0;
    No* atual = L;
    while (pos < i && atual->proximo != NULL) {
        atual = atual->proximo;
        pos++;
    }
    if (atual->proximo == NULL) {
        return; 
    }
    No* noRemovido = atual->proximo;
    atual->proximo = noRemovido->proximo;
    free(noRemovido);
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* noRemovido = atual->proximo;
            atual->proximo = noRemovido->proximo;
            free(noRemovido);
        } else {
            atual = atual->proximo;
        }
    }
}

void lista_inserir_no_ordenado(No* L, No* no) {
    No* atual = L;
    while (atual->proximo != NULL && ((float)atof(atual->proximo->valor) < (float)atof(no->valor))) {
        atual = atual->proximo;
    }
    no->proximo = atual->proximo;
    atual->proximo = no;
}