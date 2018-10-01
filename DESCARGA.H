#include "console.h"
#include "scroller.h"
class Descarga_Contenedores	 {	//: public Point { // derived from class Point

	char	Nro_Atencion	[5];
	char	Autorizacion	[11];
	char	Contenedor		[14];
	char	Ubicacion		[9];

	Scroller Lista;		//	(7,23, 13, 40);

	Console con;
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Descarga_Contenedores(PDBPROCESS dbprocess, Console con);
   void Display(void);
   void Hide(void);
   void Expand(void);
   void Show(void);
   void GetSql(char *Opcion);
   void Execute(void);
   void GetLstSql(void);
};
