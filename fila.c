//codigo escrito por Gabriel Ramalho
//####################################################################################################################################################################################
//                                                        FILA
//############################################################################################################################################################################################################################
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
//DESCRITOR
struct tDescritor{
  struct tNo *inicio;//PONTEIRO PARA O INICIO DA FILA
  struct tNo *fim;//PONTEIRO PARA O FIM DA FILA
};

void inicializar(struct tDescritor*);
int menu(int min, int max);
struct tNo* criar_no();
void listar(struct tDescritor);
void enqueue(struct tDescritor* ,struct tNo*);
struct tNo* dequeue(struct tDescritor*);
void destruir(struct tDescritor *);


int main(void) {
  struct tNo *p;
  struct tDescritor lst;
  inicializar(&lst);
  int opcao,codigo;
  do{
    opcao = menu(0,3);
    switch(opcao){
      case 1:
       p = criar_no();
      enqueue(&lst, p);
      break;
      case 2:
      listar(lst);
      break;
      case 3:
       p = dequeue(&lst);
       if(p == NULL){
         printf("Fila vazia..");
       }else{
         printf("descição-valor\n\n");
         printf("%d -- %f\n",p->dado.codigo,     
         p->dado.valor);
       }
      break;
    }

  }while(opcao != 0);

  destruir(&lst);
  return 0;
}

int menu(int min,int max) {
  int opcao;
  do{
  printf("\n\n\nDigite 1 para enfileirar..\n");
  printf("Digite 2 para listar....\n");
  printf("Digite 3 para desenfileirar....\n");
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

//ESTA FUNÇÃO NAO FAZ PARTE DE UMA FILA E ESTA SENDO USADA SOMENTE PARA TESTES
//************************************************************************************************************************************************************************************
void listar (struct tDescritor fila){
 struct tNo *p;
 p = fila.inicio;
 printf("descição-valor\n\n");
 while(p != NULL){
  printf("%d -- %f\n",p->dado.codigo,     
  p->dado.valor);
  p = p->prox;
 }  
}
//************************************************************************************************************************************************************************************

//FUNÇÃO PARA ENFILEIRAR
//@FILA RECEBE UMA STRUCT DO TIPO tDescritor
//@p RECEBE O ELEMENTO QUE SERA COLOCADO NA FILA
void enqueue(struct tDescritor *fila,struct tNo *p){
  if((*fila).inicio == NULL){//IF PARA VERIFICAR SE A LISTA ESTÁ VAZIA
    (*fila).inicio = p;
    (*fila).fim = p;
    p->prox = NULL; 
  }else{
    (*fila).fim->prox = p;
    (*fila).fim = p;
    p->prox = NULL;
  }
}

//FUNÇAO PARA DESENFILEIRAR
//RETORNA E RETIRA O PRIMEIRO DA FILA
//@fila RECEBE UMA STRUCT DO TIPO tDescritor
struct tNo* dequeue(struct tDescritor *fila){
  struct tNo *p;
  p = (*fila).inicio;
  if((*fila).inicio != NULL){
  (*fila).inicio = (*fila).inicio->prox;
  }
  return p;
}
//INICIALIZA O DESCRITOR ATRIBUINDO VALOR NULL AO PONTEIRO DO INICIOA DA FILA E DO FIM DA FILA
void inicializar(struct tDescritor *descritor){
 (*descritor).inicio = (*descritor).fim = NULL; 
}

void destruir(struct tDescritor *fila) {
	struct tNo *p=(*fila).inicio, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;		
		free(q);						
	}
	inicializar(fila);
}