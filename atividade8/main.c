#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {
    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL))));
    No* n3 = no('U', NULL);
    
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    
    char valor_busca = 'D';
    if (lista_verificar_existencia(n0, valor_busca)) {
        printf("\nO valor '%c' existe na lista.", valor_busca);
    } else {
        printf("\nO valor '%c' não existe na lista.", valor_busca);
    }
    
    int ocorrencias = lista_verificar_ocorrencias(n0, valor_busca);
    printf("\n'%c' ocorre %d vezes na lista.", valor_busca, ocorrencias);
    
    printf("\nLista Inversa: ");
    lista_imprimir_inversa(n0);
    
    // Inserir um novo nó na posição i
    lista_inserir_no_i(n0, 2); // Insere um nó na terceira posição (índice 2)
    
    // Remover um nó na posição i
    lista_remover_no_i(n0, 1); // Remove o nó na segunda posição (índice 1)
    
    // Remover todos os nós com um valor específico
    valor_busca = 'X';
    lista_remover_no(n0, valor_busca); // Remove todos os nós com valor 'X'
    
    lista_imprimir(n0);
    
    // Libera a memória
    lista_liberar(n0);
    n0 = NULL;
    
    return 0;
}