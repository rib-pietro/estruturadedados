#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
2. Construa um programa que implemente uma pilha de cartas de baralho. Cada carta deve
conter o número e o naipe. Implemente as operações abaixo:
a) Inserir uma carta.
b) Remover uma carta.
c) Consultar se uma carta está na pilha.
d) Embaralhar as cartas da pilha.
*/

struct tcarta{
	int num;
	char naipe[5];
	struct tcarta *prox;
};

struct tbaralho{
	struct tcarta *ini, *fim;
	int qntd;
};

typedef struct tcarta tcarta;
typedef struct tbaralho tbaralho;

void incluir(tbaralho *baralho, int num, char *naipe){

	tcarta *nova_carta;

	nova_carta = (tcarta*) malloc(sizeof(tcarta));
	nova_carta->num = num;
	strcpy(nova_carta->naipe, naipe);
	nova_carta->prox = NULL;

	if(baralho->ini == NULL){
		baralho->ini = nova_carta;
		baralho->fim = nova_carta;
	} else {
		baralho->fim->prox = nova_carta;
		baralho->fim = nova_carta;
	}

	baralho->qntd+=1;

}

void excluir(tbaralho *baralho){

	tcarta *aux, *aux1;

	if(baralho->ini == NULL){
		printf("baralho vazia\n");
	} else {
		if(baralho->ini == baralho->fim){
			aux = baralho->ini;
			baralho->ini = NULL;
			baralho->fim = NULL;
			free(aux);
		} else {
			aux = baralho->ini;
			while(aux->prox->prox != NULL){
				aux = aux->prox;
			}
			baralho->fim = aux;
			aux1 = aux->prox;
			aux->prox = NULL;
			free(aux1);
		}
	}

}

void consulta_carta(tbaralho *baralho){

	tcarta *aux;
	char naipe[5];
	int num;

	if(baralho->ini == NULL){
		printf("Baralho vazio\n");
	} else {
		aux = baralho->ini;
		printf("Informe o numero da carta buscada\n");
		scanf("%d", &num);
		printf("Informe o naipe da carta buscada\n");
		scanf("%s", naipe);
		while(aux != NULL){
			if(aux->num == num && strcmp(aux->naipe, naipe) == 0){
				printf("Sua carta esta aqui\n");
				break;
			}
			aux = aux->prox;
		}
		printf("Sua carta nao esta aqui\n");
	}

}

void exibir(tbaralho *baralho){

	tcarta *aux;

	if(baralho->ini == NULL){
		printf("baralho vazia\n");
	} else {
		aux = baralho->ini;
		while(aux != NULL){
			printf("Numero: %d\n", aux->num);
			printf("Naipe: %s\n", aux->naipe);
			aux = aux->prox;
		}
	}
}

void copia_baralho(tbaralho *baralho){

	tbaralho baralho2;
	baralho2.ini = NULL;
	baralho2.fim = NULL;

	while(baralho->fim != NULL){
		incluir(&baralho2, baralho->fim->num, baralho->fim->naipe);
		excluir(baralho);
	}

	//exibir(&baralho2);

}

int buscaVetor(int num, int *vet, int qntd){

	for(int i = 0; i < qntd; i++){
		if(vet[i] == num){
			return 0;
		}
	}

	return 1;

}

void embaralha_cartas(tbaralho *baralho){

	int qntd = baralho->qntd, achei;
	int numeros[qntd], i, j, x = 0, hist[qntd];
	char naipes[qntd][5], naipe[5];

	//printf("qntd: %d\n", qntd);

	
	for(i = 0; i < qntd; i++){
		numeros[i] = baralho->fim->num;
		for(j = 0; j < strlen(baralho->fim->naipe); j++){
			naipes[i][j] = baralho->fim->naipe[j];
		}
		excluir(baralho);
	}

	/*for(i = 0; i < qntd; i++){
		printf("N: %d\n", numeros[i]);
		printf("Naipe: ");
		for(j = 0; j < 5; j++){
			printf("%c", naipes[i][j]);
		}
		printf("\n");
	}*/

	srand(time(NULL));

	for(i = 0; i < 4; i++){
		hist[i] = 5;
	}

	i = 0;

	while(i < 4){
		x = rand() % 4;
		for(int c = 0; c < qntd; c++){
			if(hist[c] == x){
				achei = 1;
			}
		}
		if(achei != 1){
			hist[i] = x;
			i++;
		}
	}

	for(i = 0; i < 4; i++){
		printf("hist i: %d\n", hist[i]);
	}

	/*for(i = 0; i < qntd; i++){
		x = rand() % qntd;
		if(buscaVetor(x, hist, qntd) == 0){
			hist[i] = x;
		}
		
		printf("%d\n", x);
		for(j = 0; j < 5; j++){
			naipe[j] = naipes[x][j];
		}
		while(buscaVetor(x, hist, qntd) == 0){
			in
		}
		if(buscaVetor(x, hist, qntd) == 1){
			incluir(baralho, numeros[x], naipe);
		} else {
			i--;
		}
		hist[i] = x;
	}*/
}


int main(){

	tbaralho baralho;
	int opt, num;
	char naipe[5];
	baralho.ini = NULL;
	baralho.fim = NULL;
	baralho.qntd = 0;

	do{
		printf("1 - Inserir uma carta\n");
		printf("2 - Remover uma carta\n");
		printf("3 - Exibir baralho\n");
		printf("4 - Consultar carta\n");
		printf("5 - Embaralhar cartar\n");
		printf("6 - Copiar cartas para outro baralho\n");
		printf("0 - Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Digite o numero da carta\n");
				scanf("%d", &num);
				printf("Informe o naipe da carta\n");
				scanf("%s", naipe);
				incluir(&baralho, num, naipe);
			break;
			case 2:
				excluir(&baralho);
			break;
			case 3:
				exibir(&baralho);
			break;
			case 4:
				consulta_carta(&baralho);
			break;
			case 5:
				embaralha_cartas(&baralho);
			break;
			case 6:
				copia_baralho(&baralho);
			break;
		}
	} while(opt != 0);


	return 0;
}