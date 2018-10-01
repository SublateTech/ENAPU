#define       DBNTWIN32 	      // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include "Portuario.h"
#include "Window.h"

#include "Kbd.hpp"




// Circle constructor calls base Point constructor first
Terminal_Portuario::Terminal_Portuario(PDBPROCESS dbprocess, Console con)
{
   dbproc=dbprocess;
   hKey.Init(con, dbprocess);
}

int Terminal_Portuario::GetSql(void)
{
		dbcanquery(dbproc);
		//strcpy(Nro_Ticket, "0123456789");
		// construct command buffer to be sent to the SQL server
		dbcmd (dbproc, (char *)"spportatil 'ticketport','");
		dbcmd (dbproc, (char *) Nro_Ticket);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nro_Ticket	 );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Chofer		 );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Placa		 );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Autorizacion);
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Operacion	 );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Balanza 	 );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Reg	 );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Embalaje	 );
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Tot_Peso_Vehiculo);
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Usuario 	 );
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Hora_Reg	 );
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Area		 );

				// now process the rows
				
			if (dbnextrow(dbproc) == NO_MORE_ROWS)
				{
					con.gotoxy( 24, 0);
					con.write("No existe ticket");
					getch();
					return 0;
				  }
				else
					return 1;
		}
return 1;
}

void Terminal_Portuario::Show()
{
   
if (Terminal==1)
{
con.gotoxy( 0 ,0);
//				     1111111111222222222233333333333		
//		   01234567890123456789012345678901234567890
con.writexy(1,1,"Nro. Ticket:\n");                               
con.writexy(2,1,"------------------------------------\n");                               
con.writexy(3,1,"Chof.:          \n");                               
con.writexy(4,1,"Placa:          Embalaje    :  \n");
con.writexy(5,1,"Autor:          Tot.Peso Veh: \n");
con.writexy(6,1,"Opera:          Area        :  \n");
con.writexy(7,1,"Balan:          Usuario     :   \n");     
con.writexy(8,1,"FecRe:          Hora Reg    :      \n");
}
else
{
con.gotoxy( 0 ,0);
//				     1111111111222222222233333333333		
//		   01234567890123456789012345678901234567890
con.writexy(1,1,"Nro. Ticket:\n");                               
con.writexy(2,1,"Chof.:          \n");                               
con.writexy(3,1,"Placa:          ");
con.writexy(4,1,"Embal:  \n");
con.writexy(5,1,"Autor:          ");
con.writexy(6,1,"T.Pes:");
con.writexy(7,1,"Opera:          ");
con.writexy(8,1,"Area :  \n");
con.writexy(9,1,"Balan:          ");
con.writexy(10,1,"Usuar:   \n");     
con.writexy(11,1,"FecRe:          ");
con.writexy(12,1,"H.Reg:      \n");

}

}

void Terminal_Portuario::Display()
{
	if (Terminal== 1)
	{
	con.gotoxy( 1 ,13);  con.write(Nro_Ticket	,"9999999999");
	con.gotoxy( 2 ,7);  con.write(Chofer        ,"AAAAAAAAAA");
	con.gotoxy( 3 ,7);  con.write(Placa         ,"AAAAAAAA");
	con.gotoxy( 4 ,7);  con.write(Autorizacion  ,"9999999999"   );
	con.gotoxy( 5 ,7);  con.write(Operacion     ,"AAA"   );
	con.gotoxy( 6 ,7);  con.write(Balanza       ,"AAAA"   );
	con.gotoxy( 7 ,7);  con.write(Fecha_Reg     ,"9999999999"  );
	
	con.gotoxy( 8 ,7);  con.write(Embalaje     ,"AAA"    );
	con.gotoxy( 9 ,7);  con.write(Tot_Peso_Vehiculo,"999,99");
	con.gotoxy( 10 ,7);	con.write(Area  ,"AAAAAAAAAAAAAAA");
	con.gotoxy( 11 ,7); con.write(Usuario         ,"AAAAAAAAAAA" );
	con.gotoxy( 12 ,7); con.write(Hora_Reg        ,"99999999" );
	}
	else
	{
	con.gotoxy( 1 ,13);  con.write(Nro_Ticket	,"9999999999");
	con.gotoxy( 2  ,7);  con.write(Chofer        ,"AAAAAAAAAA");
	con.gotoxy( 3  ,7);  con.write(Placa         ,"AAAAAAAA");
	con.gotoxy( 4  ,7);  con.write(Autorizacion  ,"9999999999"   );
	con.gotoxy( 5  ,7);  con.write(Operacion     ,"AAA"   );
	con.gotoxy( 6  ,7);  con.write(Balanza       ,"AAAA"   );
	con.gotoxy( 7  ,7);  con.write(Fecha_Reg     ,"9999999999"  );
	con.gotoxy( 8  ,7); con.write(Embalaje     ,"AAA"    );
	con.gotoxy( 9  ,7); con.write(Tot_Peso_Vehiculo,"999,99");
	con.gotoxy( 10 ,7); con.write(Area  ,"AAAAAAAAAAAAAAA");
	con.gotoxy( 11 ,7); con.write(Usuario         ,"AAAAAAAAAAA" );
	con.gotoxy( 12 ,7); con.write(Hora_Reg        ,"99999999" );
	}
	
	return; 				
}

int  Terminal_Portuario::GetStr()
{
		
		int nKOff = 0;	
		//strcpy(BL_Master, "XXXXXXXXXXXXXXXXXXXXXXXXX");
		strcpy(Nro_Ticket, "");
		con.gotoxy( 1, 13);
		con.vm_setcursorstyle(CURSORNORM);
		nKOff = hKey.gettext(Nro_Ticket, sizeof(Nro_Ticket)-1); 
		return nKOff;
  
}



void Terminal_Portuario::Execute(int Term)
{
int ok=FALSE;

Terminal = Term;
con.vm_clrscr();
Window win(1,1,13,50,con);
win.Show();
do {
	win.Clear();
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
win.Close();

return;

}	
