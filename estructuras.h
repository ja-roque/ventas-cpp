#if !defined(__ESTRUCTURAS_H)
     #define __ESTRUCTURAS_H

     #if !defined(__CONIO_H)
          #include <conio.h>
     #endif

     #if !defined(__FIGURAS_H)
          #include "C:\projects\ventas-cpp\includes\figuras.h"
     #endif

     #if !defined(__TECLADO_H)
          #include "C:\projects\ventas-cpp\includes\teclado.h"
     #endif
	
	struct producto
	{
		int id;
		char nombre[30];
		float precio_unitario;
	};

	typedef struct producto strproducto;
	typedef strproducto *ptrproducto;

	struct producto_en_venta
	{
		struct producto productoVenta;
		int cantidad;
	};

	typedef struct producto_en_venta strproducto_en_venta;
	typedef strproducto_en_venta *ptrproducto_en_venta;

	struct ventas
	{
	    int id;
	    char cliente[30];
	    int forma_de_pago;
	  	int fecha;
	  	strproducto_en_venta lista_productos[100];
	  	char cai[30];
	    float regalia;
	    float subtotal;	
	    float total;
	};


	typedef struct ventas strVentas;
	typedef strVentas *ptrVentas;

	

	// Declaracion de productos por motivos de desarrollo
	strproducto prd1;
	prd1.id = 001;
	strcpy("Jabon Dove",prd1.nombre);
	prd1.precio_unitario = 20.99

	strproducto prd2;
	prd2.id = 002;
	strcpy("Pasta dental Colgate",prd2.nombre);
	prd2.precio_unitario = 10.99

	strproducto prd3;
	prd3.id = 003;
	strcpy("Shampoo Head and Shoulders",prd3.nombre);
	prd3.precio_unitario = 50.99

	// Declaracion de productos en venta por motivos de desarrollo 
	strproducto_en_venta prd_ven1;
	prd_ven1.productoVenta = prd1;
	prd_ven1.cantidad = 3;

	strproducto_en_venta prd_ven2;
	prd_ven2.productoVenta = prd2;
	prd_ven2.cantidad = 2;

	strproducto_en_venta prd_ven3;
	prd_ven3.productoVenta = prd3;
	prd_ven3.cantidad = 5;

	strproducto_en_venta prd_ven4;
	prd_ven4.productoVenta = prd3;
	prd_ven4.cantidad = 2;

	// Declaracion de Ventas por motivos de desarrollo
	strVentas venta1;
	venta1.id = 000001
	strcpy("Juan Alfonso Caicedo Chamuco", venta1.cliente)
	venta1.forma_de_pago = 1
	venta1.fecha = 14032018;
	venta1.lista_productos[0] = prd_ven1;
	venta1.lista_productos[1] = prd_ven2;
	strcpy("0001-3233434fbb", venta1.cai);
	venta1.regalia = 00;
	venta1.subtotal = 00;

	strVentas venta2;
	venta2.id = 000002
	strcpy("Ronaldihno Gaucho Aveiro Dosantos", venta2.cliente)
	venta2.forma_de_pago = 1
	venta2.fecha = 14012018;
	venta2.lista_productos[0] = prd_ven1;
	venta2.lista_productos[1] = prd_ven4;
	strcpy("0001-3233434fba", venta2.cai);
	venta2.regalia = 00;
	venta2.subtotal = 00;

	strVentas venta3;
	venta3.id = 000003
	strcpy("Alfonsina Del Sol Saliente", venta3.cliente)
	venta3.forma_de_pago = 0
	venta3.fecha = 15032018;
	venta3.lista_productos[0] = prd_ven3;
	venta3.lista_productos[1] = prd_ven4;
	strcpy("0001-3233434fbe", venta3.cai);
	venta3.regalia = 00;
	venta3.subtotal = 00;

#endif