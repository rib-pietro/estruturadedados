#include <stdio.h>

struct tvertice{
	int n;
	struct tvertice *prox;
};

typedef struct tvertice vertice;

void linhaDinamica(int nVertices, FILE *arqEnt, *vertices){

	for(int i = 0; i < nVertices; i++){

	}

}

void getVertices(int nVertices, FILE *arqEnt, *vertices){

	int cont = 0, n, encontrado = 0;

	while(!feof(arqEnt)){

		fscanf(arqEnt, "%d", &n);

		for(int i = 0; i < cont; i++){
			if(n == vertices[i]){
				encontrado = 1;
			}
		}

		if(encontrado == 0){
			vertices[cont] = n;
			cont++;
		}

		encontrado = 0;

	}

}

int main(){

	int nVertices, nArestas;
	FILE *arqEnt;

	arqEnt = fopen("Grafo.txt", "r");

	if(arqEnt == NULL){
		printf("Erro ao abrir\n");
		return 1;
	} else {
		fscanf(arqEnt, "%d %d", &nVertices, &nArestas);
		int vertices[nVertices];
		getVertices(nVertices, arqEnt, vertices);
		rewind(arqEnt);
	}

	fclose(arqEnt);

	return 0;

}