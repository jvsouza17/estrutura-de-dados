/*
typedef struct Fila Fila; e typedef struct Objeto Objeto;: Aqui, estamos
declarando as estruturas Fila e Objeto sem definir seus detalhes. Os detalhes de
implementação estão em outro lugar.
*/

typedef struct Fila Fila;
typedef struct Objeto Objeto;

Fila *criarFila(
    int capacidade); // Esta função cria uma fila com uma capacidade x
                     // especificada e retorna um ponteiro para a fila criada.

void destruirFila(Fila *fila); // Esta função libera a memória alocada para a
                               // fila quando ela não é mais necessária.

int enfileirar(Fila *fila, Objeto *objeto); // Adiciona um objeto à fila.

int desenfileirar(Fila *fila,
                  Objeto **objeto); // Remove um objeto da fila e retorna-o
                                    // através de um ponteiro.

int tamanhoFila(Fila *fila); // Retorna o número de elementos na fila.

int filaVazia(Fila *fila); // Verifica se a fila está vazia.
