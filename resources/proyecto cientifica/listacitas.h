#include <stdio.h>
#include <string.h>

struct nodolistaC{
	char Nombre[10];
	char apellido[30];
	int telefono;
	int ID;
	char especialidad[10];
	char genero[10];
	struct nodolistaC *ptrAnteriorC;
	struct nodolistaC *ptrSiguienteC;
};
	
	
typedef struct nodolistaC nodolistaC;
typedef struct nodolistaC *ptrnodolistaC;

// Prototipos de las funciones
void insertarC(ptrnodolistaC *ptrSC, ptrnodolistaC ptrDatosC);	// Funcion para insertar un nodo a la lista
void eliminarC(ptrnodolistaC *ptrSC, ptrnodolistaC ptrDatosC);
int estaVaciaC(ptrnodolistaC ptrSC);

// definiciones de funciones
void insertarC(ptrnodolistaC *ptrSC, ptrnodolistaC ptrDatosC)
{
	ptrnodolistaC ptrNuevoC;
	ptrnodolistaC ptrActualC;
	ptrnodolistaC ptrAnteriorC;
	// Solicitamos Memoria del tamanio de la estructura de nodolistaCpacientes
	ptrNuevoC = (ptrnodolistaC) malloc(sizeof(nodolistaC));
	if(ptrNuevoC != NULL){
        strcpy(ptrNuevoC->Nombre, ptrDatosC->Nombre);
		strcpy(ptrNuevoC->apellido, ptrDatosC->apellido);
		ptrNuevoC->ID = ptrDatosC->ID;
		strcpy(ptrNuevoC->especialidad, ptrDatosC->especialidad);
		ptrNuevoC->telefono = ptrDatosC->telefono;
		strcpy(ptrNuevoC->genero, ptrDatosC->genero);
		ptrNuevoC->ptrAnteriorC = NULL;
		ptrNuevoC->ptrSiguienteC = NULL;
				
		ptrAnteriorC = NULL;
		ptrActualC = *ptrSC;
		
		// Ubica el nuevo valor en la posicion donde se debe insertar
		while(ptrActualC != NULL && strcmp(ptrDatosC->Nombre, ptrActualC->Nombre) < 0 ){
			ptrAnteriorC = ptrActualC;
			ptrActualC = ptrActualC->ptrSiguienteC;
		}
		
		if(ptrAnteriorC == NULL){
			ptrNuevoC->ptrSiguienteC = *ptrSC;
			if( (*ptrSC) != NULL ){
				(*ptrSC)->ptrAnteriorC = ptrNuevoC;
			}
			*ptrSC = ptrNuevoC;
		}
		else{
			ptrAnteriorC->ptrSiguienteC = ptrNuevoC;
			ptrNuevoC->ptrSiguienteC = ptrActualC;
			ptrNuevoC->ptrAnteriorC = ptrAnteriorC;
			if( ptrActualC != NULL ){
				ptrActualC->ptrAnteriorC = ptrNuevoC;
			}
		}
	}	
}

void eliminar2(ptrnodolistaC *ptrSC, ptrnodolistaC ptrDatosC)
{
	ptrnodolistaC  ptrActualC = *ptrSC;
	ptrnodolistaC  ptrAnteriorC = NULL;
	ptrnodolistaC  ptrTempC;
	if(ptrActualC != NULL){
		if(ptrDatosC->ID == ptrActualC->ID){
			ptrTempC = *ptrSC;
			(*ptrSC)->ptrAnteriorC = NULL;
			*ptrSC = (*ptrSC)->ptrSiguienteC;
			// actualizar los datos de ptrDatosC
			strcpy(ptrDatosC->Nombre, ptrTempC->Nombre);
			strcpy(ptrDatosC->apellido, ptrTempC->apellido);
			ptrDatosC->ID = ptrTempC->ID;
			strcpy(ptrDatosC->especialidad, ptrTempC->especialidad);
			ptrDatosC->telefono = ptrTempC->telefono;
			strcpy(ptrDatosC->genero, ptrTempC->genero);
			free(ptrTempC);
		}
		else{
			ptrActualC = (*ptrSC)->ptrSiguienteC;
			ptrAnteriorC = *ptrSC;
			while(ptrActualC != NULL && ptrDatosC->ID != ptrActualC->ID){
				ptrAnteriorC = ptrActualC;
				ptrActualC = ptrActualC->ptrSiguienteC;
			}
			if(ptrActualC != NULL){
				ptrTempC = ptrActualC;
				ptrAnteriorC->ptrSiguienteC = ptrActualC->ptrSiguienteC;
				if(ptrActualC->ptrSiguienteC != NULL){
					(ptrActualC->ptrSiguienteC)->ptrAnteriorC = ptrAnteriorC;
				}
            
			strcpy(ptrDatosC->Nombre, ptrTempC->Nombre);
			strcpy(ptrDatosC->apellido, ptrTempC->apellido);
			ptrDatosC->ID = ptrTempC->ID;
			strcpy(ptrDatosC->especialidad, ptrTempC->especialidad);
			ptrDatosC->telefono = ptrTempC->telefono;
			strcpy(ptrDatosC->genero, ptrTempC->genero);
			free(ptrTempC);
			}
		}
	}
}

int estaVaciaC(ptrnodolistaC ptrSC)
{
	return ptrSC == NULL;
}
		