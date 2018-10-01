#define       DBNTWIN32               // must identify operating system environment
#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>         // DB-LIB header file (should always be included)


#include <stdio.h>       
#include <conio.h>       

#include "Vanes.h"
#include "kbd.hpp"
#include "Window.h"


Ubicacion_Vanes::Ubicacion_Vanes(PDBPROCESS dbprocess, Console consola) 
{
    con = consola;
	dbproc=dbprocess;
	hKey.Init(consola, dbprocess);
   
}

int Ubicacion_Vanes::IfUpdated()
{
		dbcanquery(dbproc);
		
		dbcmd (dbproc, (char *)"spportatil 'reubicont','");
		dbcmd (dbproc, (char *) contenedor);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) ubi_1);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) ubi_2);
		dbcmd (dbproc, (char *)"'");

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


int Ubicacion_Vanes::Verifica()
{
		dbcanquery(dbproc);

		dbcmd (dbproc, (char *)"spportatil 'buscara','");
		dbcmd (dbproc, (char *) nArea);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) ubi_1);
		dbcmd (dbproc, (char *)"'");
	
		//dbcmd (dbproc, (char *)"spportatil 'buscara','0508','001-01-3'");
		
		dbsqlexec (dbproc); // send command buffer to SQL server

		
		if ( dbresults(dbproc) ==SUCCEED)
			{
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Resp);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Existe);

		
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
				
				if (strlen(Existe) == 13)
					{
					Window win(10,15,15,45,con);
					win.SetTitle("Mensaje");
					win.Clear();
					win.Show();
					win.Writexy(1,1,"Ubicacion ocupada");
					getch();
					win.Close();
					return 1;
					}

				if (strlen(Resp)>2)
					{					
					return 0;
					}
							
			}
		}
return 0;
}

int Ubicacion_Vanes::GetSql()
{
		

	do {
		dbcanquery(dbproc);
		
			
		// construct comman7d buffer to be sent to the SQL server
		
		dbcmd (dbproc, (char *)"spportatil 'buscarcont','");
		dbcmd (dbproc, (char *) contenedor);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		if ( dbresults(dbproc) ==SUCCEED)
		
		{
						
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)contenedor);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)condicion);
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)precinto);
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)tamano);
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)tipo);
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)estado);
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)tara);
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)peso);
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)nave);
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)manifiesto);
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)area);
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Ubi_1);
				dbbind (dbproc, 13, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)Ubi_2);
				dbbind (dbproc, 14, NTBSTRINGBIND, (DBINT) 0, (unsigned  char *)nArea);
				
				// now process the rows
			if (dbnextrow(dbproc) == NO_MORE_ROWS)
				{
					con.gotoxy( 24, 0);
					con.write("No Existe este contenedor");
					return 0;
				  }
			else
				return 1;
		}
	} while (1);
}

int  Ubicacion_Vanes::GetStr()
{
		
		int nKOff = 0;	

		strcpy(contenedor, "");
		con.gotoxy( 1, 7);
		con.vm_setcursorstyle(CURSORNORM);
		nKOff = hKey.gettext(contenedor, sizeof(contenedor)-1); 
		return nKOff;
  
}

void Ubicacion_Vanes::UpdateSql()
{
    

	memset(ubi_1,0,sizeof(ubi_1)-1);
	memset(ubi_2,0,sizeof(ubi_2)-1);
	
	
	
	
	if (Terminal == 1)
	{
	con.writexy(9, 1, "Nueva Ubicacion");
	con.vm_attrib(FOREGROUND_INTENSITY);
	con.writexy(9, 20, "ubic_1:");
	con.vm_attrib(BACKGROUND_INTENSITY);
	hKey.gettext(ubi_1, sizeof(ubi_1)-1); 
	}
	else
	{
	con.vm_attrib(FOREGROUND_INTENSITY);
	con.writexy(12, 7, "");
	con.vm_attrib(BACKGROUND_INTENSITY);
	hKey.gettext(ubi_1, sizeof(ubi_1)-1); 
	}
	strcpy(ubi_2,ubi_1);
	
	if (atoi(tamano)>20)
	{
		ubi_2[5]=ubi_2[5]+1;
		con.vm_attrib(FOREGROUND_INTENSITY);
	    con.writexy(13, 7, "");
	    con.vm_attrib(BACKGROUND_INTENSITY);
	    //hKey.gettext(Ubi_2, sizeof(Ubi_2)-1); 
	
	}
	con.vm_attrib(FOREGROUND_INTENSITY);

	/*if (atoi(tamano)<=20)
	{
		con.vm_attrib(FOREGROUND_INTENSITY);
	    con.writexy(10, 20, Ubi_2);
	    con.vm_attrib(BACKGROUND_INTENSITY);
	}
*/
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
		getch();
		}	
	win.Close();
