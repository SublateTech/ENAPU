#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)


char Result[250];
char Mask[250];
char *insstr(char *fdestin,char *fsource, int fstart);

char *format(char * ,char *, char *);

int main()
{

printf(format("4b789999","A99A.9:9-9",Result));
//printf(format("abcdef","A-AA",Result));
getch();
return 0;

}

char *format(char *sval,char *Mask, char *Result)
{
int x, ind=0;
char c, car[2];
int lMask, lval;

strcpy(Result, sval);

memset(car, 0, 3); 
lMask = strlen(Mask)-1;
lval  = strlen(sval)-1;

	
for (x = 0 ; lMask - x +1; x++)
	{
	c = Mask[lMask - x];
	if (lval-x > lval)
		return Result;
	
	switch (c)
		{
		case 'A':
			car[0]=Result[lval-x+ind];
			strupr(car);
			Result[lval-x+ind] = car[0];
			continue;
		case ' ':		
		case ':':
		case '/':
		case ',':
		case '.':
		case '-':
			
			car[0]=c;
			insstr(Result,car,lval-x +ind);
			ind++;
			continue;
		default:
			break;

		}

	  }

return Result;
}


char *insstr(char *fdestin,char *fsource,int fstart)

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

