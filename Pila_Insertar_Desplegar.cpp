#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

	typedef struct Nodo
		{
			int dato;
			struct Nodo* siguiente;
		}Nodo;
		
		Nodo* primero = NULL;
		
		void insertarNodo();
		void desplegarPila();
		
		int main(){
			
			insertarNodo();
			insertarNodo();
			insertarNodo();
			desplegarPila();
			return 0;
		}
		/*
		primero = 13 actual 16
		es decir que si es 13 el primer elemento el siguiente es el 16
		actual es Null se rompe el recorrido.
		y asi sucecibamente
		13 16 18 20
		primero=20
		13 -> 16 -> 18 -> 20 -> null
		*/
		void insertarNodo(){
			Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
			printf("Ingrese el dato que contendra el nuevo Nodo: ");
			scanf("%d",&nuevo->dato);
			
			nuevo->siguiente=primero;
			primero=nuevo;
		}
		
		void desplegarPila(){
			Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
			actual = primero;
			
				if(primero!=NULL){
					while(actual!=NULL){
						printf("%d ", actual->dato);
						actual = actual->siguiente;
					}
				}else{
					printf("\nLa pila se encuentra vacia");
				}
		}
