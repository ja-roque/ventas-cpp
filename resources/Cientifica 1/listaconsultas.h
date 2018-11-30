#include <stdio.h>
#include <string.h>

struct nodolistaCon{
	char Nombre[10];
	char apellido[30];
	int telefono;
	int ID;
	char especialidad[10];
	char genero[10];
	struct nodolistaCon *ptrAnteriorCon;
	struct nodolistaCon *ptrSiguienteCon;
};
	
	
typedef struct nodolistaCon nodolistaCon;
typedef struct nodolistaCon *ptrnodolistaCon;

// Prototipos de las funciones
void insertarCon(ptrnodolistaCon *ptrSCon, ptrnodolistaCon ptrDatosCon);	// Funcion para insertar un nodo a la lista
void eliminarCon(ptrnodolistaCon *ptrSCon, ptrnodolistaCon ptrDatosCon);
int estaVaciaCon(ptrnodolistaCon ptrSCon);

// definiciones de funciones
void insertarCon(ptrnodolistaCon *ptrSCon, ptrnodolistaCon ptrDatosCon)
{
	ptrnodolistaCon ptrNuevoCon;
	ptrnodolistaCon ptrActualCon;
	ptrnodolistaCon ptrAnteriorCon;
	// Solicitamos Memoria del tamanio de la estructura de nodolistaCpacientes
	ptrNuevoCon = (ptrnodolistaCon) malloc(sizeof(nodolistaCon));
	if(ptrNuevoCon != NULL){
        strcpy(ptrNuevoCon->Nombre, ptrDatosCon->Nombre);
		strcpy(ptrNuevoCon->apellido, ptrDatosCon->apellido);
		ptrNuevoCon->ID = ptrDatosCon->ID;
		strcpy(ptrNuevoCon->especialidad, ptrDatosCon->especialidad);
		ptrNuevoCon->telefono = ptrDatosCon->telefono;
		strcpy(ptrNuevoCon->genero, ptrDatosCon->genero);
		ptrNuevoCon->ptrAnteriorCon = NULL;
		ptrNuevoCon->ptrSiguienteCon = NULL;
				
		ptrAnteriorCon = NULL;
		ptrActualCon = *ptrSCon;
		
		// Ubica el nuevo valor en la posicion donde se debe insertar
		while(ptrActualCon != NULL && strcmp(ptrDatosCon->Nombre, ptrActualCon->Nombre) < 0 ){
			ptrAnteriorCon = ptrActualCon;
			ptrActualCon = ptrActualCon->ptrSiguienteCon;
		}
		
		if(ptrAnteriorCon == NULL){
			ptrNuevoCon->ptrSiguienteCon = *ptrSCon;
			if( (*ptrSCon) != NULL ){
				(*ptrSCon)->ptrAnteriorCon = ptrNuevoCon;
			}
			*ptrSCon = ptrNuevoCon;
		}
		else{
			ptrAnteriorCon->ptrSiguienteCon = ptrNuevoCon;
			ptrNuevoCon->ptrSiguienteCon = ptrActualCon;
			ptrNuevoCon->ptrAnteriorCon = ptrAnteriorCon;
			if( ptrActualCon != NULL ){
				ptrActualCon->ptrAnteriorCon = ptrNuevoCon;
			}
		}
	}	
}

void eliminar2(ptrnodolistaCon *ptrSCon, ptrnodolistaCon ptrDatosCon)
{
	ptrnodolistaCon  ptrActualCon = *ptrSCon;
	ptrnodolistaCon  ptrAnteriorCon = NULL;
	ptrnodolistaCon  ptrTempCon;
	if(ptrActual != NULL){
		if(ptrDatosCon->ID == ptrActualCon->ID){
			ptrTempCon = *ptrSCon;
			(*ptrSCon)->ptrAnteriorCon = NULL;
			*ptrSCon = (*ptrSCon)->ptrSiguienteCon;
			// actualizar los datos de ptrDatosC
			strcpy(ptrDatosCon->Nombre, ptrTempCon->Nombre);
			strcpy(ptrDatosCon->apellido, ptrTempCon->apellido);
			ptrDatosCon->ID = ptrTempCon->ID;
			strcpy(ptrDatosCon->especialidad, ptrTempCon->especialidad);
			ptrDatosCon->telefono = ptrTempCon->telefono;
			strcpy(ptrDatosCon->genero, ptrTempCon->genero);
			free(ptrTempCon);
		}
		else{
			ptrActualCon = (*ptrSCon)->ptrSiguienteCon;
			ptrAnteriorCon = *ptrSCon;
			while(ptrActualCon != NULL && ptrDatosCon->ID != ptrActualCon->ID){
				ptrAnteriorCon = ptrActualCon;
				ptrActualCon = ptrActualCon->ptrSiguienteCon;
			}
			if(ptrActualCon != NULL){
				ptrTempCon = ptrActualCon;
				ptrAnteriorCon->ptrSiguienteCon = ptrActualCon->ptrSiguienteCon;
				if(ptrActualCon->ptrSiguienteCon != NULL){
					(ptrActualCon->ptrSiguienteCon)->ptrAnteriorCon = ptrAnteriorCon;
				}
            
			strcpy(ptrDatosCon->Nombre, ptrTempCon->Nombre);
			strcpy(ptrDatosCon->apellido, ptrTempCon->apellido);
			ptrDatosCon->ID = ptrTempCon->ID;
			strcpy(ptrDatosCon->especialidad, ptrTempCon->especialidad);
			ptrDatosCon->telefono = ptrTempCon->telefono;
			strcpy(ptrDatosCon->genero, ptrTempCon->genero);
			free(ptrTempCon);
			}
		}
	}
}

int estaVaciaCon(ptrnodolistaCon ptrSCon)
{
	return ptrSCon == NULL;
}
		