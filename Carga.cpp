#define       DBNTWIN32 	      // must identify operating system environment
#include "Afx.h"
//#include "windows.h"
#include <sqlfront.h>
#include <sqldb.h>	   // DB-LIB header file (should always be included)

#include <stdio.h>	 // for getch() function
#include <conio.h>	 // for getch() function
#include <dos.h>       // for getch() function
#include "Carga.h"
#include "Keyboard.h"
#include "Kbd.hpp"
#include "Window.h"
#include "Scrollerh.h"


extern nTermType;



// Circle constructor calls base Point constructor first
Carga_Fraccionada::Carga_Fraccionada(PDBPROCESS dbprocess, Console consola)
{
   dbproc=dbprocess;
   con = consola;
   Terminal = 1;
//   Inputs hKey	;
 //  hKey.Init(consola, dbproc);
   //memset(Resp,250,0);

}

int Carga_Fraccionada::GetSql(void)
{

	do {
		dbcanquery(dbproc);
		
	
	
		dbcmd (dbproc, (char *)"spportatil 'buscarcarg','");
		dbcmd (dbproc, (char *) BL_Master);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) BL_Hijo);
		dbcmd (dbproc, (char *)"'");
		
		
		dbsqlexec (dbproc); // send command buffer to SQL server

	
		if ( dbresults(dbproc) ==SUCCEED)

		{
			
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) BL_Master    );
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) BL_Hijo      );
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Total_Bultos );
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Total_Peso   );
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Cod_Embalaje );
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Manifiesto   );
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Nave	     );
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Area	     );
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (unsigned	char *) Ubicacion    );
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Marca_Numero );
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) Producto     );
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (unsigned char *) nArea     );

		
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
	} while (1);
}


void Carga_Fraccionada::Show()
{

if (Terminal == 1)
{	
con.gotoxy( 1, 1);
  //	   11111111112222222222333333333334		
  //       012345678901234567890123456789012345678901
con.writexy(1,1,"B/L Mast:\n");                               
con.writexy(2,1,"B/L Hijo:                         Embalaje\n");
con.writexy(3,1,"Tot Bult:        Tot.Peso:   		\n");
con.writexy(4,1,"-----------------------------------------\n");     
con.writexy(5,1,"Manif:           Nave:\n");
con.writexy(6,1,"-----------------------------------------\n");
con.writexy(7,1,"Area     : \n");
con.writexy(8,1,"Ubicacion:  \n");
}
else
{
con.gotoxy( 1, 1);
  //	   11111111112222222222333333333334		
  //       012345678901234567890123456789012345678901
con.writexy(1,1,"B/L Mast:");                               
con.writexy(2,1,"B/L Hijo:");
con.writexy(3,1,"Embalaje:");
con.writexy(4,1,"Tot Bult:");
con.writexy(5,1,"Tot.Peso:");
con.writexy(6,1,"Manif   :"); 
con.writexy(7,1,"Nave    :");
con.writexy(8,1,"Area    :");
con.writexy(9,1,"Ubic.   :");
}
}

