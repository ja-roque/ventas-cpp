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
  float monto_total;
  float impto;
  float regalia;
  struct ptrVentas_Detalles *Lista_Detalle;
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
public:
clsVentas(char ruta[100]);
~clsVentas();
void Eliminar(char nombre[30]);
bool EstaVacia();
void Insertar(char nombre[30],int genero, int fecha_nac[3], char direccion[45], char email[45], char telefono[11], char celular[11]);
ptrVentas InicioLista();
void Guardar_En_El_Archivo();
void Cargar_Datos();
};

clsVentas::clsVentas(char *ruta)
{
  ptrInicio = NULL;
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

/*void clsVentas::Insertar(char nombre[30],int genero, int fecha_nac[3], char direccion[45], char email[45], char telefono[11], char celular[11])
{
	ptrVentas ptrNuevo;
	ptrVentas ptrAnterior;
	ptrVentas ptrActual;

	ptrNuevo = (ptrVentas) malloc(sizeof(strVentas));

	if(ptrNuevo != NULL)
  {
    num_codigo++;
    ptrNuevo->codigo = num_codigo;
		strcpy(ptrNuevo->nombre,nombre);
    ptrNuevo->genero = genero;
    for(int i=0;i<3;i++)
    {
      ptrNuevo->fecha_nac[i] = fecha_nac[i];
    }
    strcpy(ptrNuevo->direccion,direccion);
    strcpy(ptrNuevo->email,email);
    strcpy(ptrNuevo->telefono,telefono);
    strcpy(ptrNuevo->celular,celular);
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
}*/


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
#endif
