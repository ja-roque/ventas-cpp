/* ---------------------------------------------------------------------
* Libreria para la clase numberbox
* Creada por: Agustin Rivera
* Fecha creación: 22 de Mayo de 2017
* Fecha Ultima Modificacion: 22/05/2017
* Ruta Archivo: D:\cientifica1\includes\numberbox.h
* ---------------------------------------------------------------------- */

#ifndef __NUMBERBOX_H		// Verificamos si no esta definida la libreria numberbox
	#define __NUMBERBOX_H  // Sino es asi se define

// Incluimos otras librerias a utilizar
#if !defined(__CONIO_H)
	#include <conio.h>         // Validamos la inclusion de conio.h
#endif

// Incluimos otras librerias a utilizar
#if !defined(__TECLADO_H)
	#include "D:\cientifica1\includes\teclado.h"         // Validamos la inclusion de conio.h
#endif

// Contenido de la libreria
class numberbox{
public:
       numberbox(int ancho1);							 	// funcion contructor
       void mostrar(int x1, int y1);	  				// Muestra el objeto
       void ocultar();	  									// Ocultar el objeto
       void valor(double valor1);							// Retorna el valor
       double valor();										// Retorna el valor
       void setbgcolor(int color);							// Cambia color de fondo
       void settxtcolor(int color);							// Cambia color de texto
       void focus();											// envia el enfoque al objeto
private:
	int x;					// Coordenda X
	int y;					// Coordenda Y
	int ancho;        	// Ancho del texto permitido
	int bgcolor;      	// color de fondo establecido
	int txtcolor;     	// color para el texto
	int bgcolor0;			// color de fondo establecido por defecto
	int txtcolor0;     	// color para el texto por defecto
	double contenido;  // El texto o contendo de la cajita
};

//  funcion del contructor de la clase numberbox
numberbox::numberbox(int ancho1)
{
	x = 1;
   y = 1;
   if(ancho1 > 78)
   	ancho = 78;
   else{
   	if(ancho1 < 1)
      	ancho = 1;
      else
		   ancho = ancho1;
   }
   bgcolor = YELLOW;
   txtcolor = BLUE;
   bgcolor0 = BLACK;
   txtcolor0 = LIGHTGRAY;
   contenido = 0; 
}

// Funcion para mostrar la caja de texto en la pantalla
void numberbox::mostrar(int x1, int y1)
{
	int xmax = 80 - ancho - 1;
   int i;

   if(x1 >= 1 && x1 <= xmax)
   	x = x1;
   else{
   	if(x1 < 1) x = 1;
      if(x1 > xmax) x= xmax;
   }
   if(y1 >= 1 && y1 <= 25)
   	y = y1;
   else{
   	if(y1 < 1) y = 1;
      if(y1 > 25) y= 25;
   }
   textbackground(bgcolor0);
   textcolor(txtcolor0);
   gotoxy(x,y);	cprintf("[");
   textbackground(bgcolor);
   textcolor(txtcolor);
   for(i=0; i<ancho; i++){
   	cprintf(" ");
   }
   textbackground(bgcolor0);
   textcolor(txtcolor0);
   cprintf("]");
   textbackground(bgcolor);
   textcolor(txtcolor);
   gotoxy(x+1,y);	cprintf("%f", contenido);
   textbackground(bgcolor0);
   textcolor(txtcolor0);
   gotoxy(x+ancho+2,y);

}  // fin de mostrar


void numberbox::ocultar()
{
	int i;
   gotoxy(x,y);
   textbackground(bgcolor0);
   textcolor(txtcolor0);
   for(i=0; i<ancho+2; i++){
      cprintf(" ");
   }
}

double numberbox::valor()
{
	return contenido;
}

void numberbox::valor(double valor1)
{
	contenido = valor1;
}

void numberbox::setbgcolor(int color)
{
    bgcolor = color;
}

void numberbox::settxtcolor(int color)
{
	txtcolor = color;
}

void numberbox::focus()
{
   int p = 0;					//Posicion
   int tecla;
   textbackground(bgcolor);
   textcolor(txtcolor);
   do{
      gotoxy(x+1+p,y);
		tecla = fxtecla();
      if(((tecla >= 48 && tecla <= 57) || tecla == PUNTO) && p < ancho){		//48 = 0 hasta 57=9
      	gotoxy(x+1+p,y);
         cprintf("%c", tecla);
         contenido[p] = tecla;
         p++;
      }
      else
      	if(tecla == RETRO && p > 0){
            p--;
			   gotoxy(x+1+p,y);
            cprintf(" ");
            contenido[p] = ' ';
	      }
   }while(tecla != TAB );
   contenido[p] = '\0';
}

#endif  // Fin del IF donde se valida la definicion de __numberbox_H
