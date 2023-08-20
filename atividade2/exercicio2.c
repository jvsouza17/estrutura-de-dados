#include <stdio.h>
#include <locale.h>


void encontraMinMax(int array[], int tamanho, int *menor, int *maior) {
    if (tamanho <= 0) {
        return; 
    }

    *menor = array[0];
    *maior = array[0];

    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    int menor, maior;
    encontraMinMax(array, tamanho, &menor, &maior);
    printf("O menor elemento do array é: %d\n", menor);
    printf("O maior elemento do array é: %d\n", maior);

    return 0;
}