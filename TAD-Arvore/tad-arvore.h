#define MAX 3
#define SAIR 0

typedef int TipoChave;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
  TipoChave chave;
  TipoApontador filhos[MAX];
  int tamanho;
  int capacidade;
  TipoApontador pai;
}TipoNo;

//definição das funções de manipulação da arvore

// imprime nó corrente
void imprimirNoCorrente(TipoNo no);

// imprime to da árvore
void imprimirNoRecursivo(TipoNo no);

// insere uma nova chave dentro de um nó existente
void inserirNovoNo(TipoApontador no, TipoChave chave);

void InicializarArvore (TipoNo *no, int capacidade);

// pesquisar por uma chave dentro de um no
TipoApontador pesquisarFilho(TipoNo no, TipoChave chave);

void menu();