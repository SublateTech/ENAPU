#include "console.h"
#include "keyboard.h"
#include "Scrollerh.h"

#ifndef CVanes
#define CVanes

class Ubicacion_Vanes	 {	//: public Point { // derived from class Point
			 
   	// Campos de la Tabla
	
	char       contenedor			[14];
	char       condicion			[6];
	char       precinto             [17];
	char       tamano               [5];
	char       tipo                 [5];
	char       estado               [5];
	char       tara					[5];
	char       peso                 [6];
	char       nave                 [8000];
	char       manifiesto			[10];
	char       area                 [51];
	char       Ubi_1                [9];
	char       Ubi_2                [9];
	char	   Resp		 			[256];
	char	   Existe	 			[256];
	char	   nArea				[7];
	char       ubi_1                [9];
	char       ubi_2                [9];

	int Terminal;
	
	
	Inputs		hKey;
	PDBPROCESS dbproc;
	Console		con;
	ScrollerH	ScrllH;

	
	RETCODE    result_code;


public:
		Ubicacion_Vanes(PDBPROCESS dbprocess, Console con);
   void Display(void);
   int GetStr(void);
   void UpdateSql(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);
   int IfUpdated();
   int Verifica();
};

#endif