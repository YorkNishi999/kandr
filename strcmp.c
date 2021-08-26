#include<stdio.h>

int strcmp( char *, char *);


int main()
{
	char *a, *b;

	a = "abz";
	b = "abc";

	int ans = strcmp(a,b);

	printf("%d\n", ans);

}

// strcmp: s t で数値的に小さい方がｓなら負の値、逆は逆
int strcmp(char *s, char *t)
{
	for( ; *s == *t; s++, t++ )
		if (*s == '\0')
			return 0;
	return *s - *t;
}