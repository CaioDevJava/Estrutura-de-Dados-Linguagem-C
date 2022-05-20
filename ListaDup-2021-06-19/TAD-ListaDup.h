//Definição da Chave e TipoItem

typedef int TipoChave;

typedef struct TipoItem
{
  TipoChave chave;
}TipoItem;

//Definição do Apontador da Célula

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
  TipoItem item;
  TipoApontador prox, ant;
}TipoCelula;

//Definião do TipoLista
typedef struct TipoLista
{
  TipoApontador primeiro; 
  TipoApontador ultimo;
  int tamanho;
  int capacidade;
}TipoLista;

//Definião das Funções para Manipular a Lista

//Inicializar a Lista
void InicializarLista (TipoLista *lista, int capacidade);

//Inserir na Lista
void InserirLista (TipoLista *lista, TipoItem item);

//Exibir Lista
void ExibirLista (TipoLista lista);

//Exibir Lista invertida
void ExibirInvertida (TipoLista lista);

//Excluir Primeiro item da Lista
void ExcluirPrimeiro (TipoLista *lista);

//Excluir Ultimo item da Lista
void ExcluirUltimo (TipoLista *lista);

//Excluir item posição Específica
void ExcluirPosicao (TipoLista *lista, int pos);

//Pesquisar item na Lista
void PesquisarLista (TipoLista lista, int valor);

//Inserir no Inicio da Lista
void InserirInicio (TipoLista *lista, TipoItem item);

//Exibir Menu das Operações
void Menu();
