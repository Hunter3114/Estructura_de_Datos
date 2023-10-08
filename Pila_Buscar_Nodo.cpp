#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	
	typedef struct Nodo
		{
			int dato;
			struct Nodo* siguiente;
		}Nodo;
		
		Nodo* primero = NULL;
		
		void insertarNodo();
		void desplegarPila();
		void buscarNodo();
		
		int main(){
			
			int op;
			do{
				printf("+-------------------------+\n");
				printf("|°         PILA          °|\n");
				printf("+-------------------------+\n");
				printf("|1.-Insertar |4.-Eliminar |\n");
				printf("|2.-Buscar   |5.-Desplegar|\n");
				printf("|3.-Modificar|6.-Salir    |\n");
				printf("+-------------------------+\n");
				printf("Escoje una opcion: ");
				scanf("%d",&op);
				
					switch(op)
						{
							case 1:
								printf("\n\nINSERTA NODO EN LA PILA\n\n");
								insertarNodo();
							break;
							case 2:
								printf("\n\nBUSCAR UN NODO EN LA PILA\n\n");
								buscarNodo();
							break;
							case 3:
								printf("\n\nMODIFICAR UN NODO EN LA PILA\n\n");
							break;
							case 4:
								printf("\n\nELIMNAR UN NODO DE LA PILA\n\n");
							break;
							case 5:
								printf("\n\nDESPLEGAR PILA DE NODOS\n\n");
								desplegarPila();
							break;
							case 6:
								printf("Programa finalizado...");
							break;
							default:
								printf("\n\nOPCION INVALIDA\n\n");
						}
			}while(op!=6);
			
			return 0;
			
		}
		
		void insertarNodo(){
			Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
			printf("Ingrese el dato que contendra el nuevo Nodo: ");
			scanf("%d",&nuevo->dato);
			
			nuevo->siguiente=primero;
			primero=nuevo;
		}
		
		/*
		primero = 13 actual = 16 nodoBuscado = 16
		*/
		void buscarNodo(){
			Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
			actual = primero;
			int nodoBuscado = 0, encontrado = 0;
			printf("Ingrese el dato del Nodo a Buscar: ");
			scanf("%d",&nodoBuscado);
				if(primero!=NULL){
					while(actual!=NULL){
						
						if(actual->dato == nodoBuscado){
							printf("\n EL Nodo con el dato (%d) Encontrado:", nodoBuscado);
							encontrado = 1;
						}
						
						actual = actual->siguiente;
					}
						if(encontrado == 0){
							printf("\n Nodo no encontrado\n\n");
						}
				}else{
					printf("\nLa pila se encuentra vacia");
				}
		}
		
		void desplegarPila(){
			Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
			actual = primero;
			
				if(primero!=NULL){
					while(actual!=NULL){
						printf("%d\n\n", actual->dato);
						actual = actual->siguiente;
					}
				}else{
					printf("\nLa pila se encuentra vacia");
				}
		}
