#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include <dos.h>       // for getch() function
#include "Muelles.h"




// Circle constructor calls base Point constructor first
Muelles::Muelles(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
}

void Muelles::GetSql()
{
		dbcanquery(dbproc);
		strcpy(Codigo_de_1, "0123");
		// construct command buffer to be sent to the SQL server

		dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Muelles");
		dbcmd (dbproc, (char *)" where Codigo_de_1= '");
		dbcmd (dbproc, (char *) Codigo_de_1);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Codigo_de_1  );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Descripcion_1);
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Codigo_de_2  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Descripcion_2);
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Codigo_de_3  );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Descripcion  );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Codigo_de_4  );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Descripcion_4);
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Codigo_de_5  );
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Descripcion_5);

				// now process the rows
				dbnextrow(dbproc);

			}

		      else
			{
				con.write ("Results Failed\n");
				getch();

			}
	}


void Muelles::Display()
{
	con.gotoxy( 1, 7);  con.write(Codigo_de_1  );
	con.gotoxy( 2, 7);  con.write(Descripcion_1);
	con.gotoxy( 3, 7);  con.write(Codigo_de_2  );
	con.gotoxy( 4, 7);  con.write(Descripcion_2);
	con.gotoxy( 5, 7);  con.write(Codigo_de_3  );
	con.gotoxy( 6, 7);  con.write(Descripcion  );
	con.gotoxy( 7, 7);  con.write(Codigo_de_4  );
	con.gotoxy( 8, 7);  con.write(Descripcion_4);
	con.gotoxy( 9, 7);  con.write(Codigo_de_5  );
	con.gotoxy( 10, 7); con.write(Descripcion_5);
	return; 
}

void Muelles::Hide()
{
   con.write("Hide");
};

void Muelles::Expand()
{
   con.write("Expand");
};

void Muelles::Show()
{
   //Ubicaci¢n de Contenedores

con.vm_clrscr();
con.gotoxy( 1 ,1);

con.write("Cont.:             Tam.:     Tipo:\n");                               
con.write("Cond.:             Est.:         Tara:\n");
con.write("Prec.:             Peso:                  \n");
con.write("------------------------------------------\n");     
con.write("Manif:             Nave:           \n");
con.write("------------------------------------------\n");
con.write("Area :                     Ubic 1: \n");
con.write("Ubic.:  \n");

};

void Muelles::Execute()
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

   Muelles MyMuelles;
   MyMuelles.Show();
   getch();
   MyMuelles.Hide();

   getch();
   MyMuelles.Expand();
   getch();
   MyMuelles.Contract();
   getch();

   return 0;
}

*/

