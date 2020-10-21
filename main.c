#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rb_tree.c"

int main(int argc, char **argv)
{
	
	int key=0,data=0;
	char opc='p';
	Tree *arblRB=NULL;
	
	
	//Inicializacion
	arblRB=(Tree *)malloc(sizeof(Tree));
		if(arblRB!=NULL){
			arblRB->raiz=NULL;
			arblRB->nil=(RBTree *)malloc(sizeof(RBTree));
			arblRB->nil->color='B';
			arblRB->nodos=0;
		}
		
	while(scanf("%c ",&opc)>0){
		switch(opc) {
			case 'p': //put
				scanf("%d %d ",&key,&data);
				put(arblRB,key,data);
				break;
			case 'd': //delete
				scanf("%d ",&key);
				delete(arblRB, key);
				break;
			case 'c': //contains
				scanf("%d ",&key);
				printf("c %d\n",contains(arblRB,key));
				break;
			case 'g': //get
				scanf("%d ",&key);
				printf("g %d\n",get(arblRB,key));
				break;
			case 's': //size
				printf("s %d\n",size(arblRB));
				break;
			case 'e': //isEmpty
				printf("e %d\n",isEmpty(arblRB));
				break;
			case 'r': //Key de la raiz del arbol
				printf("r %d\n",arblRB->raiz->key);
				break;
			case 'w': //printf de arbol en orden
				InorderTree(arblRB,arblRB->raiz);
				break;
			default: 
				printf("Error: Opcion no definida\n");
		}
    }
	freeTree(arblRB);
	return 0;
}

