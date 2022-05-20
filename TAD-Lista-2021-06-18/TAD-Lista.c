#include <stdio.h>
#include <stdlib.h>
#include "TAD-Lista.h"

void InicializarLista (TipoLista *lista, int capacidade)
{

  //Criaçao da Celula Cabeça
  lista->primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  
  //Verificação de Alocação
  if(lista->primeiro == NULL)
  {
    printf("ERRO: Não foi possivél alocar a célula cabeça!\n");
    return;
  }

  //Apontar o Último para o mesmo endereço do primeiro
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;

  //Inicialização das Variáveis de Controle
  lista->tamanho = 0;
  lista->capacidade = capacidade;

}

//Inserir na Lista
void InserirLista (TipoLista *lista, TipoItem item)
{
// Verificar se ainda há espaço para inserir itens na Lista
if(lista->tamanho == lista->capacidade)
{
  printf("INFO: Sua Lista já está cheia!\n");
  return;
}

  //Criação de um novo nodo
  lista->ultimo->prox = (TipoApontador) malloc (sizeof(TipoCelula));

  //Verificação se o novo nodo foi alocado com sucesso
  if(lista->ultimo->prox == NULL)
  {
    printf("ERRO: Não foi possível alocar um novo NODO!\n");
    return;
  }

  //Apontando o Ponteiro Ultimo para o novo nodo alocado
  lista->ultimo = lista->ultimo->prox;
  
  //Atribuindo o Valor na Lista
  lista->ultimo->item = item;

  //Apontando a ultima célula para NULL oque indica o fim da Lista
  lista->ultimo->prox = NULL;

  //Incrementando a variável de Controle tamanho
  lista->tamanho++;
}

//Exibir Lista
void ExibirLista (TipoLista lista)
{
//Verificação se a Lista contém Itens a Exibir
if(lista.tamanho == 0)
{
  printf("INFO: Sua Lista está Vazia, não há itens a Exibir!\n");
  return;
}

  TipoApontador aux = lista.primeiro->prox;

  printf("Primeiro: ");

  while(aux != NULL)
  {
    printf("[%d]-> ", aux->item.chave);
    aux = aux->prox;
  }
  printf(" :Último\n");
}

void ExcluirLista(TipoLista *lista)
{
  //Verificar se a Lista não esta Vazia
  if(lista->tamanho == 0)
  {
    printf("INFO: Sua Lista está vazia, não há itens a serem excluídos!\n\n");
    return;
  }
  //Declaração de uma variável auxiliar
  TipoApontador aux = lista->primeiro->prox;

  //Apontando a cabeça para o item a frente do item que será excluído 
  lista->primeiro->prox = aux->prox;

  lista->tamanho--;

  printf("O Item %d foi removido com sucesso da lista!\n", aux->item.chave);

  //Apontando a Variaável auxiliar para o novo primeiro item da Lista

  if(aux->prox == NULL)
  {
   lista->ultimo = lista->primeiro;
  }
  else
  aux = aux->prox;

  printf("O Primeiro Item da Lista é agora %d\n\n", aux->item.chave);
}

void PesquisarLista (TipoLista lista, int valor)
{
  if(lista.tamanho == 0)
  {
    printf("INFO: Lista Vazia, não há itens para pesquisa!\n");
    return;
  }

  TipoApontador aux = lista.primeiro->prox;
  int count = 0, teste = 0;;

  while(aux != NULL)
  {
    count++;
    if(aux->item.chave == valor)
    {
      teste++;
      printf("INFO: O Valor %d se encontra na Posição %d da Lista!\n", aux->item.chave, count);
      return;
    }
    aux = aux->prox;
  }
  if(teste == 0)
  {
    printf("INFO: O Valor %d não existe na Lista!\n\n", valor);
  }

}

void menu()
{
  printf("Programa TAD Lista Simplesmente Encadeada\n");
  printf("=========================================\n\n");
  printf("1 - Para Inicializar a Lista\n");
  printf("2 - Para Inserir na Lista\n");
  printf("3 - Para Exibir os Itens da Lista\n");
  printf("4 - Para Excluir o Primeiro Item da Lista\n");
  printf("5 - Para Pesquisar por um Item da Lista\n\n");
  printf("0 - Para Sair do Programa\n");
}