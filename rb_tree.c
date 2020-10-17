#ifndef RBTree_T09
#define RBTree_T09

#include <stdio.h>
#include <stdlib.h>

// Prototipos ==========================================================

typedef struct RedBlackTreestruct{
	struct RedBlackTreestruct* left;
	struct RedBlackTreestruct* rignt;
	struct RedBlackTreestruct* padre;
	int data;//Valor del dato
	int key;//La llave para buscar al dato
	int color;//Color del ARN
}RBTree;

void put(RBTree* s, int key, int data);
int get(RBTree* s, int key);
int contains(RBTree* s, int key);
void delete(RBTree* s, int key);
int isEmpty(RBTree* s);
int size(RBTree* s);

// Definiciones ========================================================

void put (RBTree *s, int key, int val){
	RBTree *nodo=NULL,*x=NULL,*y=NULL;
	int ban=0,ban2=1;
	if(s->color=='M'){//Primer dato
		s->data=val;
		s->key=key;
		s->color='B';
	}else{//Nodo nuevo*/
		nodo=(RBTree *)malloc(sizeof(RBTree));
		if(nodo!=NULL){
			
			//Inicializar nodo nuevo
			nodo->key=key;
			nodo->data=val;
			nodo->izq=NULL;
			nodo->der=NULL;
			nodo->padre=NULL;
			nodo->color='R';
			x=s;

			while (x != NULL){
				y = x;
				if(key < x->key){
					x = x->izq;
				}else{
					x = x->der;
				}
			}
			
			nodo->padre=y;
			
			if (key < y->key)
				y->izq = nodo;
			else
				y->der= nodo;
			
			//nodo->color = 'R';

			insertFixUp(s,nodo);
		}else{
			printf("Solicitud de memoria denegada\n");
		}
	}
}

void insertFixUp(RBTree *s, RBTree *z){
	RBTree *y=NULL;
	
    while (z != s && z!=s->der && z!=s->izq && z->padre->color == 'R'){
        if(z->padre && z->padre->padre && z->padre==z->padre->padre->izq){
            y = z->padre->padre->der;
            
            if(!y && y->color == 'R'){
				z->padre->color = 'B';
				y->color = 'B';
				z->padre->padre->color = 'R';
				z = z->padre->padre;
			}else{
				if(z == z->padre->der) {
					z = z->padre;
					LeftRotate(s,z);
				}
					
					z->padre->color = 'B';
					z->padre->padre->color = 'R';
					RightRotate(s,z->padre->padre);
			}
        }else{
            y = z->padre->padre->izq;
            
            if(!y && y->color == 'R'){
				z->padre->color = 'B';
				y->color = 'B';
				z->padre->padre->color = 'R';
				z = z->padre->padre;
			}else{
				if(z == z->padre->izq) {
					z = z->padre;
					RightRotate(s,z);
				}
				z->padre->color = 'B';
				z->padre->padre->color = 'R';
				LeftRotate(s,z->padre->padre);
			}
		}
	}
    s->color = 'B';
}

void LeftRotate(RBTree *s, RBTree *x){
	RBTree *y=NULL;
	
    if (!x || !x->der){
        return ;
    }
    
    y = x->der;
    x->der = y->izq;

    if(y->izq != NULL){
        y->izq->padre = x;
	}
	
    y->padre = x->padre;

    if(x->padre== NULL){
        s = y;
    }else{
		if(x == x->padre->izq){
			x->padre->izq = y;
		}else{
			x->padre->der = y;
		}
	}
   
    y->izq = x;
    x->padre = y;
}


void RightRotate(RBTree *s, RBTree *y){
	RBTree *x=NULL;
    
    if (!y || !y->izq)
        return ;
    
    x = y->izq;
    y->izq = x->der;
    
    if(x->der!= NULL){
        x->der->padre = y;
    }
    
    x->padre = y->padre;
    if(x->padre == NULL){
        s = x;
    }else{ 
		if(y == y->padre->izq){
			y->padre->izq = x;
		}else{
			y->padre->der = x;
		}
	}
    x->der = y;
    y->padre = x;
}
//INORDER-TREE-WALK
void InorderTree(RBTree *s){
    
    if(s == NULL)
        return;
    InorderTree(s->izq);
    printf("%c%d ", s->color,s->key);
    
    InorderTree(s->der);
}

#endif
