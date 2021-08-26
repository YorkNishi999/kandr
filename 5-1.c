#include <stdio.h>
#include <ctype.h>

int getch(void);
int ungetch(int);

int getint(int*);

// getint:入力から次の整数を取り出して *pn に入れる

int main()
{
	int a, b, c;
	c = 0;
	c = getint(&a);

	printf("c %d\n",  c);

	return 0;

}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) // 空白を飛ばす
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + ( c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;

}
