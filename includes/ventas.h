#if !defined(__VENTAS_H)
     #define __VENTAS_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Ventas_Detalle{
  char producto[30];
  float precio_unit;
  float cantidad;
  float total_producto;
  struct Ventas_Detalle *ptrAnterior;
  struct Ventas_Detalle *ptrSiguiente;
};

typedef struct Ventas_Detalle strVentas_Detalle;
typedef strVentas_Detalle *ptrVentas_Detalle;

struct Ventas{
  int codigo;
  char cliente[30];
  char CAI[17];
  float monto_total;
  float impto;
  float regalia;
  ptrVentas_Detalle Lista_Detalle;
  int forma_pago;
  bool estado;
  struct Ventas *ptrAnterior;
  struct Ventas *ptrSiguiente;
};

typedef struct Ventas strVentas;
typedef strVentas *ptrVentas;



class clsVentas{
private:
  ptrVentas ptrInicio;
  char *ruta_file;
  int num_codigo;
  ptrVentas_Detalle Inicio_Detalle;
public:
clsVentas(char ruta[100]);
~clsVentas();
void Eliminar(char nombre[30]);
bool EstaVacia();
void Insertar(char Cliente[30],float Total,float Impto,float Regalia,int FormaPago,char cai[17]);
void Insertar_Detalle(char Nombre[30],float Precio_Unit,float Cantidad,float Total_Producto);
ptrVentas InicioLista();
void Guardar_En_El_Archivo();
void Cargar_Datos();
void clsVentas::Imprimir_Detalle(ptrVentas NodoVentas);
float Subtotal();
void Imprimir(int x, int y, int page);
};

clsVentas::clsVentas(char *ruta)
{
  ptrInicio = NULL;
  Inicio_Detalle = NULL;
  num_codigo = 0;
  ruta_file = (char*)malloc((sizeof(char)*strlen(ruta)));
  strcpy(ruta_file,ruta);
}

