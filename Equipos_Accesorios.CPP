#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function

#include "Equipos_Accesorios.h"
#include "Window.h"




// Circle constructor calls base Point constructor first
	Equipos_Accesorios::Equipos_Accesorios(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
}



void Equipos_Accesorios::Show()
{


Window Win;

Win.Init(6,6,18,56,con);

Win.Show();

//con.vm_clrscr();
//con.vm_gotoxy( 1,1);

//				 11111111112222222222333333333334		
//		12345678901234567890123456789012345678901

con.vm_puts(7,7,"Servicio a sido atendido: SI/NO");                               
con.vm_puts(7,9,"Nro. Atencion   Autorización  Contenedor  ");
con.vm_puts(7,13,"Fecha Reg.:           Hora Reg.:");

getch();
Win.Close();

}


void Equipos_Accesorios::Execute(int Term)
{
Terminal = Term;

if (Terminal == 1)
{
Lista.Init(1,1,12,50,con);
Lista.SetTitle(" Equipos y Accesorios ");
Lista.SetSubTitle("Codigo                  Descripcion");
Lista.SetBorder(FRAME_SINGLE);
}
else
{
Lista.Init(1,1,12,21,con);
Lista.SetTitle(" Equipos y Accesorios ");
Lista.SetSubTitle("Cod Descripcion");
Lista.SetBorder(FRAME_SINGLE);
}

con.vm_attrib(vm_mkcolor(LIGHTGRAY,BLACK));
con.vm_clrscr();
GetLstSql();
Lista.Show();
Lista.Display();
Lista.Finish();

return;
}

void Equipos_Accesorios::GetLstSql()
{
		char Cadena[250];

		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"spportatil 'equipoacc'");
		//dbcmd (dbproc, (char *)"select cod_equ, des_equ ");
		//dbcmd (dbproc, (char *)"from tab_equipos");

		dbsqlexec (dbproc); // send command buffer to SQL server
		while ((result_code = dbresults(dbproc)) != NO_MORE_RESULTS)
		{
			if (result_code == SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) cod_equ);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) des_equ);
				
				// now process the rows
				
				while (dbnextrow(dbproc) != NO_MORE_ROWS)
				{
					if (Terminal == 1)
					{
					Cadena[0]='\0';
					con.strspc(cod_equ, sizeof(cod_equ)-1);
					strcat(Cadena, cod_equ);
					
					con.strspc(Cadena, strlen(Cadena) + 20);

					con.strspc(des_equ, sizeof(des_equ)-1);
					strcat(Cadena, des_equ);
					Lista.AddItem(Cadena,"");
					}
					else
					{
					Cadena[0]='\0';
					con.strspc(cod_equ, sizeof(cod_equ)-1);
					strcat(Cadena, cod_equ);
					
					//con.strspc(Cadena, strlen(Cadena) + 20);

					con.strspc(des_equ, sizeof(des_equ)-1);
					strcat(Cadena, des_equ);
					Lista.AddItem(Cadena,"");
					}

				}
			}
			else
			{
				con.write ("Results Failed\n");
				break;
			}
		}


}

