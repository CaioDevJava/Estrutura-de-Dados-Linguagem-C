#include <stdio.h>
#include <stdlib.h>
#include "tad-lista.h"

void InicializarFila (TipoFila *fila, int capacidade)
{
  fila->frente = (TipoApontador) malloc (sizeof(TipoCelula));

  if(fila->frente == NULL)
  {
    printf("ERRO: Não foi possível alocar a célula Cabeça!\n\n");
    return;
  }

  fila->tras = fila->frente;
  fila->frente->prox = NULL;

  fila->tamanho = 0;
  fila->capacidade = capacidade;
}

int EstaVazia (TipoFila fila)
{
  return fila.tras == fila.frente;
}

int EstaCheia (TipoFila fila)
{
  return fila.tamanho == fila.capacidade;
}

void Enfileirar (TipoFila *fila, TipoItem item)
{
  if(EstaCheia(*fila))
  {
    printf("INFO: A Fila esta Cheia!\n\n");
    return;
  }

  fila->tras->prox = (TipoApontador) malloc (sizeof(TipoCelula));

  if(fila->tras->prox == NULL)
  {
    printf("ERRO: Não foi possivel alocar uma nova Célula!\n\n");
    return;
  }

  fila->tras = fila->tras->prox;
  fila->tras->item = item;
  fila->tras->prox = NULL;
  fila->tamanho++;

  printf("Item [%d] inserido com Sucesso\n", fila->tras->item.chave);
  printf("Tamanho: [%d/%d] :Capacidade\n\n", fila->tamanho, fila->capacidade);
}

void ImprimeFila (TipoFila fila)
{
  if(EstaVazia(fila))
  {
    printf("INFO: A Fila esta Vazia, insira itens!\n\n");
    return;
  }

  TipoApontador aux = fila.frente->prox;

  printf("Frente: ");

  while(aux != NULL)
  {
    printf("[%d]->", aux->item.chave);
    aux = aux->prox;
  }

  printf(" :Tras\n\n");

  printf("Tamanho: [%d/%d] :Capacidade\n\n", fila.tamanho, fila.capacidade);

}

void Desenfileirar (TipoFila *fila, TipoItem *item)
{
  if(EstaVazia(*fila))
  {
    printf("INFO: Fila esta Vazia!\n\n");
    return;
  }

  TipoApontador aux = fila->frente;

  fila->frente = aux->prox;
  *item = aux->prox->item;
  fila->tamanho--;

  printf("Item [%d] Removido com Sucesso!\n", aux->prox->item.chave);
  printf("Tamanho: [%d/%d] :Capacidade\n\n", fila->tamanho, fila->capacidade);

  free(aux);

  if(fila->tamanho == 0)
  {
    fila->tras = fila->frente;
  }
}

void ExibirFrente (TipoFila fila)
{
  if(EstaVazia(fila))
  {
    printf("INFO: Fila Esta Vazia!\n");
    return;
  }
  TipoApontador aux = fila.frente;
  aux = aux->prox;
  printf("Frente: [%d]\n\n", aux->item.chave); 
}

void ExibirTras (TipoFila fila)
{
  if(EstaVazia(fila))
  {
    printf("INFO: Fila Esta Vazia!\n");
    return;
  }
  printf("Tras: [%d]\n\n", fila.tras->item.chave);
}

void FuraFila (TipoFila *fila, TipoItem item)
{
  if(EstaCheia(*fila))
  {
    printf("INFO: A fila está Cheia!\n\n");
    return;
  }

  TipoApontador celula = (TipoApontador) malloc (sizeof(TipoCelula));

  celula->prox = fila->frente;
  fila->frente->item = item;
  fila->frente = celula;
  fila->tamanho++;

  printf("Item [%d] Inserido com sucesso na Frente!\n\n", fila->frente->prox->item.chave);

}

void ImprimeInvertida (TipoFila fila, int capacidade)
{

  if(EstaVazia(fila))
  {
    printf("INFO: A fila esta vazia!\n\n");
    return;
  }
  
  int count = fila.tamanho - 1;
  TipoChave vet[fila.tamanho];
  TipoApontador aux = fila.frente;
  aux = aux->prox;

  while(aux != NULL)
  {
    vet[count] = aux->item.chave;
    count--;
    aux = aux->prox;
  }

  printf("Tras: ");
  for(int i = 0; i<fila.tamanho; i++)
  {
    printf("[%d]->", vet[i]);
  }
  printf(" :Frente\n\n");
}

void menu()
{
  printf("Programa TAD Fila Dinâmica\n");
  printf("===========================\n\n");
  printf("1 - Para Inicializar a Fila\n");
  printf("2 - Para Enfileirar (Enqueue)\n");
  printf("3 - Para Imprimir Fila\n");
  printf("4 - Para Desenfileirar (Denqueue)\n");
  printf("5 - Para Exibir a Frente da Fila\n");
  printf("6 - Para Exibir a Traseira da Fila\n");
  printf("7 - Para Furar Fila\n");
  printf("8 - Imprimir Invervida\n\n");
  printf("0 -  Para Sair do Programa\n\n");
}