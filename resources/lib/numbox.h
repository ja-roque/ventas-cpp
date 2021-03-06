#ifndef __NUMBOX_H
#define __NUMBOX_H

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

   #ifndef __MATH_H
   	#include "math.h"
   #endif

class numbox
{
	public:
		numbox();
		numbox(int width);
		virtual void show(int,int,bool);
      virtual void show();
		virtual void focus();
        	int width();
      double name();
      void name(double name__);

	private:
		void type();

	protected:
		unsigned int width_;
		int x;
		int y;
		double name_;
      bool f;

};

numbox::numbox()
{
	width_ = 25;
	x=1;
	y=1;
	name_=0;
}

numbox::numbox(int width)
{
	width_ = width;
	x=1;
	y=1;
	name_=0;
}

double numbox::name()
{
return name_;
}

void numbox::name(double name__)
{
 	name_=name__;
}

void numbox::show(int x1, int y1,bool f)
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
    if(f)
    {
    cprintf("%.2f",name_);
    }else
    {
    	cprintf("%0.0f",name_);
    }
    gotoxy(x+1,y);
}

void numbox::show()
{
	 gotoxy(x,y);	//used to move cursor to desired lovation
	 cprintf("[");	//intiial bracket
	 for(int i=0; i<width_; i++)
	 {
		 cprintf(" ");
	 }
	 cprintf("]");	//closing bracket
	 gotoxy(x+1,y);
     if(f)
    {
    cprintf("%.2f",name_);
    }else
    {
    	cprintf("%0.0f",name_);
    }
    gotoxy(x+1,y);
}

void numbox::focus()
{
	gotoxy(x+1,y);
	type();
}

void numbox::type()
{
	int key;
	char ch;

	do
	{
		ch = getkey();
		key = (int)ch;

		if(key!=TAB)
		{
			if(key==BCK)
			{
         	gotoxy(x+1,y);
            for(int i=0;i<width_;i++)
            {
             cprintf(" ");
            }
            gotoxy(x+1,y);
            fmod(name_,10);
            cprintf("%.2f",name_);
			}
			else if(name_==0)
			{
				name_ = ch-48;
			}
			else
			{
				name_ *= 10;
            name_+=(ch-48);
			}

		}

		gotoxy(x+1,y);
		cprintf("%.2f",name_);

	}while(key!=TAB);
}

int numbox::width()
{
    return width_;
}

#endif