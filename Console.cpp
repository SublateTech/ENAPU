#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <conio.h>
#include "Console.h"
#include "Kbd.hpp"
#include "winbase.h"

char *jzpad(int ,int );
char *jzrgtjst(char *fstr,int flen);


  Console::Console(void)
  {
		HANDLE HInput = INVALID_HANDLE_VALUE;
		HANDLE HOutput = INVALID_HANDLE_VALUE;
		key_hit = 0xFFFFFFFFUL;
	  
		strcpy(vm_frame_blank,"      ");
		strcpy(vm_frame_single, "ÚÄ¿³ÀÙ");
		strcpy(vm_frame_double, "ÉÍ»ºÈ¼");
		Terminal = 1;


		vm_vi_init();

}

void Console::vm_setattr(char attr)
{
    vm_curattr = attr;
}

void Console::vm_printf(char x, char y, const char *format,...)
{
    va_list args;
    char buffer[512];
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    vm_puts(x, y, buffer);
}

void Console::vm_printfcenter(char row, const char *format,...)
{
    va_list args;
    char buffer[512];
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    vm_puts((char)((vm_getscreenwidth() / 2) - (strlen(buffer) / 2)), row, buffer);
}

void Console::vm_printfbetween(char x1, char x2, char row, const char *format,...)
{
    char x;
    va_list args;
    char buffer[512];
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    if ((char)strlen(buffer) >= (char)(x2 - x1 + 1))
    {
        vm_puts(x1, row, buffer);
    }
    else
    {
        x = (char)(x1 + (x2 - x1 + 1 - strlen(buffer)) / 2);
        vm_puts(x, row, buffer);
    }
}

void Console::vm_xprintf(char x, char y, char attr, const char *format,...)
{
    va_list args;
    char buffer[512];
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    vm_xputs(x, y, attr, buffer);
}

void Console::vm_xprintfcenter(char row, char attr, const char *format,...)
{
    va_list args;
    char buffer[512];
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    vm_xputs((char)((vm_getscreenwidth() / 2) - (strlen(buffer) / 2)), row, attr, buffer);
}

void Console::vm_xprintfbetween(char x1, char x2, char row, char attr, const char *format,...)
{
    char x;
    va_list args;
    char buffer[512];
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    if ((char)strlen(buffer) >= (char)(x2 - x1 + 1))
    {
        vm_xputs(x1, row, attr, buffer);
    }
    else
    {
        x = (char)(x1 + (x2 - x1 + 1 - strlen(buffer)) / 2);
        vm_xputs(x, row, attr, buffer);
    }
}

void Console::vm_paintclearscreen(char attr)
{
    vm_paintclearbox(1, 1, vm_getscreenwidth(), vm_getscreenheight(), attr);
}

void Console::vm_paintclearline(char row, char attr)
{
    vm_paintclearbox(1, row, vm_getscreenwidth(), row, attr);
}

void Console::vm_paintcleareol(char row, char attr)
{
    vm_paintclearbox(vm_wherex(), row, (char)(vm_getscreenwidth() - vm_wherex() + 1), row, attr);
}

void Console::vm_paintscreen(char attr)
{
    vm_paintbox(1, 1, vm_getscreenwidth(), vm_getscreenheight(), attr);
}

void Console::vm_paintline(char row, char attr)
{
    vm_paintbox(1, row, vm_getscreenwidth(), row, attr);
}

void Console::vm_painteol(char row, char attr)
{
    vm_paintbox(vm_wherex(), row, (char)(vm_getscreenwidth() - vm_wherex() + 1), row, attr);
}

void Console::vm_clearscreen(void)
{
    vm_clearbox(1, 1, vm_getscreenwidth(), vm_getscreenheight());
}

void Console::vm_clearline(char row)
{
    vm_clearbox(1, row, vm_getscreenwidth(), row);
}

void Console::vm_cleareol(char row)
{
    vm_clearbox(vm_wherex(), row, (char)(vm_getscreenwidth() - vm_wherex() + 1), row);
}

