#include <stdio.h>
#include "TAD-ListaDup.h"

int main(void) {
 TipoLista lista;
 TipoItem item;
 int capacidade, valor, op=-1;

 while (op != 0)
 {
   Menu();
   scanf("%d", &op);

   switch(op)
   {
     case 1:
      printf("Digite a capacidade da Lista:\n");
      scanf("%d", &capacidade);

      InicializarLista(&lista, capacidade);
      break;

    case 2:
      printf("Digite o Valor que deseja adicionar na Lista:\n");
      scanf("%d", &item.chave);

      InserirLista(&lista, item);
      break;

    case 3:
      ExibirLista(lista);
      break;

    case 4:
      ExcluirPrimeiro(&lista);
      break;

    case 5:
      printf("Digite o valor que deseja pesquisar na Lista:\n");
      scanf("%d", &valor);

      PesquisarLista(lista, valor);
      break;

    case 6:
      ExibirInvertida(lista);
      break;

    case 7:
      ExcluirUltimo(&lista);
      break;

    case 8:
      printf("Digite o valor que deseja inserir:\n");
      scanf("%d", &valor);

      item.chave = valor;

      InserirInicio(&lista, item);
      break;

    case 0:
      printf("Obrigado por usar o programa!\n");
      printf("Saindo...");
      break;

    default:
      printf("INFO: Operação Invalida\n");
      break;
   }
 }
}