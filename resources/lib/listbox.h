#ifndef __LISTBOX_H
#define __LISTBOX_H

	#ifndef __CHECKBOX_H
		#include "combobox.h"
	#endif

	#ifndef __STRING_H
		#include <string>
	#endif

	#ifndef __CONIO_H
		#include "conio.h"
	#endif

	#ifndef __STDIO_H
		#include <stdio.h>
	#endif
		
	#ifndef __GETKEY_H
		#include "getkey.h"
	#endif

	#ifndef __KEYS
		#include "keys.h"
	#endif

 class listbox : public combobox
{
	public:
		listbox(std::string listboxname);
		~listbox();
		void next(listbox *next_);
		void back(listbox *back_);
		listbox *next();
		listbox *back();
	private:
		listbox *next__;
		listbox *back__;
};

class list_listbox : public list_combobox
{
	public:
		list_listbox() : list_combobox () {};
		~list_listbox();
		virtual void add(std::string name);
		listbox *last();
		void show(int x1, int y1);
		void focus();
	private:
		combobox *ini;

};

//listbox constructor using checkbox constructor

listbox::listbox(std::string listboxname) 
:combobox(listboxname)
{
	next__=NULL;
	back__=NULL;
}

//listbox destructor

listbox::~listbox()
{
}

//returns next item in the list

listbox *listbox::next()
{
	return next__;
}

listbox *listbox::back()
{
	return back__;

}

void listbox::next (listbox *next_)
{
	next__=next_;
}

void listbox::back (listbox *back_)
{
	back__=back_;
}

list_listbox::~list_listbox()
{
	listbox *current = this->ini;

	while(current)
	{
		listbox *next(current->next());
		delete current;
		current = next;
	}
}

void list_listbox::add(std::string name)
{
	listbox *newlist = new listbox (name);

	if(count_==0)
	{
		this->ini = newlist;
		this->ini->checked(1);
		count_++;
	}
	else
	{
		newlist->back(this->last());
		this->last()->next(newlist);
		count_++;
	}
}

listbox *list_listbox::last()
{
	listbox *end = this->ini;

	while(end->next())
	{
		end = end->next();
	}

	return end;
}

void list_listbox::show(int x1, int y1)
{
	x=x1;

	y=y1;

	listbox *temp = this->ini;

	gotoxy(x,y);
    	cprintf("%c",C1);
	for(int i=0; i< maxwidth() + 1; i++)
	{	
		cprintf("%c",HLINE);
	}

	cprintf("%c",C2);

 	for(int i=0; i < this->count(); i++)
 	{
		gotoxy(x,y+2+i);
		cprintf("%c",VLINE);
		for(int i=0;i<maxwidth() + 1; i++)
		{
			cprintf(" ");
		}
		cprintf("%c",VLINE);
 	}

      	gotoxy(x,y + this->count() + 2); 

	cprintf("%c",C3);

	for(int i=0; i<maxwidth() + 1; i++)
	{
		cprintf("%c",HLINE);
	}

	cprintf("%c",C4);

	for(int i=0;i<count_;i++)
	{
		if(temp->checked())
		{
			gotoxy(x+1,y+2+i);
			textbackground(CYAN);
		}
		else
		{
			gotoxy(x+1,y+2+i);
			textbackground(BLACK);
		}
		temp->show(x+1,y+2+i);
		temp=temp->next();
	}

	temp = this->ini;
	for(;temp;temp=temp->next())
	{
		if(temp->checked())
		{
			temp->focus();
			break;
		}
	}

}
#endif
