#if !defined(__PRODUCTOS_H)
     #define __PRODUCTOS_H

     #if !defined(__CONIO_H)
          #include <conio.h>
     #endif

     #if !defined(__TIME_H)
          #include <time.h>
     #endif

     #if !defined(__FIGURAS_H)
          #include "C:\projects\ventas-cpp\includes\figuras.h"
     #endif

     #if !defined(__TECLADO_H)
          #include "C:\projects\ventas-cpp\includes\teclado.h"
     #endif


     void main_menu();
     void ventas_menu_c();
     void ventas_menu_v();
     void historico_ventas_menu();
     void inventario_ventas_menu();
     void correlativos_ventas_menu();
     static char *rand_string(char *str, size_t size);

     time_t t = time(NULL);
     struct tm tm = *localtime(&t);


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
       gotoxy(59,2);printf("FACTURA:%13d",0);gotoxy(59,3);printf("CAI:%17d",0);gotoxy(64,4);printf("FECHA:%d/%d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900);
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
       gotoxy(59,2);printf("FACTURA:%13d",0);gotoxy(59,3);printf("CAI:%17d",0);gotoxy(64,4);printf("FECHA:%d/%d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900);
       gotoxy(23,5);printf("CLIENTE: ");
       gotoxy(24,7);printf("CANT.");gotoxy(32,7);printf("DESCRIPCION");gotoxy(57,7);printf("PRECIO UNIT");gotoxy(73,7);printf("TOTAL");
       //gotoxy(24,8);printf("%4.2f",1.00);gotoxy(32,8);printf("%-24s","PRD");gotoxy(57,8);printf("%7.2f",1234567.00);gotoxy(69,8);printf("%7.2f",1234567.00);
       //gotoxy(60,15);printf("SUBTOTAL:%7.2f",1234567.00);gotoxy(62,16);printf("IMPTO:%7.2f",1234567.00);gotoxy(61,16);printf("REGALIA:%7.2f",1234567.00);gotoxy(55,17);printf("TOTAL A PAGAR:%7.2f",1234567.00);
       gotoxy(60,15);printf("SUBTOTAL:");gotoxy(62,16);printf("IMPTO:");gotoxy(61,17);printf("REGALIA:");gotoxy(55,18);printf("TOTAL A PAGAR:");
       gotoxy(24,17);printf("FORMA DE PAGO:");
       gotoxy(24,18);printf("[%c] CREDITO [ ] CONTADO",254);
       fxrectangulo(2,3,20,18);
       gotoxy(7,19);printf("PAG 1/%d");
       gotoxy(40,16);printf("PAG 1/%d");
       fxrectangulo(2,20,79,25);
       gotoxy(3,21);printf("OPCIONES: ");
       gotoxy(7,22);printf("F1  - ACEPTAR Y GUARDAR VENTA");gotoxy(42,22);printf("^v - AVANZAR/RETROCEDER EN LA LISTA");
       gotoxy(5,23);printf("ENTER - AGREGAR PRODUCTO");gotoxy(42,23);printf("<> - SIGUIENTE/PAGINA");
       gotoxy(5,24);printf("SUPR  - QUITAR PRODUCTO");gotoxy(41,24);printf("ESC - REGRESAR AL MENU ANTERIOR");
     }

     void historico_ventas_menu()
     {
         gotoxy(2,2);printf("HISTORICO DE VENTAS");gotoxy(35,2);printf("MODULO DE VENTAS");gotoxy(33,4);printf("--------------------");gotoxy(59,2);printf("FACTURA:%13d",0);
         gotoxy(59,2);printf("FACTURA:%13d",0);gotoxy(59,3);printf("CAI:%17d",0);gotoxy(64,4);printf("FECHA:%d/%d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900);
         gotoxy(23,5);printf("CLIENTE:");
         gotoxy(24,7);printf("CANT.");gotoxy(32,7);printf("DESCRIPCION");gotoxy(57,7);printf("PRECIO UNIT");gotoxy(73,7);printf("TOTAL");
         //gotoxy(24,8);printf("%4.2f",1.00);gotoxy(32,8);printf("%-24s","PRD");gotoxy(57,8);printf("%7.2f",1234567.00);gotoxy(69,8);printf("%7.2f",1234567.00);
         //gotoxy(60,15);printf("SUBTOTAL:%7.2f",1234567.00);gotoxy(62,16);printf("IMPTO:%7.2f",1234567.00);gotoxy(61,16);printf("REGALIA:%7.2f",1234567.00);gotoxy(55,17);printf("TOTAL A PAGAR:%7.2f",1234567.00);
         gotoxy(60,15);printf("SUBTOTAL:");gotoxy(62,16);printf("IMPTO:");gotoxy(61,17);printf("REGALIA:");gotoxy(55,18);printf("TOTAL A PAGAR:");
         gotoxy(24,17);printf("FORMA DE PAGO:");
         gotoxy(24,18);printf("[%c] CREDITO [ ] CONTADO",254);
         gotoxy(24,19);printf("ESTADO: AUTORIZADA [ ] ANULADA[ ]");
         fxrectangulo(2,3,20,18);
         gotoxy(7,19);printf("PAG 1/%d");
         gotoxy(40,16);printf("PAG 1/%d");
         fxrectangulo(2,20,79,23);
         gotoxy(3,21);printf("OPCIONES: ");
         gotoxy(7,22);printf("F1  - AUTORIZAR/ANULAR DE VENTAS");gotoxy(42,22);printf("ESC - VOLVER AL MENU PRINCIPAL");
     }

     void inventario_ventas_menu()
     {
         gotoxy(6,2);printf("INVENTARIO");gotoxy(35,2);printf("MODULO DE VENTAS");gotoxy(33,4);printf("--------------------");
         fxrectangulo(2,3,20,18);
         gotoxy(29,6);printf("Modelo: ");
         gotoxy(24,8);printf("Descripcion: ");
         gotoxy(25,10);printf("Existencia: ");
         gotoxy(23,12);printf("Precio Venta: ");

         gotoxy(7,19);printf("PAG 1/%d");
         fxrectangulo(2,20,79,23);
         gotoxy(3,21);printf("OPCIONES: ");
         gotoxy(7,22);printf("F1  - MODIFICAR PRECIO DE VENTA");gotoxy(42,22);printf("ESC - VOLVER AL MENU PRINCIPAL");
     }

     void correlativos_ventas_menu()
     {
         gotoxy(35,2);printf("MODULO DE VENTAS");gotoxy(33,3);printf("--------------------");
         gotoxy(37,6);printf("---CAI---");
         gotoxy(32,9);printf("---VOL. REGALIA---");
         gotoxy(30,12);printf("---IMPUESTO S/VENTA---");

         fxrectangulo(2,20,79,23);
         gotoxy(3,21);printf("OPCIONES: ");
         gotoxy(7,22);printf("F1  - MODIFICAR SELECCIONADO");gotoxy(42,22);printf("ESC - VOLVER AL MENU PRINCIPAL");
     }

     static char *rand_string(char *str, size_t size)
     {
        const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        if (size)
        {
            --size;
            for (size_t n = 0; n < size; n++) {
                int key = rand() % (int) (sizeof charset - 1);
                str[n] = charset[key];
            }
            str[size] = '\0';
        }
        return str;
      }


#endif
