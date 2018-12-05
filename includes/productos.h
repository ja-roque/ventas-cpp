#if !defined(__PRODUCTOS_H)
     #define __PRODUCTOS_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Contacto{
  int codigo;
  char nombre[30];
  float precio;
  int existencia;
  struct Contacto *ptrAnterior;
  struct Contacto *ptrSiguiente;
};

typedef struct Contacto strContacto;
typedef strContacto *ptrContacto;

class productos{
private:
  ptrContacto ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
productos(char ruta[100]);
~productos();
bool EstaVacia();
Insertar(char nombre[30], float precio,int existencia)
ptrContacto InicioLista();
};

productos::productos(char *ruta)
{
  ptrInicio = NULL;
  num_codigo = 0;
  ruta_file = (char*)malloc((sizeof(char)*strlen(ruta)));
  strcpy(ruta_file,ruta);
}

productos::~productos()
{
  ptrContacto temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void productos::Insertar(char nombre[30], float precio)
{
	ptrContacto ptrNuevo;
	ptrContacto ptrAnterior;
	ptrContacto ptrActual;

	ptrNuevo = (ptrContacto) malloc(sizeof(strContacto));

	if(ptrNuevo != NULL)
  {
    num_codigo++;
    ptrNuevo->codigo = num_codigo;
		strcpy(ptrNuevo->nombre,nombre);
    ptrNuevo->precio = precio;
		ptrNuevo->ptrAnterior = NULL;
		ptrNuevo->ptrSiguiente = NULL;
		ptrAnterior = NULL;
		ptrActual = ptrInicio;

		while(ptrActual != NULL && strcmp(ptrActual->nombre,nombre) < 1)
    {
			ptrAnterior = ptrActual;
			ptrActual = ptrActual->ptrSiguiente;
		}

		if(ptrAnterior == NULL)
    {
			ptrNuevo->ptrSiguiente = ptrInicio;

			if(ptrInicio != NULL)
      {
				(ptrInicio)->ptrAnterior = ptrNuevo;
			}
			ptrInicio = ptrNuevo;
		}
		else
    {
			ptrAnterior->ptrSiguiente = ptrNuevo;
			ptrNuevo->ptrAnterior = ptrAnterior;
			ptrNuevo->ptrSiguiente = ptrActual;
			if(ptrActual != NULL)
      {
				ptrActual->ptrAnterior = ptrNuevo;
			}
		}
	}
	else
  {
		printf("MEMORIA INSUFICIENTE PARA INSERTAR EL NUEVO DATO");
	}
}

bool productos::EstaVacia()
{
  return ptrInicio == NULL;
}

ptrContacto productos::InicioLista()
{
  return ptrInicio;
}

#endif
