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



#endif
