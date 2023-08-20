#include <stdio.h>
#include <locale.h>

int contaNumero(int array[], int tamanho, int busca) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == busca) {
            contador++;
        }
    }
    return contador;
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

    int busca;
    printf("Digite o número de busca: ");
    scanf("%d", &busca);

    int quantidade = contaNumero(array, tamanho, busca);
    printf("O número %d aparece %d vezes no array.\n", busca, quantidade);

    return 0;
}