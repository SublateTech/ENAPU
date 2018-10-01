#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function

#include "Muelles_Amarradores.h"
#include "Window.h"




// Circle constructor calls base Point constructor first
	Muelles_Amarradores::Muelles_Amarradores(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
}



void Muelles_Amarradores::Show()
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


void Muelles_Amarradores::Execute()
{

Lista.Init(1,1,12,30,con);
Lista.SetTitle(" Muelles y Amarradores ");
Lista.SetSubTitle("Muelles  Amarrador");
Lista.SetBorder(FRAME_SINGLE);

con.vm_attrib(vm_mkcolor(LIGHTGRAY,BLACK));
con.vm_clrscr();
GetLstSql();
Lista.Show();
Lista.Display();
Lista.Finish();

return;
}

void Muelles_Amarradores::GetLstSql()
{
		char Cadena[250];

		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"spportatil 'muelles'");
		//dbcmd (dbproc, (char *)"from tab_muelle_amar");

		dbsqlexec (dbproc); // send command buffer to SQL server
		while ((result_code = dbresults(dbproc)) != NO_MORE_RESULTS)
		{
			if (result_code == SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) cod_mue);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) cod_ama);
				
				// now process the rows
				
				while (dbnextrow(dbproc) != NO_MORE_ROWS)
				{
					Cadena[0]='\0';
					strcpy(Cadena, cod_mue);
					strcat(Cadena, "        ");
					strcat(Cadena, cod_ama);
					Lista.AddItem(Cadena,"");
				}
			}
			else
			{
				con.write ("Results Failed\n");
				break;
			}
		}


}

