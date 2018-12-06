#if !defined(__CLIENTES_H)
     #define __CLIENTES_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Contacto{
  int codigo;
  char nombre[30];
  struct Contacto *ptrAnterior;
  struct Contacto *ptrSiguiente;
};

typedef struct Contacto strContacto;
typedef strContacto *ptrContacto;

class clientes{
private:
  ptrContacto ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
clientes(char ruta[100]);
~clientes();
bool EstaVacia();
Insertar(char nombre[30]);
ptrContacto InicioLista();
};

clientes::clientes(char *ruta)
{
  ptrInicio = NULL;
  num_codigo = 0;
  ruta_file = (char*)malloc((sizeof(char)*strlen(ruta)));
  strcpy(ruta_file,ruta);
}

clientes::~clientes()
{
  ptrContacto temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void clientes::Insertar(char nombre[30])
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

bool clientes::EstaVacia()
{
  return ptrInicio == NULL;
}

ptrContacto clientes::InicioLista()
{
  return ptrInicio;
}


#endif
