#include <stdio.h>

void reverse2(char s[]);

int main() {
	char a[] = "ABCDEF";

	printf("%s\n", a);

	reverse2(a);

	printf("%s\n", a);
}


void reverse2(char s[])
{
	char* pstart;
	int len = 0;
	char tmp;
	int i;

	pstart = s; // pstart is the beginning of pointer of s
		printf("1 tmp pstart s %c %c %c\n", tmp, *pstart, *s);

	//for (; *s == '\0'; ++s)
	while (*s++ != '\0')
		++len;
	--s;
	--s;

		printf("2 tmp pstart s %c %c %c\n", tmp, *pstart, *s);

	//for (; pstart < s; ++pstart, --s) {
	while(pstart < s) {	
		tmp = *pstart;
		printf("3 tmp pstart s %c %c %c\n", tmp, *pstart, *s);
		*pstart = *s;
		printf("4 tmp pstart s %c %c %c\n", tmp, *pstart, *s);
		*s = tmp;
		printf("5 tmp pstart s %c %c %c\n", tmp, *pstart, *s);
		++pstart;
		--s;
	}


}