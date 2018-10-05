#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatriz(int (*mat)[5]){

	int i, j, n;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			n = rand() % 20 + 1;
			mat[i][j] = n;
		}
	}

}

void imprimir(int (*mat)[5]){

	int i, j;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

int verifica(int (*mat)[5]){

	int i, j, soma = 0, produto = 1, somas[5], produtos[4], min, max;

	for(j = 0; j < 5; j++){
		for(i = 0; i < 4; i++){
			soma += mat[i][j];
		}
		somas[j] = soma;
		soma = 0;
	}

	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			produto *= mat[i][j];
		}
		produtos[i] = produto;
		produto = 1;
	}

	min = somas[0];
	for(i = 0; i < 4; i++){
		if(somas[i] < min){
			min = somas[i];
		}
	}

	max = produtos[0];
	for(i = 0; i < 5; i++){
		if(produtos[i] > max){
			max = produtos[i];
		}
	}

	if(min <= max){
		return 1;
	} else {
		return 0;
	}

}

int main(){

	int matrizA[4][5], i, j;

	srand(time(NULL));

	preencheMatriz(matrizA);

	imprimir(matrizA);

	if(verifica(matrizA)){
		printf("Condicao Satisfeita\n");
	} else {
		printf("Condicao Nao Satisfeita\n");
	}

	return 0;
}