//####################################################################################################################################################################################
//                          Arvore AVL
//                   codigo escrito por : Gabriel Ramalho
//####################################################################################################################################################################################

#include <stdio.h>
#include <stdlib.h>

#define SAIR 0
#define INCLUIR 1
#define BUSCAR 2
#define CAMINHAR_PRE_ORDEM 3
#define CAMINHAR_POS_ORDEM 4
#define CAMINHAR_EM_ORDEM 5
#define EXCLUIR 6
#define DESENHAR 7

struct dado {
	int codigo;
	int valor;
};

struct folha {
	struct dado dado;
	struct folha *direita;
	struct folha *esquerda;
};

int le_opcao(int, int);
void incluir(struct folha **, struct folha *);
void inicializar(struct folha **);
struct folha *buscar(struct folha *raiz, int p);
void caminhar_em_ordem(struct folha *);
void caminhar_preOrdem(struct folha *);
void caminhar_posOrdem(struct folha *);
int excluir(struct folha **, int cod);
struct folha *buscarMd(struct folha *raiz);
void desenhar(struct folha *);
int alturaArvoree(struct folha *,int);
int alturaArvored(struct folha *,int);
int fb(int,int);

int main(void) {
	struct folha *raiz, *p, *q;
	int codigo;
	int opcao, alturaE = 0,alturaD = 0,fatorBalanceamento = 0;;
	inicializar(&raiz);
	do {
    printf("\n\n");
		opcao = le_opcao(8, 0);
    printf("\n\n");
		switch (opcao) {
		case INCLUIR:
			/* p = (struct folha*) malloc(sizeof(struct folha));
			 printf("Digite o codigo:\n\n");
			 scanf("%i", &p->dado.codigo);
			 printf("Digite o valor:\n\n");
			 scanf("%i", &p->dado.valor);
			 incluir(&raiz,p);*/
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 10;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 7;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 15;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 20;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 8;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 4;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 5;
			incluir(&raiz, p);
			p = (struct folha *)malloc(sizeof(struct folha));
			p->dado.codigo = 3;
			incluir(&raiz, p);
			//p = (struct folha *)malloc(sizeof(struct folha));
			//p->dado.codigo = 21;
			//incluir(&raiz, p);
			break;
		case BUSCAR:
			printf("Digite o codigo\n");
			scanf("%i", &codigo);
			q = buscar(raiz, codigo);
			printf("codigo-valor %i-%i\n", q->dado.codigo, q->dado.valor);
			break;
		case CAMINHAR_PRE_ORDEM:
			caminhar_preOrdem(raiz);
      printf("\n");
			break;
		case CAMINHAR_POS_ORDEM:
			caminhar_posOrdem(raiz);
      printf("\n");
			break;
		case CAMINHAR_EM_ORDEM:
			caminhar_em_ordem(raiz);
      printf("\n");
			break;
		case 6:
			printf("Digite o codigo:");
			scanf("%i", &codigo);
			excluir(&raiz, codigo);
			break;
    case DESENHAR:
      desenhar(raiz);
      printf("\n");
      break;
    case 8:
    printf("Digite o codigo\n");
		scanf("%i", &codigo);
		q = buscar(raiz, codigo);
    alturaE = alturaArvoree(q->esquerda, alturaE);
    printf("altura esquerda: %i\n",alturaE);
    alturaD = alturaArvored(q->direita, alturaD);
    printf("altura direita: %i\n",alturaD);
    fatorBalanceamento = fb(alturaD,alturaE);
    printf("Fator balanceamento: %i",fatorBalanceamento);
    break; 
    }
	} while (opcao != SAIR);
	return 0;
}

int le_opcao(int max, int min) {
	int opcao;
	
  printf("Digite 1 para incluir...\n");
	printf("Digite 2 para buscar....\n");
  printf("Digite 3 para caminhar em ordem.\n");
  printf("Digite 4 para caminhar em pos ordem.\n");
  printf("Digite 5 para caminhar em pre ordem.\n");
  printf("Digite 6 para excluir\n");
  printf("Digite 7 desenhar\n");
	scanf("%i", &opcao);
	if (opcao > max || opcao < min) {
		printf("Opção invalida...\n\n");
		printf("Aperte qualquer tecla para continuar...\n\n");
		getchar();
	}
	return opcao;
}

