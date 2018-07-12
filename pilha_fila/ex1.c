#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tpessoa{
	char nome[30];
	char cpf[11];
	struct tpessoa *prox;
};

struct tpilha{
	struct tpessoa *ini, *fim;
	int qntd;
};

typedef struct tpessoa tpessoa;
typedef struct tpilha tpilha;

void inicializar(tpilha *pilha){

	pilha->ini = NULL;
	pilha->fim = NULL;
	pilha->qntd = 0;

}

void inserir(tpilha *pilha){

	tpessoa *novo;
	char nome[30], cpf[11];

	novo = (tpessoa*) malloc(sizeof(tpessoa));
	novo->prox = NULL;

	printf("Informe o nome:\n");
	scanf("%s", nome);
	printf("Informe o cpf:\n");
	printf("%s\n", cpf);

	strcpy(novo->nome, nome);
	strcpy(novo->cpf, cpf);

	if(pilha->ini == NULL){
		pilha->ini = novo;
		pilha->fim = novo;
	} else {
		pilha->fim->prox = novo;
		pilha->fim = novo;
	}

	pilha->qntd+=1;

}

void excluir(tpilha *pilha){

	tpessoa *aux;

	if(pilha->ini == NULL){
		printf("Pilha vazia\n");
	} else {
		aux = pilha->ini;
		while(aux->prox->prox != NULL){
			aux = aux->prox;
		}
		pilha->fim = aux;
		free(aux->prox);
	}

}

void exibirTopo(tpilha *pilha){

	if(pilha->ini == NULL){
		printf("Pilha vazia\n");
	} else {
		printf("Nome: %s\n", pilha->fim->nome);
		printf("Cpf: %s\n", pilha->fim->cpf);
	}

}

int main(){

	int opt;
	tpilha pilha;

	inicializar(&pilha);

	do{
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Exibir topo\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				inserir(&pilha);
			break;
			case 2:
				excluir(&pilha);
			break;
			case 3:
				exibirTopo(&pilha);
			break;
		}
	}
	while(opt != 0);

	return 0;
}