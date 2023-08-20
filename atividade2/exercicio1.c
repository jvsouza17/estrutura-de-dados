#include <stdio.h>
#include <locale.h>

int somaArray(int array[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
    int tamanho;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);
    
    int array[tamanho];
    
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }
    
    int resultado = somaArray(array, tamanho);
    printf("A soma dos elementos do array é: %d\n", resultado);
    
    return 0;
}