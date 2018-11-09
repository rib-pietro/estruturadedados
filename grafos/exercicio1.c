#include <stdio.h>

struct tvertice{
	int n;
	struct tvertice *prox;
};

typedef struct tvertice vertice;



int main(){

	int nVertices, nArestas;

	FILE *arqEnt;

	arqEnt = fopen("Grafo.txt", "r");

	if(arqEnt == NULL){
		printf("Erro ao abrir\n");
		return 1;
	} else {
		fscanf(arqEnt, "%d %d", &nVertices);
	}

	printf("Vertices: %d\n", nVertices);
	printf("Arestas: %d\n", nArestas);

	fclose(arqEnt);

	return 0;

}