void Console::vm_fillscreen(char ch)
{
    vm_fillbox(1, 1, vm_getscreenwidth(), vm_getscreenheight(), ch);
}

void Console::vm_fillline(char row, char ch)
{
    vm_fillbox(1, row, vm_getscreenwidth(), row, ch);
}

void Console::vm_filleol(char row, char ch)
{
    vm_fillbox(vm_wherex(), row, (char)(vm_getscreenwidth() - vm_wherex() + 1), row, ch);
}

void Console::vm_clrscr(void)
{
    vm_paintclearscreen(vm_curattr);
    vm_gotoxy(1, 1);
}

void Console::vm_clreol(void)
{
    vm_paintcleareol(vm_wherey(), vm_curattr);
}

void Console::vm_vertline(char y1, char y2, char col, char attr, char ch)
{
    char y;
    for (y = y1; y <= y2; y++)
    {
        //vm_xputch(col, y, attr, ch);
		vm_putch(col, y, ch);
    }
}

void Console::vm_frame(char x1, char y1, char x2, char y2, char attr, char *frame) 
{
    return;
	vm_xputch(x1, y1, attr, frame[0]);
    vm_horizline((char)(x1 + 1), (char)(x2 - 1), y1, attr, frame[1]);
    vm_xputch(x2, y1, attr, frame[2]);
    vm_vertline((char)(y1 + 1), (char)(y2 - 1), x1, attr, frame[3]);
    vm_vertline((char)(y1 + 1), (char)(y2 - 1), x2, attr, frame[3]);
    vm_xputch(x1, y2, attr, frame[4]);
    vm_horizline((char)(x1 + 1), (char)(x2 - 1), y2, attr, frame[1]);
    vm_xputch(x2, y2, attr, frame[5]);
}

//*************************

void Console::vm_vi_init(void)
{
if (video_init==0)

	AllocConsole();
    HInput = GetStdHandle(STD_INPUT_HANDLE);
    HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//HOutput=CreateConsoleScreenBuffer( GENERIC_WRITE, FILE_SHARE_WRITE, &lpSecurityAttributes, CONSOLE_TEXTMODE_BUFFER, NULL);
	//HInput =CreateConsoleScreenBuffer( GENERIC_READ , FILE_SHARE_READ , &lpSecurityAttributes, CONSOLE_TEXTMODE_BUFFER, NULL);
	

	//SetConsoleActiveScreenBuffer(HOutput);


    video_init = 1;
	
}

void Console::vm_vi_done(void)
{
    CloseHandle(HInput);
//    HInput = INVALID_HANDLE_VALUE;
    CloseHandle(HOutput);
 //   HOutput = INVALID_HANDLE_VALUE;
    video_init = 0;
}

void Console::vm_init(void)
{
    vi_init();
    vm_getinfo(&vm_startup);
    vm_setattr(vm_startup.attr);
}

void Console::vm_done(void)
{
    CONSOLE_CURSOR_INFO cci;
    SetConsoleCursorInfo(HOutput, &cci);
    vm_startup.dwSize = (unsigned short)cci.dwSize;
    vm_startup.bVisible = (int)cci.bVisible;
    vi_done();
}

void Console::vm_getinfo(struct vm_info *v)
{
    CONSOLE_CURSOR_INFO cci;
    v->ypos = vm_wherey();
    v->xpos = vm_wherex();
    v->attr = vm_getattrxy(v->xpos, v->ypos);
    v->height = vm_getscreenheight();
    v->width = vm_getscreenwidth();
    cci.dwSize = (DWORD) vm_startup.dwSize;
    cci.bVisible = (BOOL) vm_startup.bVisible;
    GetConsoleCursorInfo(HOutput, &cci);
}

char Console::vm_getscreenwidth(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(HOutput, &csbi);
    return (char)csbi.dwSize.X;
}

char Console::vm_getscreenheight(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(HOutput, &csbi);
    return (char)csbi.dwSize.Y;
}