clsVentas::~clsVentas()
{
  ptrVentas temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void clsVentas::Insertar(char Cliente[30],float Total,float Impto,float Regalia,int FormaPago,char cai[17])
{
	ptrVentas ptrNuevo;
	ptrVentas ptrAnterior;
	ptrVentas ptrActual;

	ptrNuevo = (ptrVentas) malloc(sizeof(strVentas));

	if(ptrNuevo != NULL)
  {
    num_codigo++;
    ptrNuevo->codigo = num_codigo;
    strcpy(ptrNuevo->cliente,Cliente);
    ptrNuevo->monto_total = Total;
    ptrNuevo->impto = Impto;
    ptrNuevo->regalia = Regalia;
    ptrNuevo->Lista_Detalle = Inicio_Detalle;
    ptrNuevo->forma_pago = FormaPago;
    ptrNuevo->estado = true;
    strcpy(ptrNuevo->CAI,cai);


		ptrNuevo->ptrAnterior = NULL;
		ptrNuevo->ptrSiguiente = NULL;
		ptrAnterior = NULL;
		ptrActual = ptrInicio;

		while(ptrActual != NULL)
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
    Inicio_Detalle = NULL;
	}
	else
  {
		printf("MEMORIA INSUFICIENTE PARA INSERTAR EL NUEVO DATO");
	}
}

void clsVentas::Insertar_Detalle(char Nombre[30],float Precio_Unit,float Cantidad,float Total_Producto)
{
  ptrVentas_Detalle ptrNuevo;
	ptrVentas_Detalle ptrAnterior;
	ptrVentas_Detalle ptrActual;

	ptrNuevo = (ptrVentas_Detalle) malloc(sizeof(strVentas_Detalle));

	if(ptrNuevo != NULL)
  {
    strcpy(ptrNuevo->producto,Nombre);
    ptrNuevo->precio_unit = Precio_Unit;
    ptrNuevo->cantidad = Cantidad;
    ptrNuevo->total_producto = Total_Producto;

		ptrNuevo->ptrAnterior = NULL;
		ptrNuevo->ptrSiguiente = NULL;
		ptrAnterior = NULL;
		ptrActual = Inicio_Detalle;

		while(ptrActual != NULL)
    {
			ptrAnterior = ptrActual;
			ptrActual = ptrActual->ptrSiguiente;
		}

		if(ptrAnterior == NULL)
    {
			ptrNuevo->ptrSiguiente = Inicio_Detalle;

			if(Inicio_Detalle != NULL)
      {
				(Inicio_Detalle)->ptrAnterior = ptrNuevo;
			}
			Inicio_Detalle = ptrNuevo;
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



bool clsVentas::EstaVacia()
{
  return ptrInicio == NULL;
}

ptrVentas clsVentas::InicioLista()
{
  return ptrInicio;
}

void clsVentas::Guardar_En_El_Archivo()
{
	FILE *ptrArchivo;
	ptrVentas ptrActual = ptrInicio;
	if(!EstaVacia())
  {
		if((ptrArchivo = fopen(ruta_file, "ab+")) != NULL)
    {
			while(ptrActual != NULL)
      {
				fwrite(ptrActual, sizeof(strVentas), 1, ptrArchivo);
				ptrActual = ptrActual->ptrSiguiente;
			}
			fclose(ptrArchivo);
		}
	}
}

void clsVentas::Cargar_Datos()
{
  FILE *ptrArchivo;
  strVentas Datos;

  if( (ptrArchivo = fopen(ruta_file, "rb+")) != NULL )
  {
    fread(&Datos, sizeof(strVentas), 1, ptrArchivo);
      while(!feof(ptrArchivo))
      {
        //Insertar(Datos.nombre,Datos.genero,Datos.fecha_nac,Datos.direccion,Datos.email,Datos.telefono,Datos.celular);
        fread(&Datos, sizeof(strVentas), 1, ptrArchivo);
      }
    fclose(ptrArchivo);
  }
}

void clsVentas::Imprimir(int x, int y, int page)
{
  ptrVentas Inic_Temp = ptrInicio;
  while(Inic_Temp != NULL)
  {
    gotoxy(x,y);printf("%d",Inic_Temp->codigo);
    y++;
    Inic_Temp  = Inic_Temp->ptrSiguiente;
  }
}

void clsVentas::Imprimir_Detalle(ptrVentas NodoVentas)
{
  int y = 8;
  ptrVentas_Detalle Inic_Temp = NodoVentas->Lista_Detalle;
  char aux[100];
  while(Inic_Temp != NULL)
  {
    sprintf(aux, "%.2f", Inic_Temp->cantidad);
    gotoxy(22,y);printf("%7s",aux);
    gotoxy(32,y);printf("%s",Inic_Temp->producto);
    sprintf(aux, "%.2f", Inic_Temp->precio_unit);
    gotoxy(57,y);printf("%11s",aux);
    sprintf(aux, "%.2f", Inic_Temp->total_producto);
    gotoxy(69,y);printf("%11s",aux);
    y++;
    Inic_Temp  = Inic_Temp->ptrSiguiente;
  }

  gotoxy(32,5);printf("%s",NodoVentas->cliente);

  sprintf(aux, "%.2f", (NodoVentas->monto_total - NodoVentas->impto - NodoVentas->regalia));
  gotoxy(69,15);printf("%11s",aux);
  sprintf(aux, "%.2f", NodoVentas->impto);
  gotoxy(69,16);printf("%11s",aux);
  sprintf(aux, "%.2f", NodoVentas->regalia);
  gotoxy(69,17);printf("%11s",aux);
  sprintf(aux, "%.2f", NodoVentas->monto_total);
  gotoxy(69,18);printf("%11s",aux);

  if(NodoVentas->forma_pago == 1)
  {
    gotoxy(25,18);printf(" ");
    gotoxy(37,18);printf("%c",254);
  }
  else
  {
    gotoxy(25,18);printf("%c",254);
    gotoxy(37,18);printf(" ");
  }

  if(NodoVentas->estado == true)
  {
    gotoxy(24,19);printf("ESTADO: AUTORIZADA [%c] ANULADA[ ]",254);
  }
  else
  {
    gotoxy(24,19);printf("ESTADO: AUTORIZADA [ ] ANULADA[%c]",254);
  }

  gotoxy(59,2);printf("FACTURA:%13d",NodoVentas->codigo);
  gotoxy(59,3);printf("CAI:%17s",NodoVentas->CAI);



}

float clsVentas::Subtotal()
{
  ptrVentas_Detalle Inic_Temp = Inicio_Detalle;
  float subtotal = 0;
  while(Inic_Temp != NULL)
  {
    subtotal = Inic_Temp->total_producto;
    Inic_Temp  = Inic_Temp->ptrSiguiente;
  }
  return subtotal;
}
#endif
