#ifndef SCRLLH
#define SCRLLH

//#include <windows.h>
#include "Console.h"
#include "conio.h"
#include "KBD.hpp"
#include "Keyboard.h"




class ScrollerH  {

		
		Console scr;	
		Inputs hKbd; 

		int		fila;
		int		columnai;
		int		columnaf;
		int x, ind, i;
		
public:

		char		Str[8000];
		char		substr[81];
		int			LastKey	;	
	
		
		ScrollerH (char x, char y, char y1, char *str,Console con);
		ScrollerH ();
		void Init(char x, char y, char y1, char *str,Console con);
		void Left(void);
		void Right(void);
		void Show(void);
		void Exec(void);
		
	
	
};

#endif