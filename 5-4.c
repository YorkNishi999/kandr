#include<stdio.h>
#include<string.h>

// int strend (char s[], char t[]);
int strend(char *s, char *t);

int main()
{
	char a[] = "EDFABC";
	char b[] = "ABC";
	char c[] = "EDF";
	char d[] = "EDFABC";

	int ab = strend(a, b);
	int ac = strend(a, c);
	int ad = strend(a, d);

	printf("b c d = %d %d %d\n", ab, ac, ad);

}



int strend (char s[], char t[])
{
	char *starts, *startt;
	starts = s;
	startt = t;

	for(; *s != '\0'; s++)
		;
	for(; *t != '\0'; t++)
		;
	while(*s-- == *t-- )
		if (t == startt)
			return 1;
	return 0;

}

