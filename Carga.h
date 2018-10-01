#include "keyboard.h"
#include "Console.h"
#include "Scrollerh.h"

class Carga_Fraccionada	 {	//: public Point { // derived from class Point
	
	char	BL_Master	    [26];
	char	BL_Hijo 	    [25+1];
	char	Total_Bultos	[6+5];
	char	Total_Peso	    [11+5];
	char	Cod_Embalaje	[4];
	char	Manifiesto	    [10];
	char	Nave		    [51];
	char	Area		    [51];
	char	Ubicacion	    [3+1];
	char	Marca_Numero	[8000+1];
	char	Producto	    [8000+1];
	char	nArea		    [10];
	char    ubi_1           [9+1];
	


	char	   Resp		   [256];

	int		Terminal;
	
	Console		con;
	Inputs		hKey;
	ScrollerH	ScrllH;


	RETCODE    result_code;

	PDBPROCESS dbproc;

public:
   Carga_Fraccionada(PDBPROCESS dbprocess, Console con);
   void Display(void);
   int GetStr(void);
   void UpdateSql(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);
   void ShowMarcaNumero(void);
   void ShowProducto(void);
   int IfUpdated(void);
   int Verifica(void);
   
};
