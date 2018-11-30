#ifndef __COMBOBOX_H
#define __COMBOBOX_H

	#ifndef __RADIOBUTTON_H
		#include "radiobutton.h"
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
    
	#ifndef __KEYS_H
		#include "keys.h"
	#endif

class combobox : public radiobutton
{
	public:
		combobox(std::string comboname);
		~combobox();
		virtual void show(int,int);
		virtual void show();
		virtual void focus();
		void next (combobox *next_);
		void back (combobox *back_);
		combobox *next();
		combobox *back();
	private:
		combobox *next__;
		combobox *back__;
};

class list_combobox : public list_radiobutton
{
	public:
		list_combobox() : list_radiobutton () {};
		~list_combobox();
		virtual void add(std::string name);
		combobox *last();
		void show (int x1, int y1, bool drop);
		void focus();
		virtual int maxwidth();

	private:
		combobox *ini;

	protected:
		void check(combobox *current);
		int x;
		int y;
};

combobox::combobox(std::string comboname)
:radiobutton(comboname)
{
	next__=NULL;
	back__=NULL;
}

combobox::~combobox()
{
}

combobox *combobox::next()
{
	return next__;
}

combobox *combobox::back()
{
	return back__;
}

void combobox::next (combobox *next_)
{
	next__=next_;
}

void combobox::back (combobox *back_)
{
	back__=back_;
}

void combobox::show(int x1, int y1)
{
	int xmax = 80 - SHOWLEN -this->name().size();  //there are usually only 80 characte  rs available to print on the screen, needs to take into account the name length and closing   bracket "]"
	if(x1>=1 && x1 <=xmax) //if x coordinate is within boundaries, assign it to x
	{  
		x=x1;
	}
        else   //else assign its max
        {
               if(x1<1) x=1; 
               if(x1 > xmax) x=xmax;
        }

        if(y1 >=1 && y1 <=25)  //there are usually only 25 characters in the y direction
        {
            y=y1;      ///if input y is within the boundary then assign it to the y coordin  ate
        }
        else   //else assign its max coordinate or its min
        {
          if(y1 <1) y=1;
          if(y1>25) y=25;
        }
 
        gotoxy(x,y);   //used to move cursor to desired lovation
        cprintf(name().c_str());        //print checkbox name
}

void combobox::show()
{
	gotoxy(x,y);
	cprintf(name().c_str());
}

void combobox::focus()
{
	gotoxy(x,y);
}

list_combobox::~list_combobox()
{
	combobox *current = this->ini;

	while(current)
	{
		combobox *next(current->next());
		delete current;
		current = next;
	}
}

combobox *list_combobox::last()
{
	combobox *end = this->ini;

	while(end->next())
	{
		end = end->next();
	}

	return end;
}

void list_combobox::add(std::string name)
{
	combobox *newcombo = new combobox (name);

	if(count_==0)
	{
		this->ini = newcombo;
		this->ini->checked(1);
		count_++;
	}
	else
	{
		newcombo->back(this->last());
		this->last()->next(newcombo);
		count_++;
	}
}

int list_combobox::maxwidth()
{
	int width=0;
	combobox *temp = this->ini;
	while(temp)
	{
		if(temp->name().size()>width)
		{
			width=temp->name().size();
		}
	
		temp=temp->next();
	}

	return width;
}

void list_combobox::show(int x1, int y1, bool drop)
{
	x=x1;
	
	y=y1;

	combobox *temp = this->ini;

	if(!drop)
	{
		gotoxy(x,y);	//used to move cursor to desired lovation
		cprintf("[");	//intiial bracket
	 	for(int i=0; i < maxwidth(); i++)
	 	{
			 cprintf(" ");
	 	}
	 	cprintf(" |v]");	//closing bracket
	 	gotoxy(x+1,y);
		for(;temp;temp=temp->next())
		{
			if(temp->checked())
			{
				cprintf(temp->name().c_str());
				break;
			}
		}
	 	gotoxy(x+1,y);
	}
	else
	{
        	gotoxy(x,y+1);	//used to move cursor to desired lovation
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
	

}

void list_combobox::focus()
{
	int key;
	bool drop = 0;
	combobox *temp = this->ini;
	gotoxy(x+1,y);
	do
	{
		key=getkey();

		if(key == UP && !drop)
		{
			if(temp->back()) 
			{
				temp->checked(0);
				temp = temp->back();
				temp->checked(1);
				for(int i=0;i<maxwidth();i++)
				{
					cprintf(" ");
				}
				gotoxy(x+1,y);
				cprintf(temp->name().c_str());
				gotoxy(x+1,y);
			}
		}

		if(key == UP && drop)
		{
			if(temp->back())
			{
				temp->focus();
				textbackground(BLACK);
				temp->show();
				temp->checked(0);
				temp = temp->back();
				temp->checked(1);
				gotoxy(x+1,y);
				for(int i=0; i<maxwidth();i++)
				{	
					cprintf(" ");
				}
				gotoxy(x+1,y);
				cprintf(temp->name().c_str());
				temp->focus();
				textbackground(CYAN);
				temp->show();
				textbackground(BLACK);
				temp->focus();
			}

		}

		if(key == DOWN && !drop)
		{
			if(temp->next()) 
			{
				temp->checked(0);
				temp = temp->next();
				temp->checked(1);
				gotoxy(x+1,y);
				for(int i=0;i<maxwidth();i++)
				{
					cprintf(" ");
				}
				gotoxy(x+1,y);
				cprintf(temp->name().c_str());
				gotoxy(x+1,y);
			}
		}

		if(key == DOWN && drop)
		{
			if(temp->next())
			{
				temp->focus();
				textbackground(BLACK);
				temp->show();
				temp->checked(0);
				temp = temp->next();
				temp->checked(1);
				gotoxy(x+1,y);
				for(int i=0; i<maxwidth();i++)
				{	
					cprintf(" ");
				}
				gotoxy(x+1,y);
				cprintf(temp->name().c_str());
				temp->focus();
				textbackground(CYAN);
				temp->show();
				textbackground(BLACK);
				temp->focus();
			}

		}

		if(key == ADOWN && !drop)
		{
			drop = 1;
			this->show(x,y,drop);
		}

		if(key == AUP && drop)
		{
			drop = 0;
			for(int j=0;j<count_ + 2;j++)
			{
				gotoxy(x,y+1+j);

				for(int i=0;i < maxwidth() + 3;i++)
				{
					cprintf(" ");
				}
			}

			this->show (x,y,drop);
		}

	}while(key!=ESC);
	
}

#endif
