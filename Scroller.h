#ifndef SCRLL
#define SCRLL

//#include <windows.h>
#include "Console.h"
#include "conio.h"
#include "KBD.hpp"
#include "Keyboard.h"


#define MAXITEMS 100

typedef struct Menudata
{
    char desc[250];
    char cmd[40];
}
MENUDATA;




class Scroller  {

		
		//CString Items;
		Console scr;	
		Inputs hKbd; 

		struct vm_info vm_startup;
		
		VIOIMAGE sysimage;

		char currow,oldrow;
		char rowend;
		int menuitems;
		char curritem;
		char options;
		char xabs, yabs;
		char x1abs, y1abs;

		char curx,cury;

		char Border[8];
		
public:

		char		SubTitle[250];
		char		Title[250];
		char		BarMsg[250];
		MENUDATA menudata[MAXITEMS];
		int LastKey	;	
	
		Scroller (void);
		Scroller (char x, char y, char x1, char y1, Console con);
		void AddItem(char *, char*);
		void Finish(void);
		void Init(char x, char y, char x1, char y1, Console con);
		void Init(void);
		void SaveScr(void);
		void Show(void);
		int  Display(void);
		void SetSubTitle(char *);
		void SetTitle(char *);
		void SetBorder(char *);
		void SetBarMsg(char *);

};

#endif