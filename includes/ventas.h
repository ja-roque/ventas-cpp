#if !defined(__VENTAS_H)
     #define __VENTAS_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Ventas{
  int id;
  char cliente[30];
  int forma_de_pago;
  int fecha;
  strProdVenta lista_productos[100];
  char cai[30];
  float regalia;
  float subtotal; 
  float total;
  struct Ventas *ptrAnterior;
  struct Ventas *ptrSiguiente;
};

typedef struct Ventas strVentas;
typedef strVentas *ptrVentas;

class ventas{
private:
  ptrVentas ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
ventas(char ruta[100]);
~ventas();
bool EstaVacia();
Insertar(char nombre[30], float precio,int existencia)
ptrVentas InicioLista();
};

ventas::ventas(char *ruta)
{
  ptrInicio = NULL;
  num_codigo = 0;
  ruta_file = (char*)malloc((sizeof(char)*strlen(ruta)));
  strcpy(ruta_file,ruta);
}

ventas::~ventas()
{
  ptrVentas temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void ventas::Insertar(char nombre[30], float precio)
{
	ptrVentas ptrNuevo;
	ptrVentas ptrAnterior;
	ptrVentas ptrActual;

	ptrNuevo = (ptrVentas) malloc(sizeof(strVentas));

	if(ptrNuevo != NULL)
  {
    num_codigo++;
    ptrNuevo->id = num_codigo
    strcpy(ptrNuevo->cliente,cliente)
    ptrNuevo->forma_de_pago = forma_de_pago
    ptrNuevo->fecha = fecha;
    ptrNuevo->lista_productos[0] = prd_ven1;
    ptrNuevo->lista_productos[1] = prd_ven2;
    strcpy(ptrNuevo->cai, cai);
    ptrNuevo->regalia = regalia;
    ptrNuevo->subtotal = subtotal;

		while(ptrActual != NULL && strcmp(ptrActual->cliente,cliente) < 1)
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

bool ventas::EstaVacia()
{
  return ptrInicio == NULL;
}

ptrVentas ventas::InicioLista()
{
  return ptrInicio;
}

#endif
