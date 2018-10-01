#include "console.h"
#include "scroller.h"

class Equipos_Accesorios	 {	//: public Point { // derived from class Point

	char	cod_equ			[4+1];
	char	des_equ 		[50+1];

	int Terminal;
	
	Scroller Lista;		//	(7,23, 13, 40);

	Console con;
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Equipos_Accesorios(PDBPROCESS dbprocess, Console con);
   void Show(void);
   void Execute(int x);
   void GetLstSql(void);
};
