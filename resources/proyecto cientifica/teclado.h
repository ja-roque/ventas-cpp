/*************************************************************************
Libreria para manejo del teclado >:v
*************************************************************************/

//libreria a utilizar, primero validamos que la libreria no este creada
#if !defined(_TECLADO_H)
     #define _TECLADO_H

//incluimos <conio.h> verificamos que no este definida
#if !defined(_CONIO_H)
     #include <conio.h>
#endif


//Establecemos algunas definiciones de teclas

//teclas de flechas
#define FARR 1072   // Valor de la fecha hacia arriba
#define FABA 1080   // Valor de la fecha hacia abajo
#define FDER 1077   // Valor de la fecha hacia derecha
#define FIZQ 1075   // Valor de la fecha hacia izquierda
//teclas de función
#define F1 1059
#define F2 1060
#define F3 1061
#define F4 1062
#define F5 1063
#define F6 1064
#define F7 1065
#define F8 1066
#define F9 1067
#define F10 1068
#define F11 1133
#define F12 1134
//teclas combinadas de ctrl y función
#define CTF1 1094
#define CTF2 1095
#define CTF3 1096
#define CTF4 1097
#define CTF5 1098
#define CTF6 1099
#define CTF7 1100
#define CTF8 1101
#define CTF9 1102
#define CTF10 1103
#define CTF11 1137
#define CTF12 1138
//teclas de letras
#define WMAYUS 87
#define WMINUS 119

#define AMAYUS 65
#define AMINUS 97

#define SMAYUS 83
#define SMINUS 115

#define DMAYUS 68
#define DMINUS 100

#define PMAYUS 802
#define PMINUS 112
//otras teclas
#define ENTER 13
#define BARRA 32
#define ESC 27
#define TAB 9
#define RETRO 8

//funcion para la captura del valor de la fecha
int fxtecla()
{
 int t;
 t=getch();
 if(t ==0)
 	t = 1000 + getch();
   return t;
 }
 
#endif //teclado