short Console::vm_getscreensize(void)
{
    return (short)(vm_getscreenwidth() * vm_getscreenheight() * 2);
}

char Console::vm_wherex(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(HOutput, &csbi);
    return (char)(csbi.dwCursorPosition.X + 1);
}

char Console::vm_wherey(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(HOutput, &csbi);
    return (char)(csbi.dwCursorPosition.Y + 1);
}

void Console::vm_gotoxy(char x, char y)
{
    COORD dwCursorPosition;
    dwCursorPosition.X = (SHORT) (x - 1);
    dwCursorPosition.Y = (SHORT) (y - 1);
    SetConsoleCursorPosition(HOutput, dwCursorPosition);
}

int Console::vm_kbhit(void)
{
    int iKey = 0;
    INPUT_RECORD irBuffer;
    DWORD pcRead;

    if (key_hit != 0xFFFFFFFFUL)
    {
        return (int)key_hit;
    }

    memset(&irBuffer, 0, sizeof irBuffer);

    if (WaitForSingleObject(HInput, 0L) == 0)
    {
        ReadConsoleInput(HInput, &irBuffer, 1, &pcRead);
        if (irBuffer.EventType == KEY_EVENT &&
          irBuffer.Event.KeyEvent.bKeyDown != 0 &&
          irBuffer.Event.KeyEvent.wRepeatCount <= 1)
        {
            WORD vk, vs, uc;
            BOOL fShift, fAlt, fCtrl;

            vk = irBuffer.Event.KeyEvent.wVirtualKeyCode;
            vs = irBuffer.Event.KeyEvent.wVirtualScanCode;
#ifdef __CYGWIN32__
            uc = irBuffer.Event.KeyEvent.AsciiChar;
#else
            uc = irBuffer.Event.KeyEvent.uChar.AsciiChar;
#endif

            fShift = (irBuffer.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED);
            fAlt = (irBuffer.Event.KeyEvent.dwControlKeyState & (RIGHT_ALT_PRESSED + LEFT_ALT_PRESSED));
            fCtrl = (irBuffer.Event.KeyEvent.dwControlKeyState & (RIGHT_CTRL_PRESSED + LEFT_CTRL_PRESSED));

            if (uc == 0)
            {                   /* function keys */
                switch (vk)
                {
                case 0x21:     /* PgUp */
                    if (fCtrl)
                    {
                        vs = 0x84;  /* Ctrl+PgUp */
                    }
                    break;

                case 0x22:     /* PgDn */
                    if (fCtrl)
                    {
                        vs = 0x76;  /* Ctrl+PgDn */
                    }
                    break;

                case 0x23:     /* End */
                    if (fCtrl)
                    {
                        vs = 0x75;  /* Ctrl+End */
                    }
                    break;

                case 0x24:     /* Home */
                    if (fCtrl)
                    {
                        vs = 0x77;  /* Ctrl+Home */
                    }
                    break;

                case 0x25:     /* Left Arrow */
                    if (fCtrl)
                    {
                        vs = 0x73;  /* Ctrl+Left Arrow */
                    }
                    break;

                case 0x26:     /* Up Arrow */
                    if (fCtrl)
                    {
                        vs = 0x8d;  /* Ctrl+Up Arrow */
                    }
                    break;

                case 0x27:     /* Right Arrow */
                    if (fCtrl)
                    {
                        vs = 0x74;  /* Ctrl+Right Arrow */
                    }
                    break;

                case 0x28:     /* Down Arrow */
                    if (fCtrl)
                    {
                        vs = 0x91;  /* Ctrl+Down Arrow */
                    }
                    break;

                case 0x70:     /* F-Keys */
                case 0x71:
                case 0x72:
                case 0x73:
                case 0x74:
                case 0x75:
                case 0x76:
                case 0x77:
                case 0x78:
                case 0x79:
                    if (fAlt)
                    {
                        vs += 0x2d;  /* Alt+F-Key */
                    }
                    else if (fShift)
                    {
                        vs += 0x19;  /* Shift+F-Key */
                    }
                    break;
                }

                if (vk > 0x20 && vk < 0x92)  /* If it's OK use scan code */
                {
                    iKey = vs << 8;
                }
            }
            else
            {
                if (fAlt)       /* Alt+Key */
                {
                    iKey = vs << 8;
                }
                else if (fCtrl) /* Ctrl+Key */
                {
                    iKey = vk & 0xbf;
                }
                else
                {
                    iKey = uc;
                }
            }
        }
    }

    if (iKey != 0)
    {
        key_hit = iKey;
    }

    return (int)iKey;
}

