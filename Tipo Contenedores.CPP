#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function

#include "Tipo_Contenedores.h"
#include "Window.h"




// Circle constructor calls base Point constructor first
Tipo_Contenedores::Tipo_Contenedores(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
}



void Tipo_Contenedores::Show()
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


void Tipo_Contenedores::Execute(int Term)
{
int nOpcion=0;

Terminal = Term;

if (Terminal == 1)
{
Lista.Init(1,1,12,50,con);
Lista.SetTitle(" Tipo de Contenedores ");
Lista.SetSubTitle("Codigo                  Descripcion");
Lista.SetBorder(FRAME_SINGLE);
}
else
{
Lista.Init(1,1,12,21,con);
Lista.SetTitle(" Tipo de Contenedores ");
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

void Tipo_Contenedores::GetLstSql()
{
		char Cadena[250];

		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"spportatil 'tipo'");
		//dbcmd (dbproc, (char *)"from tab_maes_2 where codigo like '08%'");

		dbsqlexec (dbproc); // send command buffer to SQL server
		while ((result_code = dbresults(dbproc)) != NO_MORE_RESULTS)
		{
			if (result_code == SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) codigo);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) descripcion);
				
				// now process the rows
				
				while (dbnextrow(dbproc) != NO_MORE_ROWS)
				{
					
					if (Terminal == 1)
					{
					Cadena[0]='\0';
					con.strspc(codigo, sizeof(codigo)-1);
					strcat(Cadena, codigo);
					
					con.strspc(Cadena, strlen(Cadena) + 20);

					con.strspc(descripcion, sizeof(descripcion)-1);
					strcat(Cadena, descripcion);
					Lista.AddItem(Cadena,"");
					}
					else
					{
					Cadena[0]='\0';
					con.strspc(codigo, sizeof(codigo)-1);
					strcat(Cadena, codigo);
					
					//con.strspc(Cadena, strlen(Cadena) + 20);

					con.strspc(descripcion, sizeof(descripcion)-1);
					strcat(Cadena, descripcion);
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

