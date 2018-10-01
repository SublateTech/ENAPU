
//#include "Console.h"
#include "Scroller.h"
#include "stdio.h"


Scroller::Scroller (void )
{
	Init();	
	return;
}


Scroller::Scroller (char x, char y, char x1, char y1, Console con)
{
	Init(x, y,x1,y1,con);
	return;
}


void Scroller::Init(char x, char y, char x1, char y1, Console con)
{
	SubTitle [0] = '\0';
	xabs   = x + 1;
	yabs   = y + 1;
	x1abs  = x1 -1;
	y1abs  = y1 -1;

	currow = 0;
	oldrow = 1;
	options = 0 ;
	rowend = x1-x - 2;
	curritem = 0;
	menuitems = -1;
	scr = con;
	strcpy(Border,FRAME_DOUBLE);
	curx=con.vm_wherex();
	cury=con.vm_wherey();
	Init();

	return;
}



void Scroller::Init(void)
{
	SaveScr();
	scr.vm_init();
}

void Scroller::SaveScr(void)
{
    
    scr.vioImageDefaults(&sysimage);
    scr.vioImageInit(&sysimage, scr.vm_getscreenwidth(), scr.vm_getscreenheight());
    scr.vioImageSave(&sysimage, 1, 1);
	return;
}

void Scroller::Show(void)
{
	int item;
	scr.vm_setcursorstyle(CURSORHIDE);


	scr.vm_paintbox(yabs -1, xabs -1 , y1abs + 1, x1abs +1 , vm_mkcolor(LIGHTGRAY,BLACK));
	
    scr.vm_paintclearbox(yabs -1 , xabs -1 , y1abs +1 , x1abs + 1, vm_mkcolor(LIGHTGRAY, BLACK));
    
	scr.vm_frame(yabs -1 , xabs -1 , y1abs +1 , x1abs + 1 , vm_mkcolor( LIGHTGRAY, BLACK), Border);
	
	if (Title[0] != 0)
		{
		scr.vm_puts((char) (yabs + (y1abs-yabs)/2 - strlen(Title)/2)  , (char) (xabs - 1), Title);	
		}	

	
	if (SubTitle[0] != 0)
		{
		scr.vm_puts((char) yabs, (char) (xabs), SubTitle);	
		xabs ++;
		options--;
		}	
	if (BarMsg[0] != 0)
		{
		BarMsg[y1abs-yabs+1] = 0;
		scr.vm_paintbox(yabs, (char) (x1abs),y1abs-yabs+2, (char) (x1abs ), vm_mkcolor(BLACK, LIGHTGRAY));
		scr.vm_puts((char) (yabs + (y1abs-yabs)/2 - strlen(BarMsg)/2) , (char) x1abs , BarMsg);
		x1abs --;
		options--;
		}	

	
	for (item = 0; item <= options  ; item++)
    {
        
		scr.vm_paintbox(yabs, (char) (xabs + item ), y1abs, (char) (xabs + item ), vm_mkcolor(DARKGRAY, BLACK));
		
		scr.vm_puts((char) yabs, (char) (xabs + item), menudata[item].desc);
		
	}
	

}

   
	
void Scroller::AddItem(char *str, char *str1) 
{
menuitems++;
strcpy(menudata[menuitems].desc ,str);
menudata[menuitems].desc[y1abs - yabs]=0;
strcpy(menudata[menuitems].cmd ,str1);

if (options < rowend) 
	{
	options ++;
	}
}

