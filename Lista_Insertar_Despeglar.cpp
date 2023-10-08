#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	//Lista simple
	typedef struct Nodo{
		int dato;
		struct Nodo* siguiente;
	}Nodo;
	
	void insertarNodo();
	void desplegarLista();
	
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	/*
	primero = 7 ultimo = 9 nuevo = 9 actual = 9
	lista 7 -> 5 -> 2 -> null
	7,5,2,9
	*/
	void insertarNodo(){
		Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
		printf("\n Ingrese el dato que contendra el nuevo nodo: ");
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
			printf("\n Nodo ingresado con exito...\n\n");
	}
	
	void desplegarLista(){
		Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
		actual = primero;
			
			if(primero!=NULL){
				while(actual!=NULL){
					printf("\n %d", actual->dato);
					actual = actual->siguiente;
				}
			}else{
				printf("\n La lista se encuentra vacia...\n\n");
			}
	}
	
	int main(){
		insertarNodo();
		insertarNodo();
		insertarNodo();
		insertarNodo();
		insertarNodo();
		desplegarLista();
		return 0;
	}
