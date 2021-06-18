//####################################################################################################################################################################################
//                          Arvore bínaria de busca
//                   codigo escrito por : Gabriel Ramalho
//####################################################################################################################################################################################

#include <stdio.h>
#include <stdlib.h>

#define SAIR 0
#define INCLUIR 1
#define BUSCAR 2

struct dado{
  int codigo;
  int valor;
};

struct folha{
struct dado arvore;
struct folha *direita;
struct folha *esquerda;
};

int le_opcao(int,int);

int main(void) {
  struct folha raiz;
  int opcao;
  opcao = le_opcao(2,0);
  while(opcao != SAIR){
    opcao = le_opcao(2,0);
    switch(opcao){
      case INCLUIR:
      break;
      case BUSCAR:
      break;
      default:
      break;
    }
  }
  return 0;
}


int le_opcao(int max, int min){
  int opcao;
  printf("Digite 1 para incluir...\n");
  printf("Digite 2 para buscar....\n");
  scanf("%i",&opcao);
  if(opcao > max || opcao < min){
    printf("Opção invalida...\n\n");
    printf("Aperte qualquer tecla para continuar...\n\n");
    getchar();
  }
  return opcao;
}