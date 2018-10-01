#include "Scrollerv.h"
#include "stdio.h"

ScrollerV::ScrollerV (char f, char y, char f1,char y1, char *str, Console con)
{
Init(f,y,f1,y1,str,con);
}

ScrollerV::ScrollerV ()
{

}
		
void ScrollerV::Init(char f, char y, char f1, char y1, char *str, Console con)
{

	x=0;
	fila = f;
	filaf = f1;
	columnai=y;
	columnaf=y1;
	scr=con;
	strcpy(Str, str);
	ind = 0;
}
		
void ScrollerV::Down(void)
{

ind = strlen(substr);    
i =  strlen(Str)  ;
if (x)
  	{
	x--;
  	scr.scrollh(fila,columnai,columnaf-1,0);
	scr.vm_putch(columnai+1,fila+1 ,*(Str+x));
    }
	
}

void ScrollerV::Up(void)
{
ind = strlen(substr);    
i =  strlen(Str)  ;
if (i - (x +ind +1)+1)
  	{
	x++;
  	scr.scrollh(fila,columnai+1,columnaf,1);
	scr.vm_putch(columnaf+1,fila +1,*(Str+ind+x-1));
	
    }
}
	
void ScrollerV::Show(void)
{
	scr.vm_setcursorstyle(CURSORHIDE);
	memset(substr,0,81);  
	strncpy(substr, Str, columnaf-columnai+1);
	scr.writexy(fila,columnai,substr);
}

void ScrollerV::Exec(void)
{
	
	Show();
	int ok = 0;
	do {
	
	switch (hKbd.getkey()) {
						case K_RIGHT:
							Up();
							break;
							
						case  K_LEFT:
							Down();
							break;
						
						case  K_F3:
							//ShowProducto();
							Show();
							break;
							
						case K_ESC:
							ok=1	;
							break;
							
							}
		
		}while (!ok);
	
	}
		


