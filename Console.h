#ifndef CON
#define CON
#include <windows.h>

#ifndef WINNT
#define WINNT
#endif

#define	FRAME_BLANK    "      "
#define	FRAME_SINGLE   "ÚÄ¿³ÀÙ"
#define	FRAME_DOUBLE   "ÉÍ»ºÈ¼"


#define BLACK         0x00
#define BLUE          0x01
#define GREEN         0x02
#define CYAN          0x03
#define RED           0x04
#define MAGENTA       0x05
#define PURPLE        MAGENTA
#define BROWN         0x06
#define LIGHTGRAY     0x07
#define LIGHTGREY     LIGHTGRAY
#define DARKGRAY      0x08
#define DARKGREY      DARKGRAY
#define LIGHTBLUE     0x09
#define LIGHTGREEN    0x0a
#define LIGHTCYAN     0x0b
#define LIGHTRED      0x0c
#define LIGHTMAGENTA  0x0d
#define LIGHTPURPLE   LIGHTMAGENTA
#define YELLOW        0x0e
#define WHITE         0x0f
#define BLINK         0x80

#define CURSORHIDE    0
#define CURSORNORM    1
#define CURSORHALF    2
#define CURSORFULL    3

#define vm_mkcolor(fore, back)  ((fore) | (back << 4))
#define vm_fore(attr)           (attr % 16)
#define vm_back(attr)           (attr / 16)
#define vm_mkcolour             vm_mkcolor


struct vm_info
{
    char attr;                  /* text attribute */
#if defined(DOS)
    char mode;                  /* video mode */
#endif
    char height;                /* screen height */
    char width;                 /* screen width */
    char ypos;                  /* y-coordinate */
    char xpos;                  /* x-coordinate */
#if defined(WINNT)
    unsigned short dwSize;      /* 0=minimal; 49=half; 99=full */
    int bVisible;               /* 0=cursor invisible */
#else
    char cur_start;             /* cursor start line */
    char cur_end;               /* cursor end line */
#endif
};

//extern struct vm_info vm_startup;

//struct vm_info vm_startup;
extern char vm_curattr;

extern char vm_frame_blank[];
extern char vm_frame_single[];
extern char vm_frame_double[];

//****************
#ifdef __CYGWIN32__
typedef WORD far *LPWORD;
#endif

//static HANDLE HInput = INVALID_HANDLE_VALUE;
//static HANDLE HOutput = INVALID_HANDLE_VALUE;
//static unsigned long key_hit = 0xFFFFFFFFUL;



#define vi_init()  if (!video_init) vm_vi_init()
#define vi_done()  if (video_init) vm_vi_done()

//**
typedef struct
{
    char *image;
    char width;
    char height;
}
VIOIMAGE;

#define maxx  vm_getscreenwidth()
#define maxy  vm_getscreenheight()
//#define max(x,y) (x > y ? x : y)
//#define min(x,y) (x < y ? x : y)


class Console {

		HANDLE	HInput ;
		HANDLE	HOutput;
		unsigned long key_hit ;

	
		int video_init; // = 0;
		struct vm_info vm_startup;
		char vm_curattr;
		char vm_frame_blank[6];   //="      ";
		char vm_frame_single[6];  //= "ÚÄ¿³ÀÙ";
		char vm_frame_double[6];  //= "ÉÍ»ºÈ¼";


		CONSOLE_SCREEN_BUFFER_INFO 	csbiInfo; 
		SMALL_RECT 			srctWindow; 
		LPDWORD 			Buffer[128];
		COORD 				XY;		//Coordenadas
		TCHAR 				cCharacter;
		DWORD 				nLength;
		LPDWORD 			lpNumberOfCharsWritten;	
		LPVOID				lpReserved ;
		WORD				wAttributes;
		SECURITY_ATTRIBUTES lpSecurityAttributes;

		

		

	public:
	
		int		Terminal;
		char				sResult[250];

			Console(void);
		
