#include <stdio.h>

int buscaBinaria (int procurado, int n, int vetor[]) 
{
   int esq, meio, dir, posicao;
   esq = 0; 
   dir = n-1;
   posicao = -1;
   while (esq <= dir) 
  { 
      meio = (esq + dir)/2; 
      if (vetor[meio] == procurado) 
	  posicao = meio;
      if (vetor[meio] < procurado) 
		esq = meio + 1;
      else
		dir = meio - 1;
   }
   return (posicao);
}

void main()
{
	int elementos[10], i, pesquisado, posicao;
		
	for (i=0; i<=9; i++)
	{
		printf("Digite um numero : \n");
		scanf("%d",&elementos[i]);
	}
	printf("Digite o numero a ser pesquisado : \n");
	scanf("%d",&pesquisado);
	posicao = buscaBinaria (pesquisado, 10, elementos);
	printf("O numero pesquisado esta na posicao %d \n",posicao);
}

