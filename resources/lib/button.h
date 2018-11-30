#ifndef __BUTTON_H
#define __BUTTON_H

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

class button
{
	public:
		button(std::string name);
		~button();
		virtual void show(int,int);
      virtual void show();
		void focus();
		void checked(bool mark);
		bool checked();
		std::string name();
		void next(button *next_);
		void back(button *back_);
		button *next();
		button *back();

	private:
		button *next__;
		button *back__;
		std::string name_;
		int width_;
		bool checked_;
		int x;
		int y;
};

class list_button
{
};

button::button(std::string name)
{
	next__=NULL;
	back__=NULL;
	name_=name;
	width_=name.length()+2;
	checked_=0;
	x=0;
	y=0;
}

button::~button()
{
}

button *button::next()
{
	return next__;
}

button *button::back()
{
	return back__;
}

void button::next(button *next_)
{
	next__=next_;
}

void button::back(button *back_)
{
	back__=back_;
}

std::string button::name()
{
	return name_;
}

void button::show(int x1,int y1)
{

	int xmax = 80 - this->name().size();

    	 if(x1>=1 && x1 <=xmax)	//if x coordinate is within boundaries, assign it to x
    	 {
       	    x=x1;
    	 }
    	 else	//else assign its max
    	 {
		if(x1<1) x=1;
		if(x1 > xmax) x=xmax;
   	 }

   	 if(y1 >=1 && y1 <=25)	//there are usually only 25 characters in the y direction
    	 {
      	     y=y1;	///if input y is within the boundary then assign it to the y coordinate
    	 }
    	 else	//else assign its max coordinate or its min
   	 {
      	   if(y1 <1) y=1;
      	   if(y1>25) y=25;
   	 }

	 gotoxy(x,y);	//used to move cursor to desired lovation
	 cprintf("%c",C1);	//intiial bracket
	 for(int i=0; i<width_; i++)
	 {
		 cprintf("%c",HLINE);
	 }

	 cprintf("%c",C2);	//closing bracket

	 gotoxy(x,y+1);
	 cprintf("%c",VLINE);
	 for(int i=0; i<width_;i++)
	 {
		 cprintf(" ");
	 }
    cprintf("%c",VLINE);
	 gotoxy(x,y+2);
	 cprintf("%c",C3);
	 for(int i=0;i<width_;i++)
	 {
		 cprintf("%c",HLINE);
	 }
	 cprintf("%c",C4);
	 gotoxy(x+2,y+1);
	 cprintf(this->name().c_str());
}

void button::show()
{

	 gotoxy(x,y);	//used to move cursor to desired lovation
	 cprintf("%c",C1);	//intiial bracket
	 for(int i=0; i<width_; i++)
	 {
		 cprintf("%c",HLINE);
	 }

	 cprintf("%c",C2);	//closing bracket

	 gotoxy(x,y+1);
	 cprintf("%c",VLINE);
	 for(int i=0; i<width_;i++)
	 {
		 cprintf(" ");
	 }
    cprintf("%c",VLINE);
	 gotoxy(x,y+2);
	 cprintf("%c",C3);
	 for(int i=0;i<width_;i++)
	 {
		 cprintf("%c",HLINE);
	 }
	 cprintf("%c",C4);
	 gotoxy(x+2,y+1);
	 cprintf(this->name().c_str());
}

void button::focus()
{
	gotoxy(x+2,y+1);
}

bool button::checked()
{
	return checked_;
}

void button::checked(bool mark)
{
	checked_=mark;
}

#endif
