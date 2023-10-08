#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	//Una cola es similar a la listas simples
	typedef struct Nodo{
		int dato;
		struct Nodo* siguiente;
	}Nodo;
	
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	
	void insertarNodo();
	void desplegarCola();
	
	int main(){
		insertarNodo();
		insertarNodo();
		insertarNodo();
		insertarNodo();
		insertarNodo();
		printf("\n La cola esta de esta forma \n");
		desplegarCola();
		return 0;
	}
	
	//primero = 13 ultimo = 3 nuevo 20 actual = 12
	//cola - 13 -> 12 -> 3 -> 20 -> NULL
			//13 -> NULL
				// 12 -> NULL
	//13, 12, 3, 20					-..... 13	12	3	20
	
	void insertarNodo(){
		Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
		printf("Ingrese el dato que contendra el nuevo Nodo: ");
		scanf("%d",&nuevo->dato);
		 	if(primero == NULL){
		 		primero = nuevo;
		 		primero->siguiente = NULL;
		 		ultimo = nuevo;
			 }else{
			 	ultimo->siguiente = nuevo;
			 	nuevo->siguiente = NULL;
			 	ultimo = nuevo;
			 }
		printf("\n Nodo ingresado con exito... \n");
	}
	
	void desplegarCola(){
		Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
		actual = primero;
			if(primero!=NULL){
				while(actual!=NULL){
					printf("\n %d", actual->dato);
					actual = actual->siguiente;
				}
			}else{
				printf("\n La cola no existe...\n\n");
			}
	}