		void vm_vi_done(void);
		void vm_vi_init(void);

	
		void vm_init(void);
		void vm_done(void);
		char vm_getscreenwidth(void);
		char vm_getscreenheight(void);
		short vm_getscreensize(void);
		void vm_gotoxy(char x, char y);
		char vm_wherex(void);
		char vm_wherey(void);
		int vm_kbhit(void);
		int vm_getch(void);
		void vm_paintclearbox(char x1, char y1, char x2, char y2, char attr);
		void vm_paintclearscreen(char attr);
		void vm_paintclearline(char row, char attr);
		void vm_paintcleareol(char row, char attr);
		void vm_paintbox(char x1, char y1, char x2, char y2, char attr);
		void vm_paintscreen(char attr);
		void vm_paintline(char row, char attr);
		void vm_painteol(char row, char attr);
		void vm_clearbox(char x1, char y1, char x2, char y2);
		void vm_clearscreen(void);
		void vm_clearline(char row);
		void vm_cleareol(char row);
		void vm_fillbox(char x1, char y1, char x2, char y2, char ch);
		void vm_fillscreen(char ch);
		void vm_fillline(char row, char ch);
		void vm_filleol(char row, char ch);
		void vm_clrscr(void);
		void vm_clreol(void);
		char vm_getchxy(char x, char y);
		char vm_getattrxy(char x, char y);
		void vm_xgetchxy(char x, char y, char *attr, char *ch);
		void vm_setattr(char attr);
		void vm_putattr(char x, char y, char attr);
		void vm_setcursorstyle(int style);
		void vm_putch(char x, char y, char ch);
		void vm_puts(char x, char y, char *str);
		void vm_printf(char x, char y, const char *format,...);
		void vm_printfcenter(char row, const char *format,...);
		void vm_printfbetween(char x1, char x2, char row, const char *format,...);
		void vm_xputch(char x, char y, char attr, char ch);
		void vm_xputs(char x, char y, char attr, char *str);
		void vm_xprintf(char x, char y, char attr, const char *format,...);
		void vm_xprintfcenter(char row, char attr, const char *format,...);
		void vm_xprintfbetween(char x1, char x2, char row, char attr, const char *format,...);
		void vm_horizline(char x1, char x2, char row, char attr, char ch);
		void vm_vertline(char y1, char y2, char col, char attr, char ch);
		void vm_frame(char x1, char y1, char x2, char y2, char attr, char *frame);
		void vm_gettext(char x1, char y1, char x2, char y2, char *dest);
		void vm_puttext(char x1, char y1, char x2, char y2, char *srce);
		void vm_getinfo(struct vm_info *v);
		void vm_scroll(char x1, char y1, char x2, char y2, char dir, char attr);
		void vm_setmode(char Mode);
		

		//*****
		void vioImageDefaults(VIOIMAGE * v);
		int vioImageInit(VIOIMAGE * v, char width, char height);
		int vioImageTerm(VIOIMAGE * v);
		int vioImageSave(VIOIMAGE * v, char x, char y);
		int vioImageRestore(VIOIMAGE * v, char x, char y);

		void gotoxy(char x,char y);	
		void cls(void);
		void vm_attrib(WORD wAtributo);
		void write(char *string);
		void Console::write(char *string, char* sformat);
		void writexy(char x, char y, char *string);
		void writexy(char x, char y, char *string, char *Format);
		void scroll(int x, int y, int X, int Y, int dir);
		void scrollh(int x, int y, int Y, int dir);
		char *strspc(char *str, int len);
		char *format(char *sval,char *Mask);
		char *insstr(char *fdestin,char *fsource,int fstart);


		void SaveScr(VIOIMAGE *sys);
		void RestScr(VIOIMAGE *sys);
		char *rgtjst(char *fstr,int flen);
		char *strpad(int flen,int fchar);
		void strscrll(char *str, char f, char c, char f1, char c1); 
		void strscrllh(char *str, char f, char c, char c1); 
		void delay(DWORD millisecs);


};


#endif
