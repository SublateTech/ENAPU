#include "console.h"
class Muelles  {       //: public Point { // derived from class Point

	char   Codigo_de_1		  [4];
	char   Descripcion_1		  [100];
	char   Codigo_de_2		  [5];
	char   Descripcion_2		  [100];
	char   Codigo_de_3		  [6];
	char   Descripcion		  [100];
	char   Codigo_de_4		  [7];
	char   Descripcion_4		  [30];
	char   Codigo_de_5		  [8];
	char   Descripcion_5		  [100];

	Console con;

	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Muelles(PDBPROCESS dbprocess, Console con);
   void Display(void);
   void Hide(void);
   void Expand(void);
   void Show(void);
   void GetSql(void);
   void Execute(void);
};
