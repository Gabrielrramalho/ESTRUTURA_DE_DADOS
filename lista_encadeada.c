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

int menu(int min, int max);
struct tNo* criar_no();
void listar(struct tNo *lista);
void inclusao_ordenada(struct tNo **lista,struct tNo *p);
struct tNo* consultar(struct tNo *lista,int codigo);


int main(void) {
  struct tNo *p,*q,*lista = NULL,*localizado;
  int opcao,codigo;
  do{
    opcao = menu(0,3);
    switch(opcao){
      case 1:
      inclusao_ordenada(&lista, p);
      break;
      case 2:
      listar(lista);
      break;
      case 3:
      printf("Digite o codigo\n");
      scanf("%d",&codigo);
      p = consultar(lista,codigo);
      if(p == NULL){
       printf("Codigo não encontrado");
      }else{
       printf("%d -- %f\n",
       p->dado.codigo,     
       p->dado.valor);
      }
      break;
    }

  }while(opcao != 0);

  //while(p != NULL){
    //q = p;
    //p = p->prox;
    //free(p);
  //}
  printf("%i",opcao);
  return 0;
}

int menu(int min,int max) {
  int opcao;
  do{
  printf("\n\n\nDigite 1 para incluir..\n");
  printf("Digite 2 para listar....\n");
  printf("Digite 3 para consultar....\n");
  printf("Digite 0 para sair......\n");
  scanf("%d",&opcao);
  if(opcao < min || opcao > max){
    system("clear");
    printf("Digite uma opção valida...");
  }
  }while(opcao < min || opcao > max);
  return opcao;
}


struct tNo* criar_no(){//CRIA UM NOVO NO
  struct tNo *novoNo;
  printf("\n\n\nInclusao\n");
  novoNo = malloc(sizeof(struct tNo));
  printf("Digite o codigo:\n");
  scanf("%d",&(novoNo->dado.codigo));
  printf("Digite o valor:\n");
  scanf("%f",&(novoNo->dado.valor));
  return novoNo;
}

void listar (struct tNo *lista){//PRINTA TODOS    OS PRODUTOS
 //@LISTA RECEBERA STRUCT tNo *p
 struct tNo *p;
 p = lista;
 printf("descição-valor\n\n");
 while(p != NULL){
  printf("%d -- %f\n",p->dado.codigo,     
  p->dado.valor);
  p = p->prox;
 }  
}

//INCLUI O NOVO NO ORDENADAMENTE
//@tNo *lista RECEBE A STRCUT tNo LISTA QUE É SEMPRE O PRIMEIRO ELEMENTO DA LISTA
//@tNo *p  RECEBERA STRUCT tNo P
void inclusao_ordenada(struct tNo **lst,struct tNo *p){
  struct tNo *q;
  p = criar_no();
if((*lst) == NULL){//INCLUSAO LISTA VASIA
        p->prox = NULL;
        (*lst) = p;
      }else{
        if(p->dado.codigo < (*lst)->dado.codigo){
          //INCLUSÃO NO INICIO
          p->prox = (*lst);
          (*lst) = p;
        }else{//fim meio
          q = (*lst);
          while(q->prox != NULL)//COLOCA O Q NO ULTIMO DA LISTA
            q = q->prox;
          if(p->dado.codigo > q->dado.codigo){
            q->prox = p;
            p->prox = NULL;
          }else{//meio
            q = (*lst);//q aponta para o primeiro da lista
            while(q->prox->dado.codigo < p->dado.codigo)//executa em quanto q->codigo codigo for menor q o p->codigo
              q=q->prox;// avança o q           
             p->prox = q->prox;//insere o proximo de q para ponteiro p->prox
             q->prox = p;//insere o p para sser o proximo de q
          }
        }
      }
}

struct tNo* consultar(struct tNo *lista,int codigo){
  struct tNo *q = lista;
  while((q != NULL)&&(q->dado.codigo <= codigo)){
    if(codigo == q->dado.codigo){
     return q;
    }
    q = q->prox;
  }
  return NULL;
}