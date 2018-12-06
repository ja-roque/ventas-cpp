#if !defined(__PRODUCT_EN_VENTA_H)
     #define __PRODUCT_EN_VENTA_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct ProdVenta{
  int codigo;
  int cantidad;
  strProducto ProdRelacionado;
  struct ProdVenta *ptrAnterior;
  struct ProdVenta *ptrSiguiente;
};

typedef struct ProdVenta strProdVenta;
typedef strProdVenta *ptrProdVenta;

class producto_en_venta{
private:
  ptrProdVenta ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
producto_en_venta(char ruta[100]);
~producto_en_venta();
bool EstaVacia();
Insertar(char nombre[30], float precio,int existencia)
ptrProdVenta InicioLista();
};

producto_en_venta::producto_en_venta(char *ruta)
{
  ptrInicio = NULL;
  num_codigo = 0;
  ruta_file = (char*)malloc((sizeof(char)*strlen(ruta)));
  strcpy(ruta_file,ruta);
}

producto_en_venta::~producto_en_venta()
{
  ptrProdVenta temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void producto_en_venta::Insertar(char nombre[30], float precio)
{
	ptrProdVenta ptrNuevo;
	ptrProdVenta ptrAnterior;
	ptrProdVenta ptrActual;

	ptrNuevo = (ptrProdVenta) malloc(sizeof(strProdVenta));

	if(ptrNuevo != NULL)
  {
    num_codigo++;
    ptrNuevo->codigo = num_codigo;
    ptrNuevo->ProdRelacionado = elProducto;
		ptrNuevo->cantidad = laCantidad;
		ptrNuevo->ptrSiguiente = NULL;
		ptrAnterior = NULL;
		ptrActual = ptrInicio;

		while(ptrActual != NULL && strcmp(ptrActual->codigo,codigo) < 1)
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

bool producto_en_venta::EstaVacia()
{
  return ptrInicio == NULL;
}

ptrProdVenta producto_en_venta::InicioLista()
{
  return ptrInicio;
}

#endif
