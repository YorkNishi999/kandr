#include <stdio.h>
#include <ctype.h>
#include <string.h>

// getword: 入力から次の語または文字を求める
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++){
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
