#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ponto{
    int x;
    float y;
    char* label;
} Ponto;


int main(int arfc, char* argv[]){
    Ponto p;

    p.x = 1;
    p.y = 1.8;
    p.label = "TEXTO 1";
    p.label = malloc(sizeof(char) * 5);
    strcpy(p.label, "TEXTO 1\n");


    printf("(%d, %f) %s", p.x, p.y, (p.label++));
    printf("\n%p", p.label);

    return 0;
}