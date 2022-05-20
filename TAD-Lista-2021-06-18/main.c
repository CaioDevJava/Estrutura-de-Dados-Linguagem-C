#include <stdio.h>
#include "TAD-Lista.h"

int main(void) {
 TipoLista lista;
 TipoItem item;
 int valor, capacidade, op=-1;

 while(op != 0)
 {
   menu();
   scanf("%d", &op);

   switch(op)
   {
     case 1:
      printf("Digite a Capacidade Desejada para a Lista:\n");
      scanf("%d", &capacidade);
      InicializarLista(&lista, capacidade);
      break;
    
    case 2:
      printf("Digite o valor que deseja inserir na Lista:\n");
      scanf("%d", &valor);

      item.chave = valor;

      InserirLista(&lista, item);
      break;
    
    case 3:
      printf("Exibindo Lista...\n");
      printf("========================\n\n");
      ExibirLista(lista);
      break;
    
    case 4:
      printf("Excluindo o primeiro Item da Lista!\n");
      printf("====================================\n");

      ExcluirLista(&lista);
      break;

    case 5:
      printf("Digite o valor que deseja pesquisar:\n");
      scanf("%d", &valor);

      PesquisarLista(lista, valor);
      break;

    case 0:
      printf("Obrigado por usar o programa\n");
      printf("Saindo...\n\n");
      break;

    default:
      printf("INFO: Operação Inválida!\n");
      break;
   }
 }
  return 0;
}