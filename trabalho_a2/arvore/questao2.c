// Arvore binaria de busca

#include <stdio.h>
#include <stdlib.h>

/*
2. Elabore um programa para construir uma árvore binária de busca, onde cada nó da árvore
possua as informações sobre um livro (título, autor e editora), com as operações: inserir,
remover, descobrir quantas vezes um título existe na árvore, exibir os livros utilizando o
percurso pós-ordem.
*/

struct tlivro
{
  char titulo[30], autor[30], editora[30];
  struct tlivro *esq, *dir;
};

typedef struct tlivro *pont_livro;

int vazia (pont_livro pont) {
  return (pont == NULL);
}

void inserir (pont_livro *pont, char *titulo, char *autor, char *editora){

  pont_livro novo_l;

  if ((*pont) == NULL){

    novo_l = (pont_livro)malloc(sizeof(struct arvore));
    novo_l->elem = valor;
    novo_l->esq = NULL;
    novo_l->dir = NULL;
    (*pont) = novo_l;

  } else {

    if (titulo < (*pont)->titulo){ 
      inserir(&((*pont)->esq), titulo, autor, editora);
    } else{
      inserir(&((*pont)->dir), titulo, autor, editora);
    }
  }
}

int buscar (pont_livro pont, char *titulo){

    if (pont == NULL){
        return 0;
    } else {
        if (valor == pont->elem){
            return 1;
        }
        else{
            if (valor < pont->elem){
                return(buscar(pont->esq,valor));
            } else{
                return(buscar(pont->dir,valor));
            }
        }
    }
}

pont_livro getmax (pont_livro pont)
{
    if (pont->dir == NULL){
        return(pont);
    } else {
        return(getmax(pont->dir));
    }
}

void remover (pont_livro *pont, int valor)
{
    pont_livro p, aux;
    if ((*pont) != NULL){
        if (strcmp(titulo, (*pont)->titulo) == 0){
            p = (*pont);
            if ((*pont)->esq == NULL){
                (*pont) = (*pont)->dir;
            } else {
        	 	p = (*pont)->esq;
        	 	aux = getmax(p);
        	 	strcpy((*pont)->elem = aux->elem);
        		if((p->dir == NULL) && (p->esq == NULL)){
        	   	   (*pont)->esq=NULL;
        	 	} else {
                    if (p->dir != NULL) {
                        while (p->dir->elem != aux->elem) {
                            p = p->dir;
                        }
	      		        if (aux->esq == NULL){
                            p->dir = NULL;
                        } else{
                            p->dir = aux->esq;
                        }
                    } else {
                            (*pont)->esq = aux->esq;
                    }
                }
                free(aux);
                aux = NULL;
            }
        } else {
            if (valor < (*pont)->elem){
                remover(&((*pont)->esq), valor);
            } else{
                remover(&((*pont)->dir), valor);
            }
        }
    }
}

//Atravessando em ordem.
void em_ordem (pont_livro pont)
{
   if (pont != NULL)
   {
     em_ordem(pont->esq);
     printf("%d\n",pont->elem);
     em_ordem(pont->dir);
   }
}

//Atravessando em pre_ordem.
void pre_ordem (pont_livro pont)
{
   if (pont != NULL)
   {
      printf("%d\n",pont->elem);
      pre_ordem(pont->esq);
      pre_ordem(pont->dir);
   }
}

//Atravessando em pos_ordem.
void pos_ordem (pont_livro pont)
{
   if (pont != NULL)
   {
      pos_ordem(pont->esq);
      pos_ordem(pont->dir);
      printf("%d\n",pont->elem);
   }
}

void main()
{
  pont_livro raiz = NULL;
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