int Console::vm_getch(void)
{
    int iKey;
    while (key_hit == 0xFFFFFFFFUL)
    {
         vm_kbhit();
    }
    iKey = key_hit;
    key_hit = 0xFFFFFFFFUL;
    return (int)iKey;
}

char Console::vm_getchxy(char x, char y)
{
    char ch;
    DWORD len;
    COORD coord;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    ReadConsoleOutputCharacterA(HOutput, &ch, 1, coord, &len);
    return ch;
}

char Console::vm_getattrxy(char x, char y)
{
    DWORD len;
    COORD coord;
    WORD wattr;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    ReadConsoleOutputAttribute(HOutput, &wattr, 1, coord, &len);
    return (char)wattr;
}

void Console::vm_xgetchxy(char x, char y, char *attr, char *ch)
{
    DWORD len;
    COORD coord;
    WORD wattr;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    ReadConsoleOutputCharacterA(HOutput, ch, 1, coord, &len);
    ReadConsoleOutputAttribute(HOutput, &wattr, 1, coord, &len);
    *attr = (char)wattr;
}

void Console::vm_setcursorstyle(int style)
{
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(HOutput, &cci);
    switch (style)
    {
    case CURSORHALF:
        cci.bVisible = 1;
        cci.dwSize = 49;
        SetConsoleCursorInfo(HOutput, &cci);
        break;
    case CURSORFULL:
        cci.bVisible = 1;
        cci.dwSize = 99;
        SetConsoleCursorInfo(HOutput, &cci);
        break;
    case CURSORNORM:
        cci.bVisible = 1;
        cci.dwSize = 12;
        SetConsoleCursorInfo(HOutput, &cci);
        break;
    case CURSORHIDE:
        cci.bVisible = 0;
        SetConsoleCursorInfo(HOutput, &cci);
        break;
    default:
        break;
    }
}

void Console::vm_putch(char x, char y, char ch)
{
    DWORD len;
    COORD coord;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    WriteConsoleOutputCharacterA(HOutput, &ch, 1, coord, &len);
}

void Console::vm_puts(char x, char y, char *str)
{
    DWORD len;
    COORD coord;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    WriteConsoleOutputCharacterA(HOutput, str, (DWORD) strlen(str), coord, &len);
}

void Console::vm_xputch(char x, char y, char attr, char ch)
{
    DWORD len;
    COORD coord;
    WORD wattr;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    wattr = attr;
    WriteConsoleOutputCharacterA(HOutput, &ch, 1, coord, &len);
    WriteConsoleOutputAttribute(HOutput, &wattr, 1, coord, &len);
}

void Console::vm_xputs(char x, char y, char attr, char *str)
{
    DWORD i, len;
    COORD coord;
    LPWORD pwattr;
    pwattr = (unsigned short *) malloc(strlen(str) * sizeof(*pwattr));
    if (!pwattr)
    {
        return;
    }
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    for (i = 0; i < strlen(str); i++)
    {
        *(pwattr + i) = attr;
    }
    WriteConsoleOutputCharacterA(HOutput, str, (DWORD) strlen(str), coord, &len);
    WriteConsoleOutputAttribute(HOutput, pwattr, (DWORD) strlen(str), coord, &len);
    free(pwattr);
}

