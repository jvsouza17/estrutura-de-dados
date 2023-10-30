#include <stdio.h>
#include "tabela_hash.h"

int main() {
    // Demonstração do uso da tabela hash
    hash_table_put("chave1", "0");
    hash_table_put("chave2", "1");

    char* valor1 = hash_table_get("chave1");
    char* valor2 = hash_table_get("chave2");

    printf("Valor associado a chave 1: %s\n", valor1);
    printf("Valor associado a chave 2: %s\n", valor2);

    if (hash_table_contains("chave1")) {
        printf("A chave 1 esta na tabela.\n");
    } else {
        printf("A chave 1 não esta na tabela.\n");
    }

    hash_table_remove("chave1");

    if (hash_table_contains("chave1")) {
        printf("A chave 1 esta na tabela.\n");
    } else {
        printf("A chave 3 nao esta na tabela.\n");
    }

    return 0;
}