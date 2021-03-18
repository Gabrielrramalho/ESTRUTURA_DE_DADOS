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
  struct tNo *p,*q,*lista = NULL;
  int opcao;
  do{
    printf("\n\n\nDigite 1 para incluir...\n");
    printf("Digite 2 para listar...\n");
    printf("Digite 0 para sair...\n");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
      printf("\n\n\nInclusao\n");
      p = malloc(sizeof(struct tNo));
      printf("Digite o codigo:\n");
      scanf("%d",&(p->dado.codigo));
      printf("Digite o valor:\n");
      scanf("%f",&(p->dado.valor));
      if(lista == NULL){//INCLUSAO LISTA VASIA
        p->prox = NULL;
        lista = p;
      }else{
        if(p->dado.codigo < lista->dado.codigo){
          //INCLUSÃO NO INICIO
          p->prox = lista;
          lista = p;
        }else{//fim meio
          q = lista;
          while(q->prox != NULL)//COLOCA O Q NO ULTIMO DA LISTA
            q = q->prox;
          if(p->dado.codigo > q->dado.codigo){
            q->prox = p;
            p->prox = NULL;
          }else{//meio
            q = lista;//q aponta para o primeiro da lista
            while(q->prox->dado.codigo < p->dado.codigo)//executa em quanto q->codigo codigo for menor q o p->codigo
              q=q->prox;// avança o q           
             p->prox = q->prox;//insere o proximo de q para ponteiro p->prox
             q->prox = p;//insere o p para sser o proximo de q
          }
        }
      }
      break;
      case 2:
      p = lista;
      printf("descição-valor\n\n");
      while(p != NULL){
        printf("%d -- %f\n",p->dado.codigo,
        
        p->dado.valor);
        p = p->prox;
        
      }
      break;
    }

  }while(opcao != 0);

  while(p != NULL){
    free(p);
  }
  return 0;
}