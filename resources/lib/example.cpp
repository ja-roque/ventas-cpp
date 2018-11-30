#include "radiobutton.h"
#include "numbox.h"

int main()
{
	int key=0;
   std::string cont;
   double extradi =0;
   double extram = 0;
   double extran = 0;
   double extrado =0;
   double extrao = 0;
   double textra = 0;
   double total = 0;
   double  ihss = 0;
   double rap =0;
   double ahorro =0;
   double otro = 0;
   char* after;

	textbox *name = new textbox(30);
	numbox *sueldo = new numbox(12);
	numbox *diurnas = new numbox(4);
	numbox *mixtas = new numbox(4);
	numbox *nocturnas = new numbox(4);
	numbox *dobles = new numbox(4);
   numbox *otras = new numbox(9);
   textbox *calc = new textbox(1);
   list_radiobutton *radio = new list_radiobutton;
   radio->add("MASCULINO");
   radio->add("FEMENINO");
   list_checkbox *check = new list_checkbox;
   check->add("I.H.S.S. :");
   check->add("R.A.P.   :");
   check->add("AHORRO 3%:");

	gotoxy(21,1);
	cprintf("SISTEMA DE CALCULO DE PAGOS MENSUALES");
	gotoxy(2,3);
	cprintf("INGRESE LOS SIGUIENTES DATOS DEL EMPLEADO");
	gotoxy(1,5);
	cprintf("NOMBRE: ");
	name->show(9,5);
	gotoxy(1,7);
	cprintf("SUELDO MENSUAL:");
	sueldo->show(17,7);
	gotoxy(1,9);
	cprintf("HORAS EXTRAS TRABAJADAS:   VALOR L.");
	gotoxy(1,10);
	cprintf("DIURNAS   (AL 1.25):");
	gotoxy(1,11);
	cprintf("MIXTAS    (AL 1.50):");
	gotoxy(1,12);
	cprintf("NOCTURNAS (AL 1.75):");
	gotoxy(1,13);
	cprintf("DOBLES    (AL 2.00):");
	diurnas->show(21,10);
	mixtas->show(21,11);
	nocturnas->show(21,12);
	dobles->show(21,13);
   gotoxy(1,15);
   cprintf("TOTAL A PAGAR HORAS EXTRAS:");
   gotoxy(1,16);
   cprintf("BONOS PARA EL EMPLEADO:");
   gotoxy(1,18);
   cprintf("INGRESOS TOTALES:");
   gotoxy(1,20);
   cprintf("NETO A PAGAR AL EMPLEADO:");
   gotoxy(40,8);
	cprintf("GENERO: ");
   gotoxy(40,10);
   cprintf("DETALLE DE DEDUCCIONES:");
   radio->show(48,8,1);
   check->show(40,12,0);
   gotoxy(45,15);
   cprintf("OTRAS DED:");
   otras->show(55,15);
   gotoxy(45,17);
   cprintf("TOTAL DED:");
   gotoxy(1,25);
   cprintf("DESEA REALIZAR OTRO CALCULO (S/N):");
   calc->show(35,25);


   do
   {
   	name->focus();
      sueldo->focus();
      diurnas->focus();
      extradi = diurnas->name();
      if(extradi>0)
      {
         gotoxy(28,10);
         extradi*= 300*1.25;
         cprintf("%.2f",extradi);
      }
      mixtas->focus();
      extram = mixtas->name();
      if(extram > 0)
      {
      	gotoxy(28,11);
         extram *= 300*1.5;
         cprintf("%.2f",extram);
      }
      nocturnas->focus();
      extran = nocturnas->name();
      if(extran > 0)
      {
      	gotoxy(28,12);
         extran *= 300 * 1.75;
         cprintf("%.2f",extran);
      }
      dobles->focus();
      extrado = dobles->name();

      if(extrado > 0);
      {
      	gotoxy(28,13);
         extrado *= 300 *2;
         cprintf("%.2f",extrado);
      }

      textra = extrado + extran + extram + extradi;
      if( textra > 0)
      {
      	gotoxy(28,15);
         cprintf("%.2f",textra);
      }
   	total = sueldo->name() + textra;
      radio->focus();
      check->focus();
      checkbox *temp = check->head();
      for(int i=0;i<3;i++)
      {
      	if(i==0 && temp->checked())
         {
             ihss = total *0.05;
             gotoxy(58,12);
             cprintf("%.2f",ihss);
         }

         if(i==1 && temp->checked())
         {
         	rap = total *0.05;
            gotoxy(58,13);
             cprintf("%.2f",rap);
         }

         if(i==2 && temp->checked())
         {
         	ahorro = total *0.03;
            gotoxy(58,14);
             cprintf("%.2f",ahorro);
         }

         temp = temp->next();
      }
      otras->focus();
      otro = otras->name();

      gotoxy(58,17);
      cprintf("%.2f",otro+ahorro+rap+ihss);

      gotoxy(28,18);
      cprintf("%.2f",total);

      gotoxy(28,20);
      cprintf("%.2f",total - otro - ahorro - rap - ihss);

      calc->focus();

   }while(calc->name()!="n");

}
