#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2. Antes de uma corrida de F-1, é feita a tomada de tempos dos pilotos para a formação do
grid de largada. Considerando que podem ser classificados 22 pilotos para cada corrida,
construa um programa que leia os nomes dos 22 pilotos (de acordo com a ordem de
classificação), e que depois apresente os nomes dos pilotos no grid de largada (antes do
nome do piloto, deve ser apresentada a sua posição no grid).
*/

struct tpiloto{
	char nome[30];
	struct tpiloto *prox;
};

struct tfila{
	struct tpiloto *ini, *fim;
	int qntd;
};

typedef struct tpiloto piloto;
typedef struct tfila fila;

void inicializar(&fila){
	fila->ini = NULL;
	fila->fim = NULL;
	fila->qntd = 0;
}

int main(){

	tfila fila;
	int opt;

	do{
		printf("1 - Cadastrar piloto\n");
		printf("2 - Exibir\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				
			break;
		}
	}

	return 0;
}