void Carga_Fraccionada::Display(void)
{

  if (Terminal == 1)
    {
	con.gotoxy( 1, 10);  con.write(BL_Master   ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 2 ,10);  con.write(BL_Hijo     ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	
	con.gotoxy( 3 ,10);  con.write(Total_Bultos,"999,999");
	con.gotoxy( 3 ,27);  con.write(Total_Peso  ,"9999999999");
	con.gotoxy( 3 ,33);  con.write(Cod_Embalaje,"AAA");
	
	con.gotoxy( 5 ,7);  con.write(Manifiesto  ,"999999999");

	ScrllH.Init(5,23,23+15,Nave,con); 
	ScrllH.Show();

	con.gotoxy( 7 ,11);  con.write(Area       ,"AAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 8 ,11);  con.write(Ubicacion  ,"AA");
	}
  else
	{
	con.gotoxy( 1, 10);  con.write(BL_Master   ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 2 ,10);  con.write(BL_Hijo     ,"AAAAAAAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 3 ,10);  con.write(Total_Bultos,"999,999");
	con.gotoxy( 4 ,10);  con.write(Total_Peso  ,"9999999999");
	con.gotoxy( 5 ,10);  con.write(Cod_Embalaje,"AAA");
	con.gotoxy( 6 ,10);  con.write(Manifiesto  ,"999999999");

	ScrllH.Init(7,10,10+15,Nave,con); 
	ScrllH.Show();

	con.gotoxy( 8 ,10);  con.write(Area       ,"AAAAAAAAAAAAAAAAAAAA");
	con.gotoxy( 9 ,10);  con.write(Ubicacion  ,"AA");
	}

	return;
}



void Carga_Fraccionada::ShowProducto()
{
Window win(1,1,13,45,con);
win.SetTitle("Producto");
win.Show();
   
//con.gotoxy( 0, 0);
  //	   11111111112222222222333333333334		
  //       012345678901234567890123456789012345678901
win.Writexy(1,1,"Descricion Mercadería");
win.Writexy(2,1,Producto);
hKey.getkey();

win.Close();

}

void Carga_Fraccionada::ShowMarcaNumero()
{
   
Window win(1,1,13,45,con);
win.SetTitle("Marca y Numero");
win.Show();
win.Writexy( 0, 0,"");
  //	   11111111112222222222333333333334		
  //       012345678901234567890123456789012345678901
win.Writexy(1,1,"Marca y Numero");
win.Writexy(2,1,Marca_Numero);
hKey.getkey();



win.Close();


}


void Carga_Fraccionada::Execute(int Term)
{
Terminal = Term;
int ok=FALSE;
con.vm_clrscr();
Window win(1,1,13,45,con);
win.SetBarMsg("F1=Actualiza F2=Marca y Numero F3=Producto");

win.Show();

do {
	win.Clear();
	Show();	
	ok=FALSE;
	if (GetStr()!= 0)
		{	
	
		if (GetSql()!=0)
				{
			
				Display();
				ok=FALSE;
				do {
				    
					switch (hKey.getkey()) {
						case K_F1:

							UpdateSql();
							Show();
							Display();
							break;
							
						case  K_F2:
							ShowMarcaNumero();
							Show();
							Display();
							break;
						
						case  K_F3:
							ShowProducto();
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
							ok=TRUE;
							break;

						case K_ENTER:
							ok=FALSE;
							break;
								}
				} while(!ok);
				}
			else 
				continue;
	} else
		break;

} while (1);
win.Close();
return;

}	


int  Carga_Fraccionada::GetStr()
{
		
		int nKOff = 0;	
		//strcpy(BL_Master, "XXXXXXXXXXXXXXXXXXXXXXXXX");
		strcpy(BL_Master, "");
		con.gotoxy( 1, 10);
		con.vm_setcursorstyle(CURSORNORM);
		nKOff = hKey.gettext(BL_Master, sizeof(BL_Master)-1); 
		strcpy(BL_Hijo, "");
		con.gotoxy( 2, 10);
		con.vm_setcursorstyle(CURSORNORM);
		nKOff = hKey.gettext(BL_Hijo, sizeof(BL_Hijo)-1); 
			
		return nKOff;
  
}

void Carga_Fraccionada::UpdateSql()
{
    
	memset(ubi_1,0,sizeof(ubi_1)-1);
		

	con.vm_attrib(BACKGROUND_INTENSITY);
	if (Terminal==1)
	con.gotoxy( 8, 11);
	else
	con.gotoxy( 9, 11);
	
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


int Carga_Fraccionada::Verifica(void)
{
		
		dbcanquery(dbproc);
		dbcmd (dbproc, (char *)"spportatil 'buscaram','");
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

int Carga_Fraccionada::IfUpdated()
{
		dbcanquery(dbproc);
		
		dbcmd (dbproc, (char *)"spportatil 'reubicarg','");
		dbcmd (dbproc, (char *) BL_Master);
		dbcmd (dbproc, (char *)"','");
		dbcmd (dbproc, (char *) BL_Hijo);
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
