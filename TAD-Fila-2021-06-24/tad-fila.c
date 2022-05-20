#include <stdio.h>
#include <stdlib.h>
#include "tad-fila.h"

void InicializarFila (TipoFila *fila, int capacidade)
{
  //Alocar a celula Cabeça
  fila->frente = (TipoApontador) malloc (sizeof(TipoCelula));

  //Verificação da Alocação
  if(fila->frente == NULL)
  {
    printf("ERRO: Celula Cabeça não Alocada!\n\n");
    return;
  }

  //Apontando ponteiro tras para Cabeça
  fila->tras = fila->frente;

  //Apontando Cabeça para NULO
  fila->frente->prox = NULL;

  //Atualizando variaveis de controle
  fila->tamanho = 0;
  fila->capacidade = capacidade;
}

int FilaVazia (TipoFila fila)
{
  return fila.frente == fila.tras;
}

int FilaCheia (TipoFila fila)
{
  return fila.tamanho == fila.capacidade;
}

void Enfileirar(TipoFila *fila, TipoItem item)
{
  if(FilaCheia(*fila))
  {
    printf("INFO: Pilha está Cheia!\n\n");
    return;
  }

  //Alocando uma nova Celula
  fila->tras->prox = (TipoApontador) malloc (sizeof(TipoCelula));
  
  //Verificação se a nova celula foi alocada
  if(fila->tras->prox == NULL)
  {
    printf("ERRO: Não foi possivel alocar a nova Célula!\n\n");
    return;
  }

  //Atualizando para onde aponta o ponteiro tras
  fila->tras = fila->tras->prox;

  //Inserir item na fila
  fila->tras->item = item;

  //Apontar o ponteiro prox para NULO
  fila->tras->prox = NULL;

  //Atualizar Variavel de controle
  fila->tamanho++;
}

void ImprimeFila (TipoFila fila)
{
  if(FilaVazia(fila)){
    printf("INFO: FILA VAZIA!\n");
    return;
  }

  TipoApontador aux = fila.frente;
  aux = aux->prox;

  printf("Frente: ");
  while(aux != NULL)
  {
    printf("[%d]->", aux->item.chave);
    aux = aux->prox;
  }
  printf(": Tras\n\n");

  printf("Tamanho: %d / %d Capacidade\n\n", fila.tamanho, fila.capacidade);
}

void Desenfileirar (TipoFila *fila, TipoItem *item)
{
  if(FilaVazia(*fila))
  {
    printf("INFO: Fila Vazia!\n\n");
    return;
  }
  TipoApontador aux = fila->frente;

  fila->frente = aux->prox;
  *item = aux->prox->item;
  fila->tamanho--;
  free(aux);

  if(fila->tamanho == 0)
  {
    fila->tras = fila->frente;
  }
}

void menu()
{
  printf("Programa TAD Fila Dinamica\n");
  printf("===========================\n\n");
  printf("1 - Inicializar Fila\n");
  printf("2 - Enfileirar(Enqueue)\n");
  printf("3 - Imprimir Fila\n");
  printf("4 - Desenfileirar (Denqueue)\n\n");
  printf("0 - Pra Sair do Programa\n\n");
}