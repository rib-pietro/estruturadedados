#include <stdio.h>
#include <stdlib.h>

/*
1. Construa um programa que implemente as operações abaixo em uma pilha de números
inteiros:
a) Inserir um número.
b) Remover um número.
c) Exibir todos os números de uma pilha.
d) Copiar todos os números para outra pilha.
*/

struct tno{
	int num;
	struct tno *prox;
};

struct tpilha{
	struct tno *ini, *fim;
};

typedef struct tno tno;
typedef struct tpilha tpilha;

void incluir(tpilha *pilha, int dado){

	tno *novo_no;

	novo_no = (tno*) malloc(sizeof(tno));
	novo_no->num = dado;
	novo_no->prox = NULL;

	if(pilha->ini == NULL){
		pilha->ini = novo_no;
		pilha->fim = novo_no;
	} else {
		pilha->fim->prox = novo_no;
		pilha->fim = novo_no;
	}

}

void excluir(tpilha *pilha){

	tno *aux, *aux1;

	if(pilha->ini == NULL){
		printf("Pilha vazia\n");
	} else {
		if(pilha->ini == pilha->fim){
			aux = pilha->ini;
			pilha->ini = NULL;
			pilha->fim = NULL;
			free(aux);
		} else {
			aux = pilha->ini;
			while(aux->prox->prox != NULL){
				aux = aux->prox;
			}
			pilha->fim = aux;
			aux1 = aux->prox;
			aux->prox = NULL;
			free(aux1);
			printf("%d\n", pilha->fim->num);
		}
	}

}

void exibir(tpilha *pilha){

	tno *aux;

	if(pilha->ini == NULL){
		printf("Pilha vazia\n");
	} else {
		aux = pilha->ini;
		while(aux != NULL){
			printf("%d\n", aux->num);
			aux = aux->prox;
		}
	}
}

void copia_pilha(tpilha *pilha){

	tpilha pilha2;
	pilha2.ini = NULL;
	pilha2.fim = NULL;

	while(pilha->fim != NULL){
		incluir(&pilha2, pilha->fim->num);
		excluir(pilha);
	}

	exibir(&pilha2);

}

int main(){

	tpilha pilha;
	int opt, dado;
	pilha.ini = NULL;
	pilha.fim = NULL;

	do{
		printf("1 - Inserir um numero\n");
		printf("2 - Remover um numero\n");
		printf("3 - Exibir numeros\n");
		printf("4 - Copiar dados para outra pilha\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Digite o numero a ser inserido\n");
				scanf("%d", &dado);
				incluir(&pilha, dado);
			break;
			case 2:
				excluir(&pilha);
			break;
			case 3:
				exibir(&pilha);
			break;
			case 4:
				copia_pilha(&pilha);
			break;
		}
	} while(opt != 0);


	return 0;
}