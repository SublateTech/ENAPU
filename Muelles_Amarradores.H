#include "console.h"
#include "scroller.h"

class Muelles_Amarradores {	//: public Point { // derived from class Point

	char	cod_mue			[4+1];
	char	cod_ama 		[4+1];
	
	Scroller Lista;		//	(7,23, 13, 40);

	Console con;
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Muelles_Amarradores(PDBPROCESS dbprocess, Console con);
   void Show(void);
   void Execute();
   void GetLstSql(void);
};
