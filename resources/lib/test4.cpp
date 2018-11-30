#include "combobox.h"

int main()
{
/*
	gotoxy(3,2);
   cprintf("Name:");
   textbox *text = new textbox;
   text->show(9,2);

   gotoxy(38,13);
   cprintf("Gender:");
   list_radiobutton *radio = new list_radiobutton;
   radio->add("Male");
   radio->add("Female");
   radio->box(33,14);

   gotoxy(3,2);
   cprintf("This is a checkbox:");
   list_checkbox *check = new list_checkbox;
   check->add("First");
   check->add("Second");
   check->add("Third");
   check->add("Fourth");
   check->box(3,3);
   check->focus();       */



   gotoxy(8,5);
  // cprintf("Country:");
   list_combobox *combo = new list_combobox;
   combo->add("Honduras");
   combo->add("Guatemala");
   combo->add("El Salvador");
   combo->add("Nicaragua");
   combo->show(5,7,0);
   //combo->show(5,7,1);
   combo->focus();

   //check->focus();
   //text->focus();



   getch();


}
