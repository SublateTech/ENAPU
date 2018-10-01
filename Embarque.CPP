#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function

#include "Embarque.h"
#include "Window.h"
#include "Kbd.hpp"




// Circle constructor calls base Point constructor first
Embarque_Contenedores::Embarque_Contenedores(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
}

void Embarque_Contenedores::GetSql(char *Opcion)
{
		dbcanquery(dbproc);
		strcpy(Nro_Atencion, Opcion);
		// construct command buffer to be sent to the SQL server

		dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Embarque");
		dbcmd (dbproc, (char *)" where Nro_Atencion = '");
		dbcmd (dbproc, (char *) Nro_Atencion);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nro_Atencion);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Autorizacion);
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Contenedor  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Ubicacion   );


				// now process the rows
				dbnextrow(dbproc);

			}

		      else
			{
				con.write ("Results Failed\n");
				getch();

			}
	}



void Embarque_Contenedores::Show()
{

Window Win;

Win.Init(6,6,18,56,con);

Win.Show();

//con.vm_clrscr();
//con.vm_gotoxy( 1,1);

//				 11111111112222222222333333333334		
//		12345678901234567890123456789012345678901

Win.Writexy(1,4,"   Servicio a sido atendido: SI/NO");                               
Win.Writexy(4,4,"Nro. Atencion   Autorizacion  Contenedor  ");
Win.Writexy(7,4,"  Fecha Reg.:           Hora Reg.:");

Win.Writexy(5, 10, Nro_Atencion);
Win.Writexy(5, 20, Autorizacion);
Win.Writexy(5, 32, Contenedor  );

getch();
Win.Close();

}

void Embarque_Contenedores::Display()
{
	con.gotoxy( 3, 8);  con.write(Ubicacion   );
	con.gotoxy( 6 , 4);  con.write(Nro_Atencion);
	con.gotoxy( 6 ,19);  con.write(Autorizacion);
	con.gotoxy( 6 ,33);  con.write(Contenedor  );
	
	return;
}

void Embarque_Contenedores::Execute()
{
int nOpcion=0;

Lista.Init(1,1,12,50,con);
Lista.SetSubTitle("NroAtenc Autorizacion Contenedor Ubicacion");
Lista.SetTitle("Embarque de Contenedores");
Lista.SetBorder(FRAME_SINGLE);
Lista.SetBarMsg("F1=Atiende tarea realizada");
con.vm_clrscr();
GetLstSql();
Lista.Show();
do {
	nOpcion = Lista.Display();
	
	if (Lista.LastKey != K_ESC)
		{
		strcpy(Nro_Atencion, Lista.menudata[nOpcion-1].cmd);
		GetSql(Nro_Atencion);
		Show();
		}
	
}while(nOpcion!=0);Lista.Finish();

return;
}

void Embarque_Contenedores::GetLstSql()
{
		char Cadena[250];
		char Format[250];

		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Embarque");

		dbsqlexec (dbproc); // send command buffer to SQL server
		while ((result_code = dbresults(dbproc)) != NO_MORE_RESULTS)
		{
			if (result_code == SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nro_Atencion);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Autorizacion);
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Contenedor  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Ubicacion   );
	
				// now process the rows
				
				while (dbnextrow(dbproc) != NO_MORE_ROWS)
				{
					memset(Format,0,250);
					memset(Cadena,0,250);
					con.rgtjst(Nro_Atencion, sizeof(Nro_Atencion)-1);
					strcat(Cadena, Nro_Atencion);
					strcat(Cadena, "  ");
					con.rgtjst(Autorizacion, sizeof(Autorizacion)-1);
					strcat(Cadena, Autorizacion);
					strcat(Cadena, "  ");
					con.rgtjst(Contenedor, sizeof(Contenedor)-1);
					strcat(Cadena, Contenedor);
					strcat(Cadena, "  ");
					con.rgtjst(Ubicacion, sizeof(Ubicacion)-1);
					
					strcat(Cadena, con.format(Ubicacion, "9999999-99-9"));


					//printf(Cadena);
					//getch();
					
					Lista.AddItem(Cadena,Nro_Atencion);
				}
			}
			else
			{
				con.write ("Results Failed\n");
				break;
			}
		}


}

