#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\projects\ventas-cpp\pantallas.h"

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
        do {
          tecla[1] = fxtecla();
          system("CLS");
          historico_ventas_menu();
          switch(tecla[1])
          {

          }
        }while(tecla[1] != ESC);

      break;

      case F3:
      break;

      case F4:
        do {
          tecla[1] = fxtecla();
          system("CLS");
          inventario_ventas_menu();
          switch(tecla[1])
          {

          }
        }while(tecla[1] != ESC);
      break;

    }


  }while(tecla[0] != ESC);

  gotoxy(89,5);getch();
}

//void fxrectangulo(int x1, int y1, int x2, int y2)
