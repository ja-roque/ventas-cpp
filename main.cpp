#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\projects\ventas-cpp\includes\figuras.h"

void main_menu();
void ventas_menu_c();
void ventas_menu_v();

void main()
{
  //main_menu();
  ventas_menu_v();
  gotoxy(89,5);getch();
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

void ventas_menu_c()
{
  gotoxy(7,2);printf("CLIENTES");gotoxy(35,2);printf("MODULO DE VENTAS");gotoxy(33,4);printf("--------------------");
  gotoxy(59,2);printf("FACTURA:%13d",0);gotoxy(59,3);printf("CAI:%17d",0);gotoxy(64,4);printf("FECHA:DD/MM/YYYY");
  fxrectangulo(2,3,20,18);
  gotoxy(7,19);printf("PAG 1/%d");
  fxrectangulo(2,20,78,24);
  gotoxy(3,21);printf("OPCIONES: ");
  gotoxy(5,22);printf("^v - SUBIR/BAJAR PARA SELECCIONAR UN CLIENTE");
  gotoxy(5,23);printf("ENTER - SELECCIONAR CLIENTE");gotoxy(41,23);printf("ESC - VOLVER AL MENU PRINCIPAL");
}

void ventas_menu_v()
{
  gotoxy(6,2);printf("INVENTARIO");gotoxy(35,2);printf("MODULO DE VENTAS");gotoxy(33,4);printf("--------------------");gotoxy(59,2);printf("FACTURA:%13d",0);
  gotoxy(59,2);printf("FACTURA:%13d",0);gotoxy(59,3);printf("CAI:%17d",0);gotoxy(64,4);printf("FECHA:DD/MM/YYYY");
  gotoxy(23,5);printf("CLIENTE: %-26s","ABC");
  gotoxy(24,6);printf("CANT.");gotoxy(32,6);printf("DESCRIPCION");gotoxy(57,6);printf("PRECIO UNIT");gotoxy(69,6);printf("TOTAL");
  gotoxy(24,8);printf("%4.2f",1.00);gotoxy(32,8);printf("%-24s","PRD");gotoxy(57,8);printf("%7.2f",1234.00);gotoxy(69,8);printf("%7.2f",1234567.00);
  fxrectangulo(2,3,20,18);
  gotoxy(7,19);printf("PAG 1/%d");
  fxrectangulo(2,20,79,25);
  gotoxy(3,21);printf("OPCIONES: ");
  gotoxy(7,22);printf("F1  - ACEPTAR Y GUARDAR VENTA");gotoxy(42,22);printf("^v - AVANZAR/RETROCEDER EN LA LISTA");
  gotoxy(5,23);printf("ENTER - AGREGAR PRODUCTO");gotoxy(42,23);printf("<> - SIGUIENTE/PAGINA");
  gotoxy(5,24);printf("SUPR  - QUITAR PRODUCTO");gotoxy(41,24);printf("ESC - REGRESAR AL MENU ANTERIOR");
}