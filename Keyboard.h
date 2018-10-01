#define       DBNTWIN32               // must identify operating system environment//
#include <windows.h>
#include <sqlfront.h>
#include <sqldb.h>         // DB-LIB header file (should always be included)


#include <conio.h>
#include <stdlib.h>
#include <wincon.h>
#include "kbd.hpp"
#include "Console.h"




#ifndef CInputs
#define CInputs
#define CTRL_CHARS_ALLOWED 0  /* Non-zero allows entry of Ctrl-characters   */

#define BAD_KEY() {fputc('\a', stderr); break;}
#define putch(x)   fputc((x), stderr)
static const char PWchars[] = /* Frequency approximates English usage   */
      "aaabbccddeeeeffgghhiiijklllmmmnnnoooppqrrrsssstttuuvwwxyz"
      "1234567890-|,@._"
      "aaabbccddeeeeffgghhiiijklllmmmnnnoooppqrrrsssstttuuvwwxyz";

static int pickPWchar(void);



	/*
						**  Password mode:
						**
						**  0 - Normal operation
						**  1 - Conventional password 
						**  2 - Secure password mode 
						
						*/

class Inputs	 {	

				
	 int TabSize;
	 int password_mode;
	 Console screen;
	 
	 PDBPROCESS hDb;

	
public:

	int LastKey;
        Inputs(Console con, PDBPROCESS dbproc);
		Inputs(Console con);
		Inputs(void);
	int getpassf(char buf[], int len);
	int gettext(char buf[], int len);
	int ungetkey (int key);	
	int getkey(void);							
	int editgets(char *s, int maxlen, char *string);
	void kbflush();        					
	int pickPWchar(void);
	void Init(Console screen, PDBPROCESS dbproc);
		

};

#endif