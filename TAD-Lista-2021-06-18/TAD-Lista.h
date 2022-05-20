//Definição da Lista

//Definição do TipoValor
typedef int TipoChave;

typedef struct TipoItem
{
  TipoChave chave;
}TipoItem;

//Definição do Apontador da Célula
typedef struct TipoCelula *TipoApontador;

//Definição do TipoCelula
typedef struct TipoCelula
{
  TipoItem item;
  TipoApontador prox;
}TipoCelula;

//Definição do TipoLista
typedef struct TipoLista 
{
  TipoApontador primeiro, ultimo;
  int tamanho;
  int capacidade;
}TipoLista;

//Definição das Funções para manipular a Lista

//Inicializar a Lista
void InicializarLista (TipoLista *lista, int capacidade);

//Inserir na Lista
void InserirLista (TipoLista *lista, TipoItem item);

//Exibir Lista
void ExibirLista (TipoLista lista);

//Excluir um item da Lista
void ExcluirLista (TipoLista *lista);

//Pesquisar Chave na Lista
void PesquisarLista (TipoLista lista, int valor);

//Exibir Menu
void menu ();