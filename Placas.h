#include "console.h"
#include "keyboard.h"
#include "kbd.hpp"


class Placas  {       //: public Point { // derived from class Point

	char	Placa		     [8+1];
	char	Agencia 	     [60+1];
	char	Dueno		     [40+1];
	char	Modelo		     [25+1];
	char	Nro_Ejes	     [4+1];
	char	Carreta 	     [10+1];
	char	Nro_Ejes_1	     [4+1];
	char	Estado		     [50+1];
	char	Fecha_Reg	     [10+1];
	char	Fecha_Exp	     [10+1];

	int		Terminal;
	Console		con;
	Inputs		hKey;

	
	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Placas(PDBPROCESS dbprocess, Console con);
         void Display(void);
   int GetStr(void);
   void Show(void);
   int GetSql(void);
   void Execute(int x);

};
