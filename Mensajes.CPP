#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function

#include "Mensajes.h"
#include "Window.h"
#include "Kbd.hpp"





// Circle constructor calls base Point constructor first
Mensajes::Mensajes(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
   hKey.Init(con, dbprocess);
}

void Mensajes::GetSql(char *Opcion)
{
		dbcanquery(dbproc);
		strcpy(Item, Opcion);
		// construct command buffer to be sent to the SQL server

		dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Mensajes");
		dbcmd (dbproc, (char *)" where Item = '");
		dbcmd (dbproc, (char *) Item);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Item		  );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Prioridad_Mensaje );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Detalle 	  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Usuario 	  );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Reg	  );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Hora		  );

				// now process the rows
				dbnextrow(dbproc);


			}

		      else
			{
				con.write ("Results Failed\n");
				getch();

			}
	}


void Mensajes::Show()
{
Window Win(6,6,18,56,con);

//Win.Init(6,6,18,56,con);

Win.Show();

//con.vm_clrscr();
//con.vm_gotoxy( 1,1);

//				 11111111112222222222333333333334		
//		12345678901234567890123456789012345678901

Win.Writexy(1,4,"   Servicio a sido atendido: SI/NO");                               
Win.Writexy(4,4,"Nro. Atencion   Autorizacion  Contenedor  ");
Win.Writexy(7,4,"  Fecha Reg.:           Hora Reg.:");

//Win.Writexy(5, 10, Nro_Atencion);
//Win.Writexy(5, 20, Autorizacion);
//Win.Writexy(5, 32, Contenedor  );

getch();
Win.Close();
}

void Mensajes::Display()
{
//	con.gotoxy( 6 , 4);  con.write(Nro_Atencion);
//	con.gotoxy( 6 ,19);  con.write(Autorizacion);
//	con.gotoxy( 6 ,33);  con.write(Contenedor  );
	
	return;
}

void Mensajes::Execute()
{
int nOpcion=0;

Lista.Init(1,1,12,50,con);
Lista.SetTitle(" Descarga Contenedores ");
Lista.SetSubTitle("NroAtenc. Autorizacion Contenedor Ubicacion");
con.vm_clrscr();
GetLstSql();
Lista.Show();
do {
	nOpcion = Lista.Display();
	if (Lista.LastKey != K_ESC)
		{
		///strcpy(Nro_Atencion, Lista.menudata[nOpcion-1].cmd);
		GetSql(Lista.menudata[nOpcion-1].cmd);
		Show();
		//Display();
		}
	
}while(nOpcion!=0);

Lista.Finish();
return;
}

void Mensajes::GetLstSql()
{
		char Cadena[250];

		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Mensajes");

		dbsqlexec (dbproc); // send command buffer to SQL server
		while ((result_code = dbresults(dbproc)) != NO_MORE_RESULTS)
		{
			if (result_code == SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Item		  );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Prioridad_Mensaje );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Detalle 	  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Usuario 	  );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Reg	  );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Hora		  );

	
				// now process the rows
				
				while (dbnextrow(dbproc) != NO_MORE_ROWS)
				{
					Cadena[0]='\0';
					memset(Cadena, 0, 250);
					con.strspc(Item, sizeof(Item)-1);
					strcat(Cadena, Item);
					
					strcat(Cadena, "        ");
					con.strspc(Prioridad_Mensaje, sizeof(Prioridad_Mensaje)-1);
					strcat(Cadena, Prioridad_Mensaje);
					
					strcat(Cadena, "   ");
					con.strspc(Usuario, sizeof(Usuario)-1);
					strcat(Cadena, Usuario);
					strcat(Cadena, " ");
					con.strspc(Usuario, sizeof(Usuario)-1);
					strcat(Cadena, Usuario);

				
					Lista.AddItem(Cadena,Item);
				}
			}
			else
			{
				con.write ("Results Failed\n");
				break;
			}
		}


}

