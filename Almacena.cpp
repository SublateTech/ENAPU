#define       DBNTWIN32 	      // must identify operating system environment
#include "Afx.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include "Almacena.h"
#include "window.h"
#include "Kbd.hpp"




// Circle constructor calls base Point constructor first
Terminal_Almacenamiento::Terminal_Almacenamiento(PDBPROCESS dbprocess, Console con)
{
   
	dbproc=dbprocess;
	hKey.Init(con, dbprocess);
}

int  Terminal_Almacenamiento::GetStr()
{
		
		int nKOff = 0;	
		//strcpy(BL_Master, "XXXXXXXXXXXXXXXXXXXXXXXXX");
		strcpy(Nro_Ticket, "");
		con.gotoxy( 1, 13);
		nKOff = hKey.gettext(Nro_Ticket, sizeof(Nro_Ticket)-1); 
		return nKOff;
  
}

int Terminal_Almacenamiento::GetSql(void)
{

//		strcpy(Nro_Ticket, "0123456789");

		
		dbcanquery(dbproc);
		
		dbcmd (dbproc, (char *)"spportatil 'ticketalma','");
		dbcmd (dbproc, (char *) Nro_Ticket);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); 

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{

				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nro_Ticket);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Contenedor);
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Precinto  );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Tara	  );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Condicion );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Balanza   );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Fecha_Reg );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Tamano	  );
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Tipo	  );
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Peso	  );
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Estado	  );
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Pesador   );
				dbbind (dbproc, 13, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Hora_Reg  );
											
				
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


void Terminal_Almacenamiento::Show()
{
   
if (Terminal == 1)
{

con.gotoxy( 0 ,0);
//				  1111111111222222222233333333333		
//		01234567890123456789012345678901234567890
con.writexy(1,1,"Nro. Ticket:\n");                               
con.writexy(2,1,"------------------------------------\n");                               
con.writexy(3,1,"Cont.:                Tama:          \n");                               
con.writexy(4,1,"Prec.:                            Tipo:\n");
con.writexy(5,1,"Tara :                Peso:          \n");
con.writexy(6,1,"Cond.:                Estado:          \n");
con.writexy(7,1,"Balan:                Pesador:       \n");     
con.writexy(8,1,"Fec.Reg:              Hora Reg:      \n");

}
else
{
	con.gotoxy( 0 ,0);
//				  1111111111222222222233333333333		
//		01234567890123456789012345678901234567890
con.writexy(1,1, "Nro. Ticket:");                               
con.writexy(2,1, "Cont.:        ");         
con.writexy(3,1, "Tama :        ");                               
con.writexy(4,1, "Prec.: ");                                                        
con.writexy(5,1, "Tipo :");
con.writexy(6,1, "Tara :  ");                                 
con.writexy(7,1, "Peso :        ");
con.writexy(8,1, "Cond.:      ");
con.writexy(9,1, "Estad:      ");
con.writexy(10,1,"Balan:    ");            
con.writexy(11,1,"Pesad:    ");     
con.writexy(12,1,"F.Reg: ");             
con.writexy(13,1,"H.Reg:   ");
}

}

void Terminal_Almacenamiento::Display()
{
	 
	if (Terminal == 1)
	{
	con.gotoxy( 1 , 13);  con.write(Nro_Ticket,"9999999999");
	
	 con.gotoxy( 3 , 7);  con.write(Contenedor,"AAAAAAAAAAAAA");
	 con.gotoxy( 3 , 28); con.write(Tamano    ,"AA");
	
	
	 con.gotoxy( 4,  7);  con.write(Precinto  ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	 con.gotoxy( 4, 40);  con.write(Tipo      ,"AA");
	
	 con.gotoxy( 5 , 7 ); con.write(Tara      ,"9,999");
	 con.gotoxy( 5  ,28); con.write(Peso      ,"9999999");

	 con.gotoxy( 6,  7);  con.write(Condicion ,"AAA");
	 con.gotoxy( 6, 30);  con.write(Estado    ,"AAA");
	
	 con.gotoxy( 7,  7);  con.write(Balanza   ,"AAAA");
	 con.gotoxy( 7, 31);  con.write(Pesador   ,"AAAAAAAAAAAAA");

	 con.gotoxy( 8,  9 ); con.write(Fecha_Reg ,"9999999999");
	 con.gotoxy( 8,  32); con.write(Hora_Reg  ,"99999999");
	}
	else
	{
	con.gotoxy( 1 , 13);  con.write(Nro_Ticket,"9999999999");
	
	 con.gotoxy( 2 , 7);  con.write(Contenedor,"AAAAAAAAAAAAA");
	 con.gotoxy( 3 , 7); con.write(Tamano    ,"AA");
	 con.gotoxy( 4,  7);  con.write(Precinto  ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	 con.gotoxy( 5,  7);  con.write(Tipo      ,"AA");
	 con.gotoxy( 6 , 7 ); con.write(Tara      ,"9,999");
	 con.gotoxy( 7  ,7); con.write(Peso      ,"9999999");
	 con.gotoxy( 8,  7);  con.write(Condicion ,"AAA");
	 con.gotoxy( 9, 7);  con.write(Estado    ,"AAA");
	 con.gotoxy( 10,  7);  con.write(Balanza   ,"AAAA");
	 con.gotoxy( 11, 7);  con.write(Pesador   ,"AAAAAAAAAAAAA");
	 con.gotoxy( 12,  7 ); con.write(Fecha_Reg ,"9999999999");
	 con.gotoxy( 13,  7); con.write(Hora_Reg  ,"99999999");
	
	}

	return; 		
}

void Terminal_Almacenamiento::Execute(int Term)
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
							UpdateSql();
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

void Terminal_Almacenamiento::UpdateSql()
{
    
		
	con.vm_attrib(FOREGROUND_INTENSITY);
	con.writexy(7, 20, "Nueva Ubicacion:");
	con.vm_attrib((char) BACKGROUND_INTENSITY);
	//hKey.gettext(Ubicacion, sizeof(Ubicacion)-1); 
	
	con.vm_attrib(FOREGROUND_INTENSITY);


	dbcanquery(dbproc);

	/*CString Cmd("");
	Cmd+="Update Ubicacion_Carga set Ubicacion = '";
	Cmd+= Ubicacion;
	Cmd+= "' where BL_Master = '";
	Cmd+= BL_Master;
	Cmd+="'";
	*/
	
	
//	dbcmd (dbproc, Cmd);

	dbsqlexec (dbproc); // send command buffer to SQL server

	// now check the results from the SQL server
	if ( dbresults(dbproc) ==SUCCEED) {
		con.writexy(24,0, "						");
		con.writexy(24,0, "Ok.					");
	
		}
	else
		con.writexy(24,0, "BAD					");
	
}
