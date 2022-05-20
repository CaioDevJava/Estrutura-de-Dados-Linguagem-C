#include <stdio.h>
#include "tad-arvore.h"

int main(void) {
  TipoNo raiz;
  TipoChave chave;
  int capacidade, valor, op = -1;

  while(op != 0)
  {
    menu();
    scanf("%d", &op);

    switch(op)
    {
      case 1:
        InicializarArvore (&raiz, capacidade);
        break;

      case 2:
        printf("Digite o valor que deseja inserir:\n");
        scanf("%d", &chave);
        inserirNovoNo(&raiz, chave);
        break;

      case 3:
        imprimirNoCorrente(raiz);
        break;
      
      case 0:
        
        break;

      default:
        printf("Operação Invalida!\n\n");
        break;
    }
  }
}