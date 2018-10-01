#define       DBNTWIN32               // must identify operating system environment
#include "windows.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "window.h"
#include "direct.h"
#include "keyboard.h"




#include <sqlfront.h>
#include <sqldb.h>         // DB-LIB header file (should always be included)
#include "sqlserver.h"

// Forward declarations of the error handler and message handler.
int err_handler(PDBPROCESS, int, int, int, char*, char*);
int msg_handler(PDBPROCESS, DBINT, int, int, char*);


SqlServer::SqlServer()
{

	Init_Db();
}

int err_handler(PDBPROCESS dbproc, int severity, int dberr, int oserr, char * dberrstr, char * oserrstr)
{
	
	if (dberrstr != NULL)
		printf("DB-LIBRARY error:\n\t%s\n", dberrstr);

	if (oserr != DBNOERR)
		printf("Operating-system error:\n\t%s\n", oserrstr);

	if ((dbproc == NULL) || (DBDEAD(dbproc)))
		{
		getch();
		
		return(INT_EXIT);
		}
	else
		{	
		getch();
		
		return(INT_CANCEL);
		}

}

int msg_handler(PDBPROCESS dbproc, DBINT msgno, int msgstate, int severity, char * msgtext)
{
	printf("SQL Server message %ld, state %d, severity %d:\n\t%s\n",
			msgno, msgstate, severity, msgtext);
	return(0);
}

int SqlServer::Init_Db()
{
	
	
	char Path[250]="H:\\enapu\\Enapu.ini";
	char Password[250];
	char ServerName[250];
	char User[250];
	char DataBase[250];
	

   /* Get the current working directory: */
   _getcwd( Path, 256 ) ;
	strcat(Path, "\\Enapu.ini");
	
		
//WritePrivateProfileString( "SqlServer", "Password","sa",Path);

	GetPrivateProfileString( "SqlServer","Password","", Password, 250,Path); 
	GetPrivateProfileString( "SqlServer","ServerName","", ServerName, 250,Path); 
	GetPrivateProfileString( "SqlServer","User","sa", User, 250,Path); 
	GetPrivateProfileString( "SqlServer","DataBase","master", DataBase, 250,Path); 
		

	if (dbinit() == (char *)NULL)
	{
		printf("Communications layer not loaded\n");
		return (1);
	}
	
	// Install the user-supplied error-handling     and message-handling
	// routines. They are defined at the bottom     of this source file.
	
	dberrhandle((DBERRHANDLE_PROC)err_handler);
	

	strcpy(Servername, ServerName); 

	login = dblogin();                     // get login record from DB-LIB
	DBSETLUSER (login, (char *) User);      // set the username

	
	DBSETLAPP (login, (char *) "Enapu"); // set the application name
	
	
	DBSETLPWD (login, (char *) Password);         // set the SQL Server password

	DBSETLVERSION(login,DBVER60);
	

	// Now attempt to create and initialize a DBPROCESS structure
	if ((dbproc     = dbopen (login, Servername)) == NULL)
	{
	
		printf ("dbopen failed\n");
			getch();
		return (1); // exit program
	}

	dbuse (dbproc, (char *) DataBase); // use the "pubs" database
	dbmsghandle((DBMSGHANDLE_PROC)msg_handler);
	//if (!Verifica())
	//
	
	
	return (1);
}

void SqlServer::Close_Db(void )
{
dbexit();

}

int  SqlServer::Verifica( )
{
	char Password[10];
	Inputs kbd;
	Console con;
	kbd.gettext(Password,10);

	if (strlen(Password)>0)
	{
		dbcanquery(dbproc);

		dbcmd (dbproc, (char *)"spportatil 'buscaruser','");
		dbcmd (dbproc, (char *) Password);
		dbcmd (dbproc, (char *)"'");
	
		//dbcmd (dbproc, (char *)"spportatil 'buscara','0508','001-01-3'");
		
		dbsqlexec (dbproc); // send command buffer to SQL server

		
		if ( dbresults(dbproc) ==SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Resp);


		
			if (dbnextrow(dbproc) == NO_MORE_ROWS)
				{
					Window win(10,15,15,45,con);
					win.SetTitle("Mensaje");
					win.Clear();
					win.Show();
					win.Writexy(1,1,"No existe usuario");
					getch();
					win.Close();
					
					return 0;
				}
			else
					return 1;
							
			}
	}	
return 0;
}