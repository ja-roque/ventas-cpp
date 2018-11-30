#include <stdio.h>
#include <string.h>

struct nodolista2{
	char Nombre[10];
	char apellido[30];
	int telefono;
	int ID;
	char especialidad[10];
	char genero[10];
	struct nodolista2 *ptrAnterior2;
	struct nodolista2 *ptrSiguiente2;
};
	
	
typedef struct nodolista2 nodolista2;
typedef struct nodolista2 *ptrnodolista2;

// Prototipos de las funciones
void insertar2(ptrnodolista2 *ptrS2, ptrnodolista2 ptrDatos2);	// Funcion para insertar un nodo a la lista
void eliminar2(ptrnodolista2 *ptrS2, ptrnodolista2 ptrDatos2);
int estaVacia2(ptrnodolista2 ptrS2);

// definiciones de funciones
void insertar2(ptrnodolista2 *ptrS2, ptrnodolista2 ptrDatos2)
{
	ptrnodolista2 ptrNuevo2;
	ptrnodolista2 ptrActual2;
	ptrnodolista2 ptrAnterior2;
	// Solicitamos Memoria del tamanio de la estructura de nodolista2pacientes
	ptrNuevo2 = (ptrnodolista2) malloc(sizeof(nodolista2));
	if(ptrNuevo2 != NULL){
        strcpy(ptrNuevo2->Nombre, ptrDatos2->Nombre);
		strcpy(ptrNuevo2->apellido, ptrDatos2->apellido);
		ptrNuevo2->ID = ptrDatos2->ID;
		strcpy(ptrNuevo2->especialidad, ptrDatos2->especialidad);
		ptrNuevo2->telefono = ptrDatos2->telefono;
		strcpy(ptrNuevo2->genero, ptrDatos2->genero);
		ptrNuevo2->ptrAnterior2 = NULL;
		ptrNuevo2->ptrSiguiente2 = NULL;
				
		ptrAnterior2 = NULL;
		ptrActual2 = *ptrS;
		
		// Ubica el nuevo valor en la posicion donde se debe insertar
		while(ptrActual2 != NULL && strcmp(ptrDatos2->Nombre, ptrActual2->Nombre) < 0 ){
			ptrAnterior2 = ptrActual2;
			ptrActual2 = ptrActual2->ptrSiguiente2;
		}
		
		if(ptrAnterior2 == NULL){
			ptrNuevo2->ptrSiguiente2 = *ptrS2;
			if( (*ptrS2) != NULL ){
				(*ptrS2)->ptrAnterior2 = ptrNuevo2;
			}
			*ptrS2 = ptrNuevo2;
		}
		else{
			ptrAnterior2->ptrSiguiente2 = ptrNuevo2;
			ptrNuevo2->ptrSiguiente2 = ptrActual2;
			ptrNuevo2->ptrAnterior2 = ptrAnterior2;
			if( ptrActual2 != NULL ){
				ptrActual2->ptrAnterior2 = ptrNuevo2;
			}
		}
	}	
}

void eliminar2(ptrnodolista2 *ptrS, ptrnodolista2 ptrDatos2)
{
	ptrnodolista2  ptrActual2 = *ptrS;
	ptrnodolista2  ptrAnterior2 = NULL;
	ptrnodolista2  ptrTemp2;
	if(ptrActual != NULL){
		if(ptrDatos2->ID == ptrActual2->ID){
			ptrTemp = *ptrS;
			(*ptrS2)->ptrAnterior2 = NULL;
			*ptrS2 = (*ptrS)->ptrSiguiente2;
			// actualizar los datos de ptrDatos2
			strcpy(ptrDatos2->Nombre, ptrTemp2->Nombre);
			strcpy(ptrDatos2->apellido, ptrTemp2->apellido);
			ptrDatos2->ID = ptrTemp2->ID;
			strcpy(ptrDatos2->especialidad, ptrTemp2->especialidad);
			ptrDatos2->telefono = ptrTemp2->telefono;
			strcpy(ptrDatos2->genero, ptrTemp2->genero);
			free(ptrTemp2);
		}
		else{
			ptrActual2 = (*ptrS2)->ptrSiguiente2;
			ptrAnterior2 = *ptrS2;
			while(ptrActual2 != NULL && ptrDatos2->ID != ptrActual2->ID){
				ptrAnterior2 = ptrActual2;
				ptrActual2 = ptrActual2->ptrSiguiente2;
			}
			if(ptrActual2 != NULL){
				ptrTemp2 = ptrActual2;
				ptrAnterior2->ptrSiguiente2 = ptrActual2->ptrSiguiente2;
				if(ptrActual2->ptrSiguiente2 != NULL){
					(ptrActual2->ptrSiguiente2)->ptrAnterior2 = ptrAnterior2;
				}
            
			strcpy(ptrDatos2->Nombre, ptrTemp2->Nombre);
			strcpy(ptrDatos2->apellido, ptrTemp2->apellido);
			ptrDatos2->ID = ptrTemp2->ID;
			strcpy(ptrDatos2->especialidad, ptrTemp2->especialidad);
			ptrDatos2->telefono = ptrTemp2->telefono;
			strcpy(ptrDatos2->genero, ptrTemp2->genero);
			free(ptrTemp2);
			}
		}
	}
}

int estaVacia2(ptrnodolista2 ptrS2)
{
	return ptrS2 == NULL;
}
		