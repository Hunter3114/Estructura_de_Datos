#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	
	typedef struct Nodo{
		int dato;
		struct Nodo* siguiente;
	}Nodo;
	
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	
	void insertarNodo();
	void buscarNodo();
	void modificarNodo();
	void desplegarCola();
	
	int main(){
		int op;
			do{
				printf("+-------------------------+\n");
				printf("|°         COLA          °|\n");
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
								printf("\n\nINSERTA NODO EN LA COLA\n\n");
								insertarNodo();
							break;
							case 2:
								printf("\n\nBUSCAR UN NODO EN LA COLA\n\n");
								buscarNodo();
							break;
							case 3:
								printf("\n\nMODIFICAR UN NODO EN LA COLA\n\n");
								modificarNodo();
							break;
							case 4:
								printf("\n\nELIMNAR UN NODO DE LA COLA\n\n");
							break;
							case 5:
								printf("\n\nDESPLEGAR COLA DE NODOS\n\n");
								desplegarCola();
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
	
	/*NOTE:
	
	*/
	
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
	
	void buscarNodo(){
		Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
		actual = primero;
		int nodoBuscado = 0, encontrado = 0;
		printf("\n Ingrese el valor del Nodo a buscar: ");
		scanf("%d",&nodoBuscado);
			if(primero!=NULL){
				while(actual!=NULL && encontrado!=1){
					
					if(actual->dato == nodoBuscado){
						printf("\n Nodo con el dato (%d) encontrado: \n\n", nodoBuscado);
						encontrado = 1;
					}
					
					actual = actual->siguiente;
				}
				if(encontrado == 0){
					printf("\n Nodo no encontrado...\n\n");
				}
			}else{
				printf("\n La cola no existe...\n\n");
			}
	}
	
	void modificarNodo(){
		Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
		actual = primero;
		int nodoBuscado = 0, encontrado = 0;
		printf("\n Ingrese el valor del Nodo a buscar para modificar: ");
		scanf("%d",&nodoBuscado);
			if(primero!=NULL){
				while(actual!=NULL && encontrado!=1){
					
					if(actual->dato == nodoBuscado){
						printf("\n Nodo con el dato (%d) encontrado: \n\n", nodoBuscado);
						printf("\n Ingre el nuevo dato para este Nodo: ");
						scanf("%d", &actual->dato);
						printf("\n Nodo modificado con exito...");
						encontrado = 1;
					}
					
					actual = actual->siguiente;
				}
				if(encontrado == 0){
					printf("\n Nodo no encontrado...\n\n");
				}
			}else{
				printf("\n La cola no existe...\n\n");
			}
	}
	
	void desplegarCola(){
		Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
		actual = primero;
			if(primero!=NULL){
				while(actual!=NULL){
					printf("%d\n\n", actual->dato);
					actual = actual->siguiente;
				}
			}else{
				printf("\n La cola no existe...\n\n");
			}
	}
