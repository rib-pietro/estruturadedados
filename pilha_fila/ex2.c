#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tcarro{
	char modelo[30];
	char placa[11];
	struct tcarro *prox;
};

struct tfila{
	struct tcarro *ini, *fim;
	int qntd;
};

typedef struct tcarro tcarro;
typedef struct tfila tfila;

void inicializar(tfila *fila){

	fila->ini = NULL;
	fila->fim = NULL;
	fila->qntd = 0;

}

void inserir(tfila *fila, char *modelo, char *placa){

	tcarro *novo;

	novo = (tcarro*) malloc(sizeof(tcarro));
	novo->prox = NULL;

	strcpy(novo->modelo, modelo);
	strcpy(novo->placa, placa);

	if(fila->ini == NULL){
		fila->ini = novo;
		fila->fim = novo;
	} else {
		fila->fim->prox = novo;
		fila->fim = novo;
	}

	fila->qntd+=1;

}

void excluir(tfila *fila){

	tcarro *aux;

	if(fila->ini == NULL){
		printf("Fila vazia\n");
	} else {
		aux = fila->ini;
		fila->ini = fila->ini->prox;
		free(aux);
	}

}

void exibirIni(tfila *fila){

	if(fila->ini == NULL){
		printf("Fila vazia\n");
	} else {
		printf("Modelo: %s\n", fila->ini->modelo);
		printf("Placa: %s\n", fila->ini->placa);
	}

}

void trocaFila(tfila *fila){

	tfila fila2;
	tcarro *aux;

	inicializar(&fila2);

	while(fila->ini != NULL){
		inserir(&fila2, fila->ini->modelo, fila->ini->placa);
		excluir(fila);
	}

	exibir(&fila2);

}

void exibir(tfila *fila){

	tcarro *aux;

	aux = fila->ini;

	while(aux != NULL){
		printf("Modelo: %s\n", aux->modelo);
		printf("Placa: %s\n", aux->placa);
		aux = aux->prox;
	}

}

int main(){

	int opt;
	tfila fila;
	char modelo[30], placa[11];

	inicializar(&fila);

	do{
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Exibir topo\n");
		printf("4 - Troca fila\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Informe o modelo:\n");
				scanf("%s", modelo);
				printf("Informe o placa:\n");
				scanf("%s", placa);
				inserir(&fila, modelo, placa);
			break;
			case 2:
				excluir(&fila);
			break;
			case 3:
				exibirIni(&fila);
			break;
			case 4:
				trocaFila(&fila);
			break;
		}
	}
	while(opt != 0);

	return 0;
}