#include <stdio.h>
#include <string.h>

struct nodolista{
	char Nombre[10];
	char apellido[30];
	int telefono;
	int ID;
	char genero[10];
	struct nodolista *ptrAnterior;
	struct nodolista *ptrSiguiente;
};
	
	
typedef struct nodolista nodolista;
typedef struct nodolista *ptrnodolista;

// Prototipos de las funciones
void insertar(ptrnodolista *ptrS, ptrnodolista ptrDatos);	// Funcion para insertar un nodo a la lista
void eliminar(ptrnodolista *ptrS, ptrnodolista ptrDatos);
int estaVacia(ptrnodolista ptrS);

// definiciones de funciones
void insertar(ptrnodolista *ptrS, ptrnodolista ptrDatos)
{
	ptrnodolista ptrNuevo;
	ptrnodolista ptrActual;
	ptrnodolista ptrAnterior;
	// Solicitamos Memoria del tamanio de la estructura de nodolistapacientes
	ptrNuevo = (ptrnodolista) malloc(sizeof(nodolista));
	if(ptrNuevo != NULL){
        strcpy(ptrNuevo->Nombre, ptrDatos->Nombre);
		strcpy(ptrNuevo->apellido, ptrDatos->apellido);
		ptrNuevo->ID = ptrDatos->ID;
		ptrNuevo->telefono = ptrDatos->telefono;
		strcpy(ptrNuevo->genero, ptrDatos->genero);
		ptrNuevo->ptrAnterior = NULL;
		ptrNuevo->ptrSiguiente = NULL;
				
		ptrAnterior = NULL;
		ptrActual = *ptrS;
		
		// Ubica el nuevo valor en la posicion donde se debe insertar
		while(ptrActual != NULL && strcmp(ptrDatos->Nombre, ptrActual->Nombre) < 0 ){
			ptrAnterior = ptrActual;
			ptrActual = ptrActual->ptrSiguiente;
		}
		
		if(ptrAnterior == NULL){
			ptrNuevo->ptrSiguiente = *ptrS;
			if( (*ptrS) != NULL ){
				(*ptrS)->ptrAnterior = ptrNuevo;
			}
			*ptrS = ptrNuevo;
		}
		else{
			ptrAnterior->ptrSiguiente = ptrNuevo;
			ptrNuevo->ptrSiguiente = ptrActual;
			ptrNuevo->ptrAnterior = ptrAnterior;
			if( ptrActual != NULL ){
				ptrActual->ptrAnterior = ptrNuevo;
			}
		}
	}	
}

void eliminar(ptrnodolista *ptrS, ptrnodolista ptrDatos)
{
	ptrnodolista  ptrActual = *ptrS;
	ptrnodolista  ptrAnterior = NULL;
	ptrnodolista  ptrTemp;
	if(ptrActual != NULL){
		if(ptrDatos->ID == ptrActual->ID){
			ptrTemp = *ptrS;
			(*ptrS)->ptrAnterior = NULL;
			*ptrS = (*ptrS)->ptrSiguiente;
			// actualizar los datos de ptrDatos
			strcpy(ptrDatos->Nombre, ptrTemp->Nombre);
			strcpy(ptrDatos->apellido, ptrTemp->apellido);
			ptrDatos->ID = ptrTemp->ID;
			ptrDatos->telefono = ptrTemp->telefono;
			strcpy(ptrDatos->genero, ptrTemp->genero);
			free(ptrTemp);
		}
		else{
			ptrActual = (*ptrS)->ptrSiguiente;
			ptrAnterior = *ptrS;
			while(ptrActual != NULL && ptrDatos->ID != ptrActual->ID){
				ptrAnterior = ptrActual;
				ptrActual = ptrActual->ptrSiguiente;
			}
			if(ptrActual != NULL){
				ptrTemp = ptrActual;
				ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
				if(ptrActual->ptrSiguiente != NULL){
					(ptrActual->ptrSiguiente)->ptrAnterior = ptrAnterior;
				}
            
			strcpy(ptrDatos->Nombre, ptrTemp->Nombre);
			strcpy(ptrDatos->apellido, ptrTemp->apellido);
			ptrDatos->ID = ptrTemp->ID;
			ptrDatos->telefono = ptrTemp->telefono;
			strcpy(ptrDatos->genero, ptrTemp->genero);
			free(ptrTemp);
			}
		}
	}
}

int estaVacia(ptrnodolista ptrS)
{
	return ptrS == NULL;
}