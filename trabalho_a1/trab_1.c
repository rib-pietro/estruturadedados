#include <stdio.h>
#include <stdlib.h>
#define TAM 100

/*
a) Armazenar o nome, a idade e o telefone de até 100 pessoas. O programa fará a leitura
dos dados das pessoas até que seja digitada a palavra “FIM” no lugar do nome da
pessoa.
b) Alterar a idade e o telefone de uma pessoa. O usuário digitará o nome da pessoa a ser
procurada para fazer a alteração.
c) Organizar em ordem alfabética os dados das pessoas (utilize um algoritmo de
ordenação estudado).
d) Pesquisar a idade e o telefone de uma pessoa, a partir do seu nome (utilize o algoritmo
de busca binária).
e) Exibir os dados de todas as pessoas.
*/

struct tpessoa{
	int idade;
	char nome[50];
	char tel[15];
};

typedef struct tpessoa pessoa;

struct tagenda{
	pessoa lista[TAM];
	int quantidade;
};

typedef struct tagenda agenda;

void exibir(agenda *lista){

	int i;

	if(lista->quantidade == 0){
		printf("A lista esta vazia!\n");
	} else {
		for(i = 0; i < lista->quantidade; i++){

			printf("Nome: %s\n", lista->lista[i].nome);
			printf("Idade: %d\n", lista->lista[i].idade);
			printf("Telefone: %s\n\n", lista->lista[i].tel);

		}
	}

}

void alteraCadastro(agenda *lista){

	char nome[50], tel[15];
	int idade, i;


	if(lista->quantidade == 0){
		printf("A lista esta vazia!\n");
	} else{
		printf("Informe o nome da pessoa para alterar\n");
		scanf("%s", nome);
		for(i = 0; i < lista->quantidade; i++){

			if(strcmp(lista->lista[i].nome, nome) == 0){

				printf("Digite o novo telefone\n");
				scanf("%s", tel);
				printf("Informe a nova idade\n");
				scanf("%d", &idade);
				strcpy(lista->lista[i].tel, tel);
				lista->lista[i].idade = idade;
				break;

			}

		}
	}

}

void ordemAlfab(agenda *lista){

	char a, aux_nome[50], aux_tel[15];
	int i, j, menor = 0, aux_idade;

	if(lista->quantidade == 0){
		printf("A lista esta vazia\n");
	} else {
		for(i = 0; i < lista->quantidade - 1; i++){
			menor = i;
			for(j = i+1; j < lista->quantidade; j++){
				printf("%c\n", lista->lista[j].nome[0]);
				if(lista->lista[j].nome[0] < lista->lista[menor].nome[0]){
					menor = j;
				}
			}
			aux_idade = lista->lista[i].idade;
			lista->lista[i].idade = lista->lista[menor].idade;
			lista->lista[menor].idade = aux_idade;
			strcpy(aux_nome, lista->lista[i].nome);
			strcpy(lista->lista[i].nome, lista->lista[menor].nome);
			strcpy(lista->lista[menor].nome, aux_nome);
			strcpy(aux_tel, lista->lista[i].tel);
			strcpy(lista->lista[i].tel, lista->lista[menor].tel);
			strcpy(lista->lista[menor].tel, aux_tel);
		}
	}

}

void pesquisaPessoa(agenda *lista){

	char nome[50];

	if(lista->quantidade == 0){
		printf("A lista esta vazia!\n");
	} else {
		printf("Digite o nome da pessoa a buscar\n");
		scanf("%s", nome);

		for(int i = 0; i < lista->quantidade; i++){
			if(strcmp(nome, lista->lista[i].nome)){
				printf("Telefone: %s\n", lista->lista[i].tel);
				printf("Idade: %d\n", lista->lista[i].idade);
			}
		}
	}

}

int main(){

	agenda lista;
	char nome[50], tel[15];
	int i, opt, idade;

	lista.quantidade = 0;

	do{
		printf("Informe o nome da pessoa\n");
		scanf("%s", nome);
		if (!(strcmp(nome, "FIM") == 0))
		{
			strcpy(lista.lista[lista.quantidade].nome, nome);
			printf("Informe a idade dessa pessoa\n");
			scanf("%d", &idade);
			printf("Informe o telefone dessa pessoa\n");
			scanf("%s", tel);
			lista.lista[lista.quantidade].idade = idade;
			strcpy(lista.lista[lista.quantidade].tel, tel);
			lista.quantidade+=1;
			opt = 1;
		} else {
			printf("1 - Alterar idade e telefone\n");
			printf("2 - Organizar lista por ordem alfabetica\n");
			printf("3 - Pesquisar idade e telefone\n");
			printf("4 - Exibir\n");
			printf("0 - Sair\n");
			scanf("%d", &opt);
			switch(opt){
				case 1:
					alteraCadastro(&lista);
				break;
				case 2:
					ordemAlfab(&lista);
				break;
				case 3:
					pesquisaPessoa(&lista);
				break;
				case 4:
					exibir(&lista);
				break;
			}
		}
	}
	while(opt != 0);

	return 0;
}