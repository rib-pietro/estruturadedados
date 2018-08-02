#include <stdio.h>
#include <stdlib.h>

/* Elabore um programa para construir uma árvore binária de busca de números reais, 
 com as operações: inserir, remover, buscar, exibir os números em ordem, pré-ordem, pós-ordem. */

struct arvore {
	double dado;
	struct arvore *esq, *dir;
};

typedef struct arvore *pont_arvore;

int vazia(pont_arvore pont){
	return (*(pont) == NULL);
}

void inserir(pont_arvore *pont, double dado){

	pont_arvore novo_no;

	if((*pont) == NULL){
		novo_no = (pont_arvore) malloc(sizeof(struct arvore));
		novo_no->dado = dado;
		novo_no->esq = NULL;
		novo_no->dir = NULL;
		(*pont) = novo_no;
	} else {
		if(dado < (*pont)->dado){
			inserir(&((*pont->esq)), dado);
		} else {
			inserir(&((*pont)->dir), dado);
		}
	}
}

pont_arvore getmax(pont_arvore pont){ //função que retorna o no mais a direita
	if(pont->direita == NULL){
		return pont;
	} else {
		return getmax(pont->direita);
	}
}

void em_ordem (pont_arvore pont)
{
   if (pont != NULL)
   {
     em_ordem(pont->esquerda);
     printf("%d\n",pont->elem);
     em_ordem(pont->direita);
   }
}

/*void remover(pont_arvore pont, double dado){

	pont_arvore p, aux;

	if

}*/

int main(){

	pont_arvore raiz = NULL;
	double dado;
	int opt;

	do {
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Buscar\n");
		printf("4 - Exibir em ordem\n");
		printf(" - Exibir pre ordem\n");
		printf("5 - Exibir pos ordem\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Informe o numero: \n");
				scanf("%d", &dado);
				inserir(raiz, dado);
			break;
		}
	}
	while(opt != 0);

}