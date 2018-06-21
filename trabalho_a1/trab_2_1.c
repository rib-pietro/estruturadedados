#include <stdio.h>
#include <stdlib.h>

/*
a) Armazenar o código, nome e preço de um produto.
b) Pesquisar o nome e o preço de um produto
c) Alterar o nome e o preço de um produto.
d) Excluir um produto da lista.
e) Exibir os dados de todos os produtos da lista.
f) Exibir o código e nome dos produtos da lista que estão numa determinada faixa de
preços, informada pelo usuário.
*/

struct tproduto{
	int cod;
	float preco;
	char nome[30];
	struct tproduto *prox;
};

struct tcatalogo{
	struct tproduto *ini, *fim;
};

typedef struct tproduto tproduto;
typedef struct tcatalogo tcatalogo;

void inicilizar(tcatalogo *catalogo){
	catalogo->ini = NULL;
	catalogo->fim = NULL;
}

void cadastrar(tcatalogo *catalogo){

	tproduto *novo_p;
	char nome[30];
	int codigo;
	float preco;

	novo_p = (tproduto*)malloc(sizeof(tproduto));
	printf("Insira o codigo do produto\n");
	scanf("%d", &codigo);
	printf("Insira o nome do produto\n");
	scanf("%s", nome);
	printf("Insira o preco do produto\n");
	scanf("%f", &preco);
	novo_p->cod = codigo;
	novo_p->preco = preco;
	strcpy(novo_p->nome, nome);
	novo_p->prox = NULL;
	if(catalogo->ini == NULL){
		catalogo->ini = novo_p;
		catalogo->fim = novo_p;
	} else {
		catalogo->fim->prox = novo_p;
		catalogo->fim = novo_p;
	}

}

void alterarPreco(tcatalogo *catalogo){

	tproduto *aux;
	int codigo;
	float npreco;
	char nnome[30];

	if(catalogo->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		printf("Informe o codigo do produto\n");
		scanf("%d", &codigo);
		aux = catalogo->ini;
		while(aux != NULL){
			if(aux->cod == codigo){
				printf("Informe o novo preco do produto\n");
				scanf("%f", &npreco);
				printf("Informe o novo nome do produto\n");
				scanf("%s", nnome);
				aux->preco = npreco;
				strcpy(aux->nome, nnome);
				printf("Valor alterado!\n");
				break;
			} else {
				aux = aux->prox;
			}
		}
	}

}

void excluir(tcatalogo *catalogo){

	tproduto *aux, *aux2;
	int codigo;

	if(catalogo->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		printf("Informe o codigo do produto para excluir\n");
		scanf("%d", &codigo);
		aux = catalogo->ini;
		if(catalogo->ini->cod == codigo){
			catalogo->ini = catalogo->ini->prox;
			free(aux);
		} else {
			if(catalogo->fim->cod == codigo){
				while(aux->prox->prox != NULL){
					aux = aux->prox;
				}
				catalogo->fim = aux;
				aux->prox = NULL;
				free(aux->prox);
			}
			else{
				while(aux->prox != NULL){
					if(aux->prox->cod == codigo){
						aux2 = aux->prox;
						aux->prox = aux2->prox;
						free(aux2);
					}
					aux = aux->prox;
				}
			}
		}
	}
}

void pesquisaPreco(tcatalogo *catalogo){

	int cod;
	tproduto *aux;

	if(catalogo->ini == NULL){
		printf("A lista esta vazia!");
	} else {

		printf("Informe o codigo do produto a pesquisar\n");
		scanf("%d", &cod);

		aux = catalogo->ini;
		while(aux != NULL){
			if(aux->cod == cod){
				printf("Nome: %s\n", aux->nome);
				printf("Preco: %.2f\n", aux->preco);
				break;
			}
			aux = aux->prox;
		}
	}

}

void exibir(tcatalogo *catalogo){

	tproduto *aux;

	if(catalogo->ini == NULL){
		printf("A lista esta vazia!");
	} else {
		aux = catalogo->ini;
		while(aux != NULL){
			printf("Codigo: %d\n", aux->cod);
			printf("Nome: %s\n", aux->nome);
			printf("Preco: %.2f\n\n", aux->preco);
			aux = aux->prox;
		}
	}

}

void exibirPorPreco(tcatalogo *catalogo){

	float min_preco, max_preco;
	tproduto *aux;

	if(catalogo->ini == NULL){
		printf("A lista esta vazia!");
	} else {
		printf("Informe o preco minimo:\n");
		scanf("%f", &min_preco);
		printf("Informe o preco maximo\n");
		scanf("%f", &max_preco);
		aux = catalogo->ini;
		while(aux != NULL){
			if(aux->preco > min_preco && aux->preco < max_preco){
				printf("Codigo: %d\n", aux->cod);
				printf("Nome: %s\n", aux->nome);
				printf("Preco: %.2f\n\n", aux->preco);
			}
			aux = aux->prox;
		}
	}



}

void main(){

	int opt;
	tcatalogo catalogo;

	inicilizar(&catalogo);
	do{
		printf("1 - Cadastrar Produto\n");
		printf("2 - Pesquisar preco\n");
		printf("3 - Alterar preco\n");
		printf("4 - Excluir\n");
		printf("5 - Exibir\n");
		printf("6 - Exibir por preco\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				cadastrar(&catalogo);
			break;
			case 2:
				alterarPreco(&catalogo);
			break;
			case 3:
				excluir(&catalogo);
			break;
			case 4:
				pesquisaPreco(&catalogo);
			break;
			case 5:
				exibir(&catalogo);
			break;
			case 6:
				exibirPorPreco(&catalogo);
			break;
		}
	}
	while(opt != 0);

}