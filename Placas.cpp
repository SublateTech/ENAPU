#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include <dos.h>       // for getch() function
#include "Placas.h"




// Circle constructor calls base Point constructor first
Placas::Placas(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
   hKey.Init(con, dbprocess);
}

int Placas::GetSql(void)
{
		
		dbcanquery(dbproc);
		
		 
		
		dbcmd (dbproc, (char *)"spportatil 'placas', '");
		dbcmd (dbproc, (char *) Placa);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Placa	  );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Agencia   );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Dueno	  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Modelo	  );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nro_Ejes  );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Carreta   );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nro_Ejes_1);
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Estado	  );
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Reg );
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Fecha_Exp );

				// now process the rows
				if (dbnextrow(dbproc) == NO_MORE_ROWS)
				{
					con.gotoxy( 24, 0);
					con.write("No Existe este registro");
					getch();
					return 0;
				  }
				else
						return 1;	
		}
return 1;
}

int  Placas::GetStr()
{
		int nKOff = 0;	
		
		strcpy(Placa, "");
		con.gotoxy( 1, 7);
		con.vm_setcursorstyle(CURSORNORM);
		nKOff = hKey.gettext(Placa, sizeof(Placa)-1); 
		return nKOff;
  
}

void Placas::Show()
{

if (Terminal == 1)
{

con.vm_clrscr();
con.vm_frame(1 , 1 , 50 , 13 , vm_mkcolor( LIGHTGRAY, BLACK), FRAME_SINGLE);
con.gotoxy( 1 ,1);
con.writexy(1,1,"Placa:\n");                               
con.writexy(2,1,"------------------------------------------\n");     
con.writexy(3,1,"Agencia:                              \n");
con.writexy(4,1,"Dueno  :                                  \n");
con.writexy(5,1,"Modelo :                           \n");
con.writexy(6,1,"Carreta:               N.Ejes :            \n");
con.writexy(7,1,"N. Ejes:               Estado : \n");
con.writexy(8,1,"Fec.Reg:               Fec.Exp:\n");
}
else
{
con.vm_clrscr();
//con.vm_frame(1 , 1 , 50 , 13 , vm_mkcolor( LIGHTGRAY, BLACK), FRAME_SINGLE);
con.gotoxy( 1 ,1);
con.writexy(1,1,"Placa:");                               
con.writexy(2,1,"Agencia:");
con.writexy(3,1,"Dueno  :");
con.writexy(4,1,"Modelo :");
con.writexy(5,1,"Carreta:");            
con.writexy(6,1,"N.Ejes :");
con.writexy(7,1,"N. Ejes:");               
con.writexy(8,1,"Estado :");
con.writexy(9,1,"Fec.Reg:");
con.writexy(10,1,"Fec.Exp:");

}
}


void Placas::Display()
{
	
	if (Terminal == 1)
	{
	con.gotoxy( 1 ,7);  con.write(Placa     ,"AAAAAAAA");
	con.gotoxy( 3 ,9);  con.write(Agencia   ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 4 ,9);  con.write(Dueno     ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 5 ,9);  con.write(Modelo    ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 6 ,9);  con.write(Carreta   ,"99");
	con.gotoxy( 6 ,32); con.write(Nro_Ejes  ,"99");
	con.gotoxy( 7 ,9);  con.write(Nro_Ejes_1,"99");
	con.gotoxy( 7 ,32);  con.write(Estado    ,"AAAA");
	con.gotoxy( 8 ,9);  con.write(Fecha_Reg  ,"9999999999");
	con.gotoxy( 8 ,32); con.write(Fecha_Exp  ,"9999999999");
	}
	else
	{
	con.gotoxy( 1 ,7);  con.write(Placa     ,"AAAAAAAA");
	con.gotoxy( 2 ,9);  con.write(Agencia   ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 3 ,9);  con.write(Dueno     ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 4 ,9);  con.write(Modelo    ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 5 ,9);  con.write(Carreta   ,"99");
	con.gotoxy( 6 ,9);  con.write(Nro_Ejes  ,"99");
	con.gotoxy( 7 ,9);  con.write(Nro_Ejes_1,"99");
	con.gotoxy( 8 ,9);  con.write(Estado    ,"AAAA");
	con.gotoxy( 9 ,9);  con.write(Fecha_Reg  ,"9999999999");
	con.gotoxy( 10,9);  con.write(Fecha_Exp  ,"9999999999");
	}
	return; 
}



void Placas::Execute(int Term					 )
{
int ok=FALSE;
Terminal = Term;
do {
	Show();	
	if (GetStr()!= 0)
		{	
	//	do	{
			if (GetSql()!=0)
				{
				Display();
				switch (hKey.getkey()) {
						case K_F1:
//							UpdateSql();
							Show();
							break;
							
												
						case K_ESC:
							ok=TRUE;
							break;
						default:
							continue;
							
								}
				}
			else 
				continue;
	//	} while (!ok);
	} else
		break;

} while (!ok);

return;

}	