/*		
	
	
	
	Window win(10,15,15,45,con);
	win.SetTitle("Confirmación");
	win.Clear();
	win.Show();
	win.Writexy(1,1,"Confirma actualizacion? S/N");
	
	do 	{
		nKOff=hKey.getkey();
		
	} while (nKOff!=115 && nKOff!=83 && nKOff!=78 && nKOff!=110); 
	win.Close();
	
	if (nKOff == 115 || nKOff==83) // Si
	{
	con.writexy(24,0, "Actualizando");
	
	
	dbcanquery(dbproc);
	dbcmd (dbproc, (char *)"Update Ubicacion_Contenedores set Ubi_1='");
	dbcmd (dbproc, (char *) Ubi_1);
	dbcmd (dbproc, (char *)"', ");
	dbcmd (dbproc, (char *)"Ubi_2='");
	dbcmd (dbproc, (char *) Ubi_2);
	dbcmd (dbproc, (char *)"' where contenedor = '");
	dbcmd (dbproc, (char *) contenedor);
	dbcmd (dbproc, (char *)"'");
	
		
	dbsqlexec (dbproc); // send command buffer to SQL server

	// now check the results from the SQL server
	if ( dbresults(dbproc) ==SUCCEED) {
		con.writexy(24,0, "						");
		con.writexy(24,0, "Ok.					");
		
		}
	else
		
		con.writexy(24,0, "BAD					");
	}
	getch();
*/
}

void Ubicacion_Vanes::Show()
{

if (Terminal == 1)
{
//				  1111111111222222222233333333333		
//		12345678901234567890123456789012345678901
con.writexy(1,1,"Cont.:                Tam.:     Tipo:\n");                               
con.writexy(2,1,"Cond.:                Est.:     Tara:\n");
con.writexy(3,1,"Prec.:                Peso: \n");
con.writexy(4,1,"-------------------------------------------\n");     
con.writexy(5,1,"Manif:                Nave:           \n");
con.writexy(6,1,"-------------------------------------------\n");
con.writexy(7,1,"Area :                Ubic 1: \n");
con.writexy(8,1,"Ubic2:\n");
con.writexy(9,1,"                                         ");
con.writexy(10,1,"                                         ");
}
else
{
//				  1111111111222222222233333333333		
//		12345678901234567890123456789012345678901
con.writexy(1,1,"Cont.:" );
con.writexy(2,1, "Tam.:"    ); 
con.writexy(3,1, "Tipo:");                               
con.writexy(4,1, "Cond:"      );          
con.writexy(5,1, "Est.:"     );
con.writexy(6,1, "Tara:");
con.writexy(7,1, "Prec: ");               
con.writexy(8,1, "Peso:");
con.writexy(9,1, "Mani: ");               
con.writexy(10,1,"Nave:     ");
con.writexy(11,1,"Area: ");               
con.writexy(12,1,"Ubic1:");
con.writexy(13,1,"Ubic2:");
}


}

void Ubicacion_Vanes::Display()
{

	if (Terminal == 1)
	{
	con.writexy(1,7,contenedor,"AAAAAAAAAAAAA");
	
	con.writexy(1,28,tamano,"9999");
	con.writexy(1,40,tipo,"9999");

	
	
	
	con.writexy(2, 7,condicion,"AAA");  
	
	con.writexy(2,28,estado,"99"); 
	con.writexy(2,38,tara,"9,9999"); 

	con.writexy(3, 7,precinto,"AAAAAAAAAAAAAAAA");
	con.writexy(3,28,peso,"99,999"); 
	
	con.writexy (5, 7,manifiesto,"999999999");  
	//con.writexy (6,28,nave); 
	
	ScrllH.Init(5,28,28+15,nave,con); 
	ScrllH.Show();

	con.writexy (7, 7,area,"999999999999");  
	con.writexy (7,28,Ubi_1); 

	con.writexy (8, 7,Ubi_2);  
	}
	else
	{
	con.writexy(1,7,contenedor,"AAAAAAAAAAAAA");
	
	con.writexy(2,7,tamano,"9999");
	con.writexy(3,7,tipo,"9999");
	
	con.writexy(4,7,condicion,"AAA");  
	
	con.writexy(5,7,estado,"99"); 
	con.writexy(6,7,tara,"9,9999"); 

	con.writexy(7, 7,precinto,"AAAAAAAAAAAAAAAA");
	con.writexy(8, 7,peso,"99,999"); 
	
	con.writexy (9, 7,manifiesto,"999999999");  
		
	ScrllH.Init(10,7,7+15,nave,con); 
	ScrllH.Show();

	con.writexy (11, 7,area,"999999999999");  
	con.writexy (12,7,Ubi_1); 

	con.writexy (13, 7,Ubi_2);  
	}
	return;
}

void Ubicacion_Vanes::Execute(int Term)
{
int ok=FALSE;

Terminal = Term;
con.vm_clrscr();


Window win(1,1,16,45,con);
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
return;

}	

