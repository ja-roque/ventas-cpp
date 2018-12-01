#if !defined(__FIGURAS_H)
#define __FIGURAS_H


#if !defined(__CONIO_H)
#include <conio.h>
#endif


void fxrectangulo(int x1, int y1, int x2, int y2);
void fxcprintf(int x, int y, int color, char *texto);
void fxLimpiaArea(int x1, int y1, int x2, int y2);

void fxLimpiaArea(int x1, int y1, int x2, int y2)
{
  int f, c;
  for(f=y1;f<=y2;f++)
  {
    for(c=x1;c<=x2;c++)
    {
      gotoxy(c,f);printf(" ");
    }
  }
}


void fxrectangulo(int x1, int y1, int x2, int y2)
{
	int i = 0;

	for(i=x1;i<=x2;i++)
	{
		gotoxy(i,y1);printf("%c",196);
		gotoxy(i,y2);printf("%c",196);
	}

  for(i=y1;i<=y2;i++)
  {
  gotoxy(x1,i);printf("%c",179);
  gotoxy(x2,i);printf("%c",179);
  }



	gotoxy(x1,y1);printf("%c",218); //Esquina Superior Izquierda
  gotoxy(x1,y2);printf("%c",192); //Esquina Inferior Izquierda
	gotoxy(x2,y1);printf("%c",191);	//Esquina Superior Derecha
	gotoxy(x2,y2);printf("%c",217);	//Esquina Inferior Derecha

}

void fxcprintf(int x, int y, int color, char *texto)
{
	textcolor(color);
	gotoxy(x,y);
	cprintf("%s",texto);
}



#endif
