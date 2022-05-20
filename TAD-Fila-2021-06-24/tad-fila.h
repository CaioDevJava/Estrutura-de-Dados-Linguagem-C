//Definição da Pilha

//Definição da Chave
typedef int TipoChave;

typedef struct TipoItem
{
  TipoChave chave;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
  TipoItem item;
  TipoApontador prox;
}TipoCelula;

typedef struct TipoFila
{
  TipoApontador frente, tras;
  int tamanho, capacidade;
}TipoFila;

//Definição das funções para a Manipulação da Fila

//Inicialização da Fila
void InicializarFila (TipoFila *fila, int capacidade);

//Filha Vazia
int FilaVazia (TipoFila fila);

//Filha Cheia
int FilaCheia (TipoFila fila);

//Enfileiramento (Enqueue/Inserção)
void Enfileirar (TipoFila *fila, TipoItem item);

//Desenfileirar (Denqueue/Remoção)
void Desenfileirar (TipoFila *fila, TipoItem *item);

//Imprime Fila
void ImprimeFila (TipoFila fila);

//Imprime frente
void ImprimeFrente (TipoFila fila);

//Imprime tras
void ImprimeTras (TipoFila fila);

//Fura Fila Inserir no Inicio
void FuraFila (TipoFila *fila, TipoItem item);

//Exibir Menu
void menu();