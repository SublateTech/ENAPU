#include "console.h"
#include "keyboard.h"
class Terminal_Portuario  {	//: public Point { // derived from class Point

	char	Nro_Ticket	    [10+1];
	char	Chofer		    [10+1];
	char	Placa		    [8+1];
	char	Autorizacion	[10+1];
	char	Operacion	    [3+1];
	char	Balanza 	    [4+1];
	char	Fecha_Reg	    [10+1];
	char	Embalaje	    [3+1];
	char	Tot_Peso_Vehiculo [5+1];
	char	Usuario 	    [10+1];
	char	Hora_Reg	    [9+1];
	char	Area		    [50+1];

	int Terminal;


	Console		con;
	Inputs		hKey;

	
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Terminal_Portuario(PDBPROCESS dbprocess, Console con);
      void Display(void);
   int GetStr(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);

};
