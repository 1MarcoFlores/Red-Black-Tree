#include <stdio.h>
#include <stdlib.h>
#include "rd_tree.h"

int main(int argc, char **argv)
{
	srandom(time(NULL));
	int i=0,N=12;
	
	Tree *arblRB=NULL;
	//printf ("%d\n",sizeof(RBTree));
	
	//Inicializacion
	arblRB=(Tree *)malloc(sizeof(Tree));
		if(arblRB!=NULL){
			arblRB->raiz=NULL;
			//arblRB->nil=(RBTree *)malloc(sizeof(RBTree));
			//arblRB->nil->color='M';
			arblRB->nodos=0;
		}
	
	for(i = 0; i < N; i++){
		put(arblRB,random()%20,i);
		InorderTree(arblRB,arblRB->raiz);
		printf(" i=%d\n",i);
		printf("nodo padre%d\n",arblRB->raiz->key);
	}
	InorderTree(arblRB,arblRB->raiz);
	printf("nodo padre%d\n",arblRB->raiz->key);
	printf("size%d\n", size(arblRB));
	
	return 0;
}