void incluir(struct folha **raiz, struct folha *novo) {
	if ((*raiz) == NULL) {
		novo->esquerda = novo->direita = NULL;
		(*raiz) = novo;
	} else {
		if (novo->dado.codigo < (*raiz)->dado.codigo) {
			return incluir((&(*raiz)->esquerda), novo);
		} else {
			return incluir((&(*raiz)->direita), novo);
		}
	}
}

struct folha *buscar(struct folha *raiz, int p) {
	if (raiz->dado.codigo == p) {
		return raiz;
	} else {
		if (p < raiz->dado.codigo) {
			return buscar(raiz->esquerda, p);
		} else {
			return buscar(raiz->direita, p);
		}
	}
}

void inicializar(struct folha **raiz) {
	(*raiz) = NULL;
}

void caminhar_preOrdem(struct folha *raiz) {
	if (raiz == NULL) {
		return;
	}
	printf("%i,", raiz->dado.codigo);
	caminhar_preOrdem(raiz->esquerda);
	caminhar_preOrdem(raiz->direita);

}

void caminhar_posOrdem(struct folha *raiz) {
	if (raiz == NULL) {
		return;
	}
	caminhar_posOrdem(raiz->esquerda);
	caminhar_posOrdem(raiz->direita);
	printf("%i  ", raiz->dado.codigo);
}

void caminhar_em_ordem(struct folha *raiz) {
	if (raiz == NULL) {
		return;
	}
	caminhar_em_ordem(raiz->esquerda);
	printf("%i,  ", raiz->dado.codigo);
	caminhar_em_ordem(raiz->direita);
}

int excluir(struct folha **raiz, int codigo) {
	struct folha *q = (*raiz), *p;
	if ((*raiz)->dado.codigo == codigo) {
		if ((*raiz)->direita == NULL && (*raiz)->esquerda == NULL) {
			(*raiz) = NULL;
			free(q);
			return 1;
		} else {
			if ((*raiz)->direita == NULL) { // esquerda
				(*raiz) = (*raiz)->esquerda;
				free(q);
				return 1;
			} else {
				if ((*raiz)->esquerda == NULL) { // direita
					(*raiz) = (*raiz)->direita;
					free(q);
					return 1;
				} else { // 2 filhos
					q = buscarMd((*raiz)->esquerda);
					(*raiz)->dado = q->dado;
					excluir(&(*raiz)->esquerda, q->dado.codigo);
					return 1;
				}
			}
		}
	} else {
		if (codigo < (*raiz)->dado.codigo) {
			return excluir((&(*raiz)->esquerda), codigo);
		} else {
			return excluir(&((*raiz)->direita), codigo);
		}
	}
	return 0;
}
struct folha *buscarMd(struct folha *raiz) {
	struct folha *j = raiz;
	if (j->direita != NULL) {
		j = j->direita;
	} 
	return j;
}

void desenhar(struct folha *raiz) {
	if (raiz == NULL) {
    printf("()");
		return;
	}
	printf("(%i", raiz->dado.codigo);
	desenhar(raiz->esquerda);
	desenhar(raiz->direita);
  printf(")");
}

int alturaArvoree(struct folha *raiz,int altura){
struct folha  *j = raiz;
if (j == NULL) {
		return altura;
	} else {
    altura++;
	 return alturaArvoree(raiz->esquerda,altura);
	}

}
int alturaArvored(struct folha *raiz,int altura){
struct folha  *j = raiz;
if (j == NULL) {
		return altura;
	} else {
    altura++;
	 return alturaArvored(raiz->direita,altura);
	}
}

int fb(int alturaD,int alturaE){
  int fb;
 fb = alturaD - alturaE;
 return fb;
}