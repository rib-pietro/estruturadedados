#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000

/*
Armazenar a matrícula, o nome e o endereço de até 1000 alunos.
• Alterar o endereço de um aluno. O usuário digitará a matrícula do aluno a ser
procurado para fazer a alteração.
• Organizar em ordem crescente de matrícula os dados dos alunos (utilize um algoritmo
de ordenação estudado).
• Pesquisar o nome e endereço de um aluno, a partir da sua matrícula (utilize o
algoritmo de busca binária).
• Exibir os dados de todos os alunos.
*/

struct taluno{
	char nome[20];
	char matricula[20];
	char endereco[20];
};

typedef struct taluno aluno;

struct tacadem{
	aluno lista[TAM];
	int quantidade;
};

typedef struct tacadem academ;

void cadastraAluno(academ *lista){

	char matricula[20], endereco[20], nome[20];

	printf("Informe o nome do aluno\n");
	scanf("%s", nome);
	printf("Informe a matricula do aluno\n");
	scanf("%s", matricula);
	printf("Informe o endereco dessa aluno\n");
	scanf("%s", endereco);
	strcpy(lista->lista[lista->quantidade].nome, nome);
	strcpy(lista->lista[lista->quantidade].matricula, matricula);
	strcpy(lista->lista[lista->quantidade].endereco, endereco);
	lista->quantidade+=1;

}

void exibir(academ *lista){

	int i;

	if(lista->quantidade == 0){
		printf("A lista esta vazia!\n");
	} else {
		for(i = 0; i < lista->quantidade; i++){

			printf("nome: %s\n", lista->lista[i].nome);
			printf("matricula: %s\n", lista->lista[i].matricula);
			printf("endereco: %s\n\n", lista->lista[i].endereco);

		}
	}

}

void alteraCadastro(academ *lista){

	char matricula[20], endereco[20], nome[20];
	int i;


	if(lista->quantidade == 0){
		printf("A lista esta vazia!\n");
	} else{
		printf("Informe a matricula da aluno para alterar\n");
		scanf("%s", matricula);
		for(i = 0; i < lista->quantidade; i++){

			if(strcmp(lista->lista[i].matricula, matricula) == 0){

				printf("Digite o novo endereco\n");
				scanf("%s", endereco);
				printf("Informe o novo nome\n");
				scanf("%s", nome);
				strcpy(lista->lista[i].endereco, endereco);
				strcpy(lista->lista[i].nome, nome);
				break;

			}

		}
	}

}

void ordemAlfab(academ *lista){

	char a, aux_matricula[20], aux_endereco[20], aux_nome[20];
	int i, j, menor = 0;

	if(lista->quantidade == 0){
		printf("A lista esta vazia\n");
	} else {
		for(i = 0; i < lista->quantidade - 1; i++){
			menor = i;
			for(j = i+1; j < lista->quantidade; j++){
				
				if(lista->lista[j].matricula[0] < lista->lista[menor].matricula[0]){
					menor = j;
				}
			}
			strcpy(aux_nome, lista->lista[i].nome);
			strcpy(lista->lista[i].nome, lista->lista[menor].nome);
			strcpy(lista->lista[menor].nome, aux_nome);
			strcpy(aux_matricula, lista->lista[i].matricula);
			strcpy(lista->lista[i].matricula, lista->lista[menor].matricula);
			strcpy(lista->lista[menor].matricula, aux_matricula);
			strcpy(aux_endereco, lista->lista[i].endereco);
			strcpy(lista->lista[i].endereco, lista->lista[menor].endereco);
			strcpy(lista->lista[menor].endereco, aux_endereco);
		}
	}

}

void pesquisaAluno(academ *lista){

	int esq, dir, pos = -1, meio;
	char matricula[20];

	esq = 0;
	dir = lista->quantidade - 1;

	if(lista->quantidade == 0){
		printf("A lista esta vazia!\n");
	} else {
		printf("Digite o matricula da aluno a buscar\n");
		scanf("%s", matricula);

		ordemAlfab(lista);

		while(esq <= dir){
			meio = (esq + dir)/2;
			if(strcmp(lista->lista[meio].matricula, matricula) == 0){
				pos = meio;
				break;
			} else if(lista->lista[meio].matricula[0] < matricula[0]) {
				esq = meio + 1;
			} else {
				dir = meio - 1;
			}
		}

		if(pos == -1){
			printf("O matricula nao consta na lista\n");
		} else {
			printf("Nome: %s\n", lista->lista[pos].nome);
			printf("endereco: %s\n", lista->lista[pos].endereco);
		}

	}

}

int main(){

	academ lista;
	
	int i, opt, idade;

	lista.quantidade = 0;

	do{
		printf("1 - Cadastrar aluno\n");
		printf("2 - Alterar idade e endereco\n");
		printf("3 - Organizar lista por ordem alfabetica\n");
		printf("4 - Pesquisar nome e endereco\n");
		printf("5 - Exibir\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				cadastraAluno(&lista);
			break;
			case 2:
				alteraCadastro(&lista);
			break;
			case 3:
				ordemAlfab(&lista);
			break;
			case 4:
				pesquisaAluno(&lista);
			break;
			case 5:
				exibir(&lista);
			break;
		}
	}
	while(opt != 0);

	return 0;
}