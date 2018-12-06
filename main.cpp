#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\projects\ventas-cpp\pantallas.h"
#include "C:\projects\ventas-cpp\includes\clientes.h"
#include "C:\projects\ventas-cpp\includes\productos.h"
#include "C:\projects\ventas-cpp\includes\ventas.h"

void Leer_Info_Inv(ptrProducto ABC);


void main()
{

  int tecla[3];
  do{

    system("CLS");
    main_menu();
    tecla[0] = fxtecla();

    switch(tecla[0])
    {
      case F1:
        do{
          system("CLS");
          ventas_menu_c();
          tecla[1] = fxtecla();
          switch(tecla[1])
          {
            case ENTER:
            do{
              system("CLS");
              ventas_menu_v();
              tecla[2] = fxtecla();
              switch(tecla[2])
              {
                case ENTER:
                break;
              }
            }while(tecla[2] != ESC);
            break;
          }

        }while(tecla[1] != ESC);

      break;

      case F2:
        system("CLS");
        historico_ventas_menu();
        do {
          tecla[1] = fxtecla();
          switch(tecla[1])
          {

          }

        }while(tecla[1] != ESC);

      break;

      case F3:
      break;

      /*case F4:
        int x = 3, y = 4;
        system("CLS");
        inventario_ventas_menu();
        gotoxy(x,y);
        ptrContacto Inic = P.InicioLista();
        do {
          tecla[1] = fxtecla();
          switch(tecla[1])
          {
            case FARR:
            if(I != NULL)
            {
              I = I->ptrAnterior != NULL ? I->ptrAnterior:I;
              if(I != P.InicioLista())
                y--;
              gotoxy(x,y);
              Leer_Info_Inv(I);
            }
            break;

            case FABA:
            if(I != NULL)
            {
              I = I->ptrSiguiente != NULL ? I->ptrSiguiente:I;
              if(I->ptrSiguiente != NULL)
                y++;
              gotoxy(x,y);
              Leer_Info_Inv(I);
            }
            break;
          }
        }while(tecla[1] != ESC);
      break;*/

    }


  }while(tecla[0] != ESC);

  gotoxy(89,5);getch();
}

/*void Leer_Info_Inv(ptrProducto Info)
{
  gotoxy(37,5);printf("%s"Info->modelo);
  gotoxy(37,7);printf("%s"Info->descripcion);
  gotoxy(37,9);printf("%d"Info->existencia);
  gotoxy(37,9);printf("%f"Info->precio_venta);
}*/

//void fxrectangulo(int x1, int y1, int x2, int y2)
