#include "console.h"
#include "scroller.h"
class Mensajes	 {	//: public Point { // derived from class Point

	char   Item					[2+1]; 
	char   Prioridad_Mensaje   [10+1];
	char   Detalle				[140];
	char   Usuario				[10+1];
	char   Fecha_Reg			[8+1]; 
	char   Hora					[8+1]; 
	Scroller Lista;		//	(7,23, 13, 40);
	Inputs hKey;

	Console con;
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Mensajes(PDBPROCESS dbprocess, Console con);
   void Display(void);
   void Hide(void);
   void Expand(void);
   void Show(void);
   void GetSql(char *Opcion);
   void Execute(void);
   void GetLstSql(void);
};
