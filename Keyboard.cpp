#include <time.h>
#include <stdio.h>
#include "kbd.hpp"
#include "keyboard.h"
#include "editgets.h"

#include "Tipo_Contenedores.h"
#include "Condicion_Contenedores.h"
#include "Estado_Contenedores.h"
#include "Equipos_Accesorios.h"
#include "Muelles_Amarradores.h"


Inputs::Inputs (Console con, PDBPROCESS dbproc)
{

Init(con, dbproc);
}

 Inputs::Inputs (Console con)
{
int x=0;

}
 Inputs::Inputs (void)
{
int x=0;

}

void Inputs::Init (Console con, PDBPROCESS dbproc)
{

screen = con;
hDb = dbproc;

}

int Inputs::getpassf (char buf[], int len)
{
	int ch, n = 0, ok = FALSE;

	do {
		ch = getch();
		switch (ch) {
		case K_ENTER:
			ok = TRUE;
			break;
		case 0:
			getch();
			break;
		case K_BKSP:
			if (n>0)
				n--;
			cputs ("\b \b");
			break;
		default:
			buf[n++] = toupper (ch);
			putch('*');
		}
	} while ((n < len) && !ok);
	buf[n] = 0;

	return n;
}



/*
	int ungetkey (int key)

	- put key into keyboard buffer
*/

int Inputs::ungetkey (int key)
{
	if (key > 255) 
	{
		ungetch (key);
		ungetch (0);
	} 
	else
	{
		ungetch (key);
    }

	return key;
}

void Inputs::kbflush()
{
	while (kbhit())
		getch();
}

int Inputs::getkey(void)
{
	int k;

	k = getch();

//	printf("\n%i-> ", k);

		
	if (k==0 ||  k==224 ) //|| k==27) 
		{
		k = 256 + getch();
//		printf("%i", k-256);
			
		}

	return k;
}

/*int Inputs::gettext (char buf[], int len)
{
	int ch, n = 0, ok = FALSE;

	//cputs(buf);

	do {
		ch = getch();
		//ch=getkey();
		switch (ch) 
				{
		
				case K_ENTER:
					LastKey = K_ENTER;
					ok	= TRUE;
					break;
				case K_ESC:
					LastKey=K_ESC;
					ok = TRUE;
					break;
				//case K_F1:
				//	LastKey = K_F1;
				//	ok = TRUE;
				//	break;
				case 0:	
					getch();
					break;
				case K_BKSP:
					if (n>0)
						{
						n--;
						cputs ("\b \b");
						}
					break;
					
				default:
					buf[n++] = ch; //toupper (ch);
					putch(ch);
				}
	} while ((n < len) && !ok);
	
	buf[n] = 0;
	return n;
}*/

