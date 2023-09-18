#include <stdio.h>

int main() {
    FILE *arquivo;
    int valoresX[100];
    float valoresY[100];
    int contador = 0;
    float somaX = 0.0, somaY = 0.0, somaXY = 0.0, somaXQuadrado = 0.0;
    

	// Abrir o arquivo com os dados e verificar se está vazio
    arquivo = fopen("dados.csv", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    while (contador < 100 && fscanf(arquivo, "%d,%f", &valoresX[contador], &valoresY[contador]) == 2) {
        contador++;
    }

    fclose(arquivo);

    for (int i = 0; i < contador; i++) {
        printf("Linha %d: X = %d | Y = %.2f\n", i + 1, valoresX[i], valoresY[i]);
    }

    for (int i = 0; i < contador; i++) {
        somaX += valoresX[i];
    } 

    float mediaX = somaX / contador;

        printf("\n\nMédia dos valores de X: %.2f\n", mediaX);

    for (int i = 0; i < contador; i++) {
        somaY += valoresY[i];
    } 

    float mediaY = somaY / contador;

        printf("\nMédia dos valores de Y: %.2f\n", mediaY);

    
    for (int i = 0; i < contador; i++) {
        somaXY += valoresX[i] * valoresY[i];
        somaXQuadrado += valoresX[i] * valoresX[i];
    } 

    float coeficienteAngular = (contador * somaXY - somaX * somaY) / (contador * somaXQuadrado - somaX * somaX);
    printf("\nCoeficiente Angular (Inclinação): %.2f\n", coeficienteAngular);

    float interceptacao = mediaY - (coeficienteAngular * mediaX);
    printf("\nCoeficiente linear (Interceptação): %.2f\n", interceptacao);

    printf("\nEquação da Regressão Linear: Y = %.2fX + %.2f\n", coeficienteAngular, interceptacao);

    return 0;
}
