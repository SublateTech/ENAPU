#include "Console.h"
#include "keyboard.h"
#include "kbd.hpp"

class Chofer  {       //: public Point { // derived from class Point

	char	Licencia	  [10];
	char	Agencia 	  [60];
	char	Apellido	  [20];
	char	LE_DNI		  [8];	
	char	Nombre		  [25]; 
	char	LM		  [10]; 
	char	Estado		  [50]; 
	char	Fecha_Reg	  [10+1];
	char	Fecha_Exp	  [10+1];

	int Terminal;

	Console con;
	Inputs		hKey;

	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Chofer(PDBPROCESS dbprocess, Console con);
   void Display(void);
   int GetStr(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);
};