void Console::vm_putattr(char x, char y, char attr)
{
    DWORD len;
    COORD coord;
    WORD wattr;
    coord.X = (short) (x - 1);
    coord.Y = (short) (y - 1);
    wattr = attr;
    WriteConsoleOutputAttribute(HOutput, &wattr, 1, coord, &len);
}

void Console::vm_paintclearbox(char x1, char y1, char x2, char y2, char attr)
{
    COORD coord;
    LPWORD pwattr;
    char y, *pstr;
    DWORD i, len, width;
    width = (x2 - x1 + 1);
    pwattr = (unsigned short *) malloc(width * sizeof(*pwattr));
    if (!pwattr)
    {
        return;
    }
    pstr = (char *) malloc(width);
    if (!pstr)
    {
        free(pwattr);
        return;
    }
    for (i = 0; i < width; i++)
    {
        *(pwattr + i) = attr;
        *(pstr + i) = ' ';
    }
    for (y = y1; y <= y2; y++)
    {
        coord.X = (short) (x1 - 1);
        coord.Y = (short) (y - 1);
        WriteConsoleOutputCharacterA(HOutput, pstr, width, coord, &len);
        WriteConsoleOutputAttribute(HOutput, pwattr, width, coord, &len);
    }
    free(pwattr);
    free(pstr);
}

void Console::vm_paintbox(char x1, char y1, char x2, char y2, char attr)
{
    
	DWORD i, len, width;
    COORD coord;
    LPWORD pwattr;
    char y;
    width = (x2 - x1 + 1);
    pwattr = (LPWORD) malloc(width * sizeof(*pwattr));
    if (!pwattr)
    {
        return;
    }
    for (i = 0; i < width; i++)
    {
        *(pwattr + i) = attr;
    }
    for (y = y1; y <= y2; y++)
    {
        coord.X = (short) (x1 - 1);
        coord.Y = (short) (y - 1);
        WriteConsoleOutputAttribute(HOutput, pwattr, width, coord, &len);
    }
    free(pwattr);
}

void Console::vm_clearbox(char x1, char y1, char x2, char y2)
{
    vm_fillbox(x1, y1, x2, y2, ' ');
}

void Console::vm_fillbox(char x1, char y1, char x2, char y2, char ch)
{
    DWORD i, len, width;
    COORD coord;
    char y, *pstr;
    width = (x2 - x1 + 1);
    pstr = (char * ) malloc(width);
    if (!pstr)
    {
        return;
    }
    for (i = 0; i < width; i++)
    {
        *(pstr + i) = ch;
    }
    for (y = y1; y <= y2; y++)
    {
        coord.X = (short) (x1 - 1);
        coord.Y = (short) (y - 1);
        WriteConsoleOutputCharacterA(HOutput, pstr, width, coord, &len);
    }
    free(pstr);
}

void Console::vm_gettext(char x1, char y1, char x2, char y2, char *dest)
{
    DWORD i, len, width;
    COORD coord;
    LPWORD pwattr;
    char y, *pstr;
    width = (x2 - x1 + 1);
    pwattr = (unsigned short *) malloc(width * sizeof(*pwattr));
    if (!pwattr)
    {
        return;
    }
    pstr = (char *) malloc(width);
    if (!pstr)
    {
        free(pwattr);
        return;
    }
    for (y = y1; y <= y2; y++)
    {
        coord.X = (short) (x1 - 1);
        coord.Y = (short) (y - 1);
        ReadConsoleOutputCharacterA(HOutput, pstr, width, coord, &len);
        ReadConsoleOutputAttribute(HOutput, pwattr, width, coord, &len);
        for (i = 0; i < width; i++)
        {
            *dest = *(pstr + i);
            dest++;
            *dest = (char)*(pwattr + i);
            dest++;
        }
    }
    free(pwattr);
    free(pstr);
}
void Console::vm_setmode(char Mode)
{
DWORD i;
BOOL bSuccess;

i = (DWORD) Mode;
bSuccess = SetConsoleMode(HOutput, i); 


}
void Console::vm_puttext(char x1, char y1, char x2, char y2, char *srce)
{
    DWORD i, len, width;
    COORD coord;
    LPWORD pwattr;
    char y, *pstr;
    width = (x2 - x1 + 1);
    pwattr = (unsigned short *) malloc(width * sizeof(*pwattr));
    if (!pwattr)
    {
        return;
    }
    pstr = (char * ) malloc(width);
    if (!pstr)
    {
        free(pwattr);
        return;
    }
    for (y = y1; y <= y2; y++)
    {
        for (i = 0; i < width; i++)
        {
            *(pstr + i) = *srce;
            srce++;
            *(pwattr + i) = *srce;
            srce++;
        }
        coord.X = (short) (x1 - 1);
        coord.Y = (short) (y - 1);
        WriteConsoleOutputCharacterA(HOutput, pstr, width, coord, &len);
        WriteConsoleOutputAttribute(HOutput, pwattr, width, coord, &len);
    }
    free(pwattr);
    free(pstr);
}

