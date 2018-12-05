#if !defined(__LISTA_H)
     #define __LISTA_H

#if !defined(__CONIO_H)
     #include <conio.h>
#endif

#if !defined(__STRING_H)
     #include <string.h>
#endif

struct Contacto{
  int codigo;
  char nombre[30];
  int genero;
  int fecha_nac[3];
  char direccion[45];
  char email[45];
  char telefono[11];
  char celular[11];
  struct Contacto *ptrAnterior;
  struct Contacto *ptrSiguiente;
};

typedef struct Contacto strContacto;
typedef strContacto *ptrContacto;

class clsContacto{
private:
  ptrContacto ptrInicio;
  char *ruta_file;
  int num_codigo;
public:
clsContacto(char ruta[100]);
~clsContacto();
void Eliminar(char nombre[30]);
bool EstaVacia();
void Editar(char nombre_editar[30],char nombre[30],int genero, int fecha_nac[3], char direccion[45], char email[45], char telefono[11], char celular[11]);
void Insertar(char nombre[30],int genero, int fecha_nac[3], char direccion[45], char email[45], char telefono[11], char celular[11]);
ptrContacto InicioLista();
ptrContacto Busqueda(char nombre[30]);
void Guardar_En_El_Archivo();
void Cargar_Datos();
};

clsContacto::clsContacto(char *ruta)
{
  ptrInicio = NULL;
  num_codigo = 0;
  ruta_file = (char*)malloc((sizeof(char)*strlen(ruta)));
  strcpy(ruta_file,ruta);
}

clsContacto::~clsContacto()
{
  ptrContacto temp = NULL;
  while(ptrInicio != NULL)
  {
    temp = ptrInicio;
    free(temp);
    ptrInicio = ptrInicio->ptrSiguiente;
  }
}

void clsContacto::Insertar(char nombre[30],int genero, int fecha_nac[3], char direccion[45], char email[45], char telefono[11], char celular[11])
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
}

void clsContacto::Eliminar(char nombre[30])
{
    	ptrContacto ptrTemp;
    	ptrContacto ptrAnterior;
    	ptrContacto ptrActual;

      if((strcmp(ptrInicio->nombre,nombre) == 0)){
    		ptrTemp = ptrInicio;
        if((ptrInicio)->ptrSiguiente)
        {
          ptrInicio = (ptrInicio)->ptrSiguiente;
          ((ptrInicio)->ptrAnterior) = NULL;
        }
        else
        {
          ptrInicio = NULL;
        }
    		free(ptrTemp);
    	}
    	else{
    		ptrAnterior = ptrInicio;
    		ptrActual = (ptrInicio)->ptrSiguiente;;

    		while(ptrActual != NULL && strcmp(ptrActual->nombre,nombre) != 0){
    			ptrAnterior = ptrActual;
    			ptrActual = ptrActual->ptrSiguiente;
    		}
    		if(ptrActual != NULL){
    			ptrTemp = ptrActual;
    			ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
    			if(ptrActual->ptrSiguiente != NULL){
    				(ptrActual->ptrSiguiente)->ptrAnterior = ptrAnterior;
    			}
    			free(ptrTemp);
    		}
    	}
}

bool clsContacto::EstaVacia()
{
  return ptrInicio == NULL;
}

ptrContacto clsContacto::InicioLista()
{
  return ptrInicio;
}

void clsContacto::Guardar_En_El_Archivo()
{
	FILE *ptrArchivo;
	ptrContacto ptrActual = ptrInicio;
	if(!EstaVacia())
  {
		if((ptrArchivo = fopen(ruta_file, "ab+")) != NULL)
    {
			while(ptrActual != NULL)
      {
				fwrite(ptrActual, sizeof(strContacto), 1, ptrArchivo);
				ptrActual = ptrActual->ptrSiguiente;
			}
			fclose(ptrArchivo);
		}
	}
}

void clsContacto::Cargar_Datos()
{
  FILE *ptrArchivo;
  strContacto Datos;

  if( (ptrArchivo = fopen(ruta_file, "rb+")) != NULL )
  {
    fread(&Datos, sizeof(strContacto), 1, ptrArchivo);
      while(!feof(ptrArchivo))
      {
        Insertar(Datos.nombre,Datos.genero,Datos.fecha_nac,Datos.direccion,Datos.email,Datos.telefono,Datos.celular);
        fread(&Datos, sizeof(strContacto), 1, ptrArchivo);
      }
    fclose(ptrArchivo);
  }
}

void clsContacto::Editar(char nombre_editar[30],char nombre[30],int genero, int fecha_nac[3], char direccion[45], char email[45], char telefono[11], char celular[11])
{
  if(!EstaVacia())
  {
    Eliminar(nombre_editar);
    Insertar(nombre,genero,fecha_nac,direccion,email,telefono,celular);
  }
}

ptrContacto clsContacto::Busqueda(char nombre[30])
{
  ptrContacto ptrTemp = NULL;
  if(!EstaVacia())
  {
    ptrTemp = ptrInicio;
    while(ptrTemp != NULL && strcmp(ptrTemp->nombre,nombre) != 0)
    {
      ptrTemp = ptrTemp->ptrSiguiente;
    }
    return ptrTemp;
  }
  return ptrTemp;

}





#endif
