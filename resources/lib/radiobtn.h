/*--------------------------------------------------------
  Libreria para crear grupo de radio botones
  creado por: Agustin Rivera
  el: 23 de mayo de 2017
  ruta: "D:\cientifica1\includes\radiobtn.h"
------------------------------------------------------------*/

struct nodo{
	int idndex;
	char texto[30];
	struct nodo *ptrAnterior;
	struct nodo *ptrSiguiente;
}; 

typedef struct nodo NodoLista;
typedef NodoLista *ptrNodoLista;

// clase para grupo de radio botones
class grpradio{
public:
	grpradio(char *titu);
	~grpradio();
	void mostrar(int x1, int y1, bool orienta);
	void ocultar();
	void focus();
	void agregar(char *texto);
	char *selectedtexto();
	int selectedindex();
	int count();
private:
	int x;
	int y;
	char titulo[40];
	bool orientacion;			// indica 0=Vertical, 1=horizontal 
	ptrNodoLista ptrInicio;		// Inicio de la lista de opciones
	int cantidad;				// cantidad de elementos
	ptrNodoLista ptrActual;		// nodo seleccionado
};

// Constructor de la clase
grpradio::grpradio(char *titu)
{
	x=1;
	y=1;
	strcpy(titulo, titu);
	orientacion = 0;
	ptrInicio = NULL;
	cantidad = 0;
	ptrActual = NULL;
}




