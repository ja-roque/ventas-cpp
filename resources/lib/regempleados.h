/*   Archivo de Empleados
	campos del archivo:
	codigo  tipo: Entero
	nombre	tipo: texto(30)
	genero	tipo: booleano
	iddepto	tipo: entero codigo del departamento
	sueldo tipo: float
*/
// ruta: G:\cpps\includes\regempleados.h
// Estructura de los campos del archivo


#ifndef __REGEMPLEADOS_H		// Verificamos si no esta definida la libreria textbox
	#define __REGEMPLEADOS_H  // Sino es asi se define

// Incluimos otras librerias a utilizar
#if !defined(__CONIO_H)
	#include <conio.h>         // Validamos la inclusion de conio.h
#endif

// Incluimos otras librerias a utilizar
#if !defined(__STRING_H)
	#include <string.h>         // Validamos la inclusion de conio.h
#endif



struct registro{
	int codigo;
	char nombre[30];
	bool genero;
	int iddepto;
	float sueldo;
};
typedef struct registro Registro;
typedef Registro *ptrRegistro;

struct nodor{
	Registro datos;
	struct nodor *ptrAtras;		// Apuntador al nodo de Atras
	struct nodor *ptrSiguiente;	// Apuntador al nopdo de adelante o siguiente
};

typedef struct nodor NodorLst;
typedef NodorLst *ptrNodorLst;

class regEmpleado{
public:
	regEmpleado(char *archivo);
	~regEmpleado();
	void Insertar(Registro *t);
	void Borrar(int codigo);
	void Modificar(int codigo, Registro *nuevo);
	int Existe(int codigo);
	ptrNodorLst Inicio();
	void Guardar();
	ptrNodorLst Consultar(int codigo);
	int fxitems();
private:
	ptrNodorLst ptrInicio;
	FILE *ptrArchivo;
	char rutaarch[100];
	int items;					// Cantidad de elementos dentro de la lista
};

regEmpleado::regEmpleado(char *archivo)
{
	ptrInicio = NULL;
	items=0;
	Registro Datos;
	strcpy(rutaarch, archivo);
	ptrArchivo = fopen(rutaarch, "rb");
	if(ptrArchivo != NULL){
		fread(&Datos,sizeof(Registro),1,ptrArchivo);
		while(!feof(ptrArchivo)){
			Insertar(&Datos);
			fread(&Datos,sizeof(Registro),1,ptrArchivo);
		}
		fclose(ptrArchivo);
	}
}

// Funcion para guardar
void regEmpleado::Guardar()
{
	ptrNodorLst ptrActual = ptrInicio;
	ptrArchivo = fopen(rutaarch, "wb");
	if(ptrArchivo != NULL){
		while(ptrActual != NULL){
			fwrite(&(ptrActual->datos),sizeof(Registro),1,ptrArchivo);
			ptrActual = ptrActual->ptrSiguiente;
		}
	}
}


regEmpleado::~regEmpleado()
{
	ptrNodorLst ptrActual = ptrInicio;
	Guardar();
	ptrNodorLst ptrTemp = NULL;
	ptrInicio = NULL;
	while(ptrActual != NULL){
		ptrTemp = ptrActual;
		ptrActual=ptrActual->ptrSiguiente;
		delete(ptrTemp);
	}
}

void regEmpleado::Insertar(Registro *t)
{
	ptrNodorLst ptrNuevo;
	ptrNodorLst ptrAnterior = NULL;
	ptrNodorLst ptrActual = ptrInicio;

	if(!Existe(t->codigo)){
		ptrNuevo = (ptrNodorLst) new(NodorLst);
		if(ptrNuevo != NULL){
			ptrNuevo->datos.codigo = t->codigo;
			strcpy(ptrNuevo->datos.nombre, t->nombre);
			ptrNuevo->datos.genero = t->genero;
			ptrNuevo->datos.iddepto = t->iddepto;
			ptrNuevo->datos.sueldo = t->sueldo;
			ptrNuevo->ptrAtras = NULL;
			ptrNuevo->ptrSiguiente= NULL;

			//Verificar donde debe insertarse el nuevo nodo
			while(ptrActual != NULL && ptrActual->datos.codigo < t->codigo){
				ptrAnterior = ptrActual;
				ptrActual = ptrActual->ptrSiguiente;
			}

			if(ptrAnterior == NULL){
				ptrNuevo->ptrSiguiente = ptrInicio;
				if(ptrInicio != NULL)
					ptrInicio->ptrAtras = ptrNuevo;
				ptrInicio = ptrNuevo;
			}
			else{
				ptrAnterior->ptrSiguiente = ptrNuevo;
				ptrNuevo->ptrSiguiente = ptrActual;
				ptrNuevo->ptrAtras = ptrAnterior;
				if(ptrActual != NULL)
					ptrActual->ptrAtras = ptrNuevo;
			}
			items++;
		}
		else{
			gotoxy(1,25); printf("Lo siento no hay memoria comprar unos 8GB");
		}
	}
	else{
		gotoxy(1,25); printf("Dato ya fue ingresado anteriormente por otra persona o usted");
	}
}

void regEmpleado::Borrar(int codigo)
{
	ptrNodorLst ptrAnterior = NULL;
	ptrNodorLst ptrActual = ptrInicio;

	//Verificar donde debe insertarse el nuevo nodo
	while(ptrActual != NULL && ptrActual->datos.codigo != codigo){
		ptrAnterior = ptrActual;
		ptrActual = ptrActual->ptrSiguiente;
	}

	if(ptrActual != NULL){
		if(ptrAnterior == NULL)
		{
			ptrInicio = ptrInicio->ptrSiguiente;
			if(ptrInicio != NULL){
				ptrInicio->ptrAtras = NULL;
			}
		}
		else{
			ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
			if(ptrActual->ptrSiguiente != NULL){
				(ptrActual->ptrSiguiente)->ptrAtras = ptrAnterior;
			}
		}
		delete(ptrActual);
		items--;
	}
	else{
		gotoxy(1,25); printf("No Existe el Dato");
	}
}

void regEmpleado::Modificar(int codigo, Registro *nuevo)
{
	ptrNodorLst ptrActual = ptrInicio;

	//Verificar donde debe insertarse el nuevo nodo
	while(ptrActual != NULL && ptrActual->datos.codigo != nuevo->codigo){
			ptrActual = ptrActual->ptrSiguiente;
	}
	if(ptrActual != NULL){
		ptrActual->datos.codigo = nuevo->codigo;
		strcpy(ptrActual->datos.nombre, nuevo->nombre);
		ptrActual->datos.genero = nuevo->genero;
		ptrActual->datos.iddepto = nuevo->iddepto;
		ptrActual->datos.sueldo = nuevo->sueldo;
	}
	else{
		gotoxy(1,25); printf("No Existe el Dato");
	}
}

//Funcion para validar si ya existe un item, retorna 1 si existe y 0 sino
int regEmpleado::Existe(int codigo)
{
	ptrNodorLst ptrActual = ptrInicio;

	//Verificar donde debe insertarse el nuevo nodo
	while(ptrActual != NULL && ptrActual->datos.codigo != codigo){
			ptrActual = ptrActual->ptrSiguiente;
	}
	if(ptrActual != NULL){
		return 1;
	}
	else{
		return 0;
	}
}
ptrNodorLst regEmpleado::Inicio()
{
	return ptrInicio;
}


int regEmpleado::fxitems()
{
	return items;
}


#endif  // Fin del IF donde se valida la definicion