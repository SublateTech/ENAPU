#define       DBNTWIN32 	      // must identify operating system environment

#include "Afx.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include "Rodante.h"
#include "Keyboard.h"
#include "Kbd.hpp"
#include "Window.h"



// Circle constructor calls base Point constructor first
Carga_Rodante::Carga_Rodante(PDBPROCESS dbprocess, Console consola)
{
   dbproc=dbprocess;
   con = consola;
   hKey.Init(con, dbproc);
}

int Carga_Rodante::GetSql(void)
{
		dbcanquery(dbproc);
		//strcpy(BL_Master, "YYYYYYYYYYYYYYYYYYYYYYYYY");
		// construct command buffer to be sent to the SQL server

		
		dbcmd (dbproc, (char *)"spportatil 'buscarvehi','");
		dbcmd (dbproc, (char *) Chasis);
		dbcmd (dbproc, (char *)"'");
		

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)

		{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) BL_Master   );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) BL_Hijo     );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Total_Bultos);
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Total_Peso  );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Chasis	    );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Modelo	    );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Manifiesto  );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nave	    );
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Area	    );
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Ubicacion   );
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Nueva_Ubic  );
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) nArea  );
					
			
				if (dbnextrow(dbproc) == NO_MORE_ROWS)
					{
						con.gotoxy( 24, 0);
						con.write("No Existe este registro");
						con.vm_getch();
						return 0;
					}
				else
					return 1;
		}

return 0;			
}


void Carga_Rodante::Show()
{
   //Ubicaci¢n de Contenedores

//con.cls();
//con.vm_frame(1 , 1 , 50 , 13 , vm_mkcolor( LIGHTGRAY, BLACK), FRAME_SINGLE);

//				 11111111112222222222333333333334		
		     //	12345678901234567890123456789012345678901
if (Terminal == 1)
{
con.writexy(1,1,"B/L Mast:                          Total Bultos");                               
con.writexy(2,1,"B/L Hijo:");
con.writexy(3,1,"Chasis	:                          Total Peso");
con.writexy(4,1,"Modelo	:\n");
con.writexy(5,1,"-----------------------------------------------");     
con.writexy(6,1,"Manifies:               Nave:           \n");
con.writexy(7,1,"Area:        \n");
con.writexy(8,1,"Ubic:  \n");
}
else
{
con.writexy(1,1,"B/L Mast:" );                         
con.writexy(2,1,"T.Bultos:");                               
con.writexy(3,1,"B/L Hijo:");
con.writexy(4,1,"Chasis	:");                         
con.writexy(5,1,"T.Peso  :");
con.writexy(6,1,"Modelo  :");
con.writexy(7,1,"Manifies:");               
con.writexy(8,1,"Nave    :");
con.writexy(9,1,"Area    :");
con.writexy(10,1,"Ubic   :");
}

}

