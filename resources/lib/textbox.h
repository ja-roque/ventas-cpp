#ifndef __TEXTBOX_H
#define __TEXTBOX_H

	#ifndef __STRING_H
		#include <string>
	#endif

	#ifndef  __CONIO_H
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

class textbox
{
	public:
		textbox();
		textbox(int width);
		virtual void show(int,int);
      virtual void show();
		virtual void focus(bool f);
        	int width();
      std::string name();
      virtual void name(std::string name__);

	private:
		void type();

	protected:
		unsigned int width_;
		int x;
		int y;
		std::string name_;

};

textbox::textbox()
{
	width_ = 25;
	x=1;
	y=1;
	name_="";
}

textbox::textbox(int width)
{
	width_ = width;
	x=1;
	y=1;
	name_="";
}

std::string textbox::name()
{
return name_;
}

void textbox::name(std::string name__)
{
 name_=name__;
}

void textbox::show(int x1, int y1)
{
	 int xmax = 80 - SHOWLEN - width_;	//there are usually only 80 characters available to print on the screen, needs to take into account the name length and closing bracket "]"
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
	 cprintf("[");	//intiial bracket
	 for(int i=0; i<width_; i++)
	 {
		 cprintf(" ");
	 }
	 cprintf("]");	//closing bracket
	 gotoxy(x+1,y);
    cprintf(this->name().c_str());
    gotoxy(x+1,y);
}

void textbox::show()
{
	 gotoxy(x,y);	//used to move cursor to desired lovation
	 cprintf("[");	//intiial bracket
	 for(int i=0; i<width_; i++)
	 {
		 cprintf(" ");
	 }
	 cprintf("]");	//closing bracket
	 gotoxy(x+1,y);
    cprintf(this->name().c_str());
    gotoxy(x+1,y);
}

void textbox::focus(bool f)
{
	if(f)
   {
		gotoxy(x+1+name_.size(),y);
   }else
   {
   	gotoxy(x+1,y);
   }

   type();
}

void textbox::type()
{
	int key;
	char ch;

	do
	{
		ch = getkey();
		key = (int)ch;
		if( name_.size() < width_ && key!=TAB)
		{
			if(key==BCK && name_.size()>1)
			{
				cprintf("\b ");
				name_.resize(name_.size()-1);
			}
			else if(name_=="")
			{
				name_ = ch;
			}
			else
			{
				name_ += ch;
			}

		}

		gotoxy(x+1,y);
		cprintf(name_.c_str());

	}while(key!=TAB);
}

int textbox::width()
{
    return width_;
}

#endif
