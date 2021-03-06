#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\projects\ventas-cpp\pantallas.h"
#include "C:\projects\ventas-cpp\includes\clientes.h"
#include "C:\projects\ventas-cpp\includes\productos.h"
#include "C:\projects\ventas-cpp\includes\ventas.h"

void Calculos();

class clientes C("Ruta");
class productos P("Ruta");
class clsVentas V("Ruta");
//class clsVentas V("C:\\projects\\ventas-cpp\\files\\ventas.datax");

float impto = 0.15, regalia = 3000.00 , regalia_parameter = 10000.00;
char CAI[17];
float s_t = 0;
float impto_temp = 0;
float regalia_temp = 0;
float total_pago = 0;

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
  rand_string(CAI,17);
  int x_p = 0, y_p = 0;
  int select = 0;
  //V.Cargar_Datos();
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
          gotoxy(59,2);printf("FACTURA:%13d",V.factura());gotoxy(59,3);printf("CAI:%17s",CAI);
          //Do que agrega clientes
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
            gotoxy(59,2);printf("FACTURA:%13d",V.factura());gotoxy(59,3);printf("CAI:%17s",CAI);
            if(VerP != NULL)
            {
              gotoxy(x2,y2);textbackground(BLUE);cprintf("%s",VerP->nombre);
            }
            gotoxy(32,5);printf("%s",VerC->nombre);
            x_p = 24;y_p = 8;
            do{
              //Do que agrega Productos
              tecla[2] = fxtecla();
              switch(tecla[2])
              {
                case ENTER:
                  if(VerP != NULL)
                  {
                    float cantidad_temp = 0;
                    char aux[100];
                    gotoxy(x_p,y_p);scanf("%f",&cantidad_temp);
                    gotoxy(x_p,y_p);printf("%50s"," ");
                    if(cantidad_temp <= VerP->existencia && cantidad_temp > 0)
                    {
                      bool aver = V.Verificar(VerP->nombre,cantidad_temp);
                      if(aver == false)
                      {
                        V.Insertar_Detalle(VerP->nombre,VerP->precio,cantidad_temp,(cantidad_temp * VerP->precio));
                        y_p++;
                      }
                      VerP->existencia -= cantidad_temp;
                      V.Detalle_VP();
                      Calculos();
                      gotoxy(x2,y2);
                    }
                    else
                    {
                      if(cantidad_temp > VerP->existencia)
                      {
                        gotoxy(x_p,y_p);printf("Inventario Insuficiente. Existencias Disponibles %.2f",VerP->existencia);
                        getch();
                        gotoxy(x_p,y_p);printf("%80s"," ");gotoxy(x2,y2);
                      }
                    }
                  }
                break;

                case SUPR:
                if(VerP != NULL)
                {
                  V.Eliminar(VerP->nombre);
                  fxLimpiaArea(22,8,80,14);
                  V.Detalle_VP();
                  Calculos();
                  y_p--;
                  gotoxy(x2,y2);
                }
                break;

                case ESC:
                V.ReiniciarVenta();
                break;

                case F1:
                gotoxy(23,18);
                select = 0;
                do {
                    tecla[3] = fxtecla();
                    switch(tecla[3])
                    {
                      case FDER:
                      if(select == 0)
                      {
                        gotoxy(25,18);printf(" ");
                        gotoxy(37,18);printf("%c",254);
                        select = 1;
                      }
                      break;

                      case FIZQ:
                      if(select == 1)
                      {
                        gotoxy(25,18);printf("%c",254);
                        gotoxy(37,18);printf(" ");
                        select = 0;
                      }
                      break;

                      case ENTER:
                        V.Insertar(VerC->nombre,total_pago, impto_temp, regalia_temp,select,CAI);
                        tecla[2] = ESC;
                        rand_string(CAI,17);
                      break;

                      case ESC:
                        V.ReiniciarVenta();
                        tecla[3] = ENTER;
                      break;
                    }
                } while(tecla[3] != ENTER);
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
            //Do que agrega Productos
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
        //Do que agrega clientes
        }while(tecla[1] != ESC);

      break;

      case F2:
        system("CLS");
        page = 1;
        x = 3;
        y = 4;
        moves2 = 1;
        max_moves2 = 14;
        historico_ventas_menu();
        VerV = V.InicioLista();
        V.Imprimir(x,y,page);
        if(VerV != NULL)
        {
          fxLimpiaArea(24,8,80,14);
          gotoxy(x,y);textbackground(BLUE);cprintf("%d",VerV->codigo);
          V.Imprimir_Detalle(VerV);
        }
        do {
          tecla[1] = fxtecla();
          switch(tecla[1])
          {
            case FARR:
            if(VerV != NULL)
            {
              if(moves != 1)
              {
                if(VerV->ptrAnterior != NULL)
                {
                  fxLimpiaArea(22,8,80,14);
                  gotoxy(x,y);textbackground(BLACK);cprintf("%d",VerV->codigo);
                  VerV = VerV->ptrAnterior;
                  V.Imprimir_Detalle(VerV);
                  y--;moves--;
                  gotoxy(x,y);textbackground(BLUE);cprintf("%d",VerV->codigo);
                }
              }
            }
            break;

            case FABA:
            if(VerV->ptrSiguiente != NULL)
            {
              if(moves != 14)
              {
                fxLimpiaArea(22,8,80,14);
                gotoxy(x,y);textbackground(BLACK);cprintf("%d",VerV->codigo);
                VerV = VerV->ptrSiguiente;
                V.Imprimir_Detalle(VerV);
                y++;moves++;
                gotoxy(x,y);textbackground(BLUE);cprintf("%d",VerV->codigo);
              }
            }
            break;

            case F1:
            if(VerV != NULL)
            {
              if(VerV->estado == true)
              {
                VerV->estado = false;
              }
              else
              {
                if(VerV->estado == false)
                {
                  VerV->estado = true;
                }
              }
              V.Imprimir_Detalle(VerV);
            }
            break;
          }

        }while(tecla[1] != ESC);

      break;

      case F3:
      system("CLS");
      select = 0;
      x = 40;y = 7;
      correlativos_ventas_menu();
      gotoxy(33,7);printf("%s",CAI);
      gotoxy(20,10);printf("Ventas Mayores a %.2f con una regalia de %.2f",regalia_parameter,regalia);
      gotoxy(40,13);printf("%.2f%c",impto*100,37);
      gotoxy(x,y);
      do{
        tecla[1] = fxtecla();
        switch(tecla[1])
        {
          case FARR:
          if(select != 0)
          {
            select--;
            y-=3;
            gotoxy(x,y);
          }
          break;

          case FABA:
          if(select != 2)
          {
            select++;
            y+=3;
            gotoxy(x,y);
          }
          break;

          case F1:
          switch(select)
          {
            case 0:
            rand_string(CAI,17);
            gotoxy(33,7);printf("%s",CAI);
            gotoxy(x,y);
            break;

            case 1:
            gotoxy(20,10);printf("%60s"," ");
            gotoxy(20,10);printf("Parametro: ");scanf("%f",&regalia_parameter);
            gotoxy(40,10);printf("Regalia: ");scanf("%f",&regalia);
            gotoxy(20,10);printf("Ventas Mayores a %.2f con una regalia de %.2f",regalia_parameter,regalia);
            gotoxy(x,y);
            break;

            case 2:
            gotoxy(40,13);printf("%60s"," ");
            gotoxy(40,13);scanf("%f",&impto);
            impto = impto/100;
            gotoxy(40,13);printf("%.2f%c",impto*100,37);
            gotoxy(x,y);
            break;
          }
          break;
        }

      }while(tecla[1] != ESC);
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

            case F1:
            if(VerP != NULL)
            {
              float precio_temp;
              gotoxy(37,12);printf("%30s"," ");
              gotoxy(37,12);scanf("%f",&precio_temp);
              VerP->precio = precio_temp;
              gotoxy(37,6);printf("%s",VerP->nombre);
              gotoxy(37,8);printf("%s","N/A");
              gotoxy(37,10);printf("%d",VerP->existencia);
              gotoxy(37,12);printf("%.2f",VerP->precio);
            }
            break;
          }
        }while(tecla[1] != ESC);
      break;

      case F5:
      V.Guardar_En_El_Archivo();
      gotoxy(25,5);printf("Guardado!");
      getch();
      break;

    }

  }while(tecla[0] != ESC);

  gotoxy(89,5);getch();
}

void Calculos()
{
  char aux[100];
  s_t = V.Subtotal();
  impto_temp = s_t * impto;
  regalia_temp = (s_t+impto_temp) >= regalia_parameter ? regalia:0;
  total_pago = (s_t+impto_temp-regalia_temp);
  sprintf(aux, "%.2f", s_t);
  gotoxy(69,15);printf("%11s",aux);
  sprintf(aux, "%.2f", impto_temp);
  gotoxy(69,16);printf("%11s",aux);
  sprintf(aux, "%.2f", regalia_temp);
  gotoxy(69,17);printf("%11s",aux);
  sprintf(aux, "%.2f", total_pago);
  gotoxy(69,18);printf("%11s",aux);
}
