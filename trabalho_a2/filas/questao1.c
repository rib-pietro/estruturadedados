#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Construa um programa que ajude o funcionário do INSS a organizar as pessoas que serão
atendidas num dia. O programa deve ler os nomes das pessoas que entram na fila de
atendimento até que seja digitado o nome "FIM". Após a leitura do nome "FIM", o
algoritmo deve apresentar os nomes das pessoas que serão atendidas, de acordo com a
ordem da fila.
*/

struct tpaciente {
	char nome[30];
	struct tpaciente *prox;
};

struct tfila {
	struct tpaciente *ini, *fim;
};

typedef struct tpaciente tpaciente;
typedef struct tfila tfila;

void incluir(tfila *fila, char *nome){

	tpaciente *novo_p;

	novo_p = (tpaciente*) malloc(sizeof(tpaciente));
	novo_p->prox = NULL;
	strcpy(novo_p->nome, nome);

	if(fila->ini == NULL){
		fila->ini = novo_p;
		fila->fim = novo_p;
	} else {
		fila->fim->prox = novo_p;
		fila->fim = novo_p;
	}

}

void exibir(tfila *fila){

	tpaciente *aux;

	if(fila->ini == NULL){
		printf("Fila vazia\n");
	} else {
		aux = fila->ini;
		while(aux != NULL){
			printf("%s\n", aux->nome);
			aux = aux->prox;
		}
	}

}

int main(){

	int opt;
	char nome[30];
	tfila fila;
	fila.ini = NULL;
	fila.fim = NULL;

	do{
		printf("1 - Cadastrar pacientes\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				for(;;){
					printf("Nome do paciente:\n");
					scanf("%s", nome);
					if(strcmp(nome, "FIM") != 0){
						break;
					} else {
						incluir(&fila, nome);
					}
				}
			break;
			case 2:
				exibir(&fila);
			break;
		}
	}
	while(opt != 0);

	return 0;
}