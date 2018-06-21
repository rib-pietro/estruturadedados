#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LISTA ORDENADA
a) Armazenar, em ordem crescente, as idades dos alunos de uma turma. O programa fará
a leitura das idades digitadas até que seja digitada a idade 999.
b) Considerando que temos certeza que um dos alunos da turma tem 18 anos, o programa
deve exibir a quantidade de alunos que tem idade menor que 18 anos.
c) Exibir as idades de todos os alunos que tem 18 anos ou mais.
d) Remover da lista todas as pessoas que tem idade igual a 30 anos.
e) Exibir a idade do aluno mais novo.
*/

struct taluno{
	int idade;
	char nome[30];
	struct taluno *prox;
};

typedef struct taluno taluno;

struct tlista{
	taluno *ini, *fim;
	int quantidade;
};

typedef struct tlista tlista;

void inicializar(tlista *lista){

	lista->ini = NULL;
	lista->fim = NULL;
	lista->quantidade = 0;

}

void cadastrarAluno(tlista *lista, char *nome, int idade){

	taluno *novo_a, *aux;

	novo_a = (taluno*)malloc(sizeof(taluno));
	novo_a->prox = NULL;
	strcpy(novo_a->nome, nome);
	novo_a->idade = idade;
	if(lista->ini == NULL){
		lista->ini = novo_a;
		lista->fim = novo_a;
	} else {
		aux = lista->ini;
		if(novo_a->idade < lista->ini->idade){
			novo_a->prox = lista->ini;
			lista->ini = novo_a;
		} else {
			if(novo_a->idade > lista->fim->idade){
				lista->fim->prox = novo_a;
				lista->fim = novo_a;
			}
			else {
				while(novo_a->idade > aux->prox->idade){
					aux = aux->prox;
				}
				novo_a->prox = aux->prox;
				aux->prox = novo_a;
			}
		}
	}
	
}

int qntdMenores(tlista *lista, int funcao){

	taluno *aux;
	int qntd = 0;

	if(lista->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		aux = lista->ini;
		while(aux != NULL){
			if(aux->idade < 18){
				qntd++;
			} else if(funcao == 3){
				printf("Nome: %s\n", aux->nome);
				printf("Idade: %d\n", aux->idade);
			}
			aux = aux->prox;
		}
	}
	return qntd;
}

int buscar30(tlista *lista){

	taluno *aux;
	int qntd = 0;

	aux = lista->ini;

	while(aux != NULL){
		if(aux->idade == 30){
			qntd++;
		}
		aux = aux->prox;
	}

	return qntd;

}

void excluir_30(tlista *lista){

	taluno *aux, *aux2;

	if(lista->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		aux = lista->ini;
		if(lista->ini->idade == 30){
			lista->ini = lista->ini->prox;
			free(aux);
		} else {
			if(lista->fim->idade == 30){
				while(aux->prox->prox != NULL){
					aux = aux->prox;
				}
				aux2 = aux->prox;
				aux->prox = aux2->prox;
				lista->fim = aux;
				free(aux2);
			} else {
				while(aux != NULL){
					if(aux->prox->idade == 30){
						aux2 = aux->prox;
						aux->prox = aux2->prox;
						free(aux2);
						break;
					}
					aux = aux->prox;
				}
			}
		}
	}

}

void exibir(tlista *lista){

	taluno *aux;

	if(lista->ini == NULL){
		printf("A lista esta vazia\n");
	} else {
		aux = lista->ini;
		while(aux != NULL){
			printf("Nome: %s\n", aux->nome);
			printf("Idade: %d\n", aux->idade);
			aux = aux->prox;
		}
	}

}

void exibirMaisNovo(tlista *lista){
	printf("Nome: %s\n", lista->ini->nome);
	printf("Idade: %s\n", lista->ini->idade);
}

int main(){

	tlista lista;
	int opt, idade = 0, qntd, qntd30, excluido, i;
	char nome[30];

	inicializar(&lista);

	do{
		printf("1 - Cadastrar aluno\n");
		printf("2 - Consultar quantidade de menores\n");
		printf("3 - Exibir maiores\n");
		printf("4 - Remover pessoas com 30 anos\n");
		printf("5 - Exibir aluno mais novo\n");
		printf("6 - Exibir todos\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				while(1){
					printf("Informe o nome do aluno\n");
					scanf("%s", nome);
					printf("Informe a idade do aluno\n");
					scanf("%d", &idade);
					if(idade != 999){
						cadastrarAluno(&lista, nome, idade);
					} else {
						break;
					}
				}
			break;
			case 2:
				qntd = qntdMenores(&lista, 2);
				printf("O numero de alunos menores de 18 anos e: %d\n", qntd);
			break;
			case 3:
				qntdMenores(&lista, 3);
			break;
			case 4:
				qntd30 = buscar30(&lista);
				for(i = 0; i < qntd30; i++){
					excluir_30(&lista);
				}
			break;
			case 5:
				exibirMaisNovo(&lista);
			break;
			case 6:
				exibir(&lista);
			break;
		}
	}
	while(opt != 0);

}