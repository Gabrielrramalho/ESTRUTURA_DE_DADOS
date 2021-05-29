//codigo escrito por : Gabriel Ramalho
//################################################################################################################################################################
//                                   pilha
//################################################################################################################################################################
#include <stdio.h>
#include <stdlib.h>



struct tProduto{
int codigo;
char descricao[30];
float valor;
};

struct tNo{
struct tProduto dado;
struct tNo *prox;//ponteiro para o proximo no da lista
};

void inicializar(struct tNo**);
int menu(int min, int max);
struct tNo* criar_no();
void listar(struct tNo*);
void pop(struct tNo** ,struct tNo*);
struct tNo* consultar(struct tNo,int codigo);
struct tNo* push(struct tNo**);


int main(void) {
  struct tNo *p;
  struct tNo *pil;
  inicializar(&pil);
  int opcao,codigo;
  do{
    opcao = menu(0,3);
    switch(opcao){
      case 1:
       p = criar_no();
      pop(&pil,p);
      break;
      case 2:
      listar(pil);
      break;
      case 3:
      if(pil == NULL){
       printf("pilha vazia.");
      }else{
        printf("descição-valor\n\n");
       p = push(&pil);
       printf("%d -- %f\n",p->dado.codigo,     
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
  printf("Digite 2 para empilhar....\n");
  printf("Digite 3 para desempilhar....\n");
  printf("Digite 0 para sair........\n");
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

void listar (struct tNo *pil){//PRINTA TODOS    OS PRODUTOS DA PILHA
 //@Lst RECEBERA STRUCT do tipo tDescritor
 struct tNo *p;
 p = pil;
 printf("descição-valor\n\n");
 while(p != NULL){
  printf("%d -- %f\n",p->dado.codigo,     
  p->dado.valor);
  p = p->prox;
 }  
}

//FUNÇÃO PARA EMPILHAR
//@pil RECEBE UMA STRUCT DO TIPO tNo.
//@p RECEBE UMA STRUCT DO TIPO tNo.
void pop(struct tNo **pil,struct tNo *p){
  p->prox = (*pil);
  (*pil) = p;
}

//FUNÇÃO PARA   DESEMPILHAR 
//@pil RECEBE UMA STRUCT DO TIPO tNo
struct tNo* push(struct tNo **pil){
  struct tNo* p;
  p = (*pil);
  (*pil) = (*pil)->prox;
  return p;
}

//INICIALIZA A PILHA
//RECEBE COMO PARAMETRO UMA STRUCT DO TIPO tNo
void inicializar(struct tNo **pil){
(*pil) = NULL;
}