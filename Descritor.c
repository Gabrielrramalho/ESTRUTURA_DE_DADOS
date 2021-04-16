//################################################################################################################################################################
//                    Lista duplamente encadeada com descritor
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
struct tNo *anterior;//ponteiro para o no anterior da lista
};


struct tDescritor{
int qtd;//quantidade de elementos na lista
struct tNo *inicio;//ponteiro para o primeiro no da lista
struct tNo *fim;//ponteiro para o o ultimo no da lista
};

void inicializar(struct tDescritor*);
int menu(int min, int max);
struct tNo* criar_no();
void listar(struct tDescritor);
void inclusao_ordenada(struct tDescritor* ,struct tNo*);
struct tNo* consultar(struct tDescritor,int codigo);
void excluir(struct tDescritor*,struct tNo*);


int main(void) {
  struct tNo *p;
  struct tDescritor descritor;
  inicializar(&descritor);
  int opcao,codigo;
  do{
    opcao = menu(0,4);
    switch(opcao){
      case 1:
       p = criar_no();
      inclusao_ordenada(&descritor, p);
      break;
      case 2:
      listar(descritor);
      break;
      case 3:
      printf("Digite o codigo\n");
      scanf("%d",&codigo);
      p = consultar(descritor,codigo);
      if(p == NULL){
       printf("Codigo não encontrado");
      }else{
       printf("%d -- %f\n",
       p->dado.codigo,     
       p->dado.valor);
      }
      break;
      case 4:
      printf("Digite o codigo\n");
      scanf("%d",&codigo);
       p = consultar(descritor,codigo);
       if(p == NULL){
       printf("Codigo não encontrado");
      }else{
       excluir(&descritor, p);
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
  printf("Digite 4 para excluir......\n");
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

void listar (struct tDescritor lst){//PRINTA TODOS    OS PRODUTOS
 //@Lst RECEBERA STRUCT do tipo tDescritor
 struct tNo *p;
 p = lst.inicio;
 printf("descição-valor\n\n");
 while(p != NULL){
  printf("%d -- %f\n",p->dado.codigo,     
  p->dado.valor);
  p = p->prox;
 }  
}

//INCLUI O NOVO NO ORDENADAMENTE
//@*lst RECEBE A STRCUT tDescritor
//@*p  RECEBERA STRUCT tNo P
void inclusao_ordenada(struct tDescritor *lst,struct tNo *p){
  struct tNo *q;
if((*lst).inicio == NULL  && (*lst).fim == NULL){//INCLUSAO LISTA VASIA
        p->prox = NULL;
        p->anterior = NULL;
        (*lst).inicio = p;
        (*lst).fim = p;
      }else{
        if(p->dado.codigo < (*lst).inicio->dado.codigo){//INCLUSÃO NO INICIO
          (*lst).inicio->anterior = p;
          p->prox = (*lst).inicio;
          (*lst).inicio = p;
        }else{
          if(p->dado.codigo > (*lst).fim->dado.codigo){//INCLUSÃO DE FIM
            (*lst).fim->prox = p;
            p->anterior = (*lst).fim;
            p->prox = NULL;
            (*lst).fim = p;
          }else{//meio
            q = (*lst).inicio;//q aponta para o primeiro da lista
            while(q->dado.codigo < p->dado.codigo)//executa em quanto q->codigo codigo for menor q o p->codigo
              q=q->prox;// avança o q           
            
            p->anterior = q->anterior;
            q->anterior = q->prox;
            p->anterior->prox = p;
            
          }
        }
      }
      (*lst).qtd++;
}

//@lst RECEBE UMA STRUCT DO TIPO tDescritor
//@codigo é chave para busca
struct tNo* consultar(struct tDescritor lst,int codigo){
  struct tNo *q = lst.inicio;
  while((q != NULL)&&(q->dado.codigo <= codigo)){//condição para avançar o q
    if(codigo == q->dado.codigo){//se o codigo for igual a q->codigo
     return q;//retorna q
    }
    q = q->prox;//avança o q
  }
  return NULL;//se nao existir o codigo buscado retorna NULL
}
//@lst RECEBE UMA STRUCT DO TIPO tDescritor
//@vitima No que sera excluido
void excluir(struct tDescritor *lst,struct tNo *vitima){
  struct tNo *p = (*lst).inicio;
 if((*lst).qtd == 1){//EXCLUSÃO DE UNICO
   (*lst).inicio = (*lst).fim = NULL;
 }else{//inicio fim e meio
   if(vitima == (*lst).inicio){//EXCLUSÃO DE INICIO
     vitima->prox->anterior = NULL;
     (*lst).inicio = vitima->prox;
   }else{
     if(vitima->prox == NULL){//EXCLUSÃO DE FIM
       (*lst).fim = vitima->anterior;
       (*lst).fim->prox = vitima->prox;
     }else{//EXCLUSÃO DE MEIO
     while(p->prox != vitima){
       p = p->prox;
     }
     p->prox = vitima->prox;
     p->prox->anterior = vitima->anterior;
     }}
   }
  free(vitima);
  (*lst).qtd--;
}
void inicializar(struct tDescritor *lst){
(*lst).qtd =0;
(*lst).fim = NULL;
(*lst).inicio = NULL;

}