void Console::vm_horizline(char x1, char x2, char row, char attr, char ch)
{
    char x;
    for (x = x1; x <= x2; x++)
    {
        vm_xputch(x, row, attr, ch);
    }
}

void Console::vm_scroll(char x, char y, char X, char Y, char dir, char attr)
{

SMALL_RECT ScrollRec;
COORD dwDestOrigin;
CHAR_INFO lpFill ;

lpFill.Attributes = attr;
lpFill.Char.AsciiChar = ' ';

ScrollRec.Top		=  x; //Fila Superior
ScrollRec.Left		=  y; //Columna Superior

ScrollRec.Right		= Y; //Fila Inferior
ScrollRec.Bottom	= X;  //Columna Inferior

if (dir==1)
	{
	dwDestOrigin.Y = x-1;	//Fila
	dwDestOrigin.X = y;		//Columna
	}
else
	{	
	dwDestOrigin.Y = x+1;	//Fila
	dwDestOrigin.X = y;		//Columna
	}

ScrollConsoleScreenBuffer(HOutput, &ScrollRec, NULL, dwDestOrigin, &lpFill );

}

/*******/

int Console::vioImageInit(VIOIMAGE * v, char width, char height)
{
    v->image = (char *) malloc(width * height * 2);
    if (v->image)
    {
        v->width = width;
        v->height = height;
        return 1;
    }
    else
    {
        return 0;
    }
}

