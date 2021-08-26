#include<stdio.h>
void sstrcat (char s[], char t[]);

int main()
{
	char a[] = "ABC";
	char b[] = "DEF";


	sstrcat(a, b);

	printf("%s\n", a);
	return 0;

}

void sstrcat (char s[], char t[])
{
	for( ; *s != '\0'; ++s) 
		;
	for( ; *s = *t; ++s, ++t)
		; 
}