void Carga_Rodante::Display()
{
if (Terminal == 1)
{

	con.gotoxy(1,10);  con.write(BL_Master   ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(2,11);  con.write(BL_Hijo     ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(3,38);  con.write(Total_Bultos,"9999999");
	con.gotoxy(3,10);  con.write(Chasis      ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(4,38);  con.write(Total_Peso  ,"9999999");
	con.gotoxy(4,10);  con.write(Modelo      ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(6,10);  con.write(Manifiesto  ,"999999999");
	
	ScrllH.Init(6,30,30+15,Nave,con); 
	ScrllH.Show();

	con.gotoxy(7,6);   con.write(Area        ,"AAAAAAAAAAAAAAAA");
	con.gotoxy(8,6);   con.write(Ubicacion   ,"AA");
	
}
else
{
	con.gotoxy(1,10);  con.write(BL_Master   ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(2,10);  con.write(BL_Hijo     ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(3,10);  con.write(Total_Bultos,"9999999");
	con.gotoxy(4,10);  con.write(Chasis      ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(5,10);  con.write(Total_Peso  ,"9999999");
	con.gotoxy(6,10);  con.write(Modelo      ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy(7,10);  con.write(Manifiesto  ,"999999999");
	
	ScrllH.Init(8,10,10+15,Nave,con); 
	ScrllH.Show();

	con.gotoxy(9,10);   con.write(Area        ,"AAAAAAAAAAAAAAAA");
	con.gotoxy(10,10);   con.write(Ubicacion   ,"AA");
	
}

	return;
}

void Carga_Rodante::Execute(int Term)
{
int ok=FALSE;

Terminal = Term;
con.vm_clrscr();
Window win(1,1,16,50,con);
win.SetBarMsg("F1=Actualiza");
win.Show();

do {
	win.Clear();
	Show();	
	ok=FALSE;
	if (GetStr()!= 0)
	   if (GetSql()!=0)
			{
			Display();
			do {
				
				switch (hKey.getkey()) {
						case K_F1:
							UpdateSql();
							Show();
							Display();
							break;

						case K_RIGHT:
							ScrllH.Right();
							break;
							
						case  K_LEFT:
							ScrllH.Left();
							break;
							
						case  K_F2:
							//ShowMarcaNumero();
							Show();
							Display();
							break;
						
						case  K_F3:
							//ShowProducto();
							Show();
							Display();
							break;
							
						case K_ESC:
							ok=TRUE	;
							break;
						case K_ENTER:
							ok=TRUE	;
							break;
							
					}
			}while(!ok);
		}
		else
			continue;
	else
		break;

} while (1 );

win.Close();
}

void Carga_Rodante::UpdateSql()
{
    
	memset(ubi_1,0,sizeof(ubi_1)-1);
		

	con.vm_attrib(BACKGROUND_INTENSITY);
	
	if (Terminal ==1 )
	con.gotoxy( 8, 11);
	else
	con.gotoxy( 10, 10);
	hKey.gettext(ubi_1, sizeof(ubi_1)-1); 
	
		
	con.vm_attrib(FOREGROUND_INTENSITY);

	
	if (Verifica())
		return;
	
	
	int nKOff = 0;	
	Window win(10,15,15,45,con);	
	win.Clear();
	win.Show();
	
	win.Writexy(1,1,"Confirma actualizacion? S/N");
	
	do 	{
		nKOff=hKey.getkey();
		
	} while (nKOff!=115 && nKOff!=83 && nKOff!=78 && nKOff!=110); 
	
	
	if (nKOff == 115 || nKOff==83) // Si
		{
		win.Clear();
		if (IfUpdated())
			win.Writexy(1,4,"Actualizacion OK");
		else
			win.Writexy(1,4,"Actualizacion Errada");
		
		}	
	win.Close();

}
int  Carga_Rodante::GetStr()
{
		
		int nKOff = 0;	
		strcpy(Chasis, "");
		if (Terminal == 1)
			con.gotoxy( 3, 10);
		else
			con.gotoxy( 3, 10);
		con.vm_setcursorstyle(CURSORNORM);
		nKOff = hKey.gettext(Chasis, 25); 
		return nKOff;
  
}

int Carga_Rodante::IfUpdated()
{
		dbcanquery(dbproc);
		
		dbcmd (dbproc, (char *)"spportatil 'reubivehi','");
		dbcmd (dbproc, (char *) Chasis);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) Manifiesto);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) nArea);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) ubi_1);
		dbcmd (dbproc, (char *)"'");

		//printf("%s,%s,%s,%s", BL_Master, BL_Hijo, nArea, ubi_1);
		//getch();

		dbsqlexec (dbproc); // send command buffer to SQL server

		
		if ( dbresults(dbproc) ==SUCCEED)
			{
				
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Resp);
		
			if (dbnextrow(dbproc) == NO_MORE_ROWS)
				{
					con.gotoxy( 24, 0);
					con.write("No hay respuesta");
					return 0;
				}
			else
				return strcmp(Resp,"si");
				
							
			}
return 0;
}

int Carga_Rodante::Verifica(void)
{
		
		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"spportatil 'buscarav','");
		dbcmd (dbproc, (char *) nArea);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) ubi_1);
		dbcmd (dbproc, (char *)"'");

		
	//	dbcmd (dbproc, (char *)"spportatil 'buscarm','0508','001-01-3'");
		
		dbsqlexec (dbproc); // send command buffer to SQL server

		
		if ( dbresults(dbproc) ==SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Resp);
		
			if (dbnextrow(dbproc) == NO_MORE_ROWS)
				{
					Window win(10,15,15,45,con);
					win.SetTitle("Mensaje");
					win.Clear();
					win.Show();
					win.Writexy(1,1,"No existe ubicacion");
					getch();
					win.Close();
					
					return 1;
				}
			else
				{	
					
				return 0;
				
							
			}
		}
return 0;
}