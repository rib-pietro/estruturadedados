#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Construa um programa que utilize uma lista encadeada simples ordenada para:
a) Armazenar, em ordem alfabética, n palavras, até que seja digitada a palavra "xyz". No
entanto, caso seja digitada uma palavra que já exista na lista, ela não deve ser
armazenada novamente.
b) Exibir todas as palavras da lista.
*/

struct tpalavra{
	char palavra[15];
	struct tpalavra *prox;
};

struct tlista{
	struct tpalavra *ini, *fim;
	int qntd;
};

typedef struct tpalavra tpalavra;
typedef struct tlista tlista;

void inicializar(tlista *lista){
	lista->ini = NULL;
	lista->fim = NULL;
	lista->qntd = 0;
}

int buscarPalavra(tlista *lista, char *palavra){

	tpalavra *aux;

	aux = lista->ini;

	while(aux != NULL){
		if(strcmp(aux->palavra, palavra) == 0){
			return 1;
		} else {
			aux = aux->prox;
		}
	}

	// if(aux == NULL){
	// 	armazenar(lista, palavra);
	// }
	return 0;

}

void armazenar(tlista *lista, char *palavra){

	tpalavra *nova_p, *aux;

	nova_p = (tpalavra*)malloc(sizeof(tpalavra));
	nova_p->prox = NULL;
	strcpy(nova_p->palavra, palavra);
	if(lista->ini == NULL){
		lista->ini = nova_p;
		lista->fim = nova_p;
	} else {
		aux = lista->ini;
		// printf("Palavra: %d\n", palavra[0]);
		if(nova_p->palavra[0] < lista->ini->palavra[0]){
			nova_p->prox = lista->ini;
			lista->ini = nova_p;
		} else {
			if(nova_p->palavra[0] > lista->fim->palavra[0]){
				lista->fim->prox = nova_p;
				lista->fim = nova_p;
			}
			else {
				while(nova_p->palavra[0] > aux->prox->palavra[0]){
					aux = aux->prox;
				}
				nova_p->prox = aux->prox;
				aux->prox = nova_p;
			}
		}
	}

	lista->qntd+=1;

}

void exibir(tlista *lista){

	tpalavra *aux;

	if(lista->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		aux = lista->ini;
		while(aux != NULL){
			printf("Palavra: %s\n", aux->palavra);
			aux = aux->prox;
		}
	}

}

int main(){

	int opt;
	char palavra[15];
	tlista lista;

	inicializar(&lista);

	do{
		printf("1 - Armazenar palavra\n");
		printf("2 - Exibir\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				while(1){
					printf("Informe a palavra digitada\n");
					scanf("%s", palavra);
					if(!strcmp(palavra, "xyz") == 0){
						if(!buscarPalavra(&lista, palavra)){
							armazenar(&lista, palavra);
						} else {
							printf("Palavra ja armazenada\n");
							break;
						}
					} else {
						break;
					}
				}
				
				// while(1){
				// 	printf("Informe a palavra digitada\n");
				// 	scanf("%s", palavra);
				// 	// printf("Palavra: %c\n", palavra[0]);
				// 	if(strcmp(palavra, 'xyz') != 0){
				// 		if(buscarPalavra(&lista, palavra)){
				// 			printf("Esta palavra ja esta cadastrada\n");
				// 		} else {
				// 			// printf("ME chama de meu nego\n");
							
				// 		}
				// 	} else {
				// 		break;
				// 	}
				// }
			break;
			case 2:
				exibir(&lista);
			break;
		}
	}
	while(opt != 0);

}