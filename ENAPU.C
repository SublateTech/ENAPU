#define       DBNTWIN32               // must identify operating system environment
#include "windows.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include <sqlfront.h>
#include <sqldb.h>         // DB-LIB header file (should always be included)
#include <stdio.h>


void    cls(int fattr);
void    Menu_Ubicaciones();
void    Menu_Tareas();
void    Menu_Balanza();
void    Menu_Tablas();
void    Placa_Vehicular();
void    Brevete_Chofer();
void    Vanes();
void    Carga() ;
void    Rodante() ;
void    Tipo_Van();  
void    Condicion_Van();
void    Estado_Van();
void    Equipos_Accesorios();
void    Muelles_Ama();
void    Init_Db();
void	Display_Vanes();
void	Put_Vanes(char *contenedor,char *precinto,char *tamano,char *tipo,char *estado,char *tara,char *peso,char *manifiesto,char *nave,char *area,char *Ubi_1,char *Ubi_2) ;


	PDBPROCESS dbproc;  // allocate a DB-LIB process structure
	PLOGINREC  login;   // allocate a DB-LIB login structure
	char       Servername[25];
	// Forward declarations of the error handler and message handler.


void main()
{

	char nKey = 0;


	int err_handler(PDBPROCESS, int, int, int, char*, char*);
    int msg_handler(PDBPROCESS, DBINT, int, int, char*);

	Init_Db();
	
	do      {
			
			system("cls");
			system("gotoxy 3 5");

			printf("\tMenu Principal\n\n");
			printf("\t1. Ubicaciones\n");
			printf("\t2. Tareas\n");
			printf("\t3. Balanza\n");
			printf("\t4. Tablas\n");
			printf("\t5. Placa Vehicular\n");
			printf("\t6. Brevete Chofer\n");
			printf("\t7. Mensajes\n");
			printf("\t0. Salir\n");

	
			nKey = _getch();
			switch (nKey)
				{
				case '1':
					Menu_Ubicaciones();
					break;
				case '2':
					Menu_Tareas();
					break;
				case  '3':
					Menu_Balanza();
					break;
				case  '4':
					Menu_Tablas();
					break;
				case '5':
					Placa_Vehicular();
					break;
				case '6':
					Brevete_Chofer();
					break;
				case '0':
					// Close the connection and exit
					dbexit();
					exit(0);
				}


	} while (1);
	
}

void Menu_Ubicaciones()
{
	char nKey=0;
	
	do      {
			system("cls");
			system("gotoxy 3 2");
			printf("\tMenu Ubicaciones\n\n");
			printf("\t1. Vanes\n");
			printf("\t2. Carga\n");
			printf("\t3. Rodante\n");
			printf("\t0. Volver\n");

	
			nKey = getch();
			switch (nKey)
				{
				case '1':
					Vanes();
				case '2':
					Carga();
				case  '3':
					Rodante();
				case  '0':
					break;
				}


	} while (nKey!='0');

	
}

