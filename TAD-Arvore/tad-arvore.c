#include <stdio.h>
#include <stdlib.h>
#include "tad-arvore.h"

//Inicialização da Arvore
void InicializarArvore (TipoNo *no, int capacidade)
{
  int valor;
  printf("Digite a capacidade desejada:\n");
  scanf("%d", &capacidade);

  printf("Digite uma Raiz para sua Arvore:\n");
  scanf("%d", &valor);

  no->chave = valor;

  no->tamanho = 0;
  no->capacidade = capacidade;
  no->pai = NULL; //Porque a raiz não tem filhos
}

// imprime nó corrente
void imprimirNoCorrente(TipoNo no)
{
   printf("\n==\n");

  //Verificação se é o nó Raiz
  if(no.pai == NULL)
  {
    printf("Raiz-> ");
  }

  else
  {
    printf("Pai-> [%d]->", no.pai->chave);
  }

  printf("Corrente->[%d] -> ", no.chave);

  printf("Filhos: [ ");
  for(int i = 0; i<no.tamanho; i++)
  {
    printf("[%d] ", no.filhos[i]->chave);
  }
  printf(" ] Filhos: %d\n\n", no.tamanho);

}

// imprime to da árvore
void imprimirNoRecursivo(TipoNo no);

// insere uma nova chave dentro de um nó existente
void inserirNovoNo(TipoApontador no, TipoChave chave)
{
   
  if(no->tamanho == no->capacidade)
  {
    printf("INFO: Nó Pai já tem a quantidade maxima de filhos!\n\n");
    return;
  }
  
  TipoApontador filho = (TipoApontador) malloc (sizeof(TipoNo));
  
  if(filho == NULL)
  {
    printf("ERRO: Não foi possível alocar nó filho\n\n");
    return;
  }

  //Insere o valor no novo no
  filho->chave = chave;

  //aponta o indice de filhos do nó para o novo nó
  no->filhos[no->tamanho] = filho;

  //Incrementa o tamanho
  no->tamanho ++;

  //Atribui a capacidade do nó pai ao nó filho
  filho->capacidade = no->capacidade;

  //Aponta o nó filho para o nó pai
  filho->pai = no;

}

// pesquisar por uma chave dentro de um no
TipoApontador pesquisarFilho(TipoNo no, TipoChave chave);

void menu()
{
  printf("Programa TAD Arvore\n");
  printf("========================\n\n");
  printf(" 1: inicializar a árvore         - INIT\n");
  printf(" 2: Navegar em nó filho          - VISIT\n");
  printf(" 3: inserir novo nó              - INSERT\n");
  printf(" 4: imprimir árvore              - PRINT\n");
  printf(" 5: pesquisar por nó             - SEARCH\n");
  printf(" 6: Navegar para a raiz          - VISIT\n");
  printf(" 7: imprimir nó corrente         - PRINT\n");
  printf(" 8: Navegar para o nó pai        - VISIT\n");
  printf(" 9: remover filho de nó corrente - REMOVE\n\n");
  printf("0: sair\n\n");
}