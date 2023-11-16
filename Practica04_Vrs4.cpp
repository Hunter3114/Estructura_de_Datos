#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max(a,b) (((a)>(b))?(a):(b))
	
	typedef struct NodoLista {
    	char letra;
	    int frecuencia;
	    struct NodoLista* siguiente;
	    struct NodoLista* anterior;
	}NodoLista;

	typedef struct Nodo {
	    char letra;
	    struct Nodo* izquierda;
	    struct Nodo* derecha;
	}Nodo;
	
	void CF(FILE* archivo, NodoLista** lista){
    	rewind(archivo);
    	char letra;
    		while(fscanf(archivo, " %c", &letra) != EOF){
        		NodoLista* actual = *lista;
        			while(actual != NULL) {
            			if(actual->letra == letra){
                			actual->frecuencia++;
                			break;
            			}
            				actual = actual->siguiente;
        			}
        			if(actual == NULL){
    					NodoLista* nuevo = (NodoLista*)malloc(sizeof(NodoLista));
        				nuevo->letra = letra;
    					nuevo->frecuencia = 1;
        				nuevo->siguiente = NULL;
        				nuevo->anterior = NULL;
						
            				if(*lista == NULL){
            					*lista = nuevo;
            				}else{
                				NodoLista* temp = *lista;
            						while(temp->siguiente != NULL){
                    					temp = temp->siguiente;
            						}
                				temp->siguiente = nuevo;
                				nuevo->anterior = temp;
            				}
        			}
    		}
	}

	void desplegarLO(NodoLista* lista){
    	while(lista != NULL){
    	    printf("%c=%d\n\n", lista->letra, lista->frecuencia);
    	    lista = lista->siguiente;
    	}
	}
	
	Nodo* CrearNodo(char letra){
    	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    	nuevo->letra = letra;
    	nuevo->izquierda = NULL;
    	nuevo->derecha = NULL;
    	return nuevo;
	}
	
	Nodo* insertar(Nodo* arbol, char letra){
    	Nodo* nuevo = CrearNodo(letra);
		    if(arbol == NULL){
    	    return nuevo;
    		}
    		if(arbol->izquierda == NULL && arbol->derecha == NULL){
    	    Nodo* sumNode = CrearNodo('*');
    	    sumNode->izquierda = arbol;
    	    sumNode->derecha = nuevo;
    	    return sumNode;
    		}
			if(letra < arbol->letra){
        	arbol->izquierda = insertar(arbol->izquierda, letra);
    		}else{
        	arbol->derecha = insertar(arbol->derecha, letra);
    		}
    	return arbol;
	}
	
	void preorder(Nodo* arbol){
    	if(arbol != NULL){
    	    printf("%c\t", arbol->letra);
        	preorder(arbol->izquierda);
        	preorder(arbol->derecha);
    	}
	}

	int altura(Nodo* arbol){
    	if(arbol == NULL){
			return 0;
		}else{
			return max(altura(arbol->izquierda)+1,altura(arbol->derecha)+1);
		}
	}
	
	void OrdenarL(){
		
	}
	
	int main(){
    	FILE* archivo = fopen("Practica04.txt", "a+");
    		if (archivo == NULL) {
        		printf("Error al abrir el archivo.\n");
        		return 1;
    		}
    	
    	NodoLista* Frecuencias = NULL;

    	CF(archivo, &Frecuencias);
    	//OrdenarL(&Frecuencias);
    	desplegarLO(Frecuencias);
		
    	char letra;
    	Nodo* arbol = NULL;
    		while (Frecuencias != NULL) {
        		arbol = insertar(arbol, Frecuencias->letra);
        		Frecuencias = Frecuencias->siguiente;
    		}

    	printf("PREORDER\n");
		preorder(arbol);
    	printf("\n\nAltura del arbol: %d\n", altura(arbol));
    	fclose(archivo);
    	return 0;
	}
