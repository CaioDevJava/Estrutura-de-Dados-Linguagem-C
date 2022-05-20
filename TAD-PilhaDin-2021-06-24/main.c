#include <stdio.h>
#include "tad-lista.h"

int main(void) 
{
 TipoFila fila;
 TipoItem item;
 int capacidade, valor, op = -1;

 while(op != 0)
 {
   menu();
   scanf("%d", &op);

   switch (op)
   {
     case 1:
      printf("Digite a Capacidade Desejada:\n");
      scanf("%d", &capacidade);

      InicializarFila(&fila, capacidade);
      break;

     case 2:
      printf("Digite o Valor que Deseja Inserir na Fila:\n");
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
    
    case 5:
      ExibirFrente(fila);
      break;
    
    case 6:
      ExibirTras(fila);
      break;
    
    case 7:
      printf("Digite o Valor que deseja Inserir:\n");
      scanf("%d", &valor);

      item.chave = valor;

      FuraFila(&fila, item);
      break;

    case 8:
      ImprimeInvertida(fila, capacidade);
      break;

     case 0:
      printf("Obrigado por usar o Programa!\n");
      printf("Saindo\n");
      break;

    default:
      printf("INFO: Operação Inválida!\n\n");
      break;
   }
 }
}