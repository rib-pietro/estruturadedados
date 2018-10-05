#include <stdio.h>
#include <stdlib.h>

void leMatriz(int (*mat)[3]){

	FILE *arqEnt;
	int i, j;

	arqEnt = fopen("MatrizM.txt", "r");

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			fscanf(arqEnt, "%d", &mat[i][j]);
		}
	}

	fclose(arqEnt);

}

void calculaTransp(int (*mat)[3], int (*matT)[3]){

	int i, j;

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			matT[i][j] = mat[j][i];
		}
	}

}

void multiplica(int (*mat)[3], int (*matT)[3]){

	

}

void imprimir(int (*mat)[3]){

	int i, j;

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

int main(){

	int matriz[3][3], matrizT[3][3];

	leMatriz(matriz);

	calculaTransp(matriz, matrizT);

	imprimir(matrizT);

	return 0;
}