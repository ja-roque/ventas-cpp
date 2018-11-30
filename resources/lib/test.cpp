#include "radiobutton.h"
#include <vector.h>

int main()
{
  	std::vector<list_checkbox*> v(2);
	//cprintf("La fruta que te gusta es la: ");
	list_checkbox *list1 = new list_checkbox;
	list1->add("manzana");
	list1->add("naranja");
	list1->add("melon");
	list1->add("fresa");
   	list1->add("pera");

   	list_radiobutton *list2 = new list_radiobutton;

   	list2->add("masculino");
   	list2->add("femenino");

	list1->box(2,1);
   	list2->box(25,1);


   	v[0]= list1;
   	v[1]=list2;

  	 int ch=0;
   	do
  	{
		ch=getkey();
		if(ch==ARIGHT)
		{
			v[1]->focus();
		}
		if(ch==ALEFT)
		{
      		v[0]->focus();
     	 	}

	}while(ch!=ESC);

	delete list1;
	delete list2;

	getkey();

return 0;
}
