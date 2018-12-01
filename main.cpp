#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\projects\ventas-cpp\includes\figuras.h"

void main_menu();
void ventas_menu();

void main()
{
  //main_menu();
  ventas_menu();
  gotoxy(1,25);system("PAUSE");
}

//void fxrectangulo(int x1, int y1, int x2, int y2)

void main_menu()
{
    gotoxy(35,2);printf("MODULO DE VENTAS");
    gotoxy(33,3);printf("--------------------");

    gotoxy(1,6);printf("INSTRUCCIONES: \n\n");
    gotoxy(2,9);printf("F1-GENERAR VENTA: PANTALLA QUE DESPLIEGA EL FORMULARIO PARA REGISTRAR UNA\n            NUEVA VENTA\n\n");
    gotoxy(2,12);printf("F2-CONSULTAS Y MANTENIMIENTO DE VENTAS: PANTALLA PARA CONSULTAR Y MODIFICAR,\n            AUTORIZAR Y ANULAR VENTAS\n\n");
    gotoxy(2,15);printf("F3-PARAMETROS, CORRELATIVOS Y MAS: PANTALLA PARA MANTENIMIENTO DE LOS\n            PARAMETROS,CORRELATIVOS Y OTROS CONTROLES DE VENTAS\n\n");
    gotoxy(2,18);printf("F4-INVENTARIO Y CONSULTAS DE PRECIOS: PANTALLA PARA MANTENIMIENTO DE\n             INVENTARIO DE PRODUCTO TERMINADO Y PRECIOS DE VENTA.");

    fxrectangulo(1,20,78,24);

    gotoxy(2,21);printf("OPCIONES: ");
    gotoxy(2,22);printf("F1-GENERAR VENTA");gotoxy(43,22);printf("F3-PARAMETROS, CORRELATIVOS Y MAS..");
    gotoxy(2,23);printf("F2-CONSULTAS Y MANTENIMIENTO DE VENTAS");gotoxy(43,23);printf("F4-INVENTARIO Y CONSULTA DE PRECIOS");
}

void ventas_menu()
{
  gotoxy(7,2);printf("CLIENTES");gotoxy(30,2);printf("TITULO");gotoxy(59,2);printf("FACTURA:%13d",0);
  fxrectangulo(2,3,22,18);

}
