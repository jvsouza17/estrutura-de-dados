#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

// Definindo a estrutura de um nó na tabela hash
typedef struct Node {
    char* chave;
    char* dado;
    struct Node* prox;
} Node;

// Array de ponteiros para nós
Node* table[TABLE_SIZE];

// Função de hash simples para calcular o índice
int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

// Função para inserir um par chave-valor na tabela hash
void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);

    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->chave = strdup(chave);
    novo_node->dado = strdup(dado);
    novo_node->prox = NULL;

    if (table[index] == NULL) {
        table[index] = novo_node;
    } else {
        Node* atual = table[index];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_node;
    }
}

// Função para obter o valor associado a uma chave na tabela hash
char* hash_table_get(char* chave) {
    int index = hash(chave);

    Node* atual = table[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->prox;
    }

    return NULL;
}

// Função para verificar se a chave está na tabela hash
int hash_table_contains(char* chave) {
    int index = hash(chave);

    Node* atual = table[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1; // Chave encontrada
        }
        atual = atual->prox;
    }

    return 0; // Chave não encontrada
}

// Função para remover um par chave-valor da tabela hash
void hash_table_remove(char* chave) {
    int index = hash(chave);

    Node* atual = table[index];
    Node* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                table[index] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual->chave);
            free(atual->dado);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}
