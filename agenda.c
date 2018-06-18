#include <stdio.h>
#include <string.h>
#define TAM 5

struct pessoa{

	char nome[40];
	int idade;

};

typedef struct pessoa pessoa;

struct agenda{

	pessoa lista[TAM];
	int quantidade;

};

typedef struct agenda agenda;

void cadastrarPessoa(agenda *agend){

	int idade;
	char nome[40];

	printf("Informe o nome da pessoa:");
	scanf("%s", agend->lista[agend->quantidade].nome);
	printf("Informe a idade de %s", agend->lista[agend->quantidade].nome);
	scanf("%d", &idade);

	agend->lista[agend->quantidade].idade = idade;

	agend->quantidade+=1;

}

void ordenaIdade(agenda *agend){

	pessoa aux;
	int total = agend->quantidade;
	int menor = 1;

	for(int i = 0; i < total - 1; i++){
		for(int j = i + 1; j < total; j++){

			if(agend->lista[j].idade < agend->lista[menor].idade){

				menor = j;

			}

		}

		strcpy(aux.nome, agend->lista[i].nome);
		aux.idade = agend->lista[i].idade;
		strcpy(agend->lista[i].nome, agend->lista[menor].nome);
		agend->lista[i].idade = agend->lista[menor].idade;
		strcpy(agend->lista[menor].nome, aux.nome);
		agend->lista[menor].idade = aux .idade;

	}

}

void imprimirDados(agenda *agend){

	for(int i = 0; i < agend->quantidade; i++){

		printf("Nome: %s\n", agend->lista[i].nome);
		printf("Idade: %d\n\n", agend->lista[i].idade);

	}

}

int main(){

	int opt;
	agenda agend[TAM];
	agend->quantidade = 0;

	do{

		printf("1 - Cadastrar pessoa\n");
		printf("2 - Ordenar pessoas por idade\n");
		printf("3 - Pesquisar idade de uma pessoa\n");
		printf("4 - Exibir agenda\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){

			case 1:
				cadastrarPessoa(&agend);
			break;
			case 2:
				ordenaIdade(&agend);
				imprimirDados(agend);
			break;
			case 3:
				
			break;
			case 4:
				imprimirDados(&agend);
			break;

		}

	}
	while(opt != 0);

	return 0;
}