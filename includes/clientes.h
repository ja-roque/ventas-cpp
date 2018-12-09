#if !defined(__CLIENTE_H)
     #define __CLIENTE_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Cliente{
  int codigo;
  char nombre[30];
  struct Cliente *ptrAnterior;
  struct Cliente *ptrSiguiente;
};

typedef struct Cliente strCliente;
typedef strCliente *ptrCliente;

class clientes{
private:
  ptrCliente ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
clientes(char ruta[100]);
~clientes();
bool EstaVacia();
void Insertar(char nombre[30]);
ptrCliente InicioLista();
void Imprimir(int x, int y, int page);
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
  ptrCliente temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void clientes::Insertar(char nombre[30])
{
	ptrCliente ptrNuevo;
	ptrCliente ptrAnterior;
	ptrCliente ptrActual;

	ptrNuevo = (ptrCliente) malloc(sizeof(strCliente));

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

ptrCliente clientes::InicioLista()
{
  return ptrInicio;
}

void clientes::Imprimir(int x, int y, int page)
{
  ptrCliente Inic_Temp = ptrInicio;
  while(Inic_Temp != NULL)
  {
    gotoxy(x,y);printf("%s",Inic_Temp->nombre);
    y++;
    Inic_Temp  = Inic_Temp->ptrSiguiente;
  }
}


#endif