void Vanes() 
{


	// Variables used to store the returning data
	char       contenedor   [14];
	char       condicion    [6];
	char       precinto             [17];
	char       tamano               [5];
	char       tipo                 [5];
	char       estado               [5];
	char            tara            [5];
	char       peso                 [6];
	char       nave                 [51];
	char       manifiesto   [10];
	char       area                 [51];
	char       Ubi_1                [9];
	char       Ubi_2                [9];
	
	RETCODE    result_code;

	//while (TRUE)
	//{
		//printf ("\nEnter author's last name to retrieve (return to exit): ");
		//gets (contenedor);
		strcpy(contenedor, "XXXXXXXXXXXXX");
//              if (contenedor[0] == '\0') // if only a return was entered
//                      break;

		DoSql_Vanes();

		// construct command buffer to be sent to the SQL server
		dbcmd (dbproc, (char *)"select contenedor, condicion, precinto, tamano,");
		dbcmd (dbproc, (char *)" tipo, estado, tara, peso, nave, manifiesto, area,Ubi_1, Ubi_2");
		//dbcmd (dbproc, (char *)" select * ");
		dbcmd (dbproc, (char *)" from Ubicacion_Contenedores");
		dbcmd (dbproc, (char *)" where contenedor = '");
		dbcmd (dbproc, (char *)contenedor);
		dbcmd (dbproc, (char *)"'");

		dbsqlexec (dbproc); // send command buffer to SQL server

		// now check the results from the SQL server
		while ((result_code = dbresults(dbproc)) != NO_MORE_RESULTS)
		
		{
			if (result_code == SUCCEED)
			{
				
				
				dbbind (dbproc, 1, NTBSTRINGBIND, (DBINT) 0, (char *)contenedor);
				dbbind (dbproc, 2, NTBSTRINGBIND, (DBINT) 0, (char *)condicion);
				dbbind (dbproc, 3, NTBSTRINGBIND, (DBINT) 0, (char *)precinto);
				dbbind (dbproc, 4, NTBSTRINGBIND, (DBINT) 0, (char *)tamano);
				dbbind (dbproc, 5, NTBSTRINGBIND, (DBINT) 0, (char *)tipo);
				dbbind (dbproc, 6, NTBSTRINGBIND, (DBINT) 0, (char *)estado);
				dbbind (dbproc, 7, NTBSTRINGBIND, (DBINT) 0, (char *)tara);
				dbbind (dbproc, 8, NTBSTRINGBIND, (DBINT) 0, (char *)peso);
				dbbind (dbproc, 9, NTBSTRINGBIND, (DBINT) 0, (char *)nave);
				dbbind (dbproc, 10, NTBSTRINGBIND, (DBINT) 0, (char *)manifiesto);
				dbbind (dbproc, 11, NTBSTRINGBIND, (DBINT) 0, (char *)area);
				dbbind (dbproc, 12, NTBSTRINGBIND, (DBINT) 0, (char *)Ubi_1);
				dbbind (dbproc, 13, NTBSTRINGBIND, (DBINT) 0, (char *)Ubi_2);

				
				Display_Vanes();
				
				
				// now process the rows
				while (dbnextrow(dbproc) != NO_MORE_ROWS)
				{
				
					Put_Vanes(contenedor,condicion,precinto,tamano,tipo,estado,tara,peso,manifiesto,nave,area,Ubi_1,Ubi_2);

				}
			}
		
		/*      else
			{
				printf ("Results Failed\n");
				break;
			}
			*/
		}
	//} // while (TRUE)

	
	getch();

}

void Put_Vanes(char *contenedor,char *condicion,char *precinto,char *tamano,char *tipo,char *estado,char *tara,char *peso,char *manifiesto,char *nave,char *area,char *Ubi_1,char *Ubi_2) 
			
{

						printf ("%s\n",contenedor);     
						printf ("%s\n",condicion);
						printf ("%s\n",precinto );      
						printf ("%s\n",tamano           );
						printf ("%s\n",tipo             );      
						printf ("%s\n",estado           );
						printf ("%s\n",tara             );
						printf ("%s\n",peso             );      
						printf ("%s\n",manifiesto);     
						printf ("%s\n",nave             );      
						printf ("%s\n",area             );      
						printf ("%s\n",Ubi_1            );
						printf ("%s\n",Ubi_2            );
						printf ("\n");

}

void Display_Vanes()
{
//Ubicaci¢n de Contenedores

system("cls");
system("gotoxy 1 1");

printf("Contenedor                   Tama¤o	      Tipo	  \n");                               
printf("Condici¢n                    Estado	  	  Tara	      \n");
printf("Precinto                     Peso	      			  \n");
printf("------------------------------------------------------\n");     
printf("Manifiesto                   Nave            \n");
printf("------------------------------------------------------\n");
printf("Area						 Ubicac. 1    Ub.          \n");

_getch();

}

