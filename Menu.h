#define       DBNTWIN32               // must identify operating system environment
#include "windows.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#include <sqlfront.h>
#include <sqldb.h>         // DB-LIB header file (should always be included)


#include "Enapu.h"

#include "Vanes.h"
#include "Carga.h"
#include "Rodante.h"
#include "Descarga.h"
#include "Embarque.h"
#include "Portuario.h"
#include "Almacena.h"
#include "Muelles.h"
#include "Placas.h"
#include "Chofer.h"
#include "Mensajes.h"
#include "SqlServer.h"
#include "Console.h"
#include "keyboard.h"
#include "Console.h"
#include "Tipo_Contenedores.h"
#include "Condicion_Contenedores.h"
#include "Estado_Contenedores.h"
#include "Equipos_Accesorios.h"
#include "Muelles_Amarradores.h"


class Menu	 {	//: public Point { // derived from class Point
	
	
	SqlServer Sql;
	Console		con;
	Inputs		hKey;
	char Seleccion[3];
	int nKey;
	int Terminal;

	PDBPROCESS dbproc;

	RETCODE    result_code;


public:
   Menu();
   int Exec(int x);
      
};
