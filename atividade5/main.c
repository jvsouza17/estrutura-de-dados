#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_PALAVRA_LEN 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char *palavras[100]; // Suponha que haverá no máximo 100 palavras
    int num_palavras = 0;

    char palavra[MAX_PALAVRA_LEN]; // Suponha que cada palavra terá no máximo 100 caracteres
    while (fscanf(entrada, "%s", palavra) != EOF) {
        palavras[num_palavras] = (char *)malloc((strlen(palavra) + 1) * sizeof(char));
        strcpy(palavras[num_palavras], palavra);
        num_palavras++;
    }

    fclose(entrada);

    // Ordena as palavras
    bubbleSort(palavras, num_palavras);

    // Cria o arquivo de saída
    FILE *saida = fopen("arq_palavras_ordenado.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    // Escreve as palavras ordenadas no arquivo de saída
    for (int i = 0; i < num_palavras; i++) {
        fprintf(saida, "%s\n", palavras[i]);
        free(palavras[i]);
    }

    fclose(saida);

    return 0;
}