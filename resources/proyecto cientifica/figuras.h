// Definiciones de Caracteres para lineas simples
/*
Libreria para creacion y manejo de figuras
creada por Agustin Rivera
Junio 2016
ruta: "d:\cpp\includes\figuras.h"
*/
#define VER1 179	// 179 = │ 
#define UND1 180	// 180 = ┤ 
#define ESD1 191	// 191 = ┐ Linea Esquina Superio Derecha
#define EII1 192	// 192 = └ 
#define UNB1 193	// 193 = ┴ 
#define UNT1 194	// 194 = ┬
#define UNI1 195	// 195 = ├ 
#define HOR1 196	// 196 = ─ 
#define CRUZ1 197	// 197 = ┼ 
#define EID1 217	// 217 = ┘ 
#define ESI1 218	// 218 = ┌ 

// Definiciones de Caracteres para lineas dobles
#define LINEA	// 185 = ╣
#define LINEA	// 186 = ║
#define LINEA	// 187 = ╗
#define LINEA	// 188 = ╝ 
#define LINEA	// 200 = ╚ 
#define LINEA	// 201 = ╔ 
#define LINEA	// 202 = ╩ 
#define LINEA	// 203 = ╦ 
#define LINEA	// 204 = ╠
#define LINEA	// 205 = ═ 
#define LINEA	// 206 = ╬ 

// Definiciones de Caracteres para rellenos
#define RELL1 176	// 176 = ░	caracter de relleno # 1
#define RELL2 177	// 177 = ▒  caracter de relleno # 2
#define RELL3 178	// 178 = ▓  caracter de relleno # 3
#define LINEA	// 219 = █ 
#define LINEA	// 220 = ▄ 
#define LINEA	// 223 = ▀ 

// Funcion para imprimir una linea horizontal
void fxlineah(int fil, int x1, int x2, int color)
{
	int x;
	if(fil<1 || fil >25)
		fil = 1;
	if(x1 < 1 || x1 >80)
		x1 = 1;
	if(x2 < 1 || x2 >80)
		x2 = x1+1;
	textcolor(color);
	for(x=x1; x<=x2; x++){
		gotoxy(x,fil);
		cprintf("%c", HOR1);
	}
}

// Funcion para imprimir una linea Verticales
void fxlineav(int col, int y1, int y2, int color)
{
	int y;
	if(col<1 || col >80)
		col = 1;
	if(y1 < 1 || y1 >25)
		y1 = 1;
	if(y2 < 1 || y2 >25)
		y2 = y1+1;
	textcolor(color);
	for(y=y1; y<=y2; y++){
		gotoxy(col,y);
		cprintf("%c", VER1);
	}
}

void fxrectangulo(int x1, int y1, int x2, int y2, int color)
{
	fxlineah(y1, x1, x2, color);
	fxlineah(y2, x1, x2, color);
	fxlineav(x1, y1, y2, color);
	fxlineav(x2, y1, y2, color);
	textcolor(color);
	gotoxy(x1,y1);	cprintf("%c", ESI1);
	gotoxy(x2,y1);	cprintf("%c", ESD1);
	gotoxy(x1,y2);	cprintf("%c", EII1);
	gotoxy(x2,y2);	cprintf("%c", EID1);
}

// Funcion para imprimir una linea horizontal Tabla
void fxlineaht(int fil, int x1, int x2, int color)
{
	int x;
	if(fil<1 || fil >25)
		fil = 1;
	if(x1 < 1 || x1 >80)
		x1 = 1;
	if(x2 < 1 || x2 >80)
		x2 = x1+1;
	textcolor(color);
	for(x=x1; x<=x2; x++){
		gotoxy(x,fil);
		cprintf("%c", HOR1);
	}
	gotoxy(x1, fil);	cprintf("%c", UNI1);
	gotoxy(x2, fil);	cprintf("%c", UND1);
}

// Funcion para imprimir una linea Verticales
void fxlineavt(int col, int y1, int y2, int color)
{
	int y;
	if(col<1 || col >80)
		col = 1;
	if(y1 < 1 || y1 >25)
		y1 = 1;
	if(y2 < 1 || y2 >25)
		y2 = y1+1;
	textcolor(color);
	for(y=y1; y<=y2; y++){
		gotoxy(col,y);
		cprintf("%c", VER1);
	}
	gotoxy(col, y1);	cprintf("%c", UNT1);
	gotoxy(col, y2);	cprintf("%c", UNB1);
}

//CRUZ
void fxcruz(int x, int y, int color)
{
	textcolor(color);
	gotoxy(x,y);
	cprintf("%c", CRUZ1);
}

