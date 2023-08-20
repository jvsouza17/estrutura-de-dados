#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* multiplicaArrays(const int array1[], const int array2[], int tamanho) {
    int *resultado = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        resultado[i] = array1[i] * array2[i];
    }

    return resultado;
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    int tamanho;

    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int array1[tamanho];
    int array2[tamanho];

    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array2[i]);
    }

    int *resultado = multiplicaArrays(array1, array2, tamanho);

    printf("Resultado da multiplicação dos arrays:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");


    return 0;
}