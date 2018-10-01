#ifndef SCRLLV
#define SCRLLV

//#include <windows.h>
#include "Console.h"
#include "conio.h"
#include "KBD.hpp"
#include "Keyboard.h"




class ScrollerV  {

		
		Console scr;	
		Inputs hKbd; 

		int		fila;
		int		filaf;
		int		columnai;
		int		columnaf;
		int		x, ind, i;
		
public:

		char		Str[8000];
		char		substr[81];
		int			LastKey	;	
	
		
		ScrollerV (char x, char y, char f1, char y1, char *str,Console con);
		ScrollerV ();
		void Init(char x, char y, char f1, char y1, char *str,Console con);
		void Down(void);
		void Up(void);
		void Show(void);
		void Exec(void);
	
	
};

#endif