#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	//Lista simple
	typedef struct Nodo{
		int dato;
		struct Nodo* siguiente;
	}Nodo;
	
	void insertarNodo();
	void buscarNodo();
	void desplegarLista();
	
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	
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
	
	void buscarNodo(){
		Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
		actual = primero;
		int nodoBuscado = 0, encontrado = 0;
		printf("\n Ingrese el dato del Nodo a Buscar: ");
		scanf("%d", &nodoBuscado);
			
			if(primero!=NULL){
				while(actual!=NULL && encontrado != 1){
					
						if(actual->dato == nodoBuscado){
							printf("\n El nodo con el dato (%d) encontrado\n\n", nodoBuscado);
							encontrado = 1;
						}
						
					actual = actual->siguiente;
				}
				if(encontrado == 0){
					printf("\n Nodo no encontrado...\n\n");
				}
			}else{
				printf("\n La lista se encuentra vacia...\n\n");
			}
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
		int op;
			do{
				printf("+--------------------------+\n");
				printf("|°         LISTA          °|\n");
				printf("+--------------------------+\n");
				printf("|1.-Insertar |4.-Eliminar  |\n");
				printf("|2.-Buscar   |5.-Desplegar |\n");
				printf("|3.-Modificar|6.-Salir     |\n");
				printf("+--------------------------+\n");
				printf("Escoje una opcion: ");
				scanf("%d",&op);
				
					switch(op)
						{
							case 1:
								printf("\n\nINSERTA NODO EN LA LISTA\n\n");
								insertarNodo();
							break;
							case 2:
								printf("\n\nBUSCAR UN NODO EN LA LISTA\n\n");
								buscarNodo();
							break;
							case 3:
								printf("\n\nMODIFICAR UN NODO EN LA LISTA\n\n");
								//modificarNodo();
							break;
							case 4:
								printf("\n\nELIMNAR UN NODO DE LA LISTA\n\n");
								//eliminarNodo();
							break;
							case 5:
								printf("\n\nDESPLEGAR LISTA DE NODOS\n\n");
								desplegarLista();
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
