#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; // ungetch buffer
int bufp = 0; // buf 内の次の空き位置

int getch(void)
{
	return (buf > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ubgetch: too many characters\n");
	else
		buf[bufp++] = c;
}


