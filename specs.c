#include "./rb_tree.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//Prueba de positivos
int test_insert_element(void){
  printf("Al probar un elemento se debe mantener la propiedad de color de raiz=Black (positivos)");

    // Creamos el arbol
    Tree *arblRB=NULL;

	//Inicializacion
	arblRB=(Tree *)malloc(sizeof(Tree));
		if(arblRB!=NULL){
			arblRB->raiz=NULL;
			arblRB->nodos=0;
			arblRB->nil=(RBTree *)malloc(sizeof(RBTree));
			arblRB->nil->color='B';
		}

    put(arblRB,0,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== 0){puts("ERROR"); return 0;}
    put(arblRB,8,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== 0){puts("ERROR"); return 0;}
     put(arblRB,10,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== 8){puts("ERROR"); return 0;}
    put(arblRB,1,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== 8){puts("ERROR"); return 0;}
     put(arblRB,5,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== 8){puts("ERROR"); return 0;}

    freeTree(arblRB);
    puts("OK");
    return 1;
}

//Prueba de negativos
int test_insert_element2(void){
    printf("Al probar un elemento se debe mantener la propiedad de color de raiz=Black (negativos): ");

    // Creamos el arbol
    Tree *arblRB=NULL;

	//Inicializacion
	arblRB=(Tree *)malloc(sizeof(Tree));
		if(arblRB!=NULL){
			arblRB->raiz=NULL;
			arblRB->nodos=0;
			arblRB->nil=(RBTree *)malloc(sizeof(RBTree));
			arblRB->nil->color='B';
		}
    put(arblRB,-5,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
    put(arblRB,-3,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
     put(arblRB,-7,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
    put(arblRB,-2,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
     put(arblRB,-11,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}

   freeTree(arblRB);
    puts("OK");
    return 1;
}

//Prueba de negativos y positivos
int test_insert_element3(void){
    printf("Al probar un elemento se debe mantener la propiedad de color de raiz=Black(ambos): ");

   // Creamos el arbol
    Tree *arblRB=NULL;

	//Inicializacion
	arblRB=(Tree *)malloc(sizeof(Tree));
		if(arblRB!=NULL){
			arblRB->raiz=NULL;
			arblRB->nodos=0;
			arblRB->nil=(RBTree *)malloc(sizeof(RBTree));
			arblRB->nil->color='B';
		}

//    int Keys[6]={-7,-5,-3,1,4,3};

     put(arblRB,-7,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -7){puts("ERROR"); return 0;}
    put(arblRB,-5,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -7){puts("ERROR"); return 0;}
     put(arblRB,-3,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
    put(arblRB,1,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
     put(arblRB,4,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
     put(arblRB,3,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
    put(arblRB,-1,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}
     put(arblRB,7,1);
    if(arblRB->raiz->color != 'B'&& arblRB->raiz->key== -5){puts("ERROR"); return 0;}

  freeTree(arblRB);
  puts("OK");
  return 1;
}


//prueba de delete

int test_delete_element(void){
  printf("Al eliminar un elemento se debe mantener la propiedad de color de raiz=Black \n y si se elimina la raiz, esta se actualiza: ");

   // Creamos el arbol
  Tree *arblRB=NULL;

	//Inicializacion
	arblRB=(Tree *)malloc(sizeof(Tree));
		if(arblRB!=NULL){
			arblRB->raiz=NULL;
			arblRB->nodos=0;
			arblRB->nil=(RBTree *)malloc(sizeof(RBTree));
			arblRB->nil->color='B';
		}

    //construimos un arbol
    int Keys[8]={8,9,2,1,0,7,6};
    for(int i = 0; i < 7; i++){
        put(arblRB,Keys[i],i);
    }
	
    //eleminamos un nodo interno
      delete(arblRB,2);
      
   if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 8){puts("ERROR1"); return 0;}

    //a partir de aqui vamos eliminando la raiz
    delete(arblRB,8);
    
    if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 1){puts("ERROR2"); return 0;}

    delete(arblRB, 7);
    if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 0){puts("ERROR3"); return 0;}

    //Un elemento que no esta
    delete(arblRB, 5);
    if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 0){puts("ERROR3"); return 0;}

	//Todos
	delete(arblRB, 9);
    if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 0){puts("ERROR3"); return 0;}
    
	delete(arblRB, 0);
    if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 1){puts("ERROR3"); return 0;}
    
    delete(arblRB, 1);
    if(arblRB->raiz->color != 'B' && arblRB->raiz->key== 6){puts("ERROR3"); return 0;}
    
    delete(arblRB, 6);
    if(arblRB->nodos!= 0){puts("ERROR3"); return 0;}

    freeTree(arblRB);
    puts("OK");
    return 1;
}




int main(int num_args, char ** args){
  int all_tests_ok = 1;
 
  all_tests_ok &= test_insert_element();
  all_tests_ok &= test_insert_element2();
  all_tests_ok &= test_insert_element3();
  all_tests_ok &=test_delete_element();
  assert(all_tests_ok);
  return 0;
}
