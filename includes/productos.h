#if !defined(__INVENTARIO_H)
     #define __Producto_H

#if !defined(__INVENTARIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Producto{
  int codigo;
  char nombre[30];
  float precio;
  int existencia;
  struct Producto *ptrAnterior;
  struct Producto *ptrSiguiente;
};

typedef struct Producto strProducto;
typedef strProducto *ptrProducto;

typedef struct Producto strProducto;
typedef strProducto *ptrProducto;

class productos{
private:
  ptrProducto ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
productos(char ruta[100]);
~productos();
bool EstaVacia();
void Insertar(char nombre[30],float precio, float existencia);
ptrProducto InicioLista();
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
  ptrProducto temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void productos::Insertar(char nombre[30],float precio, float existencia)
{
	ptrProducto ptrNuevo;
	ptrProducto ptrAnterior;
	ptrProducto ptrActual;

	ptrNuevo = (ptrProducto) malloc(sizeof(strProducto));

	if(ptrNuevo != NULL)
  {
    num_codigo++;
    struct Producto{
      int codigo;
      char nombre[30];
      float precio;
      int existencia;
      struct Producto *ptrAnterior;
      struct Producto *ptrSiguiente;
    };
    ptrNuevo->codigo = num_codigo;
		strcpy(ptrNuevo->nombre,nombre);
    ptrNuevo->precio = precio;
    ptrNuevo->existencia = existencia;
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

ptrProducto productos::InicioLista()
{
  return ptrInicio;
}


#endif
