
#include <string.h>

#if !defined(__CONTROLES_H)
#define __CONTROLES_H

#if !defined(__TECLAS_H)
	//#include "F:\librerias\teclas.h"
	#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\teclas.h"
#endif

#if !defined(__FIGURA_H)
	//#include "F:\librerias\figura.h"
	#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\figura.h"
#endif


			/*	Funcion para Cajas de Textos	*/

void textbox(int x, int y, int ancho, char *texto)
{
	int i;
	int tecla;

	if( (ancho + x < 80 && ancho > 0) && (x >= 1 && x <= 78) ){
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(x, y);
		cprintf("[");
		gotoxy(x + ancho+1, y);
		cprintf("]");
		textbackground(YELLOW);
	
		for(i = 0; i < ancho; i++){
			gotoxy(x+i+1, y);
			cprintf(" ");
		}
		
		gotoxy(x+1, y);
		i= 0;
		/*while(i <= ancho && tecla != ENTER){
			gotoxy(x + i + 1, y);
			tecla = fxtecla();
			/*Validamos lo caracteres
			if( (tecla >= 30 && tecla <= 168) && (i < ancho)){
				cprintf("%c", tecla);
				*texto = tecla;
				texto++;
				i++;
				/*switch(tecla){
					case 
				}
				//	Fin del Switch	
			}
			else if(tecla == RETRO && i >= 1){
				texto--;
				i--;
				*texto= BARRA;
				gotoxy(x + i + 1, y);
				cprintf("%c", *texto);
			}
			if(tecla == ENTER){
				*texto = '\0';
			}*/
			
		}	/*	FIN DE WHILE*/
		textbackground(BLACK);
	}	/*	FIN DE CASO IF	*/
	//else
		


int radiobotonv(int x, int y, char *texto, int items, int ancho)	/*	(CoordX, CoordY, ArregloTexto, CantidadElementosArreglo, AnchuraPorItem)*/
{
	int sel = -1;	/*	Item seleccionado	*/
	int largo = 0;	
	int maxlargo = 0;	/*	Para obtener cual de los elementos es el mas largo y saber cuando cerrar el corchete	*/
	int tecla;
   int i = 0;
	
	if( (y >= 1 && y + items <= 25) && (x >= 1 && x + ancho < 80) ){
		sel = 0;
		for(i = 0; i < items; i++){
			largo = strlen( (texto + ancho*i) );	/*	No se usa el asteristo porque nos lleva exactamente a un caracter en especifico	*/
			if(largo > maxlargo){
				maxlargo = largo;
			}
		}
		maxlargo += 3;
		
		gotoxy(x, y);
		printf("%c", LESI);
		
		gotoxy(x + largo+1, y);
		printf("%c", LESD);
		
		gotoxy(x, y + items-1);
		printf("%c", LEII);
		
		gotoxy(x + maxlargo+1, y + items-1);
		printf("%c", LEID);
	
		for(i = 1; i < items-1; i++){
			gotoxy(x, y + i);
			printf("%c", LVER);
			
			gotoxy(x + maxlargo+1, y + i);
			printf("%c", LVER);
		}
		
		for(i = 0; i < items; i++){
			gotoxy(x, y + i);
			printf("( )%s", (texto + ancho*i));	/*	Sin el asterisco para ir al contenido porque ocu0pamos tratarlo como un elemento del arreglo	*/
		}
	
		
		do{
			textcolor(YELLOW);
			gotoxy(x + 1, y + sel);
			cprintf("%c", 254);
			gotoxy(x + 1, y + sel);
			
			tecla = fxtecla();
				switch(tecla){
					case FARR:
						if(sel > 0){
							gotoxy(x + 1, y + sel);
							printf(" ");
							sel--;
						}
						break;
					case FABA:
						if(sel < items-1){
							gotoxy(x + 1, y + sel);
							printf(" ");
							sel++;
						}
						break;
				}
		}while(tecla != ENTER);
		textcolor(WHITE);
	}
	return sel;
}
/*	FINALIZA FUNCION DE RADIOBOTON2VERTICAL*/

int radiobotonh(int x, int y, char *texto, int items, int ancho)	/*	(CoordX, CoordY, ArregloTexto, CantidadElementosArreglo, AnchuraPorItem)*/
{
	int sel = -1;	/*	Item seleccionado	*/
	int largo = 0;
	int maxlargo = 0;	/*	Para obtener cual de los elementos es el mas largo y saber cuando cerrar el corchete	*/
	int tecla;
   int i = 0;
	
	if( (y >= 1 && y + items <= 25) && (x >= 1 && x + ancho < 80) ){
		sel = 0;
		for(i = 0; i < items; i++){
			largo = strlen( (texto + ancho*i) );	/*	No se usa el asteristo porque nos lleva exactamente a un caracter en especifico	*/
			if(largo > maxlargo){
				maxlargo = largo;
			}
		}
		maxlargo += 3;
		
		gotoxy(x, y);
		printf("%c", LESI);
		
		gotoxy(x + largo+1, y);
		printf("%c", LESD);
		
		gotoxy(x, y + items-1);
		printf("%c", LEII);
		
		gotoxy(x + maxlargo+1, y + items-1);
		printf("%c", LEID);
	
		for(i = 1; i < items-1; i++){
			gotoxy(x, y + i);
			printf("%c", LVER);
			
			gotoxy(x + maxlargo+1, y + i);
			printf("%c", LVER);
		}
		
		for(i = 0; i < items; i++){
			gotoxy(x, y + i);
			printf("( )%s", (texto + ancho*i));	/*	Sin el asterisco para ir al contenido porque ocu0pamos tratarlo como un elemento del arreglo	*/
		}
	
		
		do{
			textcolor(YELLOW);
			gotoxy(x + 1, y + sel);
			cprintf("%c", 254);
			gotoxy(x + 1, y + sel);
			
			tecla = fxtecla();
				switch(tecla){
					case FARR:
						if(sel > 0){
							gotoxy(x + 1, y + sel);
							printf(" ");
							sel--;
						}
						break;
					case FABA:
						if(sel < items-1){
							gotoxy(x + 1, y + sel);
							printf(" ");
							sel++;
						}
						break;
				}
		}while(tecla != ENTER);
		textcolor(WHITE);
	}
	return sel;
}
/*	FINALIZA FUNCION DE RADIOBOTONHORIZONTAL	*/


#endif	/*	DEFINICION DE CONTROLES.H	*/