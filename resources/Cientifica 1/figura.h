
#if !defined(_FIGURA_H)
     #define _FIGURA_H


//incluimos <conio.h> verificamos que no este definifa


 #if !defined(_CONIO_H)
     #include <conio.h>
 #endif


#define LHOR 196	/*	Linea Horizontal	*/
#define LVER 179	/*	Linea Vertical	*/
#define LESI 218	/*	Linea Superior Izquierda	*/
#define LESD 191	/*	Linea Superior Derecha	*/
#define LEII 192	/*	Linea Inferior Izquierda	*/
#define LEID 217	/*	Linea Inferior Derecha	*/
#define LCRU 197	/*	Linea Cruzada(Intercepcion o Cruz)	*/
#define LUND 180	/*	Linea Union Derecha	*/
#define LUNI 195	/*	Linea Union Izquierda	*/
#define LUNA 194	/*	Linea Union Arriba(T)	*/
#define LUNB 193	/*	Linea Union Abajo	*/

/*	FUNCION PARA BORRAR AREA	*/
/*void fxborrar(int x1, int y1, int x2, int y2)
{
	int x, y;
	for(y = y1; y <= y2; y++){
		for(x = x1, x < x2; x++){
			gotoxy(x, y);
			printf(" ");
		}
	}
} */


#endif