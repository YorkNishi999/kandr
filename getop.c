#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);

// getop: 次の演算子あるいは数値の被演算数を取ってくる
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  // 数ではない
	i = 0;
	if (isdigit(c)) // 整数部を集める
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') // 小数部を集める
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;

}
