#include "console.h"
#include "scroller.h"
class Condicion_Contenedores	 {	//: public Point { // derived from class Point

	char	codigo			[4+1];
	char	descripcion		[50+1];

	int Terminal;
	
	Scroller Lista;		//	(7,23, 13, 40);

	Console con;
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Condicion_Contenedores(PDBPROCESS dbprocess, Console con);
   void Show(void);
   void Execute(int x);
   void GetLstSql(void);
};
