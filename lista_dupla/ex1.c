#include<stdio.h>
#include<stdlib.h>

/*
a) Armazenar o código e o preço de um produto. 
b) Alterar o preço de um produto.
c) Excluir os dados de um produto.
d) Pesquisar o preço de um produto.
e) Exibir os dados de todos os produtos.
*/

struct tproduto{
	int cod;
	float preco;
	struct tproduto *prox;
	struct tproduto *ant;
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
	int codigo;
	float preco;

	novo_p = (tproduto*)malloc(sizeof(tproduto));
	printf("Insira o codigo do produto\n");
	scanf("%d", &codigo);
	printf("Insira o preco do produto\n");
	scanf("%f", &preco);
	novo_p->cod = codigo;
	novo_p->preco = preco;
	novo_p->prox = NULL;
	novo_p->ant = NULL;
	if(catalogo->ini == NULL){
		catalogo->ini = novo_p;
		catalogo->fim = novo_p;
	} else {
		novo_p->ant = catalogo->fim;
		catalogo->fim->prox = novo_p;
		catalogo->fim = novo_p;
	}

}

void alterarPreco(tcatalogo *catalogo){

	tproduto *aux;
	int codigo, npreco;

	if(catalogo->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		printf("Informe o codigo do produto\n");
		scanf("%d", &codigo);
		aux = catalogo->ini;
		while(aux != NULL){
			if(aux->cod == codigo){
				printf("Informe o novo preco do produto %d\n", codigo);
				scanf("%d", &npreco);
				aux->preco = npreco;
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
				aux = catalogo->fim;
				catalogo->fim = aux->ant;
				catalogo->fim->prox = NULL;
				free(aux);
			}
			else{
				while(aux->prox != NULL){
					if(aux->cod == codigo){
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
				printf("O preco do produto e: %.2f\n", aux->preco);
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
			printf("Preco: %.2f\n\n", aux->preco);
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
		printf("2 - Alterar preco\n");
		printf("3 - Excluir\n");
		printf("4 - Pesquisar preco\n");
		printf("5 - Exibir\n");
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
		}
	}
	while(opt != 0);

}