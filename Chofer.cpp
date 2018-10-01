#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include <dos.h>       // for getch() function
#include "Chofer.h"




// Circle constructor calls base Point constructor first
Chofer::Chofer(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
   hKey.Init(con, dbprocess);
}

int Chofer::GetSql(void)
{
		dbcanquery(dbproc);
		//strcpy(Licencia, "0123456789");
		// construct command buffer to be sent to the SQL server
		dbcmd (dbproc, (char *)"spportatil 'licencia', '");
		/*dbcmd (dbproc, (char *)"select * ");
		dbcmd (dbproc, (char *)"from Chofer");
		dbcmd (dbproc, (char *)" where Licencia = '");*/
		dbcmd (dbproc, (char *) Licencia);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Licencia );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Agencia  );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Apellido );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) LE_DNI	 );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nombre	 );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) LM	 );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Estado	 );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Reg);
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Exp);

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
void Chofer::Show()
{

if (Terminal==1)
{
con.vm_clrscr();
con.vm_frame(1 , 1 , 50 , 13 , vm_mkcolor( LIGHTGRAY, BLACK), FRAME_SINGLE);
con.gotoxy( 0 ,0);

//				     1111111111222222222233333333333		
//		   01234567890123456789012345678901234567890
con.writexy(1,1,"Licencia:\n");                               
con.writexy(2,1,"------------------------------------------\n");     
con.writexy(3,1,"Agencia:                              \n");
con.writexy(4,1,"Apellid:                                  \n");
con.writexy(5,1,"Nombre :                           \n");
con.writexy(6,1,"LE/DNI :               LM     :            \n");
con.writexy(7,1,"                       Estado : \n");
con.writexy(8,1,"Fec.Reg:               Fec.Exp:\n");

}
else
{
con.vm_clrscr();
con.vm_frame(1 , 1 , 50 , 13 , vm_mkcolor( LIGHTGRAY, BLACK), FRAME_SINGLE);
con.gotoxy( 0 ,0);

//				     1111111111222222222233333333333		
//		   01234567890123456789012345678901234567890
con.writexy(1,1,"Licencia:\n");                               
con.writexy(2,1,"Agencia:");
con.writexy(3,1,"Apellid:");
con.writexy(4,1,"Nombre :");
con.writexy(5,1,"LE/DNI :");               
con.writexy(6,1,"LM     :");
con.writexy(7,1,"Estado :");
con.writexy(8,1,"Fec.Reg:");            
con.writexy(9,1,"Fec.Exp:");
}
}
void Chofer::Display()
{
	if (Terminal == 1)
	{
	
	con.gotoxy( 1, 10);  con.write(Licencia ,"AAAAAAAA");
	con.gotoxy( 3, 9);  con.write(Agencia  ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 4, 9);  con.write(Apellido ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 5, 9);  con.write(Nombre   ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 6, 9);  con.write(LE_DNI   ,"99999999");
	con.gotoxy( 6, 32);  con.write(LM      ,"99999999");
	con.gotoxy( 7, 32);  con.write(Estado  ,"AAAA");
	con.gotoxy( 8, 9);  con.write(Fecha_Reg, "9999999999");
	con.gotoxy( 8, 32);  con.write(Fecha_Exp,"9999999999");
	}
	else
	{
	con.gotoxy( 1, 10);  con.write(Licencia ,"AAAAAAAA");
	con.gotoxy( 2, 9);  con.write(Agencia  ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 3, 9);  con.write(Apellido ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 4, 9);  con.write(Nombre   ,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 5, 9);  con.write(LE_DNI   ,"99999999");
	con.gotoxy( 6, 9);  con.write(LM      ,"99999999");
	con.gotoxy( 7, 9);  con.write(Estado  ,"AAAA");
	con.gotoxy( 8, 9);  con.write(Fecha_Reg, "9999999999");
	con.gotoxy( 9, 9);  con.write(Fecha_Exp,"9999999999");
	}

	return; 
}

int  Chofer::GetStr()
{
		int nKOff = 0;	
		
		strcpy(Licencia, "");
		con.gotoxy( 1, 10);
		nKOff = hKey.gettext(Licencia, sizeof(Licencia)-1); 
		return nKOff;
  
}



void Chofer::Execute(int Term)
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

