#include <stdio.h>
#include <stdlib.h>
#include "TAD-ListaDup.h"

//Inicializar a Lista
void InicializarLista (TipoLista *lista, int capacidade)
{
  //Ciração da Célula Cabeça
  lista->primeiro = (TipoApontador) malloc (sizeof(TipoCelula));

//Verificação se a Célula Cabeça foi alocada
  if(lista->primeiro == NULL)
  {
    printf("ERRO: Não foi possivél cria a Célula Cabeça!\n");
    return;
  }
//Apontando Ultimo para Cabeça
  lista->ultimo = lista->primeiro;

  //Apontando a Cabeça para NULL
  lista->primeiro->prox = NULL;
  lista->primeiro->ant = NULL;

//Inicializando as Variaveis de Controle
  lista->tamanho = 0;
  lista->capacidade = capacidade;
}

//Inserir na Lista
void InserirLista (TipoLista *lista, TipoItem item)
{

  if(lista->tamanho == lista->capacidade)
  {
    printf("INFO: Lista Cheia!\n\n");
    return;
  }

  //Criação de um novo NODO
  TipoApontador celula = (TipoApontador) malloc (sizeof(TipoCelula));

  //Verificação se o novo NODO foi alocado
  if(celula == NULL)
  {
    printf("ERRO: Não foi possivél criar o novo NODO para a Lista!\n");
    return;
  }

  //Atualizando ultimo para apontar para o novo NODO
  lista->ultimo->prox = celula;

  //Apontando o ponteiro ant pro anterior
  celula->ant = lista->ultimo;
 
  //Inserindo valor no novo NODO
  celula->item = item;

  //Atualizando a posição do Ultimo
  lista->ultimo = celula;

  //Apontando o prox do novo Nodo para NULO
  celula->prox = NULL;

  //incrementando o tamanho da Lista
  lista->tamanho++;
} 

//Exibir Lista
void ExibirLista (TipoLista lista)
{

  //Verificação se possuem itens para listar
  if(lista.tamanho == 0)
  {
    printf("INFO: Lista está vazia Insira itens para listar!\n");
    return;
  }

  //Declarando um ponteiro auxiliar e apontando pa Cabeça
  TipoApontador aux = lista.primeiro->prox;

  printf("Primeiro: ");

  //Exibindo os itens da Lista
  while(aux != NULL)
  {
    printf("<-[%d]-> ", aux->item.chave);
    aux = aux->prox;
  }

  printf(":Ultimo\n\n");

  printf("Tamanho: %d / %d Capacidade\n\n", lista.tamanho,lista.capacidade);
}

void ExibirInvertida(TipoLista lista)
{

  //Verificação se possuem itens a Exibir
  if(lista.tamanho == 0)
  {
    printf("INFO: Lista está Vazia!\n");
    return;
  }

  //Declarando uma Variavel auxiliar e apontando para o Ultimo elemento
  TipoApontador aux = lista.ultimo;


  //Impressão da Lista Invertida
  printf("Ultimo: ");
  while(aux != NULL && aux != lista.primeiro)
  {
    printf(" <-[%d]-> ", aux->item.chave);
    aux = aux->ant;
  }
  printf(" :Primeiro\n");
  printf("Tamanho: %d / %d Capacidade\n\n", lista.tamanho, lista.capacidade);
}

//Excluir Primeiro item da Lista
void ExcluirPrimeiro (TipoLista *lista)
{
  //Verificação se há itens para Excluir
  if(lista->tamanho == 0)
  {
    printf("INFO: Lista Vazia não há itens a Excluir!\n");
    return;
  }

  //Declaração de Variavel auxiliar e Apontando pro primeiro iten da lista
  TipoApontador aux = lista->primeiro->prox;

  //Apontando a Celula Cabeça para o segundo item da lista
  lista->primeiro->prox = aux->prox;

  //Apontando aux->ant para a Cabeça
  aux->ant = lista->primeiro->ant;

  //Exibindo o item excluído
  printf("O Item excluído foi: %d\n\n", aux->item.chave);
  
  //Liberando espaço de memoria ocupado por aux
  free(aux);

  //Decrementando o tamanho da lista
  lista->tamanho--;

  //Apontando o ponteiro ultimo para Cabeça em caso de ter excluido o ultimo item da lista
  if(lista->tamanho == 0)
  {
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->ultimo = lista->primeiro;
  }

  //Exibindo tamanho e capacidade da lista
  printf("Tamanho %d / %d Capacidade\n", lista->tamanho, lista->capacidade);
}

//Excluir Ultimo item da Lista
void ExcluirUltimo (TipoLista *lista)
{
  if(lista->tamanho == 0)
  {
    printf("INFO: Não há itens para Excluir na Lista!\n");
    return;
  }

  TipoApontador aux = lista->ultimo;

  lista->ultimo = lista->ultimo->ant;
  lista->ultimo->prox = NULL;

  lista->tamanho--;

  printf("INFO: O item excluído foi: %d\n", aux->item.chave);

  printf("Tamanho %d / %d Capacidade\n\n", lista->tamanho,lista->capacidade);

  if(lista->tamanho == 0)
  {
    lista->ultimo = lista->primeiro;
  }

  free(aux);
}

//Excluir item posição Específica
void ExcluirPosicao (TipoLista *lista, int pos)
{
  TipoApontador aux = lista->primeiro->prox;
  int count = 0;

  while(aux != NULL)
  {
    count++;
    if(count == pos){
      
    }
    aux = aux->prox;
    
  }
}

//Pesquisar item na Lista
void PesquisarLista (TipoLista lista, int valor)
{
  TipoApontador aux = lista.primeiro->prox;
  int pos=0;

  while(aux != NULL)
  {
    pos++;
    if(aux->item.chave == valor)
    {
      printf("Valor %d foi encontrado na Posição %d\n", aux->item.chave,pos);
      aux = aux->prox;
      return;
    }
  }
  printf("Valor não existe na Lista!\n\n");
}

//Inserir no Inicio
void InserirInicio (TipoLista *lista, TipoItem item)
{
  TipoApontador aux = lista->primeiro->prox;
  TipoApontador celula = (TipoApontador) malloc (sizeof(TipoCelula));

  if(celula == NULL)
  {
    printf("INFO: Não foi possivel alocar o novo NODO!\n");
    return;
  }

  celula = aux->prox;
  celula->ant = NULL;
  celula->item = item;
  lista->primeiro->prox = celula;

  lista->tamanho ++;

}

//Exibir Menu das Operações
void Menu()
{
  printf("Programa TAD Lista Duplamente Encadeada\n ");
  printf("==============================================\n\n");
  printf("1 - Para inicializar a Lista\n");
  printf("2 - Para Inserir na Lista\n");
  printf("3 - Para Exibir a Lista\n");
  printf("4 - Para Excluir o Primeiro Item da Lista\n");
  printf("5 - Para Pesquisar um item na lista\n");
  printf("6 - Para Exibir a Lista Invertida\n");
  printf("7 - Para Excluir o Ultimo elemento\n");
  printf("8 - Para Inserir no Inicio\n\n" );
  printf("0 - Para Sair do Programa\n");
}