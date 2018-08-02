// Arvore binaria de busca

#include <stdio.h>
#include <stdlib.h>

struct arvore
{
  int elem;
  struct arvore *esquerda, *direita;
};

typedef struct arvore *pont_arvore;

int vazia (pont_arvore pont) 
{
  return (pont == NULL);
}

void inserir (pont_arvore *pont,int valor)
{
  pont_arvore novo_no;
  if ((*pont) == NULL)
  {
    novo_no = (pont_arvore)malloc(sizeof(struct arvore));
    novo_no->elem = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    (*pont) = novo_no;
  }
  else
  {
    if (valor < (*pont)->elem)
      inserir(&((*pont)->esquerda), valor);
    else
      inserir(&((*pont)->direita), valor);
  }
}

int buscar (pont_arvore pont,int valor)
{
  if (pont == NULL)
  {
    return(0);
  }
  else
  {
    if (valor == pont->elem)
      	return(1);
    else
     	if (valor < pont->elem)
      		return(buscar(pont->esquerda,valor));
     	else
      		return(buscar(pont->direita,valor));
   }
}

pont_arvore getmax (pont_arvore pont)
{
   if (pont->direita == NULL)
    return(pont);
  else
    return(getmax(pont->direita));
}

void remover (pont_arvore *pont, int valor)
{
  pont_arvore p, aux;
  if ((*pont) != NULL)
  {
    if (valor == (*pont)->elem)
    {
      p = (*pont);
      if ((*pont)->esquerda == NULL){
        (*pont) = (*pont)->direita;
      } else {
    	 	p = (*pont)->esquerda;
    	 	aux = getmax(p);
    	 	(*pont)->elem = aux->elem;
    		if((p->direita == NULL) && (p->esquerda == NULL)){
    	   	(*pont)->esquerda=NULL;
    	 	} else {
          if (p->direita != NULL) {
	      		while (p->direita->elem != aux->elem) {
		 			    p = p->direita;
	      		}
	      		if (aux->esquerda == NULL)
              p->direita = NULL;
            else
		 			    p->direita = aux->esquerda;
	    	  } else {
	      		(*pont)->esquerda = aux->esquerda;
	    	  }
		    }
		    free(aux);
        aux = NULL;
      }
    }
    else
    {
      if (valor < (*pont)->elem)
    		remover(&((*pont)->esquerda), valor);
      else
	     	remover(&((*pont)->direita), valor);
    }
  }
}

//Atravessando em ordem.
void em_ordem (pont_arvore pont)
{
   if (pont != NULL)
   {
     em_ordem(pont->esquerda);
     printf("%d\n",pont->elem);
     em_ordem(pont->direita);
   }
}

//Atravessando em pre_ordem.
void pre_ordem (pont_arvore pont)
{
   if (pont != NULL)
   {
      printf("%d\n",pont->elem);
      pre_ordem(pont->esquerda);
      pre_ordem(pont->direita);
   }
}

//Atravessando em pos_ordem.
void pos_ordem (pont_arvore pont)
{
   if (pont != NULL)
   {
      pos_ordem(pont->esquerda);
      pos_ordem(pont->direita);
      printf("%d\n",pont->elem);
   }
}

void main()
{
  pont_arvore raiz = NULL;
  int num, opcao;

  do
  {
    system("cls");
    printf("1- Inserir\n");
    printf("2- Exibir em Ordem\n");
    printf("3- Exibir em Pre-ordem\n");
    printf("4- Exibir em Pos-ordem\n");
    printf("5- Buscar\n");
    printf("6- Excluir\n");
    printf("7- Sair\n");
    printf("Digite a sua opcao: ");
    scanf("%d",&opcao);
    printf("\n");
    switch (opcao)
    {
      case 1: printf("Digite um Numero:");
	      scanf("%d",&num);
	      inserir(&raiz,num);
	      break;
      case 2: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
	  			em_ordem(raiz);
	      break;
      case 3: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
				pre_ordem(raiz);
	      break;
      case 4: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
	  			pos_ordem(raiz);
	      break;
      case 5: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
      		  {
	  	  		printf("Digite um Numero:");
	     		scanf("%d",&num);
	      		if (buscar(raiz,num))
					printf("Numero encontrado!\n");
	      		else
					printf("Numero nao encontrado!\n");
			  }
	      break;
      case 6: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
	  	      {
		  		printf("Digite um Numero:");
	      		scanf("%d",&num);
	      		remover(&raiz,num);
	      	  } 
	      break;
    }
  }while (opcao!=7);
}

