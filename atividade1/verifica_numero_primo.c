#include<stdio.h>
#include <locale.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    int num, i, resultado = 0;
 
    num = atoi(argv[1]);
 
 for (i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
       resultado++;
       break;
    }
 }
 
 if (resultado == 0)
    printf("%d é um número primo\n", num);
 else
    printf("%d não é um número primo\n", num);
 
 return 0;
}








