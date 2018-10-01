#include "keyboard.h"
#include "Console.h"

class Terminal_Almacenamiento	{	//: public Point { // derived from class Point

	char   Nro_Ticket		 [10+1];
	char   Contenedor		 [14+1];
	char   Precinto 	     [17+1];
	char   Tara				 [5+1]; 
	char   Condicion		 [4+1];
	char   Balanza		     [5+1];
	char   Fecha_Reg		 [10+1];
	char   Tamano		     [3+1];
	char   Tipo				 [3+1]; 
	char   Peso				 [5+1]; 
	char   Estado		     [4+1];
	char   Pesador		     [11+1];
	char   Hora_Reg 	     [9+1];

	int Terminal;

	Console		con;
	Inputs		hKey;

	PDBPROCESS dbproc;

	RETCODE    result_code;

public:
	   Terminal_Almacenamiento(PDBPROCESS dbprocess, Console con);
   void Display(void);
   int GetStr(void);
   void UpdateSql(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);

};
