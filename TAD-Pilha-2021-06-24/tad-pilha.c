#include <stdio.h>
#include <stdlib.h>
#include "tad-pilha.h"

//CONSTANTES
#define SAIR 0
#define NAO_EXISTE -1


void InicializarPilha (TipoPilha *pilha, int capacidade)
{
  //Criação da Célula cabeça
  pilha->topo = (TipoApontador) malloc (sizeof(TipoCelula));

  //Verificação de Alocação
  if(pilha->topo == NULL)
  {
    printf("ERRO: Não foi possivél alocar a Celula Cabeça!\n\n");
    return;
  }

  //Apontando ponteiro fundo para a Cabeça
  pilha->fundo =pilha->topo;

  //Apontando a Cabeça para NULO
  pilha->topo->prox =NULL;

  //Inicializando as variaveis de controle
  pilha->tamanho = 0;
  pilha->capacidade = capacidade;
}

//Verificação se a Pilha está Vazia
int PilhaVazia (TipoPilha *pilha)
{
  return pilha->topo != pilha->fundo;
}

//Verificação se a Pilha está Cheia
int PilhaCheia (TipoPilha *pilha)
{
  return pilha->tamanho != pilha->capacidade;
}

//Empilhamento(PUSH)
void Empilhar (TipoPilha *pilha, TipoItem item)
{
  //Verificação se tem espaço para inserir na Pilha
  if(!PilhaCheia(pilha))
  {
    printf("INFO: Pilha Cheia não tem como inserir itens!\n\n");
    return;
  }

  //Alocação de uma nova celula
  TipoApontador celula = (TipoApontador) malloc (sizeof(TipoCelula));

  //verificação de alocação
  if(celula == NULL)
  {
    printf("ERRO: Não foi possivel alocar uma nova celula!\n\n");
    return;
  }

  //Empilhamento

  //Inserindo o dado na celula cabeça
  pilha->topo->item =item;

  //Apontando a nova celula para a cabeça
  celula->prox = pilha->topo;

  //Atribuindo a nova celula como a cabeça
  pilha->topo = celula;

  //Incrementando o Tamanho
  pilha->tamanho++;

  //Exibindo o Valor inserido
  printf("O Valor inserido no Topo foi: [%d]\n\n", pilha->topo->prox->item.chave);
}

//Exibir Pilha
void ImprimePilha (TipoPilha pilha)
{
  //Verificação se há itens na Pilha
  if(!PilhaVazia(&pilha))
  {
    printf("INFO: Pilha está Vazia, não há itens para listar!\n\n");
    return;
  }

  //Declaracão de Variavel auxiliar apontando ela para o 1 elemento da pilha
  TipoApontador aux = pilha.topo->prox;
  
  printf("Topo: ");

  while(aux != NULL)
  {
    printf("[%d]->", aux->item.chave);
    aux = aux->prox;
  }

  printf(" :Fundo\n");

  printf("Tamanho %d / %d Capacidade\n\n", pilha.tamanho, pilha.capacidade);
}

void Desempilhar (TipoPilha *pilha, TipoItem *item)
{
  if(!PilhaVazia (pilha))
  {
    printf("ERRO: Pilha Vazia não há itens para Desempilhar!\n\n");
    return;
  }

  //Declaração de uma Variavel auxiliar apontando para Cabeça
  TipoApontador aux = pilha->topo;

  //Topo apontando para o proximo item apos o que sera excluido
  pilha->topo = aux->prox;

  *item = aux->prox->item;

  //Liberando Aux da memoria
  free(aux);

  //Decrementando o tamanho da Pilha
  pilha->tamanho--;

  //Verificação em caso de desempilhar o ultimo item o fundo apontar para o mesmo lugar que o topo
  if(pilha->tamanho == 0)
  {
    pilha->fundo = pilha->topo;
  }
}

void ExibirTopo (TipoPilha pilha)
{
  if(!PilhaVazia (&pilha))
  {
    printf("Pilha Vazia sem Itens a Exibir!\n\n");
    return;
  }

  TipoApontador aux = pilha.topo;
  aux = aux->prox;

  printf("TOPO: [%d]\n\n", aux->item.chave);
  printf("Tamanho: %d / %d Capacidade\n\n", pilha.tamanho, pilha.capacidade);

}

void menu ()
{
  printf("Programa TAD Pilha Dinâmica\n");
  printf("============================\n\n");
  printf("1 - Para Inicializar a Pilha\n");
  printf("2 - Para Empilhar (PUSH)\n");
  printf("3 - Para Exibir a Pilha\n");
  printf("4 - Para Desempilhar (POP)\n");
  printf("5 - Para Exibir o Topo(PEEK)\n\n");
  printf("0 - Para Sair do Programa\n\n");
}