int Inputs::gettext (char buf[], int len)
{
	password_mode = 0;
	memset(buf, 0, sizeof(buf));
	
	//strcpy(buf,buffer);
	return editgets(buf, len, NULL);
}
int Inputs::editgets(char *s, int maxlen, char *string)
{
      char temp[500];         /* Working buffer                         */
      int   insert,           /* Non-zero if in insert mode             */
            done = 0,         /* Non-Zero if done                       */
            pos,              /* Our position within the string         */
            len,              /* The current length of the string       */
            i, j, k,          /* Temporary variables                    */
            c,                /* Keyboard input                         */
            skip;             /* Spaces to skip when tabbing            */

      if (NULL == string)
            string = "";

      if (0 != (pos = len = strlen(string)))
            strncpy(temp, string, min(len, maxlen));

      for (i = 0; i < maxlen; ++i)
      {
            if (0 == *string)
                  putch('_');
            else  putch(*string++);
      }
      for (i = 0; i < (maxlen - len); ++i)
            putch('\b');
      fflush(stderr);

      /* Set insert mode, save cursor, and use a big cursor */

      insert = 1;
	  screen.vm_setcursorstyle(CURSORFULL);
//      cursor('S');
//      cursor('B');

      while (!done)
      {
            
			c = getkey();
			
            if (hDb!=0)
			{
			switch (c)
            {
           	case K_F5:
					{
					Tipo_Contenedores TConten (hDb, screen);
					TConten.Execute(screen.Terminal);
					break;
					}
				
			case K_F6:
					{
					Condicion_Contenedores CConten (hDb, screen);
					CConten.Execute(screen.Terminal);
					break;
					}
			case K_F7:
					{
					Estado_Contenedores EstConten (hDb, screen);
					EstConten.Execute(screen.Terminal);
					break;
					}
			case K_F8:
					{
					Equipos_Accesorios EqAcces (hDb, screen);
					EqAcces.Execute(screen.Terminal);
					break;
					}
			case K_F9:
					{
					Muelles_Amarradores MueAma (hDb, screen);
					MueAma.Execute();
					break;
					}
			
			}

			}
			switch (c)
			{
			case K_ESC :
                  if (len == 0)
				  {done=1; break;}
                  if (pos != len)
                  {
                        for (i = pos; i < len; i++)
                              putch('_');
                  }
                  for (i = len; i > 0; i--)
                  {
                        putch('\b');
                        putch('_');
                        putch('\b');
                  }
                  pos = len = 0;
                  break;

           //case K_UP :
			case K_LEFT :
                  if (password_mode)
                        BAD_KEY();
                  if (pos == 0)
                        break;
                  pos--;
                  putch('\b');
                  break;

            //case K_DOWN :
            case K_RIGHT :
                  if (password_mode)
                        BAD_KEY();
                  if (pos == len)
                        break;
                  if (pos != maxlen)
                  {
                        putch(temp[pos]);
                        pos++;
                  }
                  break;

            case K_HOME :
            //case K_PHOME :
                  if (password_mode)
                        BAD_KEY();
                  while (pos-- > 0)
                        putch('\b');
                  pos = 0;
                  break;

            case K_END :
            //case Key_PEND :
                  if (password_mode)
                        BAD_KEY();
                  while (pos < len)
                        putch(temp[pos++]);
                  break;

            case K_INS :
            //case K_PINS :
                  if (password_mode)
                        BAD_KEY();
                  insert = (!(insert));

				  if (insert)
					  screen.vm_setcursorstyle(CURSORFULL);
				  else
					  screen.vm_setcursorstyle(CURSORNORM);
					
			//                  cursor(insert ? 'B' : 'N');
                  break;

            case K_DEL :
            //case Key_PDEL :
                  if (password_mode)
                        BAD_KEY();
                  if (pos == len)
                        break;
                  for (i = pos; i < len; i++)
                        temp[i] = temp[i + 1];
                  len--;
                  for (i = pos; i < len; i++)
                        putch(temp[i]);
                  putch('_');
                  for (i = len + 1; i > pos; i--)
                        putch('\b');
                  break;

            case K_BKSP :
                  if (pos == 0)
                        break;
                  if (pos != len)
                  {
                        for (i = pos - 1; i < len; i++)
                              temp[i] = temp[i + 1];
                        pos--;
                        len--;
                        putch('\b');
                        for (i = pos; i < len; i++)
                              putch(temp[i]);
                        putch('_');
                        for (i = len; i >= pos; i--)
                              putch('\b');
                  }
                  else
                  {
                        putch('\b');
                        putch('_');
                        putch('\b');
                        pos = --len;
                  }
                  break;

            case K_ENTER :
            //case Key_PADENTER :
            //case Key_NL :
                  done = 1;
                  break;

            case K_CTRL_END :
            //case K_CPEND :
                  if (password_mode)
                        BAD_KEY();
                  for (i = pos; i < len; ++i)
                        putch('_');
                  for (i = pos; i < len; ++i)
                        putch('\b');
                  len = pos;
                  break;

            case K_CTRL_HOME :
            //case Key_CPHOME :
                  if (pos == 0)
                        break;
                  if (pos != len)
                  {
                        while (0 != pos)
                        {
                              for (i = pos - 1; i < len; i++)
                                    temp[i] = temp[i + 1];
                              pos--;
                              len--;
                              putch('\b');
                              for (i = pos; i < len; i++)
                                    putch(temp[i]);
                              putch('_');
                              for (i = len; i >= pos; i--)
                                    putch('\b');
                        }
                  }
                  else
                  {
                        while (0 != pos)
                        {
                              putch('\b');
                              putch('_');
                              putch('\b');
                              pos = --len;
                        }
                  }
                  break;

            case K_CTRL_LEFT: //K_SH_UP :
            //case Key_CPRTARROW :
                  if (password_mode)
                        BAD_KEY();
                  do
                  {
                        if (pos == len)
                              break;
                        if (pos != maxlen)
                        {
                              putch(temp[pos]);
                              pos++;
                        }
                  } while (isspace(temp[pos]));
                  do
                  {
                        if (pos == len)
                              break;
                        if (pos != maxlen)
                        {
                              putch(temp[pos]);
                              pos++;
                        }
                  } while (!isspace(temp[pos]));
                  break;

            case K_CTRL_RIGTH :
            //case K_CPLTARROW :
                  if (password_mode)
                        BAD_KEY();
                  do
                  {
                        if (pos == 0)
                              break;
                        pos--;
                        putch('\b');
                  } while (isspace(temp[pos]));
                  do
                  {
                        if (pos == 0)
                              break;
                        pos--;
                        putch('\b');
                  } while (!isspace(temp[pos]));
                  break;

            case K_TAB :
                  if (password_mode)
                        BAD_KEY();
                  if (pos == maxlen)
                        break;

                  skip = TabSize - ((pos + TabSize) % TabSize);

                  if (insert)
                  {
                        if ((len + skip) > maxlen)
                              skip = maxlen - len;

                        for (i = pos, j = len + skip - 1, k = len - 1;
                              i < len ; ++i, --j, --k)
                        {
                              temp[j] = temp[k];
                        }
                  }
                  else  /* overwrite */
                  {
                        if ((pos + skip) > maxlen)
                              skip = maxlen - pos;
                  }
                  for (i = 0; i < skip; ++i)
                  {
                        temp[pos++] = ' ';
                        putch(' ');
                  }
                  len = insert ? len + skip : max(len, pos);
                  for (i = pos; i < len; ++i)
                        putch(temp[i]);
                  for (i = len; i > pos; --i)
                        putch('\b');
                  break;

            default :
                  if (pos == maxlen)
                        break;

                  if (c & 0xff00          /* Illegal extended character */

#if !CTRL_CHARS_ALLOWED

                  || iscntrl(c)
#endif
                  )
                  {
                        BAD_KEY();
                  }

                  if ((!(insert)) || pos == len)
                  {
                        temp[pos++] = (char)c;
                        if (pos > len) len++;
                        if (password_mode)
                        {
                              if (2 == password_mode)
                                    putch(pickPWchar());
                              else  putch('*');
                        }
                        else  putch(c);
                  }
                  else
                  {
                        if (len == maxlen)
                              break;
                        for (i = len++; i >= pos; i--)
                              temp[i + 1] = temp[i];
                        temp[pos++] = (char)c;
                        if (password_mode)
                        {
                              if (2 == password_mode)
                                    putch(pickPWchar());
                              else  putch('*');
                        }
                        else  putch(c);
                        for (i = pos; i < len; i++)
                              putch(temp[i]);
                        for (i = len; i > pos; i--)
                              putch('\b');
                  }
            }
      }
      temp[len] = '\0';
      strcpy(s, temp);
//      cursor('Z');            /* Restore cursor size  */
      return len;
}

int Inputs::pickPWchar(void)
{
      static int inited = 0;

      if (!inited)
      {
            srand(((unsigned int)time(NULL)) | 1);
            inited = 1;
      }
      
      return PWchars[rand() % (sizeof(PWchars) - 1)];
}