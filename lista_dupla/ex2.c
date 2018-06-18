#include <stdio.h>
#include <stdlib.h>

/*
a) Inserir o nome, endereço e telefone de uma pessoa na lista.
b) Alterar o endereço e telefone de uma pessoa.
c) Excluir uma pessoa da lista.
d) Pesquisar o endereço e telefone de uma pessoa.
e) Exibir os dados de todas as pessoas da lista.
f) Informar quantas pessoas da lista possuem um determinado nome a ser informado pelo usuário.
*/

struct tpessoa{
	char nome[50];
	int idade;
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
	char nome[50], telefone[11];
	int idade;

	nova_p = (tpessoa*)malloc(sizeof(tpessoa));
	printf("Insira o nome da pessoa\n");
	scanf("%s", nome);
	printf("Insira a idade da pessoa\n");
	scanf("%d", &idade);
	printf("Insira o telefone da pessoa\n");
	scanf("%s", telefone);
	strcpy(nova_p->nome, nome);
	strcpy(nova_p->telefone, telefone);
	nova_p->idade = idade;

	// printf("Nome: %s\n", nova_p->nome);
	// printf("Telefone: %s\n", nova_p->telefone);
	// printf("Idade: %d\n", nova_p->idade);

	nova_p->prox = NULL;
	if(agenda->ini == NULL){
		agenda->ini = nova_p;
		agenda->fim = nova_p;
	} else {
		nova_p->ant = agenda->fim;
		agenda->fim->prox = nova_p;
		agenda->fim = nova_p;
	}

}

void alterarCadastro(tagenda *agenda){

	tpessoa *aux;
	char nome[50];
	char telefone[11];
	int idade;

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
				printf("Informe a nova idade de %s\n", aux->nome);
				scanf("%d", &idade);
				aux->idade = idade;
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
				printf("A idade da pessoa e: %d\n", aux->idade);
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
			printf("Idade: %d\n\n", aux->idade);
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