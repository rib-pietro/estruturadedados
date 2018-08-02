#include <stdio.h>
#include <stdlib.h>

struct tno{
	int dado;
	struct tno *dir, *esq;
};

typedef struct tno tno;

void inserir(tno *raiz, int dado, tno *novo_no){

	if(raiz == NULL){
		raiz = novo_no;
	} else {
		if(dado < raiz->dado){
			if(raiz->esq == NULL){
				raiz->esq = novo_no;
			} else {
				inserir(raiz->esq, dado, novo_no);
			}
		} else {
			if(raiz->dir == NULL){
				raiz->dir = novo_no;
			} else {
				inserir(raiz->dir, dado, novo_no);
			}
		}
	}

}

void exibir(tno *raiz){

	if(raiz != NULL){
		printf("Dado: %d\n", raiz->dado);	
		exibir(raiz->esq);
	}

}

void main(){
	
	tno *arvore, *novo_no;
	int dado;

	arvore = (tno*)malloc(sizeof(tno));
	arvore->dado = 10;
	arvore->dir = NULL;
	arvore->esq = NULL;

	int opt;

	do{
		printf("1 - Inserir\n");
		printf("9 - Exibir\n");
		scanf("%d", &opt);
		switch(opt){
			case 1: 
				printf("Informe o dado do novo no\n");
				scanf("%d", &dado);

				novo_no = (tno*)malloc(sizeof(tno));
				novo_no->dado = dado;
				novo_no->dir = NULL;
				novo_no->esq = NULL;

				inserir(arvore, dado, novo_no);
			break;
			case 9:
				exibir(arvore);
			break;
		}
	}
	while(opt != 0);

}