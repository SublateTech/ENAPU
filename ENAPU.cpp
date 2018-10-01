

#include "Menu.h"
#include "Keyboard.h"
#include "console.h"

static int  nTermType=0;
static  char sUsuario[250];


 void main( int argc , char *argv[] )
{


Inputs kbd;
Console con;

	


//do {
	
//} while(kdb.getkey()!=27);

//return ;

	 
if (argc > 1)
{
	nTermType = atoi(argv[1]);
	strcpy(sUsuario,argv[2]);
	con.Terminal = nTermType;
}
else
	nTermType = 1;



Menu MenuPrincipal;
MenuPrincipal.Exec(nTermType); 	

exit(0);
}