int Scroller::Display(void)
{
    
	int done, ch ;


	done = 0;
	
	
    while (!done)
    {
    	if (currow != oldrow)
    	{
            scr.vm_paintbox(yabs, (char) (xabs + oldrow ), y1abs, (char) (xabs + oldrow ), vm_mkcolor(DARKGRAY, BLACK));
            scr.vm_paintbox(yabs, (char) (xabs + currow  ),y1abs, (char) (xabs + currow  ), vm_mkcolor(BLACK, LIGHTGRAY));
			
        }

        //while (!scr.vm_kbhit())
        //{
            /* nada */
        //}

        ch = hKbd.getkey();
		LastKey = ch;
        
		//printf("%x, ", ch-256);
		
		switch (ch)
        {
        
        

		case K_F10:    /* F1 */
            /* nada */
            break;
		case 'a':
        case 'A':
		case K_UP:    /* up arrow */
			            				
			if (currow > 0  )
            {
                oldrow = currow  ;
				currow --;
				curritem--;
				
			}
			else if (curritem > 0 )
			{
				
				oldrow = currow +1 ;
				curritem--;
				scr.vm_paintbox(yabs, (char) (xabs + oldrow ), yabs -1 , (char) (xabs + oldrow ), vm_mkcolor(DARKGRAY, BLACK));
				
				scr.vm_scroll(xabs - 1,yabs - 1, xabs + options - 2 , y1abs -1, 0, vm_mkcolor(DARKGRAY, BLACK));

				scr.vm_puts(yabs, (char) (xabs + currow), menudata[curritem].desc);


			  	//vm_paintbox(24, (char) (7 + currow  ), 56, (char) (7 + currow  ), vm_mkcolor(BLACK,LIGHTGRAY));	
			}
            
			break;


        case 'b':
		case 'B':
		case K_DOWN:    /* down arrow */
            oldrow = currow  ;
            			
			if (currow  < options    )
            {
                currow ++;
				curritem++;
				
			}
			else if (curritem < menuitems )
			{
				curritem++;
				scr.vm_paintbox(yabs, (char) (xabs + oldrow ), (char) y1abs, (char) (xabs + oldrow ), vm_mkcolor(DARKGRAY, BLACK));
				
				scr.vm_scroll(xabs , yabs -1 ,xabs + options -1 ,y1abs -1, 1 , vm_mkcolor(DARKGRAY, BLACK));
				
				
				scr.vm_puts(yabs, (char) (xabs + currow  ), menudata[curritem].desc);
				scr.vm_paintbox((char) yabs, (char) (xabs + currow  ), (char) y1abs ,  (char) (xabs + currow  ), (	WORD ) vm_mkcolor(BLACK,DARKGRAY));	
			}
            
			break;

        case K_PGUP:    /* PgUp */
		case K_HOME:    /* Home */
            oldrow  = currow  ;
            curritem -= currow;
			currow = 0;
            break;

        case K_PGDN:    /* PgDn */
		case K_END:    /* End */
            
            if (options >= rowend)
				{
				curritem  +=  (rowend - currow -1 ) ;
				oldrow    = currow ;
				currow    = rowend -1 ;
				}
			else
				{
				oldrow    = currow;
				curritem  = options ;
				currow	  = options ;	
				
				}
			
            break;

        case K_ESC:    /* Escape */
        case K_F3:    /* F3 */
//        case K_F10:    /* F10 */
        case K_ALT_F4:    /* Alt+F4 */
        case K_ALT_X:    /* Alt+X */
            
            curritem = -1;
			done = 1;
            break;

        case K_ENTER:    /* Enter */
            done = 1;
			break;
            
        default:
            break;
        }
    }


return (curritem +1);
}

void Scroller::Finish(void)
{
    scr.vioImageRestore(&sysimage, 1, 1);
    scr.vioImageTerm(&sysimage);
    scr.vm_gotoxy(curx,cury);
	scr.vm_setcursorstyle(CURSORNORM);
    //scr.vm_done();
}

void Scroller::SetSubTitle(char *Subt)
{
strcpy(SubTitle, Subt);
return;
}

void Scroller::SetTitle(char *Subt)
{
strcpy(Title, Subt);
return;
}

void Scroller::SetBorder(char *Bor)
{
strcpy(Border, Bor);
return;
}

void Scroller::SetBarMsg(char *Bor)
{
strcpy(BarMsg, Bor);
return;
}
