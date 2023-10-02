/*
Crie uma pasta atividade7 no seu repositório de atividades. Nessa pasta, crie os
arquivos main.c, pilha.h, pilha.c, fila.h e fila.c.

Implemente um caso de uso (de aplicação real) para pilha e outro para fila. O
arquivo main.c deve conter a implementação dos casos de uso. A implementação das
estruturas deve estar nos respectivos arquivos pilha.c e fila.c.

A atividade pode ser desenvolvida em grupo de até 5 pessoas. Todos os membros
devem enviar o link do github como solução da atividade no AVA.

O grupo deverá apresentar a solução na próxima aula 02/10.
*/

/*
Em resumo, fila.h fornece uma interface para operações em uma fila, enquanto
fila.c contém a implementação real dessas operações. Esse padrão de separação
ajuda a esconder os detalhes de implementação e facilita a reutilização do
código.
*/

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Definimos NUM_CAIXAS como o número de caixas de atendimento disponíveis.

#define NUM_CAIXAS 3

// menu e opções para o usuário escolher
void exibirMenu() {
  printf("\n-----------------------------\n");
  printf("Bem-vindo ao Banco UCB!\n");
  printf("Selecione uma opção:\n");
  printf("1. Adicionar cliente à fila\n");
  printf("2. Atender cliente\n");
  printf("3. Mostrar fila de espera\n");
  printf("4. Sair\n");
  printf("-----------------------------\n");
}

int main(int argc, char *argv[]) {
  Fila *filas[NUM_CAIXAS]; // Declaração de um array de filas para atendimento
                           // em diferentes caixas

  for (int i = 0; i < NUM_CAIXAS; i++) {
    filas[i] = criarFila(10); // Crie uma fila com capacidade de 10 clientes
                              // para cada caixa (3 caixas no total)
    if (!filas[i]) { // se o programa não apresentar o comportamento esperado
                     // irá responder com um erro
      printf("Erro: Memória insuficiente.\n");
      return 1;
    }
  }

  int opcao;
  int cliente = 1;

  // Entramos em um loop while (1) para exibir o menu e aguardar a seleção do
  // usuário.

  /*
  No menu, o usuário pode escolher adicionar um cliente à fila de um caixa
  específico (1), atender o próximo cliente em um caixa (2), mostrar a fila de
  espera em todos os caixas (3) ou sair do programa (4).
  */

  while (1) {
    exibirMenu();
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: // Adicionar cliente à fila
      printf("Selecione o caixa (1 a %d): ", NUM_CAIXAS);
      int caixa;
      scanf("%d", &caixa);
      if (caixa >= 1 &&
          caixa <=
              NUM_CAIXAS) { // condição que respeita o número total de caixas
        if (enfileirar(filas[caixa - 1],
                       cliente)) { // irá infileirar o cliente na fila escolhida
                                   // ou não caso a fila esteja cheia;
          printf("Cliente %d entrou na fila do caixa %d.\n", cliente, caixa);
          cliente++;
        } else {
          printf("Erro: Fila do caixa %d está cheia.\n", caixa);
        }
      } else {
        printf("Caixa inválido. Tente novamente.\n");
      }
      break;

    case 2: // Atender cliente
      printf("Selecione o caixa (1 a %d): ", NUM_CAIXAS);
      scanf("%d", &caixa);
      if (caixa >= 1 &&
          caixa <=
              NUM_CAIXAS) { // condição que respeita o número total de caixas
        if (!filaVazia(filas[caixa - 1])) { // se a fila for diferente de vazia
                                            // o if é executado
          int clienteAtendido;
          desenfileirar(filas[caixa - 1],
                        &clienteAtendido); // irá 'atender' o cliente
          printf("Caixa %d: Cliente %d está sendo atendido.\n", caixa + 1,
                 clienteAtendido);
        } else {
          printf("Caixa %d: A fila está vazia. Não há clientes para atender.\n",
                 caixa);
        }
      } else {
        printf("Caixa inválido. Tente novamente.\n");
      }
      break;

    case 3: // Mostrar fila de espera
      for (int i = 0; i <= NUM_CAIXAS; i++) {
        printf("Caixa %d - Fila de espera:\n", i + 1);
        if (!filaVazia(filas[i])) {
          int tamanho = tamanhoFila(filas[i]);
          Fila *copiaFila = criarFila(tamanho);

          // Exibir a fila e fazer uma cópia dela
          if (!filaVazia(filas[i])) {
            int clienteFila;
            desenfileirar(filas[i], &clienteFila);
            printf("Cliente %d\n", clienteFila);
            enfileirar(copiaFila, clienteFila);
          }

          // código está crashando na exibição das filas de espera

          // Restaurar a fila original a partir da cópia
          while (!filaVazia(copiaFila)) {
            int clienteCopia;
            desenfileirar(copiaFila, &clienteCopia);
            enfileirar(filas[i], clienteCopia);
          }

          destruirFila(copiaFila);

        } else {
          printf("A fila está vazia.\n");
        }
      }
      break;

      /*
      O programa continua em execução até que o usuário escolha a opção de sair
      (4), momento em que ele libera a memória alocada para as filas usando
      destruirFila e encerra.
      */

    case 4: // Sair do programa
      for (int i = 0; i < NUM_CAIXAS; i++) {
        destruirFila(filas[i]);
      }
      printf("O programa foi encerrado.\n");
      return 0;

    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}

/*
Em resumo, este programa simula um sistema de filas em um banco com múltiplos
caixas de atendimento, permitindo ao usuário adicionar clientes, atendê-los e
verificar o estado das filas. A estrutura de fila é implementada em fila.h e
fila.c, enquanto main.c lida com a lógica do banco e interação com o usuário.
*/