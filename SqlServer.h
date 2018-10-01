#define       DBNTWIN32               // must identify operating system environment
#include "windows.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "console.h"


#include <sqlfront.h>
#include <sqldb.h>         // DB-LIB header file (should always be included)


class SqlServer	 {	
	
	PLOGINREC	login;   // allocate a DB-LIB login structure
	char		Servername[25];
	char          Resp[20];		
	
public:
	PDBPROCESS	dbproc;  // allocate a DB-LIB process structure
   		
	SqlServer();
		
	int Init_Db();    
	void Close_Db(void );
	int  Verifica( void);
	
};


