#include <stdio.h>
#include "tad-pilha.h"

int main(void) 
{
  TipoItem item;
  TipoPilha pilha;
  int capacidade, valor, op = NAO_EXISTE;

  while (op != SAIR)
  {
    menu();
    scanf("%d", &op);

    switch(op)
    {
      case 1:
        printf("Digite a Capacidade da Pilha:\n");
        scanf("%d", &capacidade);

        InicializarPilha(&pilha, capacidade);
        break;
      
      case 2:
        printf("Digite o valor que deseja inserir na pilha:\n");
        scanf("%d", &valor);

        item.chave = valor;

        Empilhar(&pilha, item);
        break;
      
      case 3:
        ImprimePilha(pilha);
        break;
      
      case 4:
        Desempilhar(&pilha, &item);
        break;

      case 5:
        printf("Exibindo Topo\n");
        printf("==============\n\n");
        ExibirTopo (pilha);
        break;
      
      case SAIR:
        printf("Obrigado por usar o Program\n");
        printf("Saindo...\n\n");
        break;
      
      default:
        printf("Operação Invalidade\n\n");
        break;
    }
  }
}