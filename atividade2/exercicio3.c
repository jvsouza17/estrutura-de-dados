#include <stdio.h>
#include <string.h>
#include <locale.h>


int buscaString(const char *array[], int tamanho, const char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1;  
        }
    }
    return 0; 
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    const char *array[tamanho];
    printf("Digite as strings do array:\n");
    for (int i = 0; i < tamanho; i++) {
        char buffer[100]; 
        scanf("%s", buffer);
        array[i] = strdup(buffer); 
    }

    char busca[100];
    printf("Digite a string de busca: ");
    scanf("%s", busca);

    int resultado = buscaString(array, tamanho, busca);
    if (resultado == 1) {
        printf("A string de busca foi encontrada no array.\n");
    } else {
        printf("A string de busca não foi encontrada no array.\n");
    }

    return 0;
}