int err_handler(PDBPROCESS dbproc, int severity, int dberr, int oserr, char * dberrstr, char * oserrstr)
{
	if (dberrstr != NULL)
		printf("DB-LIBRARY error:\n\t%s\n", dberrstr);

	if (oserr != DBNOERR)
		printf("Operating-system error:\n\t%s\n", oserrstr);

	if ((dbproc == NULL) || (DBDEAD(dbproc)))
		return(INT_EXIT);
	else
		return(INT_CANCEL);
}

int msg_handler(PDBPROCESS dbproc, DBINT msgno, int msgstate, int severity, char * msgtext)
{
	printf("SQL Server message %ld, state %d, severity %d:\n\t%s\n",
			msgno, msgstate, severity, msgtext);
	return(0);
}



void Carga() {return; }
void Rodante() {return; }
void Menu_Tareas() 
{
	char nKey=0;
	
	do      {
			system("cls");
			system("gotoxy 3 2");
			printf("\tMenu de Tareas\n\n");
			printf("\t1. Entregas DIICTN\n");
			printf("\t2. Tendido EIECTN-DTR-ERE-ECA\n");
			printf("\t0. Volver\n");

	
			nKey = getch();
			switch (nKey)
				{
				case '1':
					Vanes();
				case '2':
					Carga();
				case  '3':
					Rodante();
				case  '0':
					break;
				}


	} while (nKey!='0');

	
}
void Menu_Balanza()  
{
	char nKey=0;
	
	do      {
			system("cls");
			system("gotoxy 3 2");
			printf("\tMenu de Balanza\n\n");
			printf("\t1. Tickets de TAL\n");
			printf("\t2. Tickets de TPC\n");
			printf("\t0. Volver\n");

	
			nKey = getch();
			switch (nKey)
				{
				case '1':
					Vanes();
				case '2':
					Carga();
				case  '0':
					break;
				}


	} while (nKey!='0');
}
void Menu_Tablas()  
{
	char nKey=0;
	
	do      {
			system("cls");
			system("gotoxy 3 2");
			printf("\tMenu de Tablas\n\n");
			printf("\t1. Tipo Van\n");
			printf("\t2. Condicion Van\n");
			printf("\t3. Estado Van\n");
			printf("\t4. Equipos/Accesorios\n");
			printf("\t5. Muelles/Ama\n");
			printf("\t0. Volver\n");

	
			nKey = getch();
			switch (nKey)
				{
				case '1':
					Tipo_Van();
				case '2':
					Condicion_Van();
				case  '3':
					Estado_Van();
				case  '4':
					Equipos_Accesorios();
				case  '5':
					Muelles_Ama();
				case  '0':
					break;
				}


	} while (nKey!='0');
}
void Placa_Vehicular()  {return; }
void Brevete_Chofer()  {return; }
void Tipo_Van()  {return; }
void Condicion_Van()  {return; }
void Estado_Van()  {return; }
void Equipos_Accesorios() {return; }
void Muelles_Ama() {return; }
void Init_Db()
{


	if (dbinit() == (char *)NULL)
	{
		printf("Communications layer not loaded\n");
		return(1);
	}
	
	// Install the user-supplied error-handling     and message-handling
	// routines. They are defined at the bottom     of this source file.
	
	dberrhandle((DBERRHANDLE_PROC)err_handler);
	dbmsghandle((DBMSGHANDLE_PROC)msg_handler);

	// Get server's computer name
	Servername[0] = '\0';
	//printf ("\nEnter Name of SQL Server: ");
	//gets (Servername);

	strcpy(Servername, "SERVIDOR"); 
	login = dblogin();                     // get login record from DB-LIB
	DBSETLUSER (login, (char *)"sa");      // set the username
	DBSETLAPP (login, (char *)"Enapu"); // set the application name
	DBSETLPWD (login, (char *)"");         // set the SQL Server password
	DBSETLVERSION(login,DBVER60);

	// Now attempt to create and initialize a DBPROCESS structure
	if ((dbproc     = dbopen (login, Servername)) == NULL)
	{
		printf ("dbopen failed\n");
		return (1); // exit program
	}

	dbuse (dbproc, "Enapu"); // use the "pubs" database
}

