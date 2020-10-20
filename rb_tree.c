#ifndef RBTree_T09
#define RBTree_T09

#include <stdio.h>
#include <stdlib.h>

// Prototipos ==========================================================

typedef struct strucRBTree{ 
	int key;
	int data;	
	char color; 
	struct strucRBTree *padre;
	struct strucRBTree *izq;
	struct strucRBTree *der;
}RBTree;

typedef struct strucTree{ 
	unsigned int nodos;
	RBTree *raiz;
	//RBTree *nil;
}Tree;

void put(Tree* s, int key, int data);
void InsertFixUp(Tree *s, RBTree *z);
void LeftRotate(Tree *s, RBTree *x);
void RightRotate(Tree *s, RBTree *y);

int isEmpty (Tree *s); 
int size (Tree *s);
void InorderTree(Tree *s, RBTree *x);

int get(RBTree* s, int key);
int contains(RBTree* s, int key);
void delete(RBTree* s, int key);


// Definiciones ========================================================

void put(Tree *s, int key, int val){
	RBTree *nodo=NULL,*x=NULL,*y=NULL;
	nodo=(RBTree *)malloc(sizeof(RBTree));

	if(nodo!=NULL){
		
		//Inicializar nodo nuevo
		nodo->key=key;
		nodo->data=val;
		nodo->izq=NULL;
		nodo->der=NULL;
		nodo->padre=NULL;
		nodo->color='R';
		//if(s->raiz==NULL){//Primer nodo
		if(isEmpty(s)==-1){
			s->raiz = nodo;
			nodo->color='B';
			
		}else{
			
			x=s->raiz;
			
			while (x != NULL){
				y = x;
				if(key < x->key){
					x = x->izq;
				}else{
					x = x->der;
				}
			}
			
			nodo->padre=y;
			
			if (key < y->key){
				y->izq = nodo;
			}else{
				y->der= nodo;
			}
			
			InsertFixUp(s,nodo);
			
		}
		
		s->nodos++;
	
	}else{
		printf("Solicitud de memoria denegada\n");
	}
}

void InsertFixUp(Tree *s, RBTree *z){
	RBTree *y=NULL;

    while(z->padre && z->padre->color == 'R'){
        if(z->padre==z->padre->padre->izq){
			
            y = z->padre->padre->der;
            if(y && y->color == 'R'){
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
           
				if(y && y->color == 'R'){
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
	
    s->raiz->color = 'B';
}


void LeftRotate(Tree *s, RBTree *x){
	RBTree *y=NULL,*m;
	
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
        s->raiz=y;
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


void RightRotate(Tree *s, RBTree *y){
	RBTree *x=NULL,*m;

    if (!y || !y->izq)
        return ;
    
    x = y->izq;
    y->izq = x->der;
    
    if(x->der!= NULL){
        x->der->padre = y;
    }
    
    x->padre = y->padre;
    if(x->padre == NULL){
        s->raiz=x;
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
void InorderTree(Tree *s, RBTree *n){
    if(n != NULL) {
		InorderTree(s, n->izq);
		printf("%c%d ",n->color, n->key);
		InorderTree(s, n->der);
	}
}

int isEmpty (Tree *s){
	if(size(s)==0){
		return -1;
	}else{
		return 1;
	}
}

int size (Tree *s){
	return s->nodos;
}

void delete(Tree *s, int key){
	RBTree *y=NULL,*z=NULL,*x=NULL, *m;
	char clr;
	printf("do3 \n");
	z=s->raiz;
	while(z!=s->nil && z->key!=key){
		if(key < z->key)
			z=z->izq;
		else
			z=z->der;
	}
	printf("do4 \n");
	//z=SearchTRB(s->raiz,key);
	y=z;
	
	clr=y->color;
	
	if(z->izq==s->nil){
		printf("do5 \n");
		x=z->der;
		Transplant(s,z,z->der);
		
	}else{
		
		if(z->der==s->nil){
			printf("do4 \n");
			x=z->izq;
			Transplant(s,z,z->izq);
		}else{
			printf("do7 \n");
			m=z->der;
			while(m->izq!=s->nil){
				m = m->izq;
			}
			
			
			printf("do9 \n");
			y=m;
			//y=Minimum(z->der);
				clr=y->color;
			x=y->der;
			
			
			if(y->padre==z){
				x->padre=y;
			}else{
				Transplant(s,y,y->der);
				y->der=z->der;
				y->der->padre=y;
			}
			
			printf("do10 \n");
			Transplant(s,z,y);
			y->izq=z->izq;
			y->izq->padre=y;
			y->color=z->color;
			
		}
		
	}
	//exit (-1);
	if(clr=='B'){
		DeleteFixUp(s,x);
	}
	
}

void DeleteFixUp(Tree *s, RBTree *x){
	RBTree *w=NULL;
	while(x != s->raiz && x->color == 'B'){
		if(x == x->padre->izq) {
			w = x->padre->der;
			if(w->color == 'R') {
				w->color = 'B';
				x->padre->color = 'R';
				LeftRotate(s, x->padre);
				w = x->padre->der;
			}
			if(w->izq->color == 'B' && w->der->color == 'B'){
				w->color = 'R';
				x = x->padre;
			}
			else {
				if(w->der->color == 'B'){
					w->izq->color = 'B';
					w->color = 'R';
					RightRotate(s, w);
					w = x->padre->der;
				}
				w->color = x->padre->color;
				x->padre->color = 'B';
				w->der->color = 'B';
				LeftRotate(s, x->padre);
				x = s->raiz;
			}
		}
		else {
			w = x->padre->izq;
			if(w->color == 'R') {
				w->color = 'B';
				x->padre->color = 'R';
				RightRotate(s, x->padre);
				w = x->padre->izq;
			}
			if(w->der->color == 'B' && w->izq->color == 'B') {
				w->color = 'R';
				x = x->padre;
			}
			else {
				if(w->izq->color == 'B'){
					w->der->color = 'B';
					w->color = 'R';
					LeftRotate(s, w);
					w = x->padre->izq;
				}
				w->color = x->padre->color;
				x->padre->color = 'B';
				w->izq->color = 'B';
				RightRotate(s, x->padre);
				x = s->raiz;
			}
		}
	}
	x->color = 'B';
}

#endif
