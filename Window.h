#ifndef EWIN
#define EWIN

//#include <windows.h>
#include "Console.h"
//#include "Afx.h"

class Window {

		
		//CString Items;
		Console *scr;	

		struct vm_info vm_startup;
		
		VIOIMAGE sysimage;

		char currow,curcol;
		char options;
		char xabs, yabs;
		char x1abs, y1abs;

		
		
public:

		char		Title[250];
		char		Border[8];
		char		BarMsg[250];
		
	
		Window (void);
		Window (char x, char y, char x1, char y1, Console con);
		void Close(void);
		void Init(char x, char y, char x1, char y1, Console con);
		void Init(void);
		void SaveScr(void);
		void Show(void);
		void Writexy(char x, char y, char * );
		void SetTitle(char *);
		void SetBorder(char *);
		void Clear();
		void SetBarMsg(char *);

};

#endif