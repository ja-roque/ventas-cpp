#include "listbox.h"

int main()
{
	listbox *list = new listbox("hola");
   list->show(3,3);
   list->focus();


   getch();


}