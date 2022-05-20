#include <stdio.h>
#include <stdlib.h>


struct cliente
{
  int id;
  char nome[50];
  char endereco[70];
  char telefone[13];
  char email[50];
  char cidade[25];
  char estado[2];
};
typedef struct cliente cadastro;

void menuCliente();

cadastro clientes[10];
int tamCliente = 0;

void listarClientes()
{
  int i;
  for(i=0; i<tamCliente;i++)
  printf("ID: %d\n", clientes[i].id);
  printf("NOME: %s\n", clientes[i].nome);
  printf("ENDEREÇO: %s\n", clientes[i].endereco);
  printf("TELEFONE: %s\n", clientes[i].telefone);
  printf("EMAIL: %s\n", clientes[i].email);
  printf("CIDADE/ESTADO: %s\n", clientes[i].cidade);
  printf("===============================================\n\n");
}

  void cadastroCliente()
  {
      int *ptID = &clientes->id;
      char *ptNome = &clientes->nome[50];
      char *ptEnd = &clientes->endereco[70];
      char *ptTel = &clientes->telefone[13];
      char *ptEmail = &clientes->email[50];
      char *ptCidade = &clientes->cidade[25];
      char *ptEstado = &clientes->estado[2];

      printf("Digite o ID do cliente:\n");
      scanf("%d", ptID);

      printf("Digite o nome do cliente:\n");
      fgets(ptNome,50,stdin);
      getchar();

      printf("Digite o endereço do cliente:\n");
      fgets(ptEnd,70,stdin);
      getchar();

      printf("Digite o telefone do cliente:\n");
      fgets(ptTel,13,stdin);
      getchar();

      printf("Digite o email do cliente:\n");
      fgets(ptEmail,50,stdin);
      getchar();

      printf("Digite o Cidade do cliente:\n");
      fgets(ptCidade,25,stdin);
      getchar();
      
      tamCliente++;

      getchar();
      char cond;
      printf("Deseja cadastrar outro cliente S ou N");
      scanf("%c", &cond);
      getchar();

      if(cond =='s')
      {
        cadastroCliente();
      }
      else
      {
        menuCliente();
      }
  }


int op;
void menuCliente()
{
  int op;
  
  printf("\n\nOpções do Menu de Cliente\n\n");
  printf("Clientes Cadastrados [%d]\n", tamCliente);
  printf("=================================\n");
  printf("Escolha uma das opções abaixo\n\n");
  printf("1 - Cadastrar Cliente\n");
  printf("2 - Procurar cliente\n");
  printf("3 - Listar clientes\n");
  printf("0 - Voltar ao menu anterior\n");
  scanf("%d",&op);

  switch (op){
    case 1:
       cadastroCliente();
          break;
    case 2:
    break;
    case 3:
    listarClientes();
    break;
    default:
    break;
  }
  
}
void menuProduto();
void menuFornecedor();
void menuVenda();

void menuPrincipal()
{
  
  

      printf("Programa de Gerenciamento de Loja\n");
      printf("=================================\n");
      printf("Escolha uma das opções abaixo\n\n");
      printf("1 - Cliente\n");
      printf("2 - Produto\n");
      printf("3 - Fornecedor\n");
      printf("4 - Fazer uma Venda\n");
      printf("0 - Para sair\n");
      scanf("%d", &op);
      printf("\n\n");

      switch(op)
      {
        case 1:
          menuCliente();
          menuPrincipal();
        break;
        case 2:
          menuProduto();
          menuPrincipal();
        break;
        case 3:
          menuFornecedor();
          menuPrincipal();
        break;
        case 4:
          menuVenda();
          menuPrincipal();
        break;
        default:
          printf("Saindo do programa...\n");
        break;
      }
  
}



 void menuProduto()
{
  printf("\n\nOpções do Menu de Produto\n");
  printf("=================================\n");
  printf("Escolha uma das opções abaixo\n\n");
  printf("1 - Cadastrar Produto\n");
  printf("2 - Procurar produto\n");
  printf("3 - Listar produtos\n");
  
 
}
void menuFornecedor()
{
  printf("\n\nOpções do Menu de Fornecedor\n");
  printf("=================================\n");
  printf("Escolha uma das opções abaixo\n\n");
  printf("1 - Cadastrar Fornecedor\n");
  printf("2 - Procurar fornecedor\n");
  printf("3 - Listar fornecedores\n");
  printf("4 - Voltar ao menu anterior\n");
  scanf("%d", &op);
  
}
void menuVenda()
{
  printf("\n\nOpções do Menu de Vendas\n");
  printf("=================================\n");
  printf("Escolha uma das opções abaixo\n\n");
  printf("1 - Fazer uma Venda\n");
  printf("2 - Procurar por Venda pelo nome do Cliente\n");
  printf("3 - Listar Venda\n");
  printf("4 - Voltar ao menu anterior\n");
  scanf("%d", &op);
 
}