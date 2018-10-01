#include "Window.h"
#include "stdio.h"



Window::Window (void )
{
	Init();	
	return;
}


Window::Window (char x, char y, char x1, char y1, Console con)
{
	Init(x, y,x1,y1,con);
	return;
}


void Window::Init(char x, char y, char x1, char y1, Console con)
{
	Title [0] = '\0';
	BarMsg[0] = '\0';
	xabs   = x + 1;
	yabs   = y + 1;
	x1abs  = x1 -1;
	y1abs  = y1 -1;

	//con.gotoxy(20,30);
	currow = con.vm_wherex();
	curcol = con.vm_wherey();
	//con.vm_printf(1,24,"%i,%i", currow, curcol);
	//con.vm_getch();
	scr = &con;
	Init();

	return;
}



void Window::Init(void)
{
	SaveScr();
	//scr->vm_init();
}

void Window::SaveScr(void)
{
    
    scr->vioImageDefaults(&sysimage);
    scr->vioImageInit(&sysimage, scr->vm_getscreenwidth(), scr->vm_getscreenheight());
    scr->vioImageSave(&sysimage, 1, 1);
	return;
}

void Window::Show(void)
{

	scr->vm_setcursorstyle(CURSORHIDE);


	scr->vm_paintbox(yabs -1, xabs -1 , y1abs + 1, x1abs +1 , vm_mkcolor(LIGHTGRAY,BLACK));
	
    scr->vm_paintclearbox(yabs -1 , xabs -1 , y1abs +1 , x1abs + 1, vm_mkcolor(LIGHTGRAY, BLACK));
    
	//scr->vm_frame(yabs -1 , xabs -1 , y1abs +1 , x1abs + 1 , vm_mkcolor( DARKGRAY, BLACK), FRAME_SINGLE);

	
	if (Title[0] != 0)
		{
			scr->vm_puts((char) (yabs + (y1abs-yabs)/2 - strlen(Title)/2)  , (char) (xabs - 1), Title);	
		}
	if (BarMsg[0] != 0)
		{
			BarMsg[y1abs-yabs+1] = 0;
			scr->vm_paintbox(yabs, (char) (x1abs),y1abs-yabs+2, (char) (x1abs ), vm_mkcolor(BLACK, LIGHTGRAY));
			scr->vm_puts((char) (yabs + (y1abs-yabs)/2 - strlen(BarMsg)/2) , (char) x1abs , BarMsg);
		}	
	
}

void Window::Close(void)
{
    scr->vioImageRestore(&sysimage, 1, 1);
    scr->vioImageTerm(&sysimage);
    scr->vm_gotoxy(currow, curcol);
	scr->vm_setcursorstyle(CURSORNORM);
    //scr->vm_done();
}

void Window::SetTitle(char *Subt)
{
strcpy(Title, Subt);
return;
}

void Window::Writexy(char x, char y, char *text)
{

	scr->vm_puts(yabs+y, xabs+x, text); 

}

void Window::SetBorder(char *Bor)
{
strcpy(Border, Bor);
return;
}

void Window::Clear()
{
if (BarMsg[0] == 0)
	scr->vm_clearbox(yabs , xabs  , y1abs , x1abs );
else
	scr->vm_clearbox(yabs , xabs  , y1abs , x1abs - 1);
return;
}

void Window::SetBarMsg(char *Bor)
{
strcpy(BarMsg, Bor);
return;
}