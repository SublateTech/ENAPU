#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include <dos.h>       // for getch() function
#include "T_Almac.h"




// Circle constructor calls base Point constructor first
Almacena::Almacena(PDBPROCESS dbprocess)
{
   dbproc=dbprocess;
};

void Almacena::GetSql()
{
		dbcanquery(dbproc);
		strcpy(Nro_Ticket, "0123456789");
		// construct command buffer to be sent to the SQL server

		dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Almacenamiento");
		dbcmd (dbproc, (char *)" where Nro_Ticket = '");
		dbcmd (dbproc, (char *) Nro_Ticket);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) );
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) );
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) );
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) );

				// now process the rows
				dbnextrow(dbproc);

			}

		      else
			{
				con.write ("Results Failed\n");
				getch();

			}
	}


void Almacena::Display()
{
	con.gotoxy( 1 7");  con.write();
	con.gotoxy( 2 7");  con.write();
	con.gotoxy( 3 7");  con.write();
	con.gotoxy( 4 7");  con.write();
	con.gotoxy( 5 7");  con.write();
	con.gotoxy( 6 7");  con.write();
	con.gotoxy( 7 7");  con.write();
	con.gotoxy( 8 7");  con.write();
	con.gotoxy( 9 7");  con.write();
	con.gotoxy( 10 7"); con.write();
	con.gotoxy( 11 7"); con.write();
	con.gotoxy( 12 7"); con.write();
	return; 		
}

void Almacena::Hide()
{
   con.write("Hide");
};

void Almacena::Expand()
{
   con.write("Expand");
};

void Almacena::Show()
{
   //Ubicaci¢n de Contenedores

con.vm_clrscr();
con.gotoxy( 1 1");

con.write("Cont.:             Tam.:     Tipo:\n");                               
con.write("Cond.:             Est.:         Tara:\n");
con.write("Prec.:             Peso:                  \n");
con.write("------------------------------------------\n");     
con.write("Manif:             Nave:           \n");
con.write("------------------------------------------\n");
con.write("Area :                     Ubic 1: \n");
con.write("Ubic.:  \n");

};

void Almacena::Execute()
{
GetSql();
Show();
Display();
getch();
return;
}



/*main()			// test the functions
{
   // initialize the graphics system

   Almacena MyAlmacena;
   MyAlmacena.Show();
   getch();
   MyAlmacena.Hide();

   getch();
   MyAlmacena.Expand();
   getch();
   MyAlmacena.Contract();
   getch();

   return 0;
}

*/

