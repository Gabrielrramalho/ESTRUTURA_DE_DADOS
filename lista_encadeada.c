#include <stdio.h>
#include <stdlib.h>
struct tProduto{
int codigo;
char descricao[30];
float valor;
};

struct tNo{
struct tProduto dado;
struct tNo *prox;
};

int main(void) {
  struct tNo *p,*lista = NULL;
  int opcao;
  do{
    printf("\n\n\nDigite 1 para incluir...\n");
    printf("\n\n\nDigite 0 para sair...\n");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
      printf("\n\n\nInclusao\n");
      p = malloc(sizeof(struct tNo));
      printf("Digite o codigo:\n");
      scanf("%d",&(p->dado.codigo));
      printf("Digite o valor:\n");
      scanf("%f",&(p->dado.valor));
      p->prox = lista;
      lista = p;
      break;
      case 2:
      p = lista;
      printf("descição-valor\n\n");
      while(p != NULL){
        printf("%d -- %f\n",p->dado.codigo,p->dado.valor);
        p = p->prox;
        
      }
      
      break;

    }

  }while(opcao != 0);
  return 0;
}