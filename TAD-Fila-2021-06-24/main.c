#include <stdio.h>
#include "tad-fila.h"

int main(void) 
{
  TipoFila fila;
  TipoItem item;
  int capacidade, valor, op = -1;

  while(op != 0)
  {
    menu();
    scanf("%d", &op);

    switch(op)
    {
      case 1:
        printf("Digite a capacidade deseja:\n");
        scanf("%d", &capacidade);

        InicializarFila(&fila, capacidade);
        break;
      
      case 2:
        printf("Digite o valor que deseja inserir na Chave:\n");
        scanf("%d", &valor);

        item.chave = valor;

        Enfileirar(&fila, item);
        break;
      
      case 3:
        ImprimeFila(fila);
        break;
      
      case 4:
        Desenfileirar(&fila, &item);
        break;
      
      case 0:
        printf("Obrigado por usar nosso programa!\n");
        printf("Saindo...\n\n");
        break;
      
      default:
        printf("INFO: Operação Invalida!\n\n");
        break;
    }
  }
}