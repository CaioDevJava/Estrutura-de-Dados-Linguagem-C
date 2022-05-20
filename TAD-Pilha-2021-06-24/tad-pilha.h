//Definição do cabeçalho da Pilha

//Definição de Constantes
#define SAIR 0
#define NAO_EXISTE -1

//Definição do TipoChave
typedef int TipoChave;

typedef struct TipoItem
{
  TipoChave chave;
}TipoItem;

//Definição do Ponteiro para o TipoCelula
typedef struct TipoCelula *TipoApontador;

//Definição da Celula 
typedef struct TipoCelula
{
  TipoItem item;
  TipoApontador prox;
}TipoCelula;

//Definição do TipoPilha
typedef struct TipoPilha
{
  TipoApontador topo, fundo;
  int tamanho, capacidade;
}TipoPilha;

//Definição das Funções de Manipulação da Pilha

//Inicializar Pilha
void InicializarPilha (TipoPilha *pilha, int capacidade);

//Empilhar(PUSH)
void Empilhar (TipoPilha *pilha, TipoItem item);

//Desempilhar(POP)
void Desempilhar (TipoPilha *pilha, TipoItem *item);

//Imprimir Pilha
void ImprimePilha (TipoPilha pilha);

//Exibir Topo da Pilha(PEEK)
void ExibirTopo (TipoPilha pilha);

//Exibir Tamanho e capacidade
void ExibirTamanho (TipoPilha pilha);

//Pilha Vazia
int PilhaVazia (TipoPilha *pilha);

//Pilha Cheia
int PilhaCheia (TipoPilha *pilha);

//Exibir Menu
void menu();