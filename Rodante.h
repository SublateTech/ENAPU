#include "keyboard.h"
#include "Console.h"
#include "ScrollerH.h"

class Carga_Rodante	 {	//: public Point { // derived from class Point

	char	BL_Master	    [26];
    char	BL_Hijo 	    [26];
	char	Total_Bultos	[6];
	char	Total_Peso	    [6];
	char	Chasis		    [27];
	char	Modelo		    [26];
	char	Manifiesto	    [10];
	char	Nave		    [51];
	char	Area		    [51];
	char	Ubicacion	    [3];
	char	Nueva_Ubic	    [3];

	char	nArea		    [10];
	char    ubi_1           [3+1];

	char	   Resp		   [256];

	int Terminal;


	Console		con;
	Inputs		hKey;
	ScrollerH   ScrllH;

	
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
    Carga_Rodante(PDBPROCESS dbprocess, Console con);
      void Display(void);
   int GetStr(void);
   void UpdateSql(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);
   int IfUpdated(void);
   int Verifica(void);


};
