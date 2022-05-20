#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

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
struct produto
{
  int id;
  char nome[50];
  char descr[80];
  char fornecedor[50];
  char tipo[30];
  float valorC;
  float valorV;
};
struct fornecedor
{
  int id;
  char nome[50];
  char cnpj[18];
  char endereco[70];
  char telefone[15];
  char email[50];
  char cidade[25];
  char estado[2];
};
struct venda
{
  int id;
  char cliente[50];
  char produto[50];
  int quantidade;
  float valorVenda;
  char data[10];
  char hora[8];
};

//Vetor de Registro para cadastrar 10 Clientes
typedef struct cliente clientes;
clientes sCliente[3];
//Vetor de Registro para cadastrar 5 Produtos
typedef struct produto produto;
produto prod[5];
//Vetor de Registro para cadastrar 2 Fornecedores
typedef struct fornecedor fornecedor;
fornecedor fornecedores[2];
//Vetor de Registro para fazer 20 Vendas
typedef struct venda vendas;
vendas vendaN[20];


//Declaração de Ponteiros para usar Módulos

//Struct de Clientes
int *ptId = &sCliente[0].id;
char *ptNome = &sCliente[0].nome[50];
char *ptEnd = &sCliente[0].endereco[70];
char *pttel = &sCliente[0].telefone[13];
char *ptEmail = &sCliente[0].email[50];
char *ptCid = &sCliente[0].cidade[25];
char *ptEst = &sCliente[0].estado[2];

//Struct de Produtos
int *ptIdp = &prod[0].id;
char *ptNomeP = &prod[0].nome[50];
char *ptDesc = &prod[0].descr[80];
char *ptForn = &prod[0].fornecedor[50];
char *ptTipo = &prod[0].tipo[30];
float *ptValorC = &prod[0].valorC;
float *ptValorV = &prod[0].valorV;

//Struct de Fornecedores
int *ptIDf = &fornecedores[0].id;
char *ptNomeF = &fornecedores[0].nome[50];
char *ptCnpj = &fornecedores[0].cnpj[18];
char *ptEndF = &fornecedores[0].endereco[70];
char *ptTelF = &fornecedores[0].telefone[15];
char *ptEmailF = &fornecedores[0].email[50];
char *ptCidF = &fornecedores[0].cidade[25];
char *ptEstF = &fornecedores[0].estado[2];

//Struct de Vendas

  int *ptIdV = &vendaN[0].id;
  char *ptClienV = &vendaN[0].cliente[50];
  char *ptProdV = &vendaN[0].produto[50];
  int *ptQtdV = &vendaN[0].quantidade;
  float *ptValorVd = &vendaN[0].valorVenda;
  char *ptData = &vendaN[0].data[10];
  char *ptHrs = &vendaN[0].hora[8];


int main(void)
{
  
 menuPrincipal();
  
    return 0;
}