//Definição do Cabeçalho Fila Dinâmica

//Definição da Chave
typedef int TipoChave;

typedef struct TipoItem
{
  TipoChave chave;
}TipoItem;

//Definiçãodo apontador para celula
typedef struct TipoCelula *TipoApontador;

//Definição da Célula
typedef struct TipoCelula
{
  TipoItem item;
  TipoApontador prox;
}TipoCelula;

//Definição do TipoFila
typedef struct TipoFila
{
  TipoApontador frente, tras;
  int tamanho, capacidade;
}TipoFila;

//Definição das Fuções para manipular a Fila

//Inicializar Fila
void InicializarFila (TipoFila *fila, int capacidade);

//Inserir Enfileirar (Enqueue)
void Enfileirar (TipoFila *fila, TipoItem item);

//Remover Desenfileirar (Denqueue)
void Desenfileirar (TipoFila *fila, TipoItem *item);

//Exibir fila
void ImprimeFila (TipoFila fila);

//Exibir o Elemento da frente
void ExibirFrente (TipoFila fila);

//Exibir o Elemento na parte de tras da fila
void ExibirTras (TipoFila fila);

//Esta Vazia
int EstaVazia (TipoFila fila);

//Esta Cheia
int EstaCheia (TipoFila fila);

//Imprime Invertida
void ImprimeInvertida (TipoFila fila, int capacidade);

//Inserir na Frente (Fura Fila)
void FuraFila (TipoFila *fila, TipoItem item);

//Exibir Menu
void menu();