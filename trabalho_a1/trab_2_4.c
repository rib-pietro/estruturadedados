#include <stdio.h>
#include <stdlib.h>

/*
Construa um programa que utilize uma lista encadeada dupla ordenada para
implementar uma agenda e realizar as operações abaixo. Lembre que cada operação do
programa deve ser realizada por uma função. Construa um menu para que o usuário
escolha a opção que desejar no programa.
a) Armazenar, em ordem alfabética, o nome e telefone uma pessoa.
b) Consultar o telefone de uma pessoa.
c) Exibir o nome e telefone de todas as pessoas.
d) Remover uma pessoa.
e) Alterar o telefone de uma pessoa.
f) Exibir o telefone de todas as pessoas que possuam o nome informado pelo usuário.
*/

struct tpessoa{
	char nome[50];
	char telefone[11];
	struct tpessoa *prox, *ant;
};

struct tagenda{
	struct tpessoa *ini, *fim;
	int qntd;
};

typedef struct tpessoa tpessoa;
typedef struct tagenda tagenda;

void inicilizar(tagenda *agenda){
	agenda->ini = NULL;
	agenda->fim = NULL;
}

void cadastrar(tagenda *agenda){

	tpessoa *nova_p;

	nova_p = (tpessoa*)malloc(sizeof(tpessoa));
	nova_p->prox = NULL;
	nova_p->ant = NULL;
	strcpy(nova_p->nome, nome);
	if(lista->ini == NULL){
		lista->ini = nova_p;
		lista->fim = nova_p;
	} else {
		aux = lista->ini;
		// printf("nome: %d\n", nome[0]);
		if(nova_p->nome[0] < lista->ini->nome[0]){
			nova_p->prox = lista->ini;
			lista->ini = nova_p;
		} else {
			if(nova_p->nome[0] > lista->fim->nome[0]){
				nova_p->ant = lista->fim;
				nova_p->prox = NULL;
				lista->fim->prox = nova_p;
				lista->fim = nova_p;
			}
			else {
				while(nova_p->nome[0] > aux->nome[0]){
					aux = aux->prox;
				}
				nova_p->ant = aux->ant
				nova_p->prox = aux;
				aux->ant->prox = nova_p;
			}
		}
	}

	lista->qntd+=1;

}

void alterarCadastro(tagenda *agenda){

	tpessoa *aux;
	char nome[50];
	char telefone[11];

	if(agenda->ini == NULL){
		printf("A agenda esta vazia\n");
	} else {
		printf("Informe o nome da pessoa\n");
		scanf("%s", nome);
		aux = agenda->ini;
		while(aux != NULL){
			if(strcmp(aux->nome, nome) == 0){
				printf("Informe o novo telefone de %s\n", aux->nome);
				scanf("%s", aux->telefone);
				printf("Valor alterado!\n");
				break;
			} else {
				aux = aux->prox;
			}
		}
	}

}

void excluir(tagenda *agenda){

	tpessoa *aux, *aux2;
	char nome[50];

	if(agenda->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		printf("Informe o nome da pessoa para excluir\n");
		scanf("%s", nome);
		aux = agenda->ini;
		if(strcmp(agenda->ini->nome, nome) == 0){
			agenda->ini = agenda->ini->prox;
			free(aux);
		} else {
			if(strcmp(agenda->fim->nome, nome) == 0){
				aux = agenda->fim;
				agenda->fim = aux->ant;
				agenda->fim->prox = NULL;
				free(aux);
			}
			else{
				while(aux->prox != NULL){
					if(strcmp(aux->nome, nome) == 0){
						aux2 = aux;
						aux->ant->prox = aux->prox;
						free(aux2);
						break;
					}
					aux = aux->prox;
				}
			}
		}
	}
}

void pesquisaPessoa(tagenda *agenda){

	char nome[50];
	tpessoa *aux;

	if(agenda->ini == NULL){
		printf("A lista esta vazia!");
	} else {

		printf("Informe o nome da pessoa a pesquisar\n");
		scanf("%s", nome);

		aux = agenda->ini;
		while(aux != NULL){
			if(strcmp(aux->nome, nome) == 0){
				printf("O telefone da pessoa e: %s\n", aux->telefone);
				break;
			}
			aux = aux->prox;
		}
	}

}

void exibir(tagenda *agenda){

	tpessoa *aux;

	if(agenda->ini == NULL){
		printf("A lista esta vazia!");
	} else {
		aux = agenda->ini;
		while(aux != NULL){
			printf("Nome: %s\n", aux->nome);
			printf("Telefone: %s\n", aux->telefone);
			aux = aux->prox;
		}
	}

}

void main(){

	int opt;
	tagenda agenda;

	inicilizar(&agenda);
	do{
		printf("1 - Cadastrar pessoa\n");
		printf("2 - Alterar preco\n");
		printf("3 - Excluir\n");
		printf("4 - Pesquisar preco\n");
		printf("5 - Exibir\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				cadastrar(&agenda);
			break;
			case 2:
				alterarCadastro(&agenda);
			break;
			case 3:
				excluir(&agenda);
			break;
			case 4:
				pesquisaPessoa(&agenda);
			break;
			case 5:
				exibir(&agenda);
			break;
		}
	}
	while(opt != 0);

}