int Console::vioImageTerm(VIOIMAGE * v)
{
    if (v->image)
    {
        free(v->image);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Console::vioImageSave(VIOIMAGE * v, char x, char y)
{
    if (v->image)
    {
        vm_gettext(x, y, v->width, v->height, v->image);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Console::vioImageRestore(VIOIMAGE * v, char x, char y)
{
    if (v->image)
    {
        vm_puttext(x, y, v->width, v->height, v->image);
        return 1;
    }
    else
    {
        return 0;
    }
}


//****
void Console::vioImageDefaults(VIOIMAGE * v)
{
    v->width = 0;
    v->height = 0;
    v->image = NULL;
}


void Console::gotoxy(char x,char y)
{
XY.X=y;
XY.Y=x;
SetConsoleCursorPosition(HOutput,XY);
return;  
}

void Console::cls(void)
{
	/*XY.X=0;
	XY.Y=0;
	FillConsoleOutputCharacter(HOutput, ' ', 25*80, XY, lpNumberOfCharsWritten );
	FillConsoleOutputAttribute(HOutput, FOREGROUND_INTENSITY, 25*80, XY, lpNumberOfCharsWritten );
	*/
	vm_clrscr();
}
void Console::write(char *string)
{

//vm_puts((char) vm_wherex(), (char) vm_wherey(),string);
 DWORD len;
    
 WriteConsole(HOutput, string, strlen(string), &len, lpReserved );
//WriteFile(HOutput, string, strlen(string), lpNumberOfCharsWritten, NULL);

  

}

void Console::write(char *string, char* sformat)
{

	
	write(format(string,sformat));
}

void Console::writexy(char x, char y, char *string)
{
gotoxy(x,y);
write(string);
}

void Console::writexy(char x, char y, char *string, char *sformat)
{
gotoxy(x,y);
write(format(string,sformat));
}


void Console::vm_attrib(WORD wAtributo)
{
	
	vm_curattr = (char) wAtributo;
	SetConsoleTextAttribute(HOutput,wAtributo);

}

void Console::scroll(int x, int y, int X, int Y, int dir)
{

SMALL_RECT ScrollRec;
//SMALL_RECT *lpClipRectangle;
COORD dwDestOrigin;
CHAR_INFO lpFill ;

lpFill.Attributes = FOREGROUND_INTENSITY;
lpFill.Char.AsciiChar = ' ';

ScrollRec.Top		= x; //Fila Superior
ScrollRec.Left		= y; //Columna Superior

ScrollRec.Right		= Y; //Fila Inferior
ScrollRec.Bottom	= X;  //Columna Inferior

if (dir==1)
	{
	dwDestOrigin.Y = x-1;	//Fila
	dwDestOrigin.X = y;		//Columna
	}
else
	{	
	dwDestOrigin.Y = x+1;	//Fila
	dwDestOrigin.X = y;		//Columna
	}

ScrollConsoleScreenBuffer(HOutput, &ScrollRec, NULL, dwDestOrigin, &lpFill );

}

void Console::scrollh(int x, int y,  int Y, int dir)
{


SMALL_RECT ScrollRec;
//SMALL_RECT *lpClipRectangle;
COORD dwDestOrigin;
CHAR_INFO lpFill ;

lpFill.Attributes = FOREGROUND_INTENSITY;
lpFill.Char.AsciiChar = ' ';

ScrollRec.Top		= x; //Fila Superior
ScrollRec.Left		= y; //Columna Superior

ScrollRec.Right		= Y; //Fila Inferior
ScrollRec.Bottom	= x;  //Columna Inferior

if (dir==1)
	{
	dwDestOrigin.Y = x;	//Fila
	dwDestOrigin.X = y-1;		//Columna
	}
else
	{	
	dwDestOrigin.Y = x;	//Fila
	dwDestOrigin.X = y+1;		//Columna
	}

ScrollConsoleScreenBuffer(HOutput, &ScrollRec, NULL, dwDestOrigin, &lpFill );

}

void Console::SaveScr(VIOIMAGE *sys)
{
    vioImageDefaults(sys);
    vioImageInit(sys, vm_getscreenwidth(), vm_getscreenheight());
    vioImageSave(sys, 1, 1);
	return;
}

void Console::RestScr(VIOIMAGE *sys)
{
    vioImageRestore(sys, 1, 1);
    vioImageTerm(sys);
}

char *Console::strspc(char *str, int len)
{
int n,nLen;
nLen = strlen(str);
for (n=0;n+nLen<len;n++)
{
	str[nLen+n]=' ';
}

str[nLen+n]='\0';
return str;
}

char *Console::format(char *sval,char *Mask)
{
int x, ind=0;
char c, car[1];
int lMask, lval, nLenFrm=0;
static char Result[250];

memset(Result, 0, 250); 
strcpy(Result, sval);

memset(car, 0, 2); 

lMask = strlen(Mask)-1;
lval  = strlen(sval)-1;


nLenFrm=0;
for (x=0;lMask+1!=x;x++)
	{
	c=Mask[x];
	switch (c)
		{	
		case 'A':
		case '9':
			nLenFrm++;
			break;
		default:
			break;
		}		
	}




if ((unsigned) nLenFrm  < strlen(sval))			//Ok
	{
		memset(Result, 0, 250); 
		memset(Result, '*',lMask+1);
		return Result;
	}

//printf(Result);
//getch();


for (x = 0; lMask - x +1 && x - ind  < lval +1 ; x++)
	{
	
	c = Mask[lMask - x];
		
	switch (c)
		{
		case 'A':
			car[0]=Result[lval-x+ind];
			strupr(car);
			Result[lval-x+ind] = car[0];
			break;
		case ' ':		
		case ':':
		case '/':
		case ',':
		case '.':
		case '*':
		case '-':
			ind++;	
			car[0]=c;
			//printf("%s|",Result);
			insstr(Result,car,lval-x + ind );
			
			break;
		default:
			break;

		}

  }



//if ((unsigned) lMask>strlen(Result))
		strcpy(Result,rgtjst(Result,lMask+1));

return Result;
}



char *Console::insstr(char *fdestin,char *fsource,int fstart)

{

  int wdlen,wslen;
  int w,wlen,wpad;

  wdlen = strlen(fdestin);	/* get destination string length */
  wslen = strlen(fsource);	/* get source string length */

  wlen = min(fstart,wdlen);	/* don't initially point past destin */

  wpad = fstart - wlen; 	/* get extra length to pad */

  for (w = wlen ; w < fstart ; w ++)	/* pad with blanks if neccessary */
    fdestin[w] = ' ';

  /* start at end of string and move characters to the right */
  /* draw it out if necessary; It's hard to follow if you don't */

  for (w = wdlen + wslen - 1 ; w >= fstart + wslen ; w --)
    fdestin[w] = fdestin[w - wslen];

  for (w = 0 ; w < wslen ; w ++)	/* now insert into the dest string */
    fdestin[w+fstart] = *fsource++;

  fdestin[wslen+wdlen+wpad] = 0;	/* string is bigger, needs NULL */
return fdestin;
}

char *Console::rgtjst(char *fstr,int flen)
{
  static char wbuf[256];
  int len,w;
  char wtemp[256];

  strcpy(wtemp,fstr);
  w = strlen(wtemp);
  len = w-1;

  if (wtemp[len] == ' ') {
    do len --; while(wtemp[len] == ' ');
    wtemp[++len] = 0;
  }

  sprintf(wbuf,"%s%s",strpad((int) (flen - strlen(wtemp)),' '),wtemp);
  return(wbuf);
}

char *Console::strpad(int flen,int fchar)
{
  static char wbuf[256];

  memset(wbuf,fchar,flen);

  wbuf[flen] = 0;		/* flag the end of string */

  return(wbuf);
}

void Console::strscrll(char *str, char f, char c, char f1, char c1)
{

 int x, ind=0, i;
 
 char substr[81];
 
 //memset(str,0,150);  
 
 
 //strcpy(str, string);
 
 i =  strlen(str)/(f1-f+1);
 
 for(x=0; i - x +1;x++)
  	{
  	memset(substr,0,81);  
 	strncpy(substr, str+ind, c1-c+1);
 	
 	ind += strlen(substr);    


    if ( x > (f1-f))
    	{
    	delay(200);
		scroll(f+1,c,f1,c1,1);
    	writexy(f1,c, substr);
    	//delay(200);
		
    	}
   	else 	
        {
    	writexy(f+x,c, substr);
 		}
    }


return;
}

void Console::strscrllh(char *str, char f, char c,  char c1)
{

 int x, ind=0, i;
 
char substr[256];
vm_setcursorstyle(CURSORHIDE);
memset(substr,0,256);  
strncpy(substr, str+ind, c1-c+1);
writexy(f,c,substr);
ind += strlen(substr);    
i =  strlen(str)  ;
for(x=0; i - x +1;x++)
  	{
  	delay(50);
	scrollh(f,c,c1,1);
	vm_putch(c1,f+1 ,*(str+ind+x));
    }
vm_setcursorstyle(CURSORNORM);
return;
}

void Console::delay(DWORD millisecs)
{
DWORD elapsed=0;

	elapsed=GetTickCount();
	while (GetTickCount()-elapsed < millisecs)
		;

}