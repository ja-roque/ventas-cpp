#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\projects\ventas-cpp\pantallas.h"
#include "C:\projects\ventas-cpp\includes\clientes.h"
#include "C:\projects\ventas-cpp\includes\productos.h"
#include "C:\projects\ventas-cpp\includes\ventas.h"

void Leer_Info_Inv(ptrProducto ABC);

class clientes C("Ruta");
class productos P("Ruta");

void Create_Info()
{
  C.Insertar("Aby P.");
  C.Insertar("Elias M.");
  C.Insertar("Javier R.");
  C.Insertar("Maria G.");

  P.Insertar("PC - 1",25.00,230);
  P.Insertar("PC - 2",15.00,500);
  P.Insertar("PC - 3",45.00,750);
  P.Insertar("PC - 4",55.00,350);

  //C.Imprimir(1,1,250);
  //system("pause");
}


void main()
{
  Create_Info();
  int tecla[3];
  int x = 0, y = 0,x2 = 0, y2 = 0;
  int moves = 0, max_moves = 0,moves2 = 0, max_moves2 = 0;
  int page = 0, page2 = 0;
  ptrProducto VerP = NULL;ptrCliente VerC = NULL;ptrVentas VerV = NULL;
  do{

    system("CLS");
    main_menu();
    tecla[0] = fxtecla();

    switch(tecla[0])
    {
      case F1:
        system("CLS");
        x = 3; y = 4;
        page = 1;
        C.Imprimir(x,y,page);
        VerC = C.InicioLista();
        gotoxy(x,y);textbackground(BLUE);cprintf("%s",VerC->nombre);
        moves = 1;
        max_moves = 14;
        do{
          ventas_menu_c();
          tecla[1] = fxtecla();
          switch(tecla[1])
          {
            case ENTER:
            system("CLS");
            moves2 = 1;
            max_moves2 = 14;
            x2=3;y2=4;
            page2 = 1;
            ventas_menu_v();
            P.Imprimir(x2,y2,page2);
            VerP = P.InicioLista();
            if(VerP != NULL)
            {
              gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
            }
            gotoxy(32,5);printf("%s",VerC->nombre);
            do{
              tecla[2] = fxtecla();
              switch(tecla[2])
              {
                case ENTER:
                break;

                case FARR:
                if(VerP != NULL)
                {
                  if(moves2 != 1)
                  {
                    if(VerP->ptrAnterior != NULL)
                    {
                      gotoxy(x2,y2);textbackground(BLACK);cprintf("%s",VerP->nombre);
                      VerP = VerP->ptrAnterior;
                      y2--;moves2--;
                      gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
                    }
                  }
                }
                break;

                case FABA:
                if(VerP->ptrSiguiente != NULL)
                {
                  if(moves2 != 14)
                  {
                    gotoxy(x2,y2);textbackground(BLACK);cprintf("%s",VerP->nombre);
                    VerP = VerP->ptrSiguiente;
                    y2++;moves2++;
                    gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
                  }
                }
                break;

              }
            }while(tecla[2] != ESC);
            system("CLS");
            ventas_menu_c();
            C.Imprimir(3,4,page);
            gotoxy(x,y);textbackground(BLUE);cprintf("%s",VerC->nombre);
            break;

            case FARR:
            if(VerC != NULL)
            {
              if(moves != 1)
              {
                if(VerC->ptrAnterior != NULL)
                {
                  gotoxy(x,y);textbackground(BLACK);cprintf("%s",VerC->nombre);
                  VerC = VerC->ptrAnterior;
                  y--;moves--;
                  gotoxy(x,y);textbackground(BLUE);cprintf("%s",VerC->nombre);
                }
              }
            }
            break;

            case FABA:
            if(VerC->ptrSiguiente != NULL)
            {
              if(moves != 14)
              {
                gotoxy(x,y);textbackground(BLACK);cprintf("%s",VerC->nombre);
                VerC = VerC->ptrSiguiente;
                y++;moves++;
                gotoxy(x,y);textbackground(BLUE);cprintf("%s",VerC->nombre);
              }
            }
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

      case F4:
        system("CLS");
        inventario_ventas_menu();
        moves2 = 1;
        max_moves2 = 14;
        x2=3;y2=4;
        page2 = 1;
        P.Imprimir(x2,y2,page2);
        VerP = P.InicioLista();
        if(VerP != NULL)
        {
          gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
          gotoxy(37,6);printf("%s",VerP->nombre);
          gotoxy(37,8);printf("%s","N/A");
          gotoxy(37,10);printf("%d",VerP->existencia);
          gotoxy(37,12);printf("%.2f",VerP->precio);
        }
        do {
          tecla[1] = fxtecla();
          switch(tecla[1])
          {
            case FARR:
            if(VerP != NULL)
            {
              if(moves2 != 1)
              {
                if(VerP->ptrAnterior != NULL)
                {
                  gotoxy(x2,y2);textbackground(BLACK);cprintf("%s",VerP->nombre);
                  VerP = VerP->ptrAnterior;
                  y2--;moves2--;
                  gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
                  gotoxy(37,6);printf("%s",VerP->nombre);
                  gotoxy(37,8);printf("%s","N/A");
                  gotoxy(37,10);printf("%d",VerP->existencia);
                  gotoxy(37,12);printf("%.2f",VerP->precio);
                }
              }
            }
            break;

            case FABA:
            if(VerP->ptrSiguiente != NULL)
            {
              if(moves2 != 14)
              {
                gotoxy(x2,y2);textbackground(BLACK);cprintf("%s",VerP->nombre);
                VerP = VerP->ptrSiguiente;
                y2++;moves2++;
                gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
                gotoxy(37,6);printf("%s",VerP->nombre);
                gotoxy(37,8);printf("%s","N/A");
                gotoxy(37,10);printf("%d",VerP->existencia);
                gotoxy(37,12);printf("%.2f",VerP->precio);
              }
            }
            break;
          }
        }while(tecla[1] != ESC);
      break;

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
