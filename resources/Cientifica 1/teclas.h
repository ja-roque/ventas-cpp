/*	Henry Japheth Alvarado Sandoval	*/


  /*
F:\ALGORITMOS Y DAGRAMACION\librerias\teclas.h
L:\ALGORITMOS Y DAGRAMACION\librerias\teclas.h
    */

 // libreria a utilizar, primero validamos que la libreria no este creada

 #if !defined(_TECLAS_H)
     #define _TECLAS_H


//incluimos <conio.h> verificamos que no este definifa


 #if !defined(_CONIO_H)
     #include <conio.h>
 #endif


 //Establecemos algunas definiciones de teclas
    // Valor de la fecha hacia arriba

 #define FARR 1072   // Valor de la fecha hacia arriba
 #define FABA 1080   // Valor de la fecha hacia arriba
 #define FDER 1077   // Valor de la fecha hacia arriba
 #define FIZQ 1075
 #define F1 1059
 #define F2 1060
 #define F3 1061
 #define F4 1062
 #define F10 1068
 #define N1 49
 #define N2 50
 #define N3 51
 #define N4 52
 
 
 // Otras teclas necesarias
 #define BARRA 32
 #define ENTER 13
 #define ESC 27
 #define EQUIS 88
 #define EQUISX 120
 #define RETRO 8
 
 #define BAND 232
 #define MINA 207
 #define MINA2 15
 #define RELL1 176
 #define RELL2 177
 #define RELL3 219
 #define RELL4 254
 #define CFARR 24
 #define CFABA 25

 //Abecedario Minuscula [97 - 122]
 #define LA 97
 #define LB 98
 #define LC 99
 #define LD 100
 #define LE 101
 #define LF 102
 #define LG 103
 #define LH 104
 #define LI 105
 #define LJ 106
 #define LK 107
 #define LL 108
 #define LM 109
 #define LN 110
 #define LO 111
 #define LP 112
 #define LQ 113
 #define LR 114
 #define LS 115
 #define LT 116
 #define LU 117
 #define LV 118
 #define LW 119
 #define LX 120
 #define LY 121
 #define LZ 122


// 01 48 49



/*int fxtecla()
{
 int t;
 t=getch();
 if(t == 0)
 	t = 1000 + getch();
   return t;
 